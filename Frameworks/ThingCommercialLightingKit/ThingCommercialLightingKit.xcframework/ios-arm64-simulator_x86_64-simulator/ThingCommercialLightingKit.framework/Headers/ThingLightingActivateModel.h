//
//  ThingLightingActivateModel.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import "ThingLightingActivateGroupModel.h"
#import "ThingLightingActivateDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingActivateModel : NSObject

@property (nonatomic, strong) NSString *jobId;
@property (nonatomic, strong) NSMutableArray<ThingLightingActivateGroupModel *> *groups;
@property (nonatomic, strong) NSMutableArray<ThingLightingActivateDeviceModel *> *devices;

@end

NS_ASSUME_NONNULL_END
