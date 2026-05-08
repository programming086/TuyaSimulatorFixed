
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBLEDeviceCheckModel : NSObject

@property (nonatomic, assign) NSInteger businessCode;

@property (nonatomic, copy) NSString *encryptedAuthKey;

@property (nonatomic, copy) NSString *random;

@end

NS_ASSUME_NONNULL_END
