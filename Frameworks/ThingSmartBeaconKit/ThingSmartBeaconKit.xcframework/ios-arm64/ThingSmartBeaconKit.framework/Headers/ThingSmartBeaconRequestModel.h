
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBeaconRequestModel : NSObject

@property (nonatomic) NSUInteger groupId;
@property (nonatomic, strong) NSString *authDeviceMac;
@property (nonatomic) BOOL authResult;
@property (nonatomic) BOOL checkResult;

@end

NS_ASSUME_NONNULL_END
