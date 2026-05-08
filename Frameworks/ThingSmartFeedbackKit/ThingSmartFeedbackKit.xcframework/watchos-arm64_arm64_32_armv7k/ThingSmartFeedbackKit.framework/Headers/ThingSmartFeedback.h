
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingSmartFeedbackTalkListModel.h"
#import "ThingSmartFeedbackModel.h"
#import "ThingSmartFeedbackTypeListModel.h"

/// @brief ThingSmartFeedback provides methods for developers to implement feedback functionalities.
///
/// When the user finds a problem and needs to submit feedback, he/she can add it. When adding feedback, he/she should first select the feedback type, then write the feedback content and submit it.
///
/// All functions related to feedback correspond to the ThingSmartFeedback class, which supports the following list of functions:
///
/// - ThingSmartFeedback::getFeedbackTalkList:failure: for getting a list of feedback sessions
/// - ThingSmartFeedback::getFeedbackList:hdType:success:failure: for getting a list of feedback contents in a session
/// - ThingSmartFeedback::getFeedbackTypeList:failure: for getting a list of feedback types
/// - adding feedback
@interface ThingSmartFeedback : NSObject

/// Get a list of sessions that users have submitted feedback on.
///
/// @param success      When success, return feedback session list.
/// @param failure      When error occurred, return ThingFailureError.
- (void)getFeedbackTalkList:(void (^)(NSArray<ThingSmartFeedbackTalkListModel *> *list))success
                    failure:(ThingFailureError)failure;


/// Get a list of the corresponding feedback contents in the feedback session. The `hdId` and `hdType` can be obtained from ThingSmartFeedbackTalkListModel.
///
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param success      When success, return feedback list.
/// @param failure      When error occurred, return ThingFailureError.
- (void)getFeedbackList:(NSString *)hdId
                 hdType:(NSUInteger)hdType
                success:(void (^)(NSArray<ThingSmartFeedbackModel *> *list))success
                failure:(ThingFailureError)failure;


/// Get feedback type list. When adding feedback, select the type of feedback first.
///
/// @param success      When success, return ThingSmartFeedbackTypeListModel.
/// @param failure      When error occurred, return ThingFailureError.
- (void)getFeedbackTypeList:(void (^)(NSArray<ThingSmartFeedbackTypeListModel *> *list))success
                    failure:(ThingFailureError)failure;


/// Add feedback and submit the content of the feedback entered by the user.
///
/// The `hdId` and `hdType` can be obtained from ThingSmartFeedbackTalkListModel.
///
/// @note This is suggested for App related issues and devices that do not need strong bindings.
///
/// @param content      The feedback content.
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param contact      The contact information.
/// @param success      When successfully add the feedback, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
            success:(ThingSuccessHandler)success
            failure:(ThingFailureError)failure;


/// Add feedback and submit the content of the feedback entered by the user.
///
/// The `hdId` and `hdType` can be obtained from ThingSmartFeedbackTalkListModel.
///
/// @note This is suggested for devices that need strong bindings, for example IP cameras.
///
/// @param content      The feedback content.
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param contact      The contact information.
/// @param uuid         The UUID for the device.
/// @param region       The user's region.
/// @param success      When successfully add the feedback, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
               uuid:(NSString *)uuid
             region:(NSString *)region
            success:(ThingSuccessHandler)success
            failure:(ThingFailureError)failure;


/// Canceling an ongoing operation.
- (void)cancelRequest;

@end
