//
//  ThingLightSceneIconsModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Scene icon list model
@interface ThingLightSceneIconsModel : NSObject

/// Default icon list of the scene
@property (nonatomic, strong) NSArray<NSString *>*defaultList;

/// Clicked icon list of the scene
@property (nonatomic, strong) NSArray<NSString *>*clickList;

/// Default big icon list of the scene
@property (nonatomic, strong) NSArray<NSString *>*bigDefaultList;

/// Clicked big icon list of the scene
@property (nonatomic, strong) NSArray<NSString *>*bigClickList;

/// Get the image name from the icon url
///
/// @param imgUrl The url of the scene icon
- (NSString *)getImageNameWithUrl:(NSString *)imgUrl;

/// Get the clicked image url corresponding to imgName from clickList
///
/// @param imgName The default name of the scene icon
- (NSString *)fetchClickImageUrlWithDefaultName:(NSString *)imgName;

/// Get the clicked image url corresponding to imgName from defaultList
///
/// @param imgName The default name of the scene icon
- (NSString *)fetchDefaultImageUrlWithClickName:(NSString *)imgName;

/// Get the clicked image url corresponding to imgName from bigClickList
///
/// @param imgName The default name of the scene icon
- (NSString *)fetchBigClickImageUrlWithName:(NSString *)imgName;

/// Get the clicked image url corresponding to imgName from bigDefaultList
///
/// @param imgName The default name of the scene icon
- (NSString *)fetchBigDefaultImageUrlWithName:(NSString *)imgName;

@end

NS_ASSUME_NONNULL_END

