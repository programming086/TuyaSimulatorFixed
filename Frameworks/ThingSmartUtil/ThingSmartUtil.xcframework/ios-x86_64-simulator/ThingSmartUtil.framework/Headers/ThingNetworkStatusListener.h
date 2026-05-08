//
//  ThingNetworkStatusListener.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//
#if TARGET_OS_IOS

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingNetworkStatusListener : NSObject

+ (instancetype)sharedInstance;

- (NSString *)networkStatus;

@end

NS_ASSUME_NONNULL_END

#endif
