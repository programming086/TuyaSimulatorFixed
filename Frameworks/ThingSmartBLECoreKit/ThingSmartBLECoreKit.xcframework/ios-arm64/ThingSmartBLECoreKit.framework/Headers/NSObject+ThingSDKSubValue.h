//
//  NSObject+ThingSDKSubValue.h
//  ThingSmartBLEKit
//
//  Created by 吴戈 on 2019/7/15.
//

#import <Foundation/Foundation.h>

@interface NSData (ThingSDKSubValue)

- (NSData *)thingsdk_subdataWithRange:(NSRange)range;

@end


@interface NSString (ThingSDKSubValue)

- (NSString *)thingsdk_substringFromIndex:(NSUInteger)from;

- (NSString *)thingsdk_substringToIndex:(NSUInteger)to;

- (NSString *)thingsdk_substringWithRange:(NSRange)range;

@end
