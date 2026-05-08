//
//  ThingSmartGroup+DpCode.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <ThingSmartDeviceCoreKit/ThingSmartGroup.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartGroup (DpCode)

#pragma mark - Wi-Fi dpCode

/// Creates groups of Wi-Fi standard DPCode devices.
///
/// @param name The group name.
/// @param homeId The home ID.
/// @param categoryCode The category code.
/// @param devIdList A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use ThingSmartGroup::createDpCodeGroupWithName:homeId:devIdList:success:failure: instead.
+ (void)createDpCodeGroupWithName:(NSString *)name
                           homeId:(long long)homeId
                     categoryCode:(NSString *)categoryCode
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(ThingSmartGroup *group))success
                          failure:(nullable ThingFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use createDpCodeGroupWithName:homeId:devIdList:success:failure: instead");



/// Returns a list of Wi-Fi devices that belong to standard DPCode groups based on category codes.
///
/// @param homeId The home ID.
/// @param categoryCode The category code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use ThingSmartGroup::getDpCodeDevListWithHomeId:success:failure: instead.
+ (void)getDpCodeDevListWithHomeId:(long long)homeId
                      categoryCode:(NSString *)categoryCode
                           success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                           failure:(nullable ThingFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use getDpCodeDevListWithHomeId:success:failure: instead");




/// Creates groups of Wi-Fi standard DPCode devices.
///
/// @param name The group name.
/// @param homeId The home ID.
/// @param devIdList A list of device IDs.
/// @param success Called when the task is finished. ThingSmartGroup is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)createDpCodeGroupWithName:(NSString *)name
                           homeId:(long long)homeId
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(ThingSmartGroup *group))success
                          failure:(nullable ThingFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use createDpCodeGroupWithName:homeId:productId:devIdList:success:failure: instead");


/// Creates groups of standard DPCode devices.
///
/// @param name The group name.
/// @param homeId The home ID.
/// @param productId The product ID.
/// @param devIdList A list of device IDs.
/// @param success Called when the task is finished. ThingSmartGroup is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)createDpCodeGroupWithName:(NSString *)name
                           homeId:(long long)homeId
                        productId:(NSString *)productId
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(ThingSmartGroup *group))success
                          failure:(nullable ThingFailureError)failure;

/// Creates groups of standard DPCode devices.
///
/// @param name The group name.
/// @param homeId The home ID.
/// @param productId The product ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished. ThingSmartGroup is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)createDpCodeGroupWithName:(NSString *)name
                           homeId:(long long)homeId
                        productId:(NSString *)productId
                           devIds:(NSArray<NSString *> *)devIds
                           meshId:(NSString *)meshId
                          success:(nullable void (^)(ThingSmartGroup *group))success
                          failure:(nullable ThingFailureError)failure;

/// Returns a list of Wi-Fi devices that belong to standard DPCode groups based on category codes.
///
/// @param homeId The home ID.
/// @param success Called when the task is finished. A list of ThingSmartGroupDevListModel is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDpCodeDevListWithHomeId:(long long)homeId
                           success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                           failure:(nullable ThingFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use getDpCodeDevListWithHomeId:productId:success:failure: instead");

/// Returns a list of Wi-Fi devices that belong to standard DPCode groups based on category codes.
///
/// @param homeId The home ID.
/// @param productId The product ID of the device.
/// @param success Called when the task is finished. A list of ThingSmartGroupDevListModel is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDpCodeDevListWithHomeId:(long long)homeId
                         productId:(NSString *)productId
                           success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                           failure:(nullable ThingFailureError)failure;


/// Returns a list of devices that belong to the group.
///
/// @param success Called when the task is finished. A list of ThingSmartGroupDevListModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getDpCodeDevListWithSuccess:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                            failure:(nullable ThingFailureError)failure;



/// Modifies a list of devices that belong to the group.
///
/// @param devList A list of devices.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateDpCodeGroupRelationsWithDevList:(NSArray <NSString *>*)devList
                                      success:(nullable ThingSuccessHandler)success
                                      failure:(nullable ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
