//
//  ThingLockGateway.h
//  ThingSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingResidenceSiteManager+Lock.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingLockGateway : NSObject



/// Get device list of gateway device
/// - Parameters:
///   - gatewayId: Gateway ID
///   - pageSize: Page size
///   - startId: Page start ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getSubDeviceListWithGatewayId:(NSString *)gatewayId
                             pageSize:(NSInteger)pageSize
                              startId:(NSInteger)startId
                              success:(ThingLockDeviceListSuccess)success
                              failure:(ThingFailureError)failure;


/// Unbinds subdevices from a specified gateway
/// - Parameters:
///   - gatewayId: The ID of the gateway from which to unbind the device
///   - devIdList: A list of IDs for target devices to unbind
///   - success: Success callback
///   - failure: Failure callback
+ (void)unbindSubDeviceWithGatewayId:(NSString *)gatewayId
                           devIdList:(NSArray<NSString *> *)devIdList
                             success:(ThingSuccessID)success
                             failure:(ThingFailureError)failure;


/// Binds subdevices to a specified gateway
/// - Parameters:
///   - gatewayId: The ID of the gateway to which the devices will be bound
///   - devIdList: A list of ID for the target devices to bind
///   - success: Success callback
///   - failure: Failure callback
+ (void)bindSubDeviceWithGatewayId:(NSString *)gatewayId
                         devIdList:(NSArray<NSString *> *)devIdList
                           success:(ThingSuccessID)success
                           failure:(ThingFailureError)failure;



/// Get a list of unbind devices
/// - Parameters:
///   - siteId: Site ID
///   - pageSize: Page size
///   - startId: Page start ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getUnbinedDeviceListWithSiteId:(long long)siteId
                              pageSize:(NSInteger)pageSize
                               startId:(NSInteger)startId
                               success:(ThingLockDeviceListSuccess)success
                               failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
