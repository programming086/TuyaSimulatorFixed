//
//  ThingSDKDevice.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface ThingSDKDevice : NSObject

+ (NSString *)thingsdk_UUID __deprecated_msg("Use +[ThingSmartSDK sharedInstance].uuid instead.");

+ (NSString *)thingsdk_generateUUID;

+ (NSString *)thingsdk_deviceNameString;

+ (NSString *)thingsdk_model;

+ (NSString *)thingsdk_systemName;

+ (NSString *)thingsdk_systemVersion;

@end
