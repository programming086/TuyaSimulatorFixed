//
//  TYAntiReplayService.h
//  TuyaSmartKit
//
//  Created by 冯晓 on 2016/10/28.
//  Copyright © 2016年 Tuya. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYAntiReplayModel.h"
#import "TuyaSmartUtil.h"

NS_ASSUME_NONNULL_BEGIN

//防重放攻击
@interface TYAntiReplayService : NSObject

TYSDK_SINGLETON

- (TYAntiReplayModel *)getReplayPublishModel:(nonnull NSString *)devId;

- (BOOL)isNormalReplayReport:(NSInteger)s r:(NSInteger)r devId:(nonnull NSString *)devId;


@end

NS_ASSUME_NONNULL_END
