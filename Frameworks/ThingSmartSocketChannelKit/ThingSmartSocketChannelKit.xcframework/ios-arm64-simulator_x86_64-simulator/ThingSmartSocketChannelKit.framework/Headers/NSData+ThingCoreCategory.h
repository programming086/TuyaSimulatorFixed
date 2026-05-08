//
//  NSData+ThingCoreCategory.h
//  ThingSmartSocketChannelKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (ThingCoreCategory)

- (NSString *)thingCore_UTF8String;

- (NSData*)thingCore_dataByHealingUTF8Stream;

@end

NS_ASSUME_NONNULL_END
