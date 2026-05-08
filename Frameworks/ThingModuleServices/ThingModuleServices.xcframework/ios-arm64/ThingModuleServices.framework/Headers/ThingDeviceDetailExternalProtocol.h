//
//  ThingDeviceDetailExternalProtocol.h
//  Pods
//
//  Created by yuheng on 2023/2/7.
//

@protocol ThingDeviceDetailExternalProtocol <NSObject>

@optional

/// @brief 移除设备后，自定义回退到哪个页面
/// @return YES 自定义处理，NO 默认逻辑
- (BOOL)customExitWhenDeleted;

@end
