//
//  ThingResidenceAddAppAccessModel.h
//  ThingSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ThingResidenceAccessUserType) {
    ThingResidenceAccessUserTypeAdmin = 20, // Administrators
    ThingResidenceAccessUserTypeMember = 30 // General Members
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceAddAppAccessModel : NSObject
/// The ID of site
@property (nonatomic, assign) long long siteId;

/// Account
@property (nonatomic, copy) NSString *username;

/// Nickname
@property (nonatomic, copy) NSString *nickname;

/// The list of device ID
@property (nonatomic, strong) NSArray<NSString *> *deviceIdList;

/// Start Timestamp（13-digit number），-1：Permanently
@property (nonatomic, assign) long startTime;

/// Ending Timestamp（13-digit number）,   -1：Permanently
@property (nonatomic, assign) long endTime;

/// Type of membership: 20 - Administrator,  30 - General Members
@property (nonatomic, assign) ThingResidenceAccessUserType userType;

@end

NS_ASSUME_NONNULL_END
