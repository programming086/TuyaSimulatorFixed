
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBTActiveParams : NSObject

@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, strong) NSString *productKey;
@property (nonatomic, strong) NSString *btName;
@property (nonatomic, assign) long long homeId;
@property (nonatomic, strong) NSString *mac;

@end


@interface ThingSmartBTLinkActivator : NSObject

- (void)activeBTDeviceWithParams:(ThingSmartBTActiveParams *)activeParams  success:(void (^)(ThingSmartDeviceModel *deviceModel))success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
