//
//  ThingAntiReplayModel.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

@interface ThingAntiReplayModel : NSObject


//上报的
@property (nonatomic, assign) NSInteger reportS;//序列号
@property (nonatomic, assign) NSInteger reportR;//模块标识符


//下发的
@property (nonatomic, assign) NSInteger publishS;//序列号
@property (nonatomic, assign) NSInteger publishR;//模块标识符




@end
