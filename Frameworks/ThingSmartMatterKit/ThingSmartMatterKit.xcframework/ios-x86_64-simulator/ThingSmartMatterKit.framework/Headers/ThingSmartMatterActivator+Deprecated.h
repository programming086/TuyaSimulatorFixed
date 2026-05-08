
#import "ThingSmartMatterActivator.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterActivator (Deprecated)

# pragma mark Deprecated API

- (nullable ThingSmartMatterSetupPayload *)checkMatterCodeInvalid:(NSString *)matterCode __deprecated_msg("Will be removed in the future, please use connectDeviceWithSetupPayload");


- (void)pairDeviceWithSetupPayload:(ThingSmartMatterSetupPayload *)payload toke:(NSString *)token spaceId:(long long)spaceId timeout:(NSTimeInterval)timeout __deprecated_msg("Will be removed in the future, please use connectDeviceWithSetupPayload");


- (void)setGatewayDeviceBeforePairing:(NSString *)devId __deprecated_msg("⚠️⚠️⚠️ This api causes issues. Will be removed in the future, if you want set gwid, please set in commissionDevice:commssionModel:");


- (void)continueCommissionDevice:(nonnull ThingSmartMatterDeviceModel *)deviceModel WithSSID:(nonnull NSString *)ssid password:(nonnull NSString *)password __deprecated_msg("Will be removed in the future, please use commissionDevice:commissionModel:");


@end

NS_ASSUME_NONNULL_END
