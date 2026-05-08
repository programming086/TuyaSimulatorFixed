//
//  ThingLightingRepiar.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingRepairOrderDetailModel;

@interface ThingLightingRepair : NSObject

- (instancetype)init NS_UNAVAILABLE;

/// Get ThingLightingRepair instance.
/// @param ticketNum The ticket number.
/// @param projectId The project Id.
- (instancetype)initWithTicketNum:(NSString *)ticketNum projectId:(long long)projectId NS_DESIGNATED_INITIALIZER;

/// Get ThingLightingRepair instance.
/// @param ticketNum The ticket number.
/// @param projectId The project Id.
+ (nullable instancetype)createByTicketNum:(NSString *)ticketNum projectId:(long long)projectId;


/// Get the Detailed Information Of Repair Work Order
/// @param success          Called when the task finishes successfully.
/// @param failure          If error occurred while adding the task, this block will be called.
- (void)getRepairOrderDetail:(nullable void(^)(ThingLightingRepairOrderDetailModel * _Nonnull orderDetail))success
                     failure:(nullable ThingFailureError)failure;



/// Submit repair order results
/// @param devId            Device ID
/// @param feedbackContent  The Content Of Feedback
/// @param feedbackPic      The Picture URL Of Feedback Material
/// @param success          Called when the task finishes successfully.
/// @param failure          If error occurred while adding the task, this block will be called.
- (void)finishRepairOrder:(NSString *)devId
          feedbackContent:(nullable NSString *)feedbackContent
              feedbackPic:(nullable NSString *)feedbackPic
                  success:(nullable ThingSuccessDict)success
                  failure:(nullable ThingFailureError)failure;



@end

NS_ASSUME_NONNULL_END
