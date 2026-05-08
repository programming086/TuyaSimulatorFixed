//
//  ThingLightScenePreviewResultModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Scene preview result model
@interface ThingLightScenePreviewResultModel : NSObject

/// Successfully previewed actions of the scene
@property (nonatomic, strong) NSArray<NSString *>*successActions;

/// Failed preview actions of the scene
@property (nonatomic, strong) NSArray<NSString *>*failActions;


@end

NS_ASSUME_NONNULL_END
