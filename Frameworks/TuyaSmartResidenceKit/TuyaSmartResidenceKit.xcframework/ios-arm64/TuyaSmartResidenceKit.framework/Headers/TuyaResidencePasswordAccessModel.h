//
//  TuyaResidencePasswordAccessModel.h
//  TuyaSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
#import "TuyaResidenceAddPasswordAccessModel.h"

NS_ASSUME_NONNULL_BEGIN


@interface TuyaResidenceAccessPasswordDeviceModel : NSObject
/// The ID of device
@property (nonatomic, copy) NSString *deviceId;

@property (nonatomic, copy) NSString *operationStatus;
@end


@interface TuyaResidencePasswordAccessModel : NSObject
/// The ID of Authorized Groups
@property (nonatomic, copy) NSString *authGroupId;

/// Password Authorisation Status ， -1-Unknown error，1-effective，2-Issuing, 3-Modification in progress, 4-Delete in progress, 5-Failed to issue, 6-Modification failed, 7-invalid
@property (nonatomic, strong) NSNumber *passwordAuthStatus;

/// Authorized personnel information
@property (nonatomic, copy) NSArray <TuyaResidencePasswordUserModel *> *contactsList;

/// Number of authorized devices
@property (nonatomic, strong) NSNumber *authDeviceCount;

/// Number of failed device modifications
@property (nonatomic, strong) NSNumber *updateFailDeviceCount;

/// Number of failures to issue
@property (nonatomic, strong) NSNumber *issueFailDeviceCount;

/// Remaining time, in seconds
@property (nonatomic, strong) NSNumber *remainingTime;

/// The list of device
@property (nonatomic, copy) NSArray <TuyaResidenceAccessPasswordDeviceModel *> *deviceList;

/// Password information
@property (nonatomic, strong) TuyaResidenceBasePasswordInfoModel *doorPassword;

/// Modified by
@property (nonatomic, copy) NSString *modifier;

/// Creator
@property (nonatomic, copy) NSString *creator;

/// Creation time
@property (nonatomic, strong) NSNumber *createTime;

/// Modify time
@property (nonatomic, strong) NSNumber *modifiedTime;

@end

NS_ASSUME_NONNULL_END
