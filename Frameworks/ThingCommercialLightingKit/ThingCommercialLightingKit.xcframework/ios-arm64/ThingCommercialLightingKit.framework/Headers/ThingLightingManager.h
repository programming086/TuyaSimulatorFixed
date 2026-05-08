//
//  ThingLightingManager.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingManager : NSObject

ThingSDK_SINGLETON;

/// Is need to cache data
@property (nonatomic, assign) BOOL isCacheNeeded;

/// Enabel pre-control or not.
@property (nonatomic, assign) BOOL preControlEnable;

/// Is there a network connection
@property (nonatomic, assign) BOOL hasNetwork;

@property (nonatomic, assign, readonly) NSUInteger cachedSize;


- (void)clearCache;

@end

NS_ASSUME_NONNULL_END
