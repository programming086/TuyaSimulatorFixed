//
//  IndustryDeviceRegistrationResult.h
//  IndustryActivatorImpl
//
//  Created by 后主 on 2022/8/11.
//

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

@import IndustryActivatorKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryPairFailedDevice : NSObject

/// The device ID.
@property (nonatomic, copy) NSString *deviceId;

/// The name of the device.
@property (nonatomic, copy) NSString *name;

/// The error code of pairing.
@property (nonatomic, copy) NSString *errorCode;

/// The error message.
@property (nonatomic, copy) NSString *errorMessage;

@end



@interface IndustryPairSucceedDevice : NSObject <IActivatedDevice>

/// The universally unique identifier of the device.
@property (nonatomic, copy) NSString *uuid;

/// The device ID.
@property (nonatomic, copy) NSString *deviceId;

/// The name of the device.
@property (nonatomic, copy) NSString *name;

/// The product ID.
@property (nonatomic, copy) NSString *productID;

/// The longitude of the device.
@property (nonatomic, copy) NSString *longitude;

/// The latitude of the device.
@property (nonatomic, copy) NSString *latitude;

/// The IP address of the device.
@property (nonatomic, copy) NSString *ipAddress;

/// A boolean value indicates whether the device is online.
@property (nonatomic, assign) BOOL isOnline;

@property (nonatomic, copy) NSString *meshId;

+ (instancetype)initWithDeviceModel:(ThingSmartDeviceModel *)deviceModel;

@end



@interface IndustryDeviceRegistrationResult : NSObject

@property (nonatomic, strong) NSArray<IndustryPairSucceedDevice *> *succeedDevices;

@property (nonatomic, strong) NSArray<IndustryPairFailedDevice *> *failedDevices;

@end

NS_ASSUME_NONNULL_END
