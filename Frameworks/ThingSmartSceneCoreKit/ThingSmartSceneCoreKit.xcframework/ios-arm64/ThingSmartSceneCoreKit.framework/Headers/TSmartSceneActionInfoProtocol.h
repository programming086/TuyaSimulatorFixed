//
//  TSmartSceneActionInfoProtocol.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/9/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TSmartSceneActionInfoProtocol <NSObject>

- (NSString *)actionExecutor;

- (NSString *)entityName;

- (NSString *)entityId;

- (nullable NSDictionary *)extraProperty;

- (NSDictionary *)executorProperty;

@end

NS_ASSUME_NONNULL_END
