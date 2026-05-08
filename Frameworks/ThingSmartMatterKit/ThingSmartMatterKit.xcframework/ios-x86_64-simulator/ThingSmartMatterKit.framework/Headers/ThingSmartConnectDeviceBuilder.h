

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartConnectDeviceBuilder : NSObject

@property (nonatomic, strong) ThingSmartMatterSetupPayload *setupPayload;

@property (nonatomic, assign) long long spaceId;

@property (nonatomic, strong) NSString *gatewayId;

@property (nonatomic, strong) NSString *token;

@property (nonatomic, assign) BOOL extraBind;

- (instancetype)initWithPayload:(ThingSmartMatterSetupPayload *)payload spaceId:(long long)spaceId token:(NSString *)token;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
