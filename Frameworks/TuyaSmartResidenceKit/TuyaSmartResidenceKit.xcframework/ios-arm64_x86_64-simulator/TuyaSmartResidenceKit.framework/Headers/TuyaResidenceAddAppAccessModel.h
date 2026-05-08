//
//  TuyaResidenceAddAppAccessModel.h
//  TuyaSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TuyaResidenceAccessUserType) {
    TuyaResidenceAccessUserTypeAdmin = 20, // Administrators
    TuyaResidenceAccessUserTypeMember = 30 // General Members
};

NS_ASSUME_NONNULL_BEGIN

@interface TuyaResidenceAddAppAccessModel : NSObject
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
@property (nonatomic, assign) TuyaResidenceAccessUserType userType;

@end

NS_ASSUME_NONNULL_END
