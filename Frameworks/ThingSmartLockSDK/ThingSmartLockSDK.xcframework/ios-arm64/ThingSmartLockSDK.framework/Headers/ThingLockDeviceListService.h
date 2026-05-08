//
//  ThingLightingDeviceListService.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <ThingSmartNetworkKit/ThingSmartNetworkKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLockDeviceListService : ThingSmartRequest


/// Method to get the device list (and update cache), applicable to all scenarios for retrieving device model data.
/// - Parameters:
///   - apiName: Requested API
///   - postData: Post data
///   - getData: Get data
///   - version: API version
///   - success: Success callback, which returns a dictionary including devIds (all device IDs), end (whether pagination is complete), and more.
///   - failure: Failure callback
- (void)requestDeviceListWithApiName:(NSString *)apiName
                            postData:(nullable NSDictionary *)postData
                             getData:(nullable NSDictionary *)getData
                             version:(NSString *)version
                             success:(nullable ThingSuccessDict)success
                             failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
