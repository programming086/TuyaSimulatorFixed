
#import <Foundation/Foundation.h>
#import "ThingDeviceDetailKitErrorDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceDetailKitErrorUtils : NSObject

+ (NSError *)errorWithCode:(ThingDeviceDetailKitError)code;

+ (NSError *)errorWithCode:(ThingDeviceDetailKitError)code text:(NSString *)text;

+ (NSError *)deviceNullError;

+ (NSError *)deviceOfflineError;

+ (NSError *)timerExtraError;

+ (NSError *)bleTransmissionTimeoutError;

+ (NSError *)bleDataParseError;

+ (NSError *)deviceCannotSyncError;

@end

NS_ASSUME_NONNULL_END
