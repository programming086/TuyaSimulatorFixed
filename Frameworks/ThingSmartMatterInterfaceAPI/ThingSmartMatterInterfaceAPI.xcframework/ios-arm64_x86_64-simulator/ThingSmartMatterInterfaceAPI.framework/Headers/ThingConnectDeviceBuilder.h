
#import <Foundation/Foundation.h>
#import "ThingMatterSetupPayload.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingConnectDeviceBuilder : NSObject

@property (nonatomic, strong) ThingMatterSetupPayload *setupPayload;

@property (nonatomic, assign) long long spaceId;

@property (nonatomic, strong) NSString *gatewayId;

@property (nonatomic, strong) NSString *token;

@property (nonatomic, assign) BOOL extraBind;

- (instancetype)initWithPayload:(ThingMatterSetupPayload *)payload spaceId:(long long)spaceId token:(NSString *)token;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
