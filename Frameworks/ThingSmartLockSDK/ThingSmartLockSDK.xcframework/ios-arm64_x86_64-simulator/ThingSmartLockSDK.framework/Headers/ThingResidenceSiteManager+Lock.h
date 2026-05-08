//
//  Lock.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import <ThingSmartResidenceKit/ThingResidenceSiteManager.h>

@class ThingResidenceSiteModel;

typedef void (^ThingSiteSuccessList)(NSArray<ThingResidenceSiteModel *> * _Nullable list);
typedef void (^ThingSiteSuccess)(ThingResidenceSiteModel * _Nullable model);
typedef void (^ThingLockDeviceListSuccess)(NSArray<NSString *> * _Nullable deviceIdList, NSInteger lastId);

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceSiteManager (Lock)

/// Get site list
/// - Parameters:
///   - success: Success callback
///   - failure: Failure callback
+ (void)getSiteListWithSuccess:(ThingSiteSuccessList)success failure:(ThingFailureError)failure;


/// Get site detail
/// - Parameters:
///   - siteId: Site ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getSiteDetailWithSiteId:(long long)siteId 
                        success:(ThingSiteSuccess)success
                        failure:(ThingFailureError)failure;


/// Create a new site
/// - Parameters:
///   - name: Site name
///   - latitude: latitude
///   - longitude: longitude
///   - geoName: Geography name
///   - success: Success callback
///   - failure: Failure callback
+ (void)createSiteWithName:(NSString *)name
                  latitude:(double)latitude
                 longitude:(double)longitude
                   geoName:(NSString *)geoName
                   success:(ThingSuccessID)success
                   failure:(ThingFailureError)failure;

/// Remove a site
/// - Parameters:
///   - name: Site ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)removeSiteWithSiteID:(long long)siteId
                     success:(ThingSuccessID)success
                     failure:(ThingFailureError)failure;



/// Get lock device list
/// - Parameters:
///   - siteId: Site ID
///   - pageSize: Page size
///   - startId: Start ID such as page number
///   - success: Success callback
///   - failure: Failure callback
+ (void)getLockDeviceListWithSiteId:(long long)siteId
                           pageSize:(NSInteger)pageSize
                            startId:(NSInteger)startId
                            success:(ThingLockDeviceListSuccess)success
                            failure:(ThingFailureError)failure;


/// Get gateway device list
/// - Parameters:
///   - siteId: Site ID
///   - pageSize: Page size
///   - startId: Start ID such as page number
///   - success: Success callback
///   - failure: Failure callback
+ (void)getGatewayDeviceListWithSiteId:(long long)siteId
                              pageSize:(NSInteger)pageSize
                               startId:(NSInteger)startId
                               success:(ThingLockDeviceListSuccess)success
                               failure:(ThingFailureError)failure;



@end

NS_ASSUME_NONNULL_END
