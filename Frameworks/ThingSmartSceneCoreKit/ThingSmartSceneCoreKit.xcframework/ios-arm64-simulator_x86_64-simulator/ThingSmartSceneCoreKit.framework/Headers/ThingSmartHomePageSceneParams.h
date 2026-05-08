//
//  ThingSmartHomePageSceneParams.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/3/8.
//

#import <Foundation/Foundation.h>
#import "TSceneDefined.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHomePageSceneParams : NSObject
/// The request scene type, manual scene equal 1, automatic scene equal 2.
@property (nonatomic, assign) TSceneType ruleType;
/// The page number for per request, default is 0.
@property (nonatomic, assign) NSInteger offset;
/// The maximum number of requests per request, default is 1000.
@property (nonatomic, assign) NSInteger limit;

@end

NS_ASSUME_NONNULL_END
