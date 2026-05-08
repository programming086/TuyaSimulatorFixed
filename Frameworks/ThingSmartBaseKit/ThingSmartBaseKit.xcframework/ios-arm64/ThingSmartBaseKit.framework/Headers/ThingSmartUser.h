
#ifndef ThingSmartUser_h
#define ThingSmartUser_h

#import <UIKit/UIKit.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// The notification is sent when the user session is invalid.
extern NSString *const ThingSmartUserNotificationUserSessionInvalid;

/// The user registration type.
typedef NS_ENUM(NSInteger, ThingRegType) {
    /// Register from email.
    ThingRegEmailType,
    /// Register from mobile phone.
    ThingRegPhoneType,
    /// Register from other methods.
    ThingRegOtherType,
    /// Register from QQ.
    ThingRegQQType,
    /// Register from Sina Weibo.
    ThingRegWeiboType,
    /// Register from Facebook.
    ThingRegFacebookType,
    /// Register from Twitter.
    ThingRegTwitterType,
    /// Register from WeChat.
    ThingRegWechatType,
    /// Register from Apple.
    ThingRegAppleIdType,
    /// Register from Google.
    ThingRegGoogleType,
    /// Register from Line.
    ThingRegLineType,
};

/// The password strength type.
typedef NS_ENUM(NSInteger, ThingPasswordRegularType) {
    ThingPasswordRegularLow = 1,       // Contains 8-20 characters in length,including letters and numbers.
    ThingPasswordRegularMiddle = 2,       // Contains 8-20 characters,including uppercase and lowercase letters and numbers.
    ThingPasswordRegularHigh = 3,     // Contains 8-20 characters,including uppercase and lowercase letters, numbers, and special characters.
};


/// Auth 2.0 login type
typedef NSString * ThingSmartUserLoginType;

/// Login type constants
extern NSString *const ThingSmartUserLoginTypeGoogle;       // Google authentication
extern NSString *const ThingSmartUserLoginTypeWechat;       // WeChat authentication
extern NSString *const ThingSmartUserLoginTypeQQ;           // QQ authentication
extern NSString *const ThingSmartUserLoginTypeApple;        // Sign in with Apple
extern NSString *const ThingSmartUserLoginTypeFacebook;     // Facebook authentication
extern NSString *const ThingSmartUserLoginTypeTwitter;      // Twitter authentication
extern NSString *const ThingSmartUserLoginTypeJWT;          // JWT authentication


// Error domain for ThingSmartUser login errors
extern NSString * const ThingSmartUserLoginErrorDomain;
// Enumeration for error codes
typedef NS_ENUM(NSInteger, ThingSmartUserLoginErrorCode) {
    ThingSmartUserLoginErrorCodeMissingUniqueId = 100,
    ThingSmartUserLoginErrorCodeMissingAccessToken,
    ThingSmartUserLoginErrorCodeMissingCountryCode
};

// A flag in the login notification to declare whether the login is triggered by server switch.
extern NSString * const ThingSmartUserLoginBySwitchServerFlag;
// A flag in the login notification to declare whether the login is triggered by auto login.
extern NSString * const ThingSmartUserLoginByAutoLoginFlag;


/// Main:
///     - Email
///     - Phone
/// Third-party:
///     - QQ
///     - Weibo
///     - WeChat
///     - Facebook
///     - Twitter
///     - Google
///     - AppleID
/// Other:
///     - UID (for advance usage)
///     - Anonymous
///     - QRCode
///
/// For email and phone account, usually we need to send a verify code to continue the following steps.
///
/// For uid account, it is designed for developers who already has the account system for their own. The developer can register the uid account without any verification. So please keep your username/password in safe place.
///
/// @warning Thing server have many regions over the world, China/Europe/America, and so on. Account system between regions are separated. When user is not logged in, Thing SDK will select a nearest region for the initial API request. During the register step, Thing Cloud will see the account country code and create it in the right region. After the register or login step, the API request will be sent to the right region. So, the country code is part of the account username, please do not ignore it.
///
@interface ThingSmartUser : NSObject

/// Returns the singleton of the class.
+ (instancetype)sharedInstance;

/// The session ID.
@property (nonatomic, strong, readonly) NSString *sid;

/// The user ID.
@property (nonatomic, strong, readonly) NSString *uid;

