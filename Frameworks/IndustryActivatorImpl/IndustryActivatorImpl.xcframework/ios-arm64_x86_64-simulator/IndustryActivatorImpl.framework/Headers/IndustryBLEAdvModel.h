//
//  IndustryBLEAdvModel.h
//  IndustryActivatorImpl
//
//  Created by ChenKun on 2023/5/30.
//

#import <Foundation/Foundation.h>

@import IndustryActivatorKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryBLEAdvModel : NSObject<ISmartBLEAdv>

/// The UUID of the Bluetooth LE device.
@property (nonatomic, copy) NSString           *uuid;
/// The product ID of the Bluetooth LE device.
@property (nonatomic, copy) NSString           *productId;
/// The MAC address of the Bluetooth LE device.
@property (nonatomic, copy) NSString           *mac;
/// The activation state of the Bluetooth LE device.
@property (nonatomic, assign) BOOL              isActive;
/// The type of Bluetooth LE device.
@property (nonatomic, assign) SmartBLEType      bleType;
/// Indicates whether the Bluetooth LE device supports connections through the router on a 5 GHz band.
/// @note `TYSmartBLETypeBLEWifi` or `TYSmartBLETypeBLEWifiSecurity` is only available for `bleType`.
@property (nonatomic, assign) BOOL              isSupport5G;
/// Indicates whether the Bluetooth LE device supports the product key.
@property (nonatomic, assign) BOOL              isProuductKey;
/// The protocol version of the Bluetooth LE device.
@property (nonatomic, assign) NSInteger         bleProtocolV;
/// Whether the device is activated by scanning, such as scanning a QR code.Defaults to NO.
@property (nonatomic, assign) BOOL              isQRCodeDevice;
/// Whether the device is support config by multi user.
@property (nonatomic, assign) BOOL              isSupportMultiUserShare;

@end

NS_ASSUME_NONNULL_END
