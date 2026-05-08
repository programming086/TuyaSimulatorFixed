//
//  ThingSmartModuleRouter.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartModuleRouter : NSObject

+ (instancetype)router;
+ (instancetype)shared;

- (void)registerProtocol:(Protocol *)protocol;

- (void)unregistServiceOfProtocol:(Protocol *)protocol;

- (id)serviceOfProtocol:(Protocol *)protocol;

- (id)entryForProtocol:(Protocol *)protocol;

@end

NS_ASSUME_NONNULL_END