/// The avatar.
@property (nonatomic, strong, readonly) NSString *headIconUrl;

/// The nickname.
@property (nonatomic, strong, readonly) NSString *nickname;

/// The username. If the account is registered with a mobile phone number, the value is set to the mobile phone number. If the account is registered with an email, the value is set to the email.
@property (nonatomic, strong, readonly) NSString *userName;

/// The mobile phone number.
@property (nonatomic, strong, readonly) NSString *phoneNumber;

/// The email.
@property (nonatomic, strong, readonly) NSString *email;

/// The country code. For example, `86` means China, `1` means America.
@property (nonatomic, strong, readonly) NSString *countryCode;

/// The login status.
@property (nonatomic, assign, readonly) BOOL isLogin;

/// The region code of the current account. For example, `AY` means China, `AZ` means America, and `EU` means Europe.
@property (nonatomic, strong, readonly) NSString *regionCode;

/// The API domains of the current account region.
@property (nonatomic, strong, readonly) NSDictionary *domain;

/// The timezone ID, such as `Asia/Shanghai`.
@property (nonatomic, strong, readonly) NSString *timezoneId;

@property (nonatomic, strong, readonly) NSString *partnerIdentity;

/// The MQTT host.
@property (nonatomic, strong, readonly) NSString *mbHost;

@property (nonatomic, strong, readonly) NSString *gwHost;

/// The MQTT port.
@property (nonatomic, assign, readonly) NSInteger port;

/// Specifies whether to enable SSL.
@property (nonatomic, assign, readonly) BOOL useSSL;

/// The QUIC host.
@property (nonatomic, strong, readonly) NSString *quicHost;

/// The QUIC port.
@property (nonatomic, assign, readonly) NSInteger quicPort;

/// Specifies whether to enable QUIC.
@property (nonatomic, assign, readonly) BOOL useQUIC;

/// The temperature unit. For example, `1` means `°C` and `2` means `°F`.
@property (nonatomic, assign) NSInteger tempUnit;

/// The user registration type.
@property (nonatomic, assign, readonly) ThingRegType regFrom;

/// The nickname of the SNS account.
@property (nonatomic, strong, readonly) NSString *snsNickname;

@property (nonatomic, strong, readonly) NSString *ecode;

/// The user type.
@property (nonatomic, assign, readonly) NSInteger userType;

/// Extra parameters.
@property (nonatomic, strong, readonly) NSDictionary *extras;

@property (nonatomic, strong) NSString *userAlias;



#pragma mark - Mobile phone verification code login

/// Sends the verification code to register, log in, or reset the password.
/// @param userName The mobile phone number or email address.
/// @param region To enable required registration, use [ThingSmartUser regionListWithCountryCode:success:failure:] or [ThingSmartUser getDefaultRegionWithCountryCode:] to get the region.
/// @param countryCode The country code.
/// @param type Valid values: `1`: Register with the mobile phone verification code. `2`: Log in with the mobile phone verification code. `3`: Reset the password with the mobile phone number. `5`: Complete account information in trial mode. `7`: Change the account. `8`: Cancel the account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVerifyCodeWithUserName:(NSString *)userName
                            region:(NSString *_Nullable)region
                       countryCode:(NSString *)countryCode
                              type:(NSInteger)type
                           success:(ThingSuccessHandler)success
                           failure:(ThingFailureError)failure;


/// Enables login with the mobile phone verification code.
/// @param mobile The mobile phone number.
/// @param countryCode The country code.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithMobile:(NSString *)mobile
            countryCode:(NSString *)countryCode
                   code:(NSString *)code
                success:(ThingSuccessHandler)success
                failure:(ThingFailureError)failure;


#pragma mark - Mobile phone binding

/// Sends the verification code to bind a mobile phone number or change the mobile phone number.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindVerifyCode:(NSString *)countryCode
               phoneNumber:(NSString *)phoneNumber
                   success:(nullable ThingSuccessHandler)success
                   failure:(nullable ThingFailureError)failure;


/// Sends the verification code to bing a mobile phone and enable more services.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindVasVerifyCode:(NSString *)countryCode
                  phoneNumber:(NSString *)phoneNumber
                      success:(nullable ThingSuccessHandler)success
                      failure:(nullable ThingFailureError)failure;

