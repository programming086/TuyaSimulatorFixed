//
//  ThingLightSceneTempValueModel.h
//  ThingLightSceneKit
//
//  Created by 和叶 on 2022/5/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightSceneTempKeyPointsModel : NSObject

@property (nonatomic, assign) NSInteger percentValue;

@property (nonatomic, assign) NSInteger colorTempValue;

@end

@interface ThingLightSceneTempValueModel : NSObject


@property (nonatomic, assign) NSInteger bizType;

@property (nonatomic, strong) NSString *bizId;

@property (nonatomic, strong) NSArray<ThingLightSceneTempKeyPointsModel *>*keyPoints;

@end

NS_ASSUME_NONNULL_END
