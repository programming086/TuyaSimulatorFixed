//
//  ThingMeshGroupBaseVC.h
//  ThingGroupHandleModule
//
//  Created by yuheng on 2021/6/25.
//

#import "ThingGroupBaseVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingMeshGroupBaseVC : ThingGroupBaseVC

/// 群组id
@property (nonatomic, readonly) NSString *groupId;
/// 设备id
@property (nonatomic, readonly) NSString *entryDevId;
/// 保存按钮是否一直可以点击
@property (nonatomic, assign) BOOL rightButtonEnableAlways;

- (void)updateGroup;

@end

NS_ASSUME_NONNULL_END
