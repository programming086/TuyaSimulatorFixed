//
//  ThingSmartHome+SIGMesh.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import "ThingSmartHome.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHome (SIGMesh)

@property (nonatomic, strong, readonly) ThingSmartBleMeshModel *sigMeshModel;

/// Returns the Bluetooth mesh list for the home.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshListWithSuccess:(void(^)(NSArray <ThingSmartBleMeshModel *> *list))success
                          failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
