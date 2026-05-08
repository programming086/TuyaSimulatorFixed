//
//  ThingIoTLogger.h
//  ThingIoTNetworkKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingIoTLogger : NSObject

+ (void)debug:(NSString *)message;

+ (void)info:(NSString *)message;

+ (void)warn:(NSString *)message;

+ (void)error:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
