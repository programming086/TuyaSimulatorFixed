
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingBLEWifiConfigModel : NSObject

@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, assign) long long homeId;
@property (nonatomic, strong) NSString *productId;
@property (nonatomic, strong) NSString *ssid;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, assign) NSTimeInterval timeOut;

@end

@interface ThingBLETransportRequest : NSObject

@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, assign) NSTimeInterval queryWifiListTimeout;
@property (nonatomic, assign) int maxWifiListCount;

@end

@interface ThingBLEConfigStateModel : NSObject

@property (nonatomic, strong) NSString *uuid;//设备uuid
@property (nonatomic, assign) int configStage;//配网阶段
@property (nonatomic, assign) int status;//阶段结果

@end

@interface ThingBLEWifiModel : NSObject

@property (nonatomic, strong) NSString *ssid;
@property (nonatomic, assign) int rssi;
@property (nonatomic, strong) NSString *sec;

@end

NS_ASSUME_NONNULL_END
