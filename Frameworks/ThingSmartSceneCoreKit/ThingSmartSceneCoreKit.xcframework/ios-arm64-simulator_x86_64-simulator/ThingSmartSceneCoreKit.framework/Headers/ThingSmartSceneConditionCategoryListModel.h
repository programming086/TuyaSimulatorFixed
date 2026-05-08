//
//  ThingSmartSceneConditionCategoryListModel.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/3/28.
//

#import <Foundation/Foundation.h>

@class ThingSmartSceneDPModel;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief List of conditional categories
 */
@interface ThingSmartSceneConditionCategoryListModel : NSObject

/// Device related condition categories, such as family return, face recognition.
@property (nonatomic, copy) NSArray<ThingSmartSceneDPModel *> *devConditions;

/// Weather related conditions categories, such as temperature, humidity, PM2.5.
@property (nonatomic, copy) NSArray<ThingSmartSceneDPModel *> *envConditions;

/// Security-related conditions, such as change deployment, disarming, and alarm.
@property (nonatomic, copy) NSArray<ThingSmartSceneDPModel *> *securityConditions;

@end

NS_ASSUME_NONNULL_END
