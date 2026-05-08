//
//  TYSecuritSaveModeDeviceRuleModel.h
//  TYSecurityArmAbilityUISkin
//
//  Created by Tuya.Inc on 2021/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYSecuritSaveModeDeviceRuleModel : NSObject

@property (nonatomic, copy) NSString *gatewayId;

@property (nonatomic, strong) NSArray<NSString *>*deviceIds;

// 1为安防网关    2为云安防网关   3为IPC摄像头
@property (nonatomic, assign) NSInteger type;
@end

NS_ASSUME_NONNULL_END
