//
//  ThingResidenceAddPasswordAccessModel.h
//  ThingSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingResidencePasswordAuthType) {
    ThingResidencePasswordAuthTypeTemporary = 0, // Temporary password
    ThingResidencePasswordAuthTypePeriodic = 1, // Periodic password
};


@interface ThingResidencePasswordScheduleModel : NSObject
/// Start clock (for example：9 : 00 ->  9 * 60 + 0 = 540,  9 : 10 -> 9 * 60 + 10 = 550)
@property (nonatomic, assign) NSInteger startClock;

/// End clock (for example：21 : 00 -> 21 * 60 = 1260)
@property (nonatomic, assign) NSInteger endClock;

/// Week（for example：1111100 -> 124 ）
@property (nonatomic, assign) NSInteger weekDay;

@end


@interface ThingResidenceBasePasswordInfoModel : NSObject
/// Authorization password type, 0 - Temporary password , 1 - Periodic password
@property (nonatomic, assign) ThingResidencePasswordAuthType authType;

/// Authorization name
@property (nonatomic, copy) NSString *authName;

/// entry-into-force time（13-digit number）
@property (nonatomic, assign) long effectiveTime;

/// Expiry time（（13-digit number）
@property (nonatomic, assign) long invalidTime;

/// 0 - No use of plans , 1 - Usage Plan
@property (nonatomic, assign) NSInteger scheduleRepeat;

/// this parameter needs to be set when the "schedulerepeat" value is 1
@property (nonatomic, strong, nullable) ThingResidencePasswordScheduleModel *schedule;

@end


@interface ThingResidencePasswordInfoModel : ThingResidenceBasePasswordInfoModel
/// password
@property (nonatomic, copy) NSString *passwordValue;

@end

@interface ThingResidencePasswordUserModel : NSObject
/// Nickname
@property (nonatomic, copy) NSString *nickname;

/// Account
@property (nonatomic, copy) NSString *username;

@end


@interface ThingResidenceAddPasswordAccessModel : NSObject
/// The ID of site
@property (nonatomic, assign) long long siteId;

/// The list of device ID
@property (nonatomic, strong) NSArray<NSString *> *deviceIdList;

/// Password information
@property (nonatomic, strong) ThingResidencePasswordInfoModel *passwordInfo;

/// Authorized personnel information
@property (nonatomic, strong) NSArray<ThingResidencePasswordUserModel *> *userList;

@end

NS_ASSUME_NONNULL_END
