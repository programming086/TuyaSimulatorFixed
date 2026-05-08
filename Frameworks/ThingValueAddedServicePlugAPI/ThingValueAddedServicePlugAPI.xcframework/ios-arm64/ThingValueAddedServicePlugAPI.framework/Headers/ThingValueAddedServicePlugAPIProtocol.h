
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingVoiceServiceType) {
    ThingVoiceServiceTypeAmazonAlexa,
    ThingVoiceServiceTypeGoogleHome,
};

@protocol ThingValueAddedServicePlugAPIProtocol <NSObject>

@optional

#pragma mark - Before Authorization
/// Icon for the header of the pre-authorization page
- (nullable UIImage *)preAuthorizationIcon:(ThingVoiceServiceType)type;

/// Image for the pre-authorization page
- (nullable UIImage *)preAuthorizationImage:(ThingVoiceServiceType)type;

/// Hint content for the pre-authorization page
- (nullable NSString *)preAuthorizationDetail:(ThingVoiceServiceType)type;

#pragma mark - Authorization Confirmation

/// App icon for the authorization confirmation page
- (nullable UIImage *)authorizationConfirmIcon:(ThingVoiceServiceType)type;

/// App name for the authorization confirmation page
- (nullable NSString *)authorizationConfirmAppName:(ThingVoiceServiceType)type;

/// Authorization title for the authorization confirmation page
- (nullable NSString *)authorizationConfirmTitle:(ThingVoiceServiceType)type;

/// Authorization tips title for the authorization confirmation page
- (nullable NSString *)authorizationConfirmTipsTitle:(ThingVoiceServiceType)type;

/// Authorization tips content for the authorization confirmation page
- (nullable NSString *)authorizationConfirmTipsDetail:(ThingVoiceServiceType)type;

#pragma mark - Authorized

/// Icon for the header of the authorized page
- (nullable UIImage *)didAuthorizationIcon:(ThingVoiceServiceType)type;

/// Authorization title for the authorized page
- (nullable NSString *)didAuthorizationTitle:(ThingVoiceServiceType)type;

/// Authorization tips title for the authorized page
- (nullable NSString *)didAuthorizationTipsTitle:(ThingVoiceServiceType)type;

/// Authorization tips content for the authorized page
- (nullable NSString *)didAuthorizationTipsDetail:(ThingVoiceServiceType)type;

#pragma mark - Unbind Authorization

/// App icon for the authorization unbind page
- (nullable UIImage *)authorizationUnbindIcon:(ThingVoiceServiceType)type;

/// Authorization title for the authorization unbind page
- (nullable NSString *)authorizationUnbindTitle:(ThingVoiceServiceType)type;

/// Authorization tips title for the authorization unbind page
- (nullable NSString *)authorizationUnbindTipsTitle:(ThingVoiceServiceType)type;

/// Authorization tips content for the authorization unbind page
- (nullable NSArray<NSString *> *)authorizationUnbindTipsDetails:(ThingVoiceServiceType)type;

@end

NS_ASSUME_NONNULL_END