/// Binds a mobile phone number.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)mobileBinding:(NSString *)countryCode
          phoneNumber:(NSString *)phoneNumber
                 code:(NSString *)code
              success:(nullable ThingSuccessHandler)success
              failure:(nullable ThingFailureError)failure;

/// Change to bind a mobile phone number or a email.
/// @param account A mobile phone number or a email.
/// @param countryCode The country code.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)changBindAccount:(NSString *)account
                      countryCode:(NSString *)countryCode
                                  code:(NSString *)code
                             success:(nullable ThingSuccessHandler)success
                             failure:(nullable ThingFailureError)failure;

#pragma mark - Mobile phone password login

/// Registers with a mobile phone number.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param password The password.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)registerByPhone:(NSString *)countryCode
            phoneNumber:(NSString *)phoneNumber
               password:(NSString *)password
                   code:(NSString *)code
                success:(nullable ThingSuccessHandler)success
                failure:(nullable ThingFailureError)failure;

/// Enables login with the mobile phone password.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param password The password.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByPhone:(NSString *)countryCode
         phoneNumber:(NSString *)phoneNumber
            password:(NSString *)password
             success:(nullable ThingSuccessHandler)success
             failure:(nullable ThingFailureError)failure;

/// Resets the mobile phone password.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param newPassword The new password.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)resetPasswordByPhone:(NSString *)countryCode
                 phoneNumber:(NSString *)phoneNumber
                 newPassword:(NSString *)newPassword
                        code:(NSString *)code
                     success:(nullable ThingSuccessHandler)success
                     failure:(nullable ThingFailureError)failure;

#pragma mark - Email login

/// Enables login with an email.
/// @param countryCode The country code.
/// @param email The email.
/// @param password The password.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByEmail:(NSString *)countryCode
               email:(NSString *)email
            password:(NSString *)password
             success:(nullable ThingSuccessHandler)success
             failure:(nullable ThingFailureError)failure;


/// Resets the email password.
/// @param countryCode The country code.
/// @param email The email.
/// @param newPassword The new password.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)resetPasswordByEmail:(NSString *)countryCode
                       email:(NSString *)email
                 newPassword:(NSString *)newPassword
                        code:(NSString *)code
                     success:(nullable ThingSuccessHandler)success
                     failure:(nullable ThingFailureError)failure;


#pragma mark - Email register 2.0

/// Email register 2.0.
/// @param countryCode The country code.
/// @param email The email.
/// @param password The password.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)registerByEmail:(NSString *)countryCode
                  email:(NSString *)email
               password:(NSString *)password
                   code:(NSString *)code
                success:(nullable ThingSuccessHandler)success
                failure:(nullable ThingFailureError)failure;

#pragma mark - Email verification code login

/// Enables login with an email verification code.
/// @param email The email.
/// @param countryCode The country code.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithEmail:(NSString *)email countryCode:(NSString *)countryCode code:(NSString *)code success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

#pragma mark - Email bind

/// Returns the email verification code.
/// @param email The email.
/// @param countryCode The country code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindingVerificationCodeWithEmail:(NSString *)email
                                 countryCode:(NSString *)countryCode
                                     success:(nullable ThingSuccessHandler)success
                                     failure:(nullable ThingFailureError)failure;

/// Binds an email.
/// @param email The email.
/// @param countryCode The country code.
/// @param code The verification Code.
/// @param sId The user session ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindEmail:(NSString *)email
  withCountryCode:(NSString *)countryCode
             code:(NSString *)code
              sId:(NSString *)sId
          success:(nullable ThingSuccessHandler)success
          failure:(nullable ThingFailureError)failure;

#pragma mark - uid login

