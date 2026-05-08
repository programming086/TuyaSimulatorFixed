//
//  ThingLampSmartSceneProtocol.h
//  Pods
//
//  Created by Gollen on 2021/6/22.
//

#import <Foundation/Foundation.h>

@class ThingSmartSceneModel;

@protocol ThingLampSmartSceneProtocol <NSObject>


- (void)updateSceneModels:(NSArray<ThingSmartSceneModel *> *)sceneModels refresh:(BOOL)refresh;


@end

