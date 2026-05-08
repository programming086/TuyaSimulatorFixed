
#import <Foundation/Foundation.h>
#import "ThingSmartPairSuccessDevice.h"
#import "ThingSmartPairErrorDevice.h"
#import "ThingSmartPairingHeader.h"
#import <ThingSmartUtil/ThingSmartUtil.h>

typedef void(^ ThingPollingRetry)(void);
typedef void(^ ThingApCompensation)(void);

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartPairingHandlerDelegate <NSObject>

@optional

- (void)pairingDeviceReady;

- (void)pairingDeviceStateError:(NSError *)error;

- (void)pollingDeviceWithToken:(NSString *)token retry:(nullable ThingPollingRetry)retry success:(nullable void(^)(ThingSmartPairSuccessDevice * _Nullable device))success failure:(nullable void(^)(ThingSmartPairErrorDevice * _Nullable device))failure;

- (void)pairingWithResult:(nullable id)result error:(nullable NSError *)error step:(ThingActivatorStep)step;

- (void)pairingSuccessWithResult:(nullable id)result;

- (void)pairingError:(nullable NSError *)error errorDevice:(nullable id)errorDevice;

- (void)pairingDidPassWiFiToSecurityLevelDevice:(NSString *)uuid;

- (void)deviceDataUpdate:(NSString *)devId;

- (void)meshSubDeviceDataUpdateWithMeshId:(NSString *)meshId deviceId:(NSString *)deviceId error:(NSError *)error;

- (void)checkDeviceStatusByDevId:(nullable NSString *)devId token:(nullable NSString *)token apCompensation:(nullable ThingSuccessHandler)compensation;

- (void)fetchInitKeyWithUUID:(NSString *)uuid success:(nullable void(^)(NSString * initKey))success failure:(nullable ThingFailureError)failure;

- (void)fetchPSKInfoWithSL:(NSNumber *)SL success:(nullable ThingSuccessDict)success failure:(nullable ThingFailureError)failure;

- (void)checkGatewayInfo:(nullable NSString *)devId
                   token:(nullable NSString *)token
                 success:(nullable void(^)(void))success
                 failure:(ThingFailureError)failure;

- (void)resetDevice:(nullable NSString *)devId
              token:(nullable NSString *)token
            success:(nullable void(^)(void))success
            failure:(ThingFailureError)failure;


- (NSDictionary *)requestDeviceModel;


- (void)updateDeviceModelWithBody:(NSDictionary *)body data:(NSData *)data lpv:(NSString *)lpv type:(int)type;


- (NSDictionary *)requestDeviceSchema;


- (void)activatorDeviceSuccessed;

- (void)activatorDeviceFailureWithError:(NSError *)error;

- (void)didFailedToConnectWiFiToDevice:(NSString *)ssid uuid:(NSString *)uuid error:(NSError*)error;

@end

NS_ASSUME_NONNULL_END
