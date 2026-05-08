//
//  ThingResidenceRoom.h
//  CocoaAsyncSocket
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
@class ThingResidenceRoomModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceRoom : NSObject

@property (nonatomic, strong, readonly) ThingResidenceRoomModel *roomModel;

/// Returns the room instance.
///
/// @param roomId The room ID.
/// @param siteId The site ID.
/// @return The instance.
+ (instancetype)roomWithRoomId:(long long)roomId siteId:(long long)siteId;

/// Returns the room instance.
///
/// @param roomId The room ID.
/// @param siteId The site ID.
/// @return The instance.
- (instancetype)initWithRoomId:(long long)roomId siteId:(long long)siteId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
