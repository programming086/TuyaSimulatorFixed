
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Enumeration representing the type of account used for authentication.
 */
typedef NS_ENUM(NSUInteger, ThingSmartAuthenticationAccountType) {
    /** The account type is a phone number. */
    ThingSmartAuthenticationAccountTypePhone = 1,
    /** The account type is an email address. */
    ThingSmartAuthenticationAccountTypeEmail = 2,
};

/**
 * Enumeration representing the type of verification used for authentication.
 */
typedef NS_ENUM(NSUInteger, ThingSmartAuthenticationVerifyType) {
    /** Verification is done using a password. */
    ThingSmartAuthenticationVerifyTypePassword = 1,
    /** Verification is done using an authentication code. */
    ThingSmartAuthenticationVerifyTypeAuthCode = 2,
};

/**
 * A model representing the request data for account authentication.
 */
@interface ThingSmartAccountAuthenticationRequestModel : NSObject
/**
 * The country code associated with the account (e.g., "+1" for the United States).
 */
@property (nonatomic, strong) NSString *countryCode;

/**
 * The username associated with the account (e.g., phone number or email address).
 */
@property (nonatomic, strong) NSString *userName;

/**
 * The password used for authentication (if `verifyType` is `ThingSmartAuthenticationVerifyTypePassword`).
 */
@property (nonatomic, strong) NSString *password;

/**
 * The authentication code used for verification (if `verifyType` is `ThingSmartAuthenticationVerifyTypeAuthCode`).
 */

@property (nonatomic, strong) NSString *authCode;

/**
 * A token used for additional security or validation during authentication (if `verifyType` is `ThingSmartAuthenticationVerifyTypePassword`)..
 */
@property (nonatomic, strong) NSString *token;

/**
 * A flag indicating whether the data is encrypted (1 for encrypted, 0 for unencrypted)
 * (if `verifyType` is `ThingSmartAuthenticationVerifyTypePassword`).
 */
@property (nonatomic, assign) NSInteger ifencrypt;

/**
 * The type of account used for authentication, represented by the `ThingSmartAuthenticationAccountType` enum.
 */
@property (nonatomic, assign) ThingSmartAuthenticationAccountType accountType;

/**
 * The type of verification used for authentication, represented by the `ThingSmartAuthenticationVerifyType` enum.
 */
@property (nonatomic, assign) ThingSmartAuthenticationVerifyType verifyType;
@end

NS_ASSUME_NONNULL_END
