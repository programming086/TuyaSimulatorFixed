
#import <Foundation/Foundation.h>
#import "ThingDeviceShareConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceShareManager : NSObject

#pragma mark - Sharer
/// Determine whether the device or group supports share
/// - Parameters:
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - success: Success callback, true if sharing is supported, otherwise false.
///   - failure: Failure callback
+ (void)supportShare:(NSString *)resId resType:(ThingShareResType)resType success:(void(^)(BOOL support))success failure:(void(^)(NSError *error))failure;



/// Get the remaining share times of device or group.
/// - Parameters:
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - success: Success callback. Not limit If times is -1
///   - failure: Failure callback
+ (void)remainingShareTimes:(NSString *)resId resType:(ThingShareResType)resType success:(void(^)(int times))success failure:(void(^)(NSError *error))failure;



/// Share a device or group to other user
/// - Parameters:
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - spaceId: The home id of the device or group
///   - userAccount: the account of the user shared to
///   - success: Success callback with share result
///   - failure: Failure callback
+ (void)share:(NSString *)resId resType:(ThingShareResType)resType spaceId:(long long)spaceId userAccount:(NSString *)userAccount success:(void(^)(ThingDeviceShareResult *result))success failure:(void(^)(NSError *error))failure;
+ (void)share:(NSString *)resId resType:(ThingShareResType)resType spaceId:(long long)spaceId countryCode:(NSString *)countryCode userAccount:(NSString *)userAccount success:(void(^)(ThingDeviceShareResult *result))success failure:(void(^)(NSError *error))failure;



/// Remove the share of device or group
/// - Parameters:
///   - memberId: The id of the member to be removed
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - success: Success callback
///   - failure: Failure callback
+ (void)removeReceiver:(long)memberId resId:(NSString *)resId resType:(ThingShareResType)resType success:(void(^)(void))success failure:(void(^)(NSError *error))failure;



/// Get the receivers of a device or group shared to
/// - Parameters:
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - page: The number of page to fetch, 1 based. This parameter is useful only for devices. For groups, it will return all members at once.
///   - pageSize: The size of page to fetch, must greater than zero. This parameter is useful only for device. For groups, it will return all members at once.
///   - success: Success callback with a list of ThingSmartShareMemberModel
///   - failure: Failure callback
+ (void)receivers:(NSString *)resId resType:(ThingShareResType)resType page:(int)page pageSize:(int)pageSize success:(void(^)(NSArray<ThingSmartShareMemberModel *> * _Nullable members))success failure:(void(^)(NSError *error))failure;

+ (void)receiversWithTotal:(NSString *)resId resType:(ThingShareResType)resType page:(int)page pageSize:(int)pageSize success:(void(^)(NSArray<ThingSmartShareMemberModel *> * _Nullable members, NSInteger total))success failure:(void(^)(NSError *error))failure;



/// Update the share expiration date
/// - Parameters:
///   - memberId: The id of a member to be updated
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - mode: ThingShareValidationTypeForever if forever, otherwise ThingShareValidationTypePeriod
///   - endTime: Timestamp in millisecond if mode is ThingShareValidationTypePeriod, or it will be ignored.
///   - success: Success callback
///   - failure: Failure callback
+ (void)updateShareExpirationDate:(long)memberId resId:(NSString *)resId resType:(ThingShareResType)resType mode:(ThingShareValidationType)mode endTime:(long long)endTime success:(void(^)(void))success failure:(void(^)(NSError *error))failure;


/// Get the members who were recently shared
/// - Parameters:
///   - success: Success callback with a list of ThingSmartShareMemberModel
///   - failure: Failure callback
+ (void)relationMembers:(void(^)(NSArray<ThingSmartShareMemberModel *> * _Nullable members))success failure:(void(^)(NSError *error))failure;


