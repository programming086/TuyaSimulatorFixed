//
//  ThingLightingActivateDeviceModel.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The model for cloud activation of devices for offline construction.
@interface ThingLightingActivateDeviceModel : NSObject

@property (nonatomic, strong) NSString *spaceId;
@property (nonatomic, assign) NSInteger activeTime;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *devKey;
@property (nonatomic, assign) NSInteger nodeId;
@property (nonatomic, strong) NSString *mac;
@property (nonatomic, strong) NSString *ver;
@property (nonatomic, assign) long long gid;
@property (nonatomic, strong) NSString *productKey;
@property (nonatomic, strong) NSString *pubAddress;
@property (nonatomic, strong) NSString *meshCategory;
@property (nonatomic, strong) NSString *meshCategoryExt;
@property (nonatomic, strong) NSMutableArray<NSString *> *defaultGroups;

@end

NS_ASSUME_NONNULL_END
