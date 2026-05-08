//
//  TYBLEFindMacDelegate.h
//  TuyaSmartBLECoreKit
//
//  Created by Tuya on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYBLEFindMacDelegate <NSObject>

@optional

- (nullable NSString *)findDeviceMacFromUUID:(nullable NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
