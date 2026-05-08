//
//  ThingSmartSceneActionFactory.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <Foundation/Foundation.h>
#import "ThingSmartSceneCoreKit.h"

/// The two types of automation state. Provides enable and disable types.
typedef NS_ENUM(NSInteger, AutoSwitchType) {
    /// The enable type.
    kAutoSwitchTypeEnable,
    /// The disable type.
    kAutoSwitchTypeDisable
};

NS_ASSUME_NONNULL_BEGIN

/// @brief A factory design mode for create ThingSmartSceneActionModel.
///
/// @note In order to facilitate the handling of multiple languages, this class does not handle the actionDisplay and actionDisplayNew fields of the ThingSmartSceneActionModel. These two properties are spliced by the developer themselves when they are created. When saving, the server will generate them according to the executiveProperty and the language environment of the interface. The property saved by the developer will not be used.
@interface ThingSmartSceneActionFactory : NSObject

/// Create a device action with all param.
///
/// @param devId The device id.
/// @param devName The device name.
/// @param executerProperty Action to execute, format:{dpId: <dpId's value>} eg: {"1":true}.
/// @param extraProperty The optional parameters, extraProperty of action.
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)createDeviceDpActionWithDevId:(NSString *)devId
                                                      devName:(NSString *)devName
                                             executerProperty:(NSDictionary *)executerProperty
                                                extraProperty:(NSDictionary *)extraProperty;

/// Create a group action with group's params.
///
/// @param groupId The group id.
/// @param groupName The group name.
/// @param executerProperty Action to execute, format:{dpId: <dpId's value>} eg: {"1":true}.
/// @param extraProperty The  optional parameters, extraProperty of action.
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)createGroupDpActionWithGroupId:(NSString *)groupId
                                                     groupName:(NSString *)groupName
                                              executerProperty:(NSDictionary *)executerProperty
                                                 extraProperty:(NSDictionary *)extraProperty;

/// Create an action to trigger a scene.
///
/// @param sceneId The sceneId id.
/// @param sceneName The sceneName name.
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)createTriggerSceneActionWithSceneId:(NSString *)sceneId
                                                          sceneName:(NSString *)sceneName;

/// Create an action to enable/disable an automation.
///
/// @param sceneId The sceneId id.
/// @param sceneName The sceneName name.
/// @param type AutoSwitchType.
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)createSwitchAutoActionWithSceneId:(NSString *)sceneId
                                                        sceneName:(NSString *)sceneName
                                                             type:(AutoSwitchType)type;

/// Create a delay action.
///
/// @param hours hours,range 0-5.
/// @param minutes minutes,range 0-59.
/// @param seconds seconds,range 0-59.
/// 
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)createDelayActionWithHours:(NSString *)hours
                                                   minutes:(NSString *)minutes
                                                   seconds:(NSString *)seconds;

/// Create a push notification action.
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)createSendNotificationAction;

/// Create a call notification action(internal use, not open).
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)createCallAction;

/// Create a send sms action(internal use, not open).
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)createSmsAction;


/// The new method for create device action with params.
/// @param feature The device feature model. Detail see `ThingSmartSceneCoreFeatureModel`.
/// @param devId The device ID.
/// @param deviceName The device name.
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)deviceActionWithFeature:(ThingSmartSceneCoreFeatureModel *)feature
                                                  devId:(NSString *)devId
                                             deviceName:(NSString *)deviceName;


/// The new method for create group action with params.
/// @param feature The group feature model. Detail see `ThingSmartSceneCoreFeatureModel`.
/// @param groupId The group ID.
/// @param groupName The group name.
///
/// @return The ThingSmartSceneActionModel class.
+ (ThingSmartSceneActionModel *)groupActionWithFeature:(ThingSmartSceneCoreFeatureModel *)feature
                                               groupId:(NSString *)groupId
                                             groupName:(NSString *)groupName;


@end

NS_ASSUME_NONNULL_END

