
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityDeviceSchemeByPidRuleDpItemAbnormalExprModel : NSObject

@property (nonatomic, copy) NSString *function;
@property (nonatomic, copy) NSString *display;
@property (nonatomic, strong) NSArray *parameters;

@end

@interface ThingSecurityDeviceSchemeByPidRuleDpItemModel : NSObject

@property (nonatomic, copy) NSString *dp;
@property (nonatomic, copy) NSString *dpName;
@property (nonatomic, copy) NSString *dpType;
@property (nonatomic, strong) NSArray<ThingSecurityDeviceSchemeByPidRuleDpItemAbnormalExprModel *> *dpSchema;

@end

@interface ThingSecurityDeviceSchemeByPidRuleModel : NSObject

@property (nonatomic, copy) NSString *productId;
@property (nonatomic, strong) NSArray<ThingSecurityDeviceSchemeByPidRuleDpItemModel *> *schemas;

- (ThingSecurityDeviceSchemeByPidRuleDpItemModel *)fetchDpItemRuleModelWithDp:(NSString *)dpId;


@end

NS_ASSUME_NONNULL_END
