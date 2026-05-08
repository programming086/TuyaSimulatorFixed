
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingSmartMessageListModel.h"
#import "ThingSmartMessageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN
/// @brief ThingSmartMessage provides methods to implement message functionalities.
///
/// ThingSmartMessage provides a message center and supports push functions. The messages are classified into the following categories: alert messages, home messages, and notifications. Each type of message can be enabled or disabled.
@interface ThingSmartMessage : NSObject

/// Returns a list of messages.
/// @param listRequestModel Returns a list of ThingSmartMessageListModel.
/// @param success Called when the task is finished. A list of ThingSmartMessageListModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageListWithListRequestModel:(ThingSmartMessageListRequestModel *)listRequestModel
                                     success:(void (^)(NSArray<ThingSmartMessageListModel *> *messageList))success
                                     failure:(ThingFailureError)failure;

/// Returns a list of messages.
/// @param requestModel ThingSmartMessageListRequestModelV1
/// @param success Called when the task is finished. A list of ThingSmartMessageListModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageListWithRequestModel:(ThingSmartMessageListRequestModelV1 *)requestModel
                                 success:(void (^)(NSArray<ThingSmartMessageListModel *> *messageList))success
                                 failure:(ThingFailureError)failure;

/// Returns a list of message details.
/// @param detailListRequestModel Returns a list of ThingSmartMessageListModel.
/// @param success Called when the task is finished. A list of ThingSmartMessageListModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageDetailListWithListRequestModel:(ThingSmartMessageDetailListRequestModel *)detailListRequestModel
                                           success:(void (^)(NSArray<ThingSmartMessageListModel *> *messageList))success
                                           failure:(ThingFailureError)failure;

/// Returns a list of message details. Some details require additional decryption
/// @param detailListRequestModel Returns a list of ThingSmartMessageListModel.
/// @param success Called when the task is finished. A list of ThingSmartMessageListModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchEncryptMessageDetailListWithListRequestModel:(ThingSmartMessageDetailListRequestModel *)detailListRequestModel
                                                  success:(void (^)(NSArray<ThingSmartMessageListModel *> *messageList))success
                                                  failure:(ThingFailureError)failure;

/// Returns the latest messages of all types.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getLatestMessageWithSuccess:(ThingSuccessDict)success failure:(ThingFailureError)failure;

/// Sets and reads a list of data of the message center.
/// @param readRequestModel A list of read messages. All types of messages can be read.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)readMessageWithReadRequestModel:(ThingSmartMessageListReadRequestModel *)readRequestModel success:(ThingSuccessBOOL)success failure:(ThingFailureError)failure;


/// Deletes a list of data from the message center.
/// @param deleteRequestModel A list of deleted messages. The deletion of all data is not supported.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteMessageWithDeleteRequestModel:(ThingSmartMessageListDeleteRequestModel *)deleteRequestModel success:(ThingSuccessBOOL)success failure:(ThingFailureError)failure;

/// Request message details decryption key
/// @param encryptRequestListModel A list of encryptRequestModel
/// @param success Called when the task is finished. A list of ThingSmartMessageDecryptModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageDecryptKeyWithEncryptRequestModel:(NSArray<ThingSmartMessageEncryptRequestModel *> *)encryptRequestListModel success:(void (^)(NSArray<ThingSmartMessageDecryptModel *> *messageList))success
                                              failure:(ThingFailureError)failure;
/// Cancels the ongoing request.
- (void)cancelRequest;

@end
NS_ASSUME_NONNULL_END
