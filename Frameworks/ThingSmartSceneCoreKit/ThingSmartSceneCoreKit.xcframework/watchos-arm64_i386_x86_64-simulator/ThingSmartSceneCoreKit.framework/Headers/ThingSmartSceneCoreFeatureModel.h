//
//  ThingSmartSceneCoreFeatureModel.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <Foundation/Foundation.h>
#import "ThingSmartSceneCoreActionDpModel.h"

/// The two expression type in function. Provide single and group types.
typedef NS_ENUM(NSUInteger, ThingSmartSceneCoreFunctionType) {
    /// The single type
    ThingSmartSceneCoreFunctionSingleType = 0,
    /// The group type
    ThingSmartSceneCoreFunctionGroupType,
};

/// This string means function code is "white_light"
extern NSString *const ThingSmartSceneCoreFunctionCodeWhite;
/// This string means function code is "color_light"
extern NSString *const ThingSmartSceneCoreFunctionCodeColor;

/// This model represents all information of Feature, including data points list.
@interface ThingSmartSceneCoreFeatureModel : NSObject

/// The feature ID.
@property (nonatomic, strong) NSString *featureId;
/// The product ID.
@property (nonatomic, strong) NSString *productId;
/// The function name.
@property (nonatomic, strong) NSString *functionName;
/// The function code.
@property (nonatomic, strong) NSString *functionCode;
/// The function type.
@property (nonatomic, assign) ThingSmartSceneCoreFunctionType functionType;
/// Data point list.
@property (nonatomic, strong) NSArray<ThingSmartSceneCoreActionDpModel *> *dataPoints;

/// The device ID.
@property (nonatomic, strong) NSString *devId;
/// The hsv color values.
@property (nonatomic, strong) NSArray *hsvColor;
/// The rgb color values.
@property (nonatomic, strong) NSString *rgbColor;
/// The light color.
@property (nonatomic, strong) NSString *lightColor;
/// The light data point.
@property (nonatomic, strong) ThingSmartSceneCoreActionDpModel *brightModel;

/// Set the value of hsv
///
/// @param h Hue. the value range 0-1
/// @param s Saturation. the value range 0-1
/// @param v Value. the value range 0-1
- (void)setH:(CGFloat)h s:(CGFloat)s v:(CGFloat)v;

/// Get the brightness data point model
///
/// @return ThingSmartSceneCoreActionDpModel object.
- (ThingSmartSceneCoreActionDpModel *)getBrightnessDpModel;

/**
 Check if function code is white light.
 */
- (BOOL)isWhiteLight;

/**
 Check if function code is coloured light.
 */
- (BOOL)isColouredLight;

/**
 Check if function code is white or color light.
 */
- (BOOL)isColorSelectType __attribute__((deprecated("Please use isGroupFeature method")));
/**
 The new method to check function code is white light or coloured light.
 */
- (BOOL)isGroupFeature;

@end

