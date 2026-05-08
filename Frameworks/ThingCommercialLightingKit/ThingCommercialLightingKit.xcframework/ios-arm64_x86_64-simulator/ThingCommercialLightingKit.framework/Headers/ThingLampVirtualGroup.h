//
//  ThingLampVirtualGroup.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLampVirtualGroup : NSObject

@property (nonatomic, strong) NSString *virtualGroupId;
@property (nonatomic, strong) NSString *groupName;

/// Total number of devices in virtual groups
@property (nonatomic, assign) int deviceCount;

/// Total number of failed group join attempts
@property (nonatomic, assign) int failCount;

/// "true" represents that real groups have been created, "false" represents that real groups have not been created, and "null" represents all cases.
@property (nonatomic, assign) BOOL finish;
@property (nonatomic, strong) NSString *roomId;
@property (nonatomic, strong) NSString *groupPackageId;

@end

NS_ASSUME_NONNULL_END
