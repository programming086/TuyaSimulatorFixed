//
//  ThingSmartHome+BleMesh.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import "ThingSmartHome.h"

@interface ThingSmartHome (BleMesh)

@property (nonatomic, strong, readonly) ThingSmartBleMeshModel *meshModel;

@property (nonatomic, strong, readonly) ThingSmartBleMeshModel *beaconMeshModel;

/// Returns the mesh list for the home.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getMeshListWithSuccess:(void(^)(NSArray <ThingSmartBleMeshModel *> *list))success
                       failure:(ThingFailureError)failure;

@end
