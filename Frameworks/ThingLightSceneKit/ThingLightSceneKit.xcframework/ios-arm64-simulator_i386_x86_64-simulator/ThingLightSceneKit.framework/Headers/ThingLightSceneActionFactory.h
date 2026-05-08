//
//  ThingLightSceneActionFactory.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightSceneActionModel.h"
#import "ThingLightSceneSituationDataModel.h"
#import "ThingLightSceneCustomSituationDataModel.h"
#import "ThingLightSceneMusicLibDataModel.h"

typedef enum : NSInteger {
    kLightTypeSingle,
    kLightTypeGroup
}LightType;

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightSceneActionFactory : NSObject

/// Create a turn on/turn off action
+ (ThingLightSceneActionModel *)createLightSwitchActionWithEntityId:(NSString *)entityId
                                                          lightType:(LightType)type
                                                           regionId:(NSString *)regionId
                                                           switchDp:(NSString *)switchDp
                                                           switchOn:(BOOL)switchOn;

/// Create a situational action
+ (ThingLightSceneActionModel *)createLightSceneActionWithEntityId:(NSString *)entityId
                                                         lightType:(LightType)type
                                                          regionId:(NSString *)regionId
                                                         sceneMode:(ThingLightSceneSituationDataModel *)sceneMode
                                                          switchDp:(NSString *)switchDp
                                                          switchOn:(BOOL)switchOn;

/// Create a custom situational action
+ (ThingLightSceneActionModel *)createLightSceneActionWithEntityId:(NSString *)entityId
                                                         lightType:(LightType)type
                                                          regionId:(NSString *)regionId
                                                   customSceneMode:(ThingLightSceneCustomSituationDataItemModel *)sceneMode
                                                          switchDp:(NSString *)switchDp
                                                          switchOn:(BOOL)switchOn;

/// Create a music lib action
+ (ThingLightSceneActionModel *)createLightSceneActionWithEntityId:(NSString *)entityId
                                                         lightType:(LightType)type
                                                          regionId:(NSString *)regionId
                                                          musicLib:(ThingLightSceneMusicLibDataItemModel *)musicLib
                                                          switchDp:(NSString *)switchDp
                                                          switchOn:(BOOL)switchOn;
/// Create a color light scene
+ (ThingLightSceneActionModel *)createLightColorActionWithEntityId:(NSString *)entityId
                                                         lightType:(LightType)type
                                                          regionId:(NSString *)regionId
                                                        colourData:(NSString *)colorData
                                                        rgbaString:(NSString *)rgba
                                                      functionCode:(NSString *)functionCode
                                                          switchDp:(NSString *)switchDp
                                                          switchOn:(BOOL)switchOn
                                                           isOldDp:(BOOL)isOldDp;

/// Create a white light scene
+ (ThingLightSceneActionModel *)createLightWhiteActionWithEntityId:(NSString *)entityId
                                                        lightType:(LightType)type
                                                         regionId:(NSString *)regionId
                                                      brightValue:(NSInteger)brightV
                                                        tempValue:(NSInteger)tempV
                                                       rgbaString:(NSString *)rgba
                                                     functionCode:(NSString *)functionCode
                                                         switchDp:(NSString *)switchDp
                                                         switchOn:(BOOL)switchOn
                                                        brightMin:(double)brightMin
                                                        brightMax:(double)brightMax
                                                          isOldDp:(BOOL)isOldDp;

/// Create a white light scene, temp_value defaults to 307
+ (ThingLightSceneActionModel *)createLightBrightActionWithEntityId:(NSString *)entityId
                                                         lightType:(LightType)type
                                                          regionId:(NSString *)regionId
                                                       brightValue:(NSInteger)brightV
                                                        rgbaString:(NSString *)rgba
                                                      functionCode:(NSString *)functionCode
                                                          switchDp:(NSString *)switchDp
                                                          switchOn:(BOOL)switchOn
                                                         brightMin:(double)brightMin
                                                         brightMax:(double)brightMax
                                                           isOldDp:(BOOL)isOldDp;

/// Create a mixed light scene
+ (ThingLightSceneActionModel *)createLightMixActionWithEntityId:(NSString *)entityId
                                                       lightType:(LightType)type
                                                        regionId:(NSString *)regionId
                                                 whiteRgbaString:(NSString *)whiteRgba
                                                 colorRgbaString:(NSString *)colorRgba
                                                        mixValue:(NSString *)mixValue
                                                    functionCode:(NSString *)functionCode
                                                         isOldDp:(BOOL)isOldDp;

@end

NS_ASSUME_NONNULL_END
