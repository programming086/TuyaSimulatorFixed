//
//  ThingLampVirtualGroupManager.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import "ThingLampVirtualGroup.h"
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^ThingLampVirtualGroupListSuccess)(NSArray<ThingLampVirtualGroup *> *list);
typedef void (^ThingLampVirtualFailDetailSuccess)(NSArray<ThingSmartDeviceModel *> *list);


typedef NS_ENUM(NSUInteger,ThingLampVirtualGroupFinishState) {
    
    ThingLampVirtualGroupFinishState_ALL = -1, // All cases
    ThingLampVirtualGroupFinishState_NO = 0, // Real groups have not been created
    ThingLampVirtualGroupFinishState_YES = 1, // Real groups have been created
};

@interface ThingLampVirtualGroupManager : NSObject

/// Lookup device by MAC address
-(void)queryByMacWithAreaId:(NSString *)areaId
                     macIds:(NSArray<NSString *> *)macIds
                    success:(nullable ThingSuccessID)success
                    failure:(nullable ThingFailureError)failure;

/// Virtual group list
-(void)getVirtualGroupListWithAreaId:(NSString *)areaId
                              finish:(ThingLampVirtualGroupFinishState)finish
                             success:(nullable ThingLampVirtualGroupListSuccess)success
                             failure:(nullable ThingFailureError)failure;

/// Delete virtual group
-(void)removeVirtualGroupWithAreaId:(NSString *)areaId
                    virtualGroupIds:(NSArray<NSString *> *)virtualGroupIds
                            success:(nullable ThingSuccessHandler)success
                            failure:(nullable ThingFailureError)failure;

/// Save virtual group
-(void)saveVirtualGroupWithAreaId:(NSString *)areaId
                  virtualGroupIds:(NSArray<NSString *> *)virtualGroupIds
                     addDeviceIds:(NSArray<NSString *> *)addDeviceIds
                          success:(nullable ThingSuccessHandler)success
                          failure:(nullable ThingFailureError)failure ;

/// Create a new virtual group
-(void)createVirtualGroupWithAreaId:(NSString *)areaId
                          groupName:(NSString *)groupName
                       addDeviceIds:(NSArray<NSString *> *)addDeviceIds
                            success:(nullable ThingSuccessHandler)success
                            failure:(nullable ThingFailureError)failure;

/// Virtual group failure details
-(void)getVirtualFailDetailWithAreaId:(NSString *)areaId
                       virtualGroupId:(NSString *)virtualGroupId
                              success:(nullable ThingLampVirtualFailDetailSuccess)success
                              failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
