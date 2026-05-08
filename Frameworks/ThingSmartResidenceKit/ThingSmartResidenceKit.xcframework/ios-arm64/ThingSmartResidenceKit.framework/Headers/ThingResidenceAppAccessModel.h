//
//  ThingResidenceAppAccessModel.h
//  ThingSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, ThingResidenceAccessMemberType) {
    ThingResidenceAccessMemberTypeUnregistered = -1, //-1：Unregistered user
    ThingResidenceAccessMemberTypeAccessMember = 0, //0：Access member
    ThingResidenceAccessMemberTypeSiteMember = 1, //1：Site member
};



@interface ThingResidenceAppAccessModel : NSObject
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


@interface ThingResidenceAppAccessDetailModel : ThingResidenceAppAccessModel

/// The list of device ID
@property (nonatomic, copy) NSArray<NSString *> *deviceIdList;

@end

NS_ASSUME_NONNULL_END
