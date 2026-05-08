
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterDiscoveryModel : NSObject

@property (nonatomic, strong) ThingSmartMatterSetupPayload *payload;

@property (nonatomic, strong) NSString *iconUrl;

@property (nonatomic, strong) NSString *deviceName;

@property (nonatomic, strong) NSString *productId;

@property (nonatomic, assign) BOOL isThingDevice;

@property (nonatomic, assign) BOOL dualNetwork;

@property (nonatomic, assign) long long scanTime;

@property (nonatomic, assign) ThingSmartMatterDeviceType deviceType;

- (instancetype)initWithPayload:(ThingSmartMatterSetupPayload *)payload;

@end

NS_ASSUME_NONNULL_END
