//
//  TSceneRecomHandleParams.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/8/3.
//

#import <Foundation/Foundation.h>
#import "TSmartSceneModelTypes.h"

NS_ASSUME_NONNULL_BEGIN

/// The request object for handle recommend scene.
@interface TSceneRecomHandleParams : NSObject
/// The recommend source type. 1: linkage 2: energy 3:warning
@property (nonatomic, assign) TSceneRecomBizType recomBizType;
/// The recommend ID.
@property (nonatomic, strong) NSString *recommendId;
/// The Home ID.
@property (nonatomic, strong) NSString *gid;

/// Return the recommend source description.
- (NSString *)recommendSource;

@end

NS_ASSUME_NONNULL_END