/// Remove the relation member
/// - Parameters:
///   - uid: The id of relation member to be removed
///   - success: Success callback
///   - failure: Failure callback
+ (void)removeRelationMember:(NSString *)uid success:(void(^)(void))success failure:(void(^)(NSError *error))failure;


/// Create a share code to share a device
/// For now, group does not support. In short, it can only be used to share a device.
/// - Parameters:
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - spaceId: The home id of the device or group
///   - shareType: The type to share the code, ie: email, message, etc. For more, see ThingDeviceShareType.
///   - shareCount: The count of valid uses for the share code
///   - success: Success callback
///   - failure: Failure callback
+ (void)createShareInfo:(NSString *)resId resType:(ThingShareResType)resType spaceId:(long long)spaceId shareType:(ThingDeviceShareType)shareType shareCount:(int)shareCount success:(void(^)(ThingDeviceShareInfo *info))success failure:(void(^)(NSError *error))failure;




#pragma mark - receiver


/// Validate a share code
/// - Parameters:
///   - code: The share code
///   - success: Success callback, true if valid
///   - failure: Failure callback
+ (void)validate:(NSString *)code successWithOrigin:(void(^)(BOOL valid, NSDictionary *originResult))success failure:(void(^)(NSError *error))failure;
+ (void)validate:(NSString *)code success:(void(^)(BOOL valid))success failure:(void(^)(NSError *error))failure;

/// Get info of the share code
/// - Parameters:
///   - code: The share code
///   - success: Success callback, with ThingDeviceShareCodeInfo
///   - failure: Failure callback
+ (void)shareCodeInfo:(NSString *)code success:(void(^)(ThingDeviceShareCodeInfo *info))success failure:(void(^)(NSError *error))failure;


/// Accept the share invite
/// - Parameters:
///   - code: The share code
///   - success: Success callback
///   - failure: Failure callback
+ (void)accept:(NSString *)code success:(void(^)(void))success failure:(void(^)(NSError *error))failure;



/// Remove a share of device or group
/// - Parameters:
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - success: Success callback
///   - failure: Failure callback
+ (void)removeShare:(NSString *)resId resType:(ThingShareResType)resType success:(void(^)(void))success failure:(void(^)(NSError *error))failure;


/// Get the sharers who share the device or group
/// - Parameters:
///   - success: Success callback, with a list of ThingDeviceSharer
///   - failure: Failure callback
+ (void)sharers:(void(^)(NSArray<ThingDeviceSharer *> * _Nullable sharers))success failure:(void(^)(NSError *error))failure;


/// Get the name of the sharer
/// - Parameters:
///   - resId: The id of device or group to be shared
///   - resType: ThingShareResTypeDevice if share a device, otherwise ThingShareResTypeGroup
///   - success: Success callback
///   - failure: Failure callback
+ (void)sharerName:(NSString *)resId resType:(ThingShareResType)resType success:(void(^)(NSString *name))success failure:(void(^)(NSError *error))failure;


/// Get the detail of sharer who shares the device or group
/// - Parameters:
///   - memberId: The id of sharer who shares the device or group
///   - success: Success callback, with ThingDeviceSharerDetail
///   - failure: Failure callback
+ (void)sharerDetail:(long)memberId success:(void(^)(ThingDeviceSharerDetail *detail))success failure:(void(^)(NSError *error))failure;



/// Remove the sharer
/// - Parameters:
///   - memberId: The id of sharer to be removed
///   - success: Success callback
///   - failure: Failure callback
+ (void)removeSharer:(long)memberId success:(void(^)(void))success failure:(void(^)(NSError *error))failure;


/// Update the name of the Sharer
/// - Parameters:
///   - memberId: The id of sharer to be updated
///   - name: The new name of the sharer
///   - success: Success callback
///   - failure: Failure callback
+ (void)updateSharer:(long)memberId name:(NSString *)name success:(void(^)(void))success failure:(void(^)(NSError *error))failure;


@end

NS_ASSUME_NONNULL_END
