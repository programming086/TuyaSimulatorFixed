//
//  ThingSmartActivatorHomekitDevice.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/9/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartActivatorHomekitDevice : NSObject

@property (copy, nonatomic) NSString *uuid;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *icon;

@end

NS_ASSUME_NONNULL_END
