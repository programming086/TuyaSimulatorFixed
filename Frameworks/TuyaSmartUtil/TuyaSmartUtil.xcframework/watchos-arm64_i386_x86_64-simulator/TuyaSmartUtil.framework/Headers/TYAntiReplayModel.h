//
//  TYAntiReplayModel.h
//  TuyaSmartKit
//
//  Created by 冯晓 on 2016/10/28.
//  Copyright © 2016年 Tuya. All rights reserved.
//

@interface TYAntiReplayModel : NSObject


//上报的
@property (nonatomic, assign) NSInteger reportS;//序列号
@property (nonatomic, assign) NSInteger reportR;//模块标识符


//下发的
@property (nonatomic, assign) NSInteger publishS;//序列号
@property (nonatomic, assign) NSInteger publishR;//模块标识符




@end
