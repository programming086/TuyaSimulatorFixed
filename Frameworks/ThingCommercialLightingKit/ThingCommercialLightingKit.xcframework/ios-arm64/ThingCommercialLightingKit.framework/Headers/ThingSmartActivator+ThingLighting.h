//
//  ThingSmartActivator+ThingLighting.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <ThingSmartActivatorCoreKit/ThingSmartActivatorCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartActivator (ThingLighting)


/// Obtain allocation token using home ID (valid for 10 minutes).
/// @param gId The G Id of current area.
/// @param meshId The mesh Id that current area was binded to.
/// @param success Called when the task finishes successfully. ThingSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithGId:(NSInteger)gId
                 meshId:(NSString *)meshId
                success:(ThingSuccessString)success
                failure:(ThingFailureError)failure;


/// Obtain allocation token using product ID (valid for 10 minutes).
/// @param productKey Product Id
/// @param gId The G Id of current area.
/// @param meshId The mesh Id that current area was binded to.
/// @param success Called when the task finishes successfully. ThingSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithProductKey:(nullable NSString *)productKey
                           gId:(long long)gId
                        meshId:(NSString *)meshId
                       success:(ThingSuccessString)success
                       failure:(ThingFailureError)failure;

/// Obtain allocation token using UUID (valid for 10 minutes).
/// @param uuid Device uuid
/// @param gId The G Id of current area.
/// @param success Called when the task finishes successfully. ThingSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithUUID:(NSString *)uuid
                     gId:(NSInteger)gId
                 success:(ThingSuccessString)success
                 failure:(ThingFailureError)failure;
@end

NS_ASSUME_NONNULL_END
