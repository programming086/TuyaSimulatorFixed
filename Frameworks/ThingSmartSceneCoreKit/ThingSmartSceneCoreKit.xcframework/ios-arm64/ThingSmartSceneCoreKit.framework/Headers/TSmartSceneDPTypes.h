//
//  TSmartSceneDPTypes.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/8/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The seven types of datapoint display style.
typedef NS_ENUM(NSUInteger, SceneDisplayType) {
    /// The normal style, indicates display numeric UI.
    SceneDisplayNormal = 1,
    /// The first percent style, indicates the content show numeric UI and the unit show percent. The datapoint minimum value is 0.
    SceneDisplayPercent = (1 << 1),
    /// The second percent style, indicates the content show numeric UI and the unit show percent. The datapoint minimum value is 1.
    SceneDisplayNewPercent = (1 << 2),
    /// The first countdown style, indicates the content only shows hours and minutes.
    SceneDisplayCountDown = (1 << 3),
    /// The brightness value style, indicates the content shows a color slider and you can select value as the brightness value. For example, brightness value is 500.
    SceneDisplayBrightness = (1 << 4),
    /// The warm cold value style, indicates the content shows a color slider and you can select value as the warm cold value. For example, warm cold value is 500.
    SceneDisplayTemp = (1 << 5),
    /// The second countdown style, indicates The content shows hours, minutes and seconds.
    SceneDisplayCountDown1 = (1<< 6)
};


/**
 The various of datapoint temperature type.
 */
typedef NS_ENUM(NSInteger, TSceneDPTempType) {
    /**
     No temperature unit for datapoint.
     */
    TSceneDPTempTypeNone,
    /**
     The datapoint temperature unit is ℃, °C, ˚C.
     */
    TSceneDPTempTypeCelsius,
    /**
     The datapoint temperature unit is ℉, °F, ˚F.
     */
    TSceneDPTempTypeFahrenheit
};

NS_ASSUME_NONNULL_END
