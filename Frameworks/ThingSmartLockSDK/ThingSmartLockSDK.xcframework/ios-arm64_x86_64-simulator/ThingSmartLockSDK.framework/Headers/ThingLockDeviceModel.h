//
//  ThingLockDeviceModel.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLockDeviceModel : NSObject

@property (nonatomic, strong) NSString *account;
@property (nonatomic, strong) NSString *eKeyId;
@property (nonatomic, strong) NSString *automaticLock;
@property (nonatomic, strong) NSString *deviceId;
@property (nonatomic, strong) NSString *deviceName;
@property (nonatomic, strong) NSString *deviceRole;
@property (nonatomic, strong) NSString *devicTag;
@property (nonatomic, strong) NSString *deviceType;
@property (nonatomic, strong) NSString *electricQuantity;
@property (nonatomic, strong) NSString *gatewayId;
@property (nonatomic, strong) NSString *gatewayName;
@property (nonatomic, assign) BOOL isSupportOta;
@property (nonatomic, strong) NSString *livecycleType;
@property (nonatomic, strong) NSString *lockMotorState;
@property (nonatomic, strong) NSArray<NSString *> *specialAbilities;
@property (nonatomic, strong) NSArray<NSString *> *supportAbilities;
@property (nonatomic, strong) NSDictionary *timeScheduleInfo;
@property (nonatomic, strong) NSString *timeZoneId;

@end

NS_ASSUME_NONNULL_END
