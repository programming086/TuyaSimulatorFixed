//
//  ThingLightSceneActionDpModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightDpPropertyModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, LightSceneColorType) {
    LightSceneColorTypeBrightness = 1,
    LightSceneColorTypeTemperature
};

/// Scene action dp model
@interface ThingLightSceneActionDpModel : NSObject

/// The unique identifier for the action dp
@property (nonatomic, assign) NSInteger dpId;

/// The name name of the action dp
@property (nonatomic, strong) NSString *dpName;

/// The code of the action dp
@property (nonatomic, strong) NSString *dpCode;

/// The type of the action dp
@property (nonatomic, strong) NSString *dpType;

/// Whether to allow editing
@property (nonatomic, assign) BOOL editable;

/// The value type of the action dp
@property (nonatomic, strong) NSString *valueType;

/// Default value of dp points that cannot be edited
@property (nonatomic, strong) NSString *defaultValue;

/// Description and value of the action dp
@property (nonatomic, strong) ThingLightDpPropertyModel *dpProperty;

/// The value range of the action dp
@property (nonatomic, strong) NSArray *valueRangeJson;


- (LightSceneColorType)colorType;

@end

NS_ASSUME_NONNULL_END

