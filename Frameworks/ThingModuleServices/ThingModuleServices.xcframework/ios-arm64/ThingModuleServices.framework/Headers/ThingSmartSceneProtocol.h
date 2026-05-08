//
//  ThingSmartSceneProtocol.h
//  ThingSmartSceneModule
//
//  Created by huangmengfei on 2018/5/7.
//

#import <Foundation/Foundation.h>

@class ThingSmartSceneModel;

@protocol ThingSmartSceneProtocol <NSObject>

//新增自动化场景
- (void)addAutoScene:(void(^)(ThingSmartSceneModel *secneModel, BOOL addSuccess))callback;

//编辑场景
- (void)editScene:(ThingSmartSceneModel *)model;

@end
