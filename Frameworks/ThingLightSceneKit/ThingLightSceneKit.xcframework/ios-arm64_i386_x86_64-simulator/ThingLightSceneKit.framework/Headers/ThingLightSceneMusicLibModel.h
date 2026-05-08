//
//  ThingLightSceneMusicLibModel.h
//  ThingLightSceneKit
//
//  Created by 和叶 on 2022/5/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightSceneMusicLibDataModel;

@interface ThingLightSceneMusicLibModel : NSObject

/// The name of the situation
@property (nonatomic, strong) NSString *plateName;

/// The data of the situation
@property (nonatomic, strong) NSArray<ThingLightSceneMusicLibDataModel *>*data;

@end

NS_ASSUME_NONNULL_END
