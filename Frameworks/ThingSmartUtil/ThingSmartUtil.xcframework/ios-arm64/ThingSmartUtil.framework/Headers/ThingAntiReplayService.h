//
//  ThingAntiReplayService.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import "ThingAntiReplayModel.h"

NS_ASSUME_NONNULL_BEGIN

//防重放攻击
@interface ThingAntiReplayService : NSObject

+ (instancetype)sharedInstance;

- (ThingAntiReplayModel *)getReplayPublishModel:(nonnull NSString *)devId;

- (BOOL)isNormalReplayReport:(NSInteger)s r:(NSInteger)r devId:(nonnull NSString *)devId;


@end

NS_ASSUME_NONNULL_END
