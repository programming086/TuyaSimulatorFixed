//
//  TSceneDefined.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/6/8.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_OSX
#import <AppKit/AppKit.h>
#endif

@class ThingSmartSceneModel;
@class ThingSmartDeviceModel;
@class ThingSmartSceneDPModel;
@class ThingSmartSceneCoreFeatureModel;
@class ThingSmartCityModel;
@class ThingSmartSceneLogModel;
@class ThingSmartSceneLogDetailModel;

NS_ASSUME_NONNULL_BEGIN

/// The scene enumeration.
typedef NS_ENUM(NSInteger, TSceneType) {
    /// Manual scene type.
    TSceneTypeTapToRun = 1,
    /// Automatic scene type.
    TSceneTypeAutomatic
};

typedef void(^ThingSceneErrorBlock)(NSError *error);

/// Completion of the result of get scene list in the home.
///
/// @param list The list of scene model.
typedef void(^ThingSceneGetListCompletion)(NSArray<ThingSmartSceneModel *> *list);


/// Completion of the result of get scene detail.
///
/// @param scene The information object for scene.
typedef void(^ThingSceneGetModelCompletion)(ThingSmartSceneModel *scene);


/// Completion of the result of get device list.
///
/// @param list The list of device model.
typedef void(^ThingSceneGetDeviceListCompletion)(NSArray<ThingSmartDeviceModel *> *list);


/// Completion of the result of get condition device datapoint list.
///
/// @param list The list of datapoint model.
typedef void(^ThingSceneGetDPListCompletion)(NSArray<ThingSmartSceneDPModel *> *list);


/// Completion of the result of get device feature list.
///
/// @param list The list of feature model.
typedef void(^ThingSceneGetFeatureListCompletion)(NSArray<ThingSmartSceneCoreFeatureModel *> *list);


/// Completion of the result of get city list.
///
/// @param list The list of city model.
typedef void(^ThingSceneGetCityListCompletion)(NSArray<ThingSmartCityModel *> *list);


/// Completion of the result of get city information.
///
/// @param model The information object for city model.
typedef void(^ThingSceneGetCityInfoCompletion)(ThingSmartCityModel *model);


/// Completion of the result of get log model.
///
/// @param model The information object for log model.
typedef void(^ThingSceneLogCompletion)(ThingSmartSceneLogModel *model);


/// Completion of the result of get log detail list.
///
/// @param list The list of log detail model.
typedef void(^ThingSceneLogDetailListCompletion)(NSArray<ThingSmartSceneLogDetailModel *> *list);

NS_ASSUME_NONNULL_END
