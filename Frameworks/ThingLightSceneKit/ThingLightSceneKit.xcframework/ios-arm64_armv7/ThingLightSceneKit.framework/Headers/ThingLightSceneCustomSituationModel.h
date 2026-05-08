//
//  ThingLightSceneCustomSituationModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import "ThingLightSceneCustomSituationDataModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Custom scene situation model
@interface ThingLightSceneCustomSituationModel : NSObject

/// The name of the situation
@property (nonatomic, strong) NSString *plateName;

/// The data of the situation
@property (nonatomic, strong) NSArray<ThingLightSceneCustomSituationDataModel *>*data;

@end

NS_ASSUME_NONNULL_END
