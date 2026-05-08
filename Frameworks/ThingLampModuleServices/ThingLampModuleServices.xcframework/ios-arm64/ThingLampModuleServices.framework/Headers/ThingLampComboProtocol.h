//
//  ThingLampComboProtocol.h
//  Pods
//
//  Created by huxn on 2021/4/20.
//

#ifndef ThingLampComboProtocol_h
#define ThingLampComboProtocol_h

typedef void(^ThingLampComboDetail)(void);
typedef void(^ThingLampComboVoidHandler)(void);

@protocol ThingLampComboProtocol <NSObject>

/// 检测是否存在套餐，未选择套餐，会自动显示套餐列表
- (void)beginComboService;

/// 套餐标题颜色
/// @param version 版本
- (UIColor *_Nullable)comboNameColorWithVersion:(NSString *_Nullable)version;

/// 套餐渐变色
/// @param version 版本
- (NSArray *)comboGradientColorsWithVersion:(NSString *_Nullable)version;

/// 套餐入口文字颜色
/// @param version 版本
- (UIColor *_Nullable)comboEntryTitleColorWithVersion:(NSString *_Nullable)version;

/// 清空弹窗标志
- (void)clearAlertFlag;

@end


#endif /* ThingLampComboProtocol_h */
