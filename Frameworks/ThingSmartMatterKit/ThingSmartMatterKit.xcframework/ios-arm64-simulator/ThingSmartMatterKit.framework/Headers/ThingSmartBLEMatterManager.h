
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBLEMatterManager : NSObject

/// shareInstance
ThingSDK_SINGLETON

//if matter device only
- (BOOL)isMatterDeviceSupportMutipleFabric:(NSString *)devId;

- (void)sendDeviceReopenMatterService:(NSString *)devId Success:(ThingSuccessString)success failure:(ThingFailureError)failure;

- (void)checkDeviceCanJoinMatter:(NSString *)devId Success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

- (void)checkSupportMutipleFabric:(NSString *)devId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
