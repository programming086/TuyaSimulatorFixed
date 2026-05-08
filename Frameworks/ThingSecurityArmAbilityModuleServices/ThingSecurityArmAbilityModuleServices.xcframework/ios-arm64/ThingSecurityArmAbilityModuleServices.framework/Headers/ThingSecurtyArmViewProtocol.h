
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSecurityArmMode);

@protocol ThingSecurtyArmViewProtocol <NSObject>

@required



- (void)switchSecurityMode:(ThingSecurityArmMode)targetMode;

@optional;

- (void)itemViewBeginCountDown:(NSString *)desString;


- (void)addGatewayDevice;

@end

NS_ASSUME_NONNULL_END
