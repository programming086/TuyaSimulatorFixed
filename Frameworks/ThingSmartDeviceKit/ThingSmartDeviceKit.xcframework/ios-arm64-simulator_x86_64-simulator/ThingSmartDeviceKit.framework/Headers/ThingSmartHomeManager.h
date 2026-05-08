//
//  ThingSmartHomeManager.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

#import "ThingSmartHomeModel.h"

@class ThingSmartHomeManager;


@protocol ThingSmartHomeManagerDelegate <NSObject>

@optional

/// The delegate that is instantiated when a home is added.
///
/// @param manager  The instance.
/// @param home     The home model.
- (void)homeManager:(ThingSmartHomeManager *)manager didAddHome:(ThingSmartHomeModel *)home;

/// The delegate that is instantiated when an existing home is removed.
///
/// @param manager  The instance.
/// @param homeId   The home ID.
- (void)homeManager:(ThingSmartHomeManager *)manager didRemoveHome:(long long)homeId;
- (void)homeManager:(ThingSmartHomeManager *)manager didRemoveHome:(long long)homeId homeModel:(ThingSmartHomeModel *)homeModel;

/// MQTT service connection success callback.
- (void)serviceConnectedSuccess;


@end

@interface ThingSmartHomeManager : NSObject

@property (nonatomic, weak) id <ThingSmartHomeManagerDelegate> delegate;

@property (nonatomic, copy, readonly) NSArray <ThingSmartHomeModel *> *homes;
/// 等待缓存初始化完成，如果已经加载过，直接返回成功，如果正在加载中，则等待加载完成，如果还未初始化缓存，则直接返回NO
- (void)waitLoadCacheComplete:(void (^)(BOOL complete))blcok;
/// 查询是否有家庭缓存
- (BOOL)hasHomeCache:(long long)homeId;

/// Returns a list of homes. To get home details, initialize a home and call getHomeDetailWithSuccess: failure:.
///
/// @param success Called when the task is finished. A list of ThingSmartHomeModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomeListWithSuccess:(void(^)(NSArray <ThingSmartHomeModel *> *homes))success
                       failure:(ThingFailureError)failure;


/// Adds a home.
///
/// @param homeName    The home name.
/// @param geoName     The city name.
/// @param rooms       The rooms list.
/// @param latitude    The latitude.
/// @param longitude   The longitude.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addHomeWithName:(NSString *)homeName
                geoName:(NSString *)geoName
                  rooms:(NSArray <NSString *>*)rooms
               latitude:(double)latitude
              longitude:(double)longitude
                success:(ThingSuccessLongLong)success
                failure:(ThingFailureError)failure;


/// Sorts the homes.
///
/// @param homeList    A list of homes.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)sortHomeList:(NSArray <ThingSmartHomeModel *> *)homeList
             success:(ThingSuccessHandler)success
             failure:(ThingFailureError)failure;

#pragma mark - deprecated

/// Accepts or rejects to share a home.
///
/// @param homeId       The home ID.
/// @param isAccept     Specifies whether to accept the invitation.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use ThingSmartHome::joinFamilyWithAccept:success:failure: instead.
- (void)joinFamilyWithHomeId:(long long)homeId
                      action:(BOOL)isAccept
                     success:(ThingSuccessBOOL)success
                     failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartHome - (void)joinFamilyWithAccept:success:failure:] instead");

@end
