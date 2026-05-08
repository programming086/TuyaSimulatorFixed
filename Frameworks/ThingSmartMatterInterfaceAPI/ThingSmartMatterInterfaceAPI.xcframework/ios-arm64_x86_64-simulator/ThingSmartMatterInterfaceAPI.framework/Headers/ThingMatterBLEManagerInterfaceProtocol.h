
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

@protocol ThingMatterBLEManagerInterfaceProtocol <NSObject>

- (void)sendDeviceReopenMatterService:(NSString *)devId Success:(ThingSuccessString)success failure:(ThingFailureError)failure;

- (void)checkDeviceCanJoinMatter:(NSString *)devId Success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

- (void)checkSupportMutipleFabric:(NSString *)devId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@end
