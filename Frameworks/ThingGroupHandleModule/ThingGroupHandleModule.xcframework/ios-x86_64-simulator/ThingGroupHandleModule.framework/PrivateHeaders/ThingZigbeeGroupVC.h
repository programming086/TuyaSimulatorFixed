//
//  ThingZigbeeGroupVC.h
//  ThingGroupHandleModule
//
//  Created by 尼诺 on 2021/7/26.
//

#import <UIKit/UIKit.h>
#import "ThingGroupBaseVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingZigbeeGroupVC : ThingGroupBaseVC

/// 群组id
@property (nonatomic, readonly) NSString *groupId;
/// 设备id
@property (nonatomic, readonly) NSString *entryDevId;
/// 保存按钮是否一直可以点击
@property (nonatomic, assign) BOOL rightButtonEnableAlways;

@end

NS_ASSUME_NONNULL_END
