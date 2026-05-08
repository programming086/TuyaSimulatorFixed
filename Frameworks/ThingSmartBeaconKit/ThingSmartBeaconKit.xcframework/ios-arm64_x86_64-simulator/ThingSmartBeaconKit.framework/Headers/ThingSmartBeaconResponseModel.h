
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBeaconResponseModel : NSObject

@property (nonatomic) NSUInteger groupId;
@property (nonatomic, strong) NSString *authDeviceMac;
@property (nonatomic, strong) NSString *authDeviceS1;

@end

NS_ASSUME_NONNULL_END
