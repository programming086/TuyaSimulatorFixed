//
//  ThingSmartDeviceModel+BusinessLighting.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//


#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingCommercialLightingKit/ThingLightingPublicEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLampPurposeModel : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *code;

@end

@interface ThingSmartDeviceModel (ThingLighting)

/// The area ID.
@property (nonatomic, assign) long long areaId;

/// The name of area.
@property (nonatomic, strong) NSString *areaName;

/// The status of join master group.
@property (nonatomic, assign) ThingLightingMasterGroupJoinStatus masterGroupJoinStatus;


/// The group that the device has joined.
@property (nonatomic, strong, readonly) NSArray<ThingSmartGroupModel *> *joinedGroups;

/// When creating a packed group, determine whether it is in the packed group
@property (nonatomic, assign) BOOL checked;

@property (nonatomic, assign) BOOL limited;

@property (nonatomic, strong) ThingLampPurposeModel *devicePurpose;
@property (nonatomic, strong) ThingLampPurposeModel *industryPurpose;

@end

NS_ASSUME_NONNULL_END
