//
//  ThingLightSceneSituationModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightSceneSituationDataModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Scene situation model
@interface ThingLightSceneSituationModel : NSObject

/// The name of the situation
@property (nonatomic, strong) NSString *plateName;

/// The dp code of the situation
@property (nonatomic, strong) NSString *dpCode;

/// The data of the situation
@property (nonatomic, strong) NSArray<ThingLightSceneSituationDataModel *>*data;


@end

NS_ASSUME_NONNULL_END

