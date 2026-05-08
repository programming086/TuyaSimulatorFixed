//
//  TuyaSmartDirectlyConnectedActivator+Home.h
//  Pods
//
//  Copyright (c) 2014-2022 Tuya Inc. (https://developer.tuya.com/)

#import <TuyaSmartActivatorCoreKit/TuyaSmartDirectlyConnectedActivator.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartDirectlyConnectedActivator (Home)

/// Activate devices to the cloud
/// @param uuid the uuid of device
/// @param groupId the home id
/// @param groupType the home type
/// @param success the callback of success
/// @param failure the callback of failure
- (void)deviceCloudActivateWithUUID:(NSString *)uuid
                            groupId:(long long)groupId
                          groupType:(NSString *)groupType
                            success:(TYSuccessDict)success
                            failure:(TYFailureError)failure;
@end

NS_ASSUME_NONNULL_END
