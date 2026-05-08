//
//  ThingLightSceneFunctionModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightSceneEnums.h"
#import "ThingLightSceneActionDpModel.h"

NS_ASSUME_NONNULL_BEGIN

static NSString *const LightSceneFunctionCodeWhite = @"white_light";
static NSString *const LightSceneFunctionCodeColor = @"color_light";
static NSString *const LightSceneFunctionCodeMix   = @"mix_light";

/// Lamp function message model
@interface ThingLightSceneFunctionModel : NSObject

/// The status of the function
@property (nonatomic, assign) BOOL status;

/// The product identifier of the lamp
@property (nonatomic, strong) NSString *productId;

/// The name of the function
@property (nonatomic, strong) NSString *functionName;

/// The code of the function
@property (nonatomic, strong) NSString *functionCode;

/// The type of the function
@property (nonatomic, assign) ThingLightSceneFunctionType functionType;

/// The dp points of the function
@property (nonatomic, strong) NSArray<ThingLightSceneActionDpModel *>*dataPoints;

@end

NS_ASSUME_NONNULL_END

