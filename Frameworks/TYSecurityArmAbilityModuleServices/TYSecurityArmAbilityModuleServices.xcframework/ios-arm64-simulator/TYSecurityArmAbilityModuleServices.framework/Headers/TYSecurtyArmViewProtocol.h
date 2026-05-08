//
//  TYSecurtyArmViewProtocol.h
//  TYSecurityArmAbilityUISkin
//
//  Created by Tuya.Inc on 2021/4/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TYSecurityArmMode);

@protocol TYSecurtyArmViewProtocol <NSObject>

@required

/// 点击布撤防按钮
/// @param targetMode 对应布撤防
- (void)switchSecurityMode:(TYSecurityArmMode)targetMode;

@optional;

/// itemView倒计时时调用方法，每秒调用一次
/// @param desString 倒计时描述(区分报警倒计时描述和布防倒计时描述)
- (void)itemViewBeginCountDown:(NSString *)desString;

/// 添加安防网关
- (void)addGatewayDevice;

@end

NS_ASSUME_NONNULL_END
