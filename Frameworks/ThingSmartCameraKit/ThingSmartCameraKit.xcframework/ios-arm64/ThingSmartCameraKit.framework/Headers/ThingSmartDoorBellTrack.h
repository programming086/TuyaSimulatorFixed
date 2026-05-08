
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDoorBellTrack : NSObject

+ (void)trackEvent_Receive43Protocol:(NSString *)type;

+ (void)trackEvent_APNS43Protocol:(NSString *)type;

+ (void)trackEvent_43Protocol_Success:(NSString *)type source:(NSString *)sourceType;

+ (void)trackEvent_43Protocol_Fail:(NSString *)type code:(NSInteger)code;

@end

NS_ASSUME_NONNULL_END
