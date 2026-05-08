
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMatterManagerInterfaceProtocol <NSObject>

- (long long)currentMatterSpaceId;

- (void)loadFabricWithSpaceId:(long long)spaceId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

- (NSArray *)fetchAvailableGatewayDevice;

- (NSArray *)fetchAllGatewayDeviceForSpaceID:(long long)spaceId;

@end

NS_ASSUME_NONNULL_END
