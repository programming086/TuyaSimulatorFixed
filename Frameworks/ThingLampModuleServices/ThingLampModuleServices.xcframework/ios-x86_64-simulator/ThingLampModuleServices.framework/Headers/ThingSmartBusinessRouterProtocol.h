//
//  ThingSmartBusinessRouterProtocol.h
//  Pods
//
//  Created by Gollen on 2020/12/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartBusinessRouterProtocol <NSObject>


/// 通过路由获取场景模块中场景列表
/// @param areaId 区域Id 
- (UIViewController *)getSceneListControllerWithAreaId:(long long)areaId;


@end

NS_ASSUME_NONNULL_END
