

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterCommissionModel : NSObject

@property (nonatomic, strong) NSString *ssid;

@property (nonatomic, strong) NSString *password;

@property (nonatomic, strong)  NSString * _Nullable gwId;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithSSid:(NSString *)ssid password:(NSString *)password;

- (instancetype)initWithGatewayId:(NSString *)gwId;

@end

NS_ASSUME_NONNULL_END
