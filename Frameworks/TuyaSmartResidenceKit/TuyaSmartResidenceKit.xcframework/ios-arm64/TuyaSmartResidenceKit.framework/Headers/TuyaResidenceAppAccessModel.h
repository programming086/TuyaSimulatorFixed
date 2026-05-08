//
//  TuyaResidenceAppAccessModel.h
//  TuyaSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, TuyaResidenceAccessMemberType) {
    TuyaResidenceAccessMemberTypeUnregistered = -1, //-1：Unregistered user
    TuyaResidenceAccessMemberTypeAccessMember = 0, //0：Access member
    TuyaResidenceAccessMemberTypeSiteMember = 1, //1：Site member
};



@interface TuyaResidenceAppAccessModel : NSObject
/// The ID of access member
@property (nonatomic, copy) NSString *accessUserId;

/// Account
@property (nonatomic, copy) NSString *username;

/// Nickname
@property (nonatomic, copy) NSString *nickname;

/// Type of membership: 10 - Owner, 20 - Administrator,  30 - General Members
@property (nonatomic, strong) NSNumber *userType;

/// Number of devices
@property (nonatomic, copy) NSString *deviceCount;

/// Start time
@property (nonatomic, strong) NSNumber *startTime;

/// Ending time
@property (nonatomic, strong) NSNumber *endTime;

/// 
@property (nonatomic, strong) NSNumber *homeMember;

@property (nonatomic, copy) NSString *creator;

@property (nonatomic, copy) NSString *modifier;


@property (nonatomic, strong) NSNumber *gmtCreate;

@property (nonatomic, strong) NSNumber *gmtModified;

@end


@interface TuyaResidenceAppAccessDetailModel : TuyaResidenceAppAccessModel

/// The list of device ID
@property (nonatomic, copy) NSArray<NSString *> *deviceIdList;

@end

NS_ASSUME_NONNULL_END
