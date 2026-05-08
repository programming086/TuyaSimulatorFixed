//
//  ThingWiFiGroupVC.h
//  ThingGroupHandleModule
//
//  Created by 尼诺 on 2021/7/22.
//

#import "ThingGroupBaseVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingWiFiGroupVC : ThingGroupBaseVC

/// 群组id
@property (nonatomic, readonly) NSString *groupId;
/// 设备id
@property (nonatomic, readonly) NSString *entryDevId;
/// 保存按钮是否一直可以点击
@property (nonatomic, assign) BOOL rightButtonEnableAlways;

@property (nonatomic, strong) ThingSmartGroup *wifiGroup;

@end

NS_ASSUME_NONNULL_END
