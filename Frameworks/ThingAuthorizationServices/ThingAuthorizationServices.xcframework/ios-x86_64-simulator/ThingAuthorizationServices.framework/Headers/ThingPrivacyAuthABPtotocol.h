
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingPrivacyAuthABType)  {
    ThingPrivacyAuthABType_Other = 0,
    ThingPrivacyAuthABType_Open = 1,
    ThingPrivacyAuthABType_Close = 2,
};

// App startup permission application optimization, AB grayscale uses temporary agreement, custom parties do not need to care
@protocol ThingPrivacyAuthABPtotocol <NSObject>
// AB Grayscale uses a temporary agreement, and the customizing party does not need to care
- (ThingPrivacyAuthABType)appRightABTestType;
// AB Grayscale uses a temporary agreement, and the customizing party does not need to care
- (void)registerAppRightABTestTypeChangeBlock:(void (^)(ThingPrivacyAuthABType type))block;
@end
NS_ASSUME_NONNULL_END