/// The user ID that is used to log in or register. The account is registered at the first login.
/// @param countryCode The country code.
/// @param uid The user ID.
/// @param password The password.
/// @param createHome Creates the default home.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              password:(NSString *)password
                            createHome:(BOOL)createHome
                               success:(nullable ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

#pragma mark - Social login

/// Enables login with the QQ account.
/// @param countryCode The country code.
/// @param userId The user ID that is authorized for login with the QQ account.
/// @param accessToken AccessToken that is used for login with the QQ account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByQQ:(NSString *)countryCode
           userId:(NSString *)userId
      accessToken:(NSString *)accessToken
          success:(nullable ThingSuccessHandler)success
          failure:(nullable ThingFailureError)failure;

/// Enables login with the WeChat account.
/// @param countryCode The country code.
/// @param code The code that is used for login with the WeChat account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByWechat:(NSString *)countryCode
                 code:(NSString *)code
              success:(nullable ThingSuccessHandler)success
              failure:(nullable ThingFailureError)failure;

/// Enables login with the Facebook account.
/// @param countryCode The country code.
/// @param token The token that is used for login with the Facebook account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByFacebook:(NSString *)countryCode
                  token:(NSString *)token
                success:(nullable ThingSuccessHandler)success
                failure:(nullable ThingFailureError)failure;

/// Enables login with the Twitter account.
/// @param countryCode The country code.
/// @param key The key that is used for login with the Twitter account.
/// @param secret The secret that is used for login with the Twitter account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByTwitter:(NSString *)countryCode
                   key:(NSString *)key
                secret:(NSString *)secret
               success:(nullable ThingSuccessHandler)success
               failure:(nullable ThingFailureError)failure;

/// Enables login with a third-party account.
/// @param type The login type, such as `ThingSmartUserLoginTypeApple` for Apple login.
/// @param countryCode The country code.
/// @param accessToken The access token for third-party account login.
/// @param extraInfo Additional parameters containing platform identifier and unique ID for cryptographic tokens. If `type` is `ThingSmartUserLoginTypeJWT`, also can use `ThingSmartUserLoginJWTModel`in params extraInfo.
/// @param success Called upon successful completion of the task.
/// @param failure Called when the task fails due to an error. Error domian is `ThingSmartUserLoginErrorDomain`, error code is `ThingSmartUserLoginErrorCode`
- (void)loginByAuth2WithType:(ThingSmartUserLoginType)type
                 countryCode:(NSString *)countryCode
                 accessToken:(NSString *)accessToken
                   extraInfo:(NSDictionary *)extraInfo
                     success:(nullable ThingSuccessHandler)success
                     failure:(nullable ThingFailureError)failure;

#pragma mark -

/// Logout.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginOut:(nullable ThingSuccessHandler)success
         failure:(nullable ThingFailureError)failure;

/// Edits the nickname.
/// @param nickName The nickname.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateNickname:(NSString *)nickName
               success:(nullable ThingSuccessHandler)success
               failure:(nullable ThingFailureError)failure;

/// Edits the avatar.
/// @param headIcon The avatar.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated Will be removed in the future, please maintain user avatar by yourself. USER_AVATAR_UPLOAD_REJECT_FOR_CUSTOMIZE error message will be returned when this method is called.
- (void)updateHeadIcon:(UIImage *)headIcon
               success:(nullable ThingSuccessHandler)success
               failure:(nullable ThingFailureError)failure __deprecated_msg("Will be removed in the future, please maintain user avatar by yourself");

/// Edits the avatar.
/// @param imageUrl The avatar image Url.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated Will be removed in the future, please maintain user avatar by yourself. USER_AVATAR_UPLOAD_REJECT_FOR_CUSTOMIZE error message will be returned when this method is called.
- (void)updateAvatarWithImageUrl:(NSString *)imageUrl
               success:(nullable ThingSuccessHandler)success
               failure:(nullable ThingFailureError)failure __deprecated_msg("Will be removed in the future, please maintain user avatar by yourself");

/// Updates user information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateUserInfo:(nullable ThingSuccessHandler)success
               failure:(nullable ThingFailureError)failure;

/// Edits user time zone information.
/// @param timeZoneId The time zone ID, such as `Asia/Shanghai`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimeZoneWithTimeZoneId:(NSString *)timeZoneId
                             success:(nullable ThingSuccessHandler)success
                             failure:(nullable ThingFailureError)failure;

/// Edits the user temperature unit.
/// @param tempUnit The temperature unit. For example, `1` means `°C` and `2` means `°F`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTempUnitWithTempUnit:(NSInteger)tempUnit
                           success:(nullable ThingSuccessHandler)success
                           failure:(nullable ThingFailureError)failure;

/// Destroys an account. One week after the operation, all of the account information is permanently removed from the server. After login before the information is removed, the destroying request is canceled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelAccount:(nullable ThingSuccessHandler)success
              failure:(nullable ThingFailureError)failure;


/**
 * Checks whether the password format meets the password strength requirements.
 * @param password The password to be checked.
 * @param regularType The recommended password type.
 * @return The result of the check.
 */
- (BOOL)checkPasswordFormat:(NSString *)password withPasswordRegularType:(ThingPasswordRegularType)regularType;


#pragma mark - Ticket from third cloud login

/// Login with ticket.
/// Ticket is created from a third-party cloud platform, for more information, please refer to the thing.cloud-to-cloud solution.
///
/// @param ticket User ticket from service.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithTicket:(NSString *)ticket
                success:(ThingSuccessHandler)success
                failure:(ThingFailureError)failure;


/// Sends the verification code to bind a mobile phone number or change the mobile phone number.
/// @param countryCode The country code.
/// @param account The mobile phone number/email.
/// @param captchaContext Man-machine identification ticket
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVerifyCode:(NSString *)countryCode
               account:(NSString *)account
            captchaContext:(NSDictionary *)captchaContext
                   success:(nullable ThingSuccessHandler)success
                   failure:(nullable ThingFailureError)failure;

/// Sends the verification code to register, log in, or reset the password.
/// @param userName The mobile phone number or email address.
/// @param region To enable required registration, use [ThingSmartUser regionListWithCountryCode:success:failure:] or [ThingSmartUser getDefaultRegionWithCountryCode:] to get the region.
/// @param countryCode The country code.
/// @param type Valid values: `1`: Register with the mobile phone verification code. `2`: Log in with the mobile phone verification code. `3`: Reset the password with the mobile phone number. `5`: Complete account information in trial mode. `7`: Change the account. `8`: Cancel the account.
/// @param captchaContext Man-machine identification ticket
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVerifyCodeWithUserName:(NSString *)userName
                            region:(NSString *_Nullable)region
                       countryCode:(NSString *)countryCode
                              type:(NSInteger)type
                    captchaContext:(nonnull NSDictionary *)captchaContext
                           success:(nonnull ThingSuccessHandler)success
                           failure:(nonnull ThingFailureError)failure;
/// Returns the email verification code.
/// @param email The email.
/// @param countryCode The country code.
/// @param captchaContext Man-machine identification ticket
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindingVerificationCodeWithEmail:(NSString *)email
                                 countryCode:(NSString *)countryCode
                              captchaContext:(NSDictionary *)captchaContext
                                     success:(nullable ThingSuccessHandler)success
                                     failure:(nullable ThingFailureError)failure;

- (void)sendBindVasVerifyCode:(NSString *)countryCode
                        phoneNumber:(NSString *)phoneNumber
               captchaContext:(NSDictionary *)captchaContext
                            success:(ThingSuccessHandler)success
                            failure:(ThingFailureError)failure;



/// is during server switch.
- (BOOL)isInServerSwitch;
/// is requesting the server switch.
- (BOOL)isRequestingServerSwitch;
/// the server switch info did fetched.
- (BOOL)didFetchServerSwitchInfo;

/// begin switch the server
/// @param regionCode The region code of the server.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)beginSwitchServerWithRegionCode:(NSString *)regionCode success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


/// finish switch the server
/// @param complete Called when the task is finished.
- (void)finishSwitchServerComplete:(void(^)(BOOL result))complete;

#pragma mark -

///
/// @param info
/// @param source  6:login by phone 7: login by email
- (void)resetWithUserInfo:(NSDictionary *)info source:(NSUInteger)source;
/// Clear user data
- (void)clearUserInfo;

/// Cancels the network request.
- (void)cancelRequest;


/// check email password
/// @param passwd password
/// @param success  success callback
/// @param failure failure callback
- (void)checkEmailPasswd:(NSString *)passwd
                 success:(ThingSuccessHandler)success
                 failure:(ThingFailureError)failure;

/// check mobile code
/// @param countryCode countryCode
/// @param mobile mobile
/// @param code code
/// @param success success callback
/// @param failure failure callback
- (void)checkMobileCode:(NSString *)countryCode
                 mobile:(NSString *)mobile
                   code:(NSString *)code
                success:(ThingSuccessHandler)success
                failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSmartUser_h */
