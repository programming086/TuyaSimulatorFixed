//
//  ThingZigbeeRemoteControlVC.h
//  ThingGroupHandleModule
//
//  Created by 尼诺 on 2021/7/27.
//

#import <UIKit/UIKit.h>
#import "ThingGroupBaseVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingZigbeeRemoteControlVC : ThingGroupBaseVC

/// 群组id
@property (nonatomic, readonly) NSString *localId;
/// 设备id
@property (nonatomic, readonly) NSString *entryDevId;
///categoryCode非三级品类编码，云端用于判断处理遥控器群组  zigbee遥控器有单分组和8分组的区别，单分组为8001，8分组为3001-3008
@property (nonatomic, strong) NSString *categoryCode;
/// 二级品类编码
@property (nonatomic, strong) NSArray *codes;
/// 保存按钮是否一直可以点击
@property (nonatomic, assign) BOOL rightButtonEnableAlways;

@end

NS_ASSUME_NONNULL_END
