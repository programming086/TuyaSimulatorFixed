//
//  ThingLightingRepairManager.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingRepairOrderModel;
@class ThingLightingRepairFaultTypeModel;
@class ThingLightingRepairDeviceConfigModel;

@interface ThingLightingRepairManager : NSObject


/// Create Repair Work Order
/// @param projectId        Project ID
/// @param devId            Device ID
/// @param ticketContent    Work Order Description
/// @param ticketPic        Work Order Picture URL
/// @param problemClassification Work Order Problem Description
/// @param success          Called when the task finishes successfully.
/// @param failure          If error occurred while adding the task, this block will be called.
- (void)createRepairOrder:(long long)projectId
                    devId:(NSString *)devId
            ticketContent:(nullable NSString *)ticketContent
                ticketPic:(nullable NSString *)ticketPic
    problemClassification:(nullable NSString *)problemClassification
                  success:(nullable ThingSuccessID)success
                  failure:(nullable ThingFailureError)failure;


/// Query Problem Type List
/// @param projectId        Project ID
/// @param success          Called when the task finishes successfully.
/// @param failure          If error occurred while adding the task, this block will be called.
- (void)getRepairFaultTypeList:(long long)projectId
                       success:(nullable void(^)(NSArray<ThingLightingRepairFaultTypeModel *> * _Nonnull typeAry))success
                       failure:(nullable ThingFailureError)failure;


/// Query Repair Work Order List
/// @param projectId        Project ID
/// @param ticketStatus     Work Order Status: 1.Unfinished 2.Finished
/// @param limit            Datas to Load Per Page
/// @param offsetKey        Page Number
/// @param success          Called when the task finishes successfully.
/// @param failure          If error occurred while adding the task, this block will be called.
- (void)getRepairList:(long long)projectId
         ticketStatus:(NSInteger)ticketStatus
                limit:(NSInteger)limit
            offsetKey:(nullable NSString *)offsetKey
              success:(nullable void(^)(NSArray<ThingLightingRepairOrderModel *> * _Nonnull orderList, NSString * _Nonnull nextOffsetKey, BOOL end))success
              failure:(nullable ThingFailureError)failure;


/// Query Config information Of Device
/// @param projectId        Project ID
/// @param devId            Device ID
/// @param success          Called when the task finishes successfully.
/// @param failure          If error occurred while adding the task, this block will be called.
- (void)getDeviceConfigInfo:(long long)projectId
                      devId:(NSString *)devId
                    success:(nullable void(^)(ThingLightingRepairDeviceConfigModel * _Nonnull model))success
                    failure:(nullable ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
