//
//  TSceneRecomListParams.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/8/3.
//

#import <Foundation/Foundation.h>

/// The recommend list source represents the type of request.
typedef NS_ENUM(NSInteger, TSceneRecomListSource) {
    /// normal recommend list.
    TSceneRecomListSourceNormal,
    /// home top recommend list.
    TSceneRecomListSourceHomeTop,
    /// after device did activated recommend list.
    TSceneRecomListSourceDeviceActivated
};

NS_ASSUME_NONNULL_BEGIN

@interface TSceneRecomListParams : NSObject
/// The request recommned list source.
@property (nonatomic, assign) TSceneRecomListSource source;
/// The number of requests for recommend data. Default is 10.
@property (nonatomic, assign) NSInteger size;
/// Device ID. This parameter is mandatory for the recommend data after device did activated.
@property (nonatomic, copy, nullable) NSString *devId;
/// Whether to display the added recommend data. Default is NO.
@property (nonatomic, assign) BOOL shouldShowDidAddedRecommend;

- (NSString *)stringForSource;

@end

NS_ASSUME_NONNULL_END
