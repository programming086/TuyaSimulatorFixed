
#import <Foundation/Foundation.h>
#import <LocalAuthentication/LocalAuthentication.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSErrorDomain const ThingSmartLocalAuthErrorDomain;


typedef enum : NSUInteger {
    ThingSmartLocalAuthErrorBiometricLoginNotOpen = -5001,
    ThingSmartLocalAuthErrorBiometricLoginInfoModified = -5002,
} ThingSmartLocalAuthError;

@interface ThingBiometricLogiUserInfo : NSObject
@property(nonatomic, strong) NSString *userName;
@property(nonatomic, strong) NSString *icon;
@property(nonatomic, strong) NSString *uid;
@property(nonatomic, strong) NSString *countryCode;
@property(nonatomic, strong) NSString *nickName;
@end

@interface ThingBiometricLoginManager : NSObject

@property (nonatomic, strong) LAContext *laContext;

/// Check whether device hardware supports Face ID login. Currently only Face ID is supported.
- (BOOL)mobileHardwareSupportFaceIDLogin;

/// Whether biometric login is enabled
- (BOOL)isBiometricLoginEnabled:(NSError * __autoreleasing *)error;

/// Get stored biometric login user info
- (ThingBiometricLogiUserInfo *)getBiometricLoginUserAccountInfo;

/// Update stored user display name and avatar for biometric login
- (void)updateCurrentAccountBiometricLoginInformation;

/// Open biometric login
/// @param policy The LAPolicy to evaluate
/// @param localizedReason The reason displayed in the authentication prompt
/// @param reply Completion block with success flag and error
- (void)openBiometricLoginWithEvaluatePolicy:(LAPolicy)policy
      localizedReason:(NSString *)localizedReason
                reply:(void(^)(BOOL success,NSError * __nullable error))reply;

/// Disable biometric login and clear stored biometric data
/// @param reply Completion block with success flag and error
- (void)closeBiometricLogin:(void(^)(BOOL success, NSError * __nullable error))reply;

/// Perform biometric login
/// @param policy The LAPolicy to evaluate
/// @param localizedReason The reason displayed in the authentication prompt
/// @param reply Completion block with success flag, result and error
- (void)loginByBiometricWithEvaluatePolicy:(LAPolicy)policy
       localizedReason:(NSString *)localizedReason
                 reply:(void(^)(BOOL success, id result, NSError * __nullable error))reply;
@end

NS_ASSUME_NONNULL_END
