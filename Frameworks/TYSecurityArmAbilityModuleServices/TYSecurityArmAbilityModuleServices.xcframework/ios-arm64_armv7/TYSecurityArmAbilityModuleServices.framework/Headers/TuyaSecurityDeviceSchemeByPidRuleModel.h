//
//  TuyaSecurityDeviceSchemeByPidRuleModel.h
//  TYSecurityArmAbilityBizKit
//
//  Created by Tuya.Inc on 2021/4/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityDeviceSchemeByPidRuleDpItemAbnormalExprModel : NSObject

@property (nonatomic, copy) NSString *function;
@property (nonatomic, copy) NSString *display;
@property (nonatomic, strong) NSArray *parameters;

@end

@interface TuyaSecurityDeviceSchemeByPidRuleDpItemModel : NSObject

@property (nonatomic, copy) NSString *dp;
@property (nonatomic, copy) NSString *dpName;
@property (nonatomic, copy) NSString *dpType;
@property (nonatomic, strong) NSArray<TuyaSecurityDeviceSchemeByPidRuleDpItemAbnormalExprModel *> *dpSchema;

@end

@interface TuyaSecurityDeviceSchemeByPidRuleModel : NSObject

@property (nonatomic, copy) NSString *productId;
@property (nonatomic, strong) NSArray<TuyaSecurityDeviceSchemeByPidRuleDpItemModel *> *schemas;

- (TuyaSecurityDeviceSchemeByPidRuleDpItemModel *)fetchDpItemRuleModelWithDp:(NSString *)dpId;


@end

NS_ASSUME_NONNULL_END
