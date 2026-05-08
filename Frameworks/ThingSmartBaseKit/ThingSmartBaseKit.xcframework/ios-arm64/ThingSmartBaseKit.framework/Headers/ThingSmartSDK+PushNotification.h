
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSDK (PushNotification)

/// Pushes a token.
/// @deprecated Use +[ThingSmartSDK sharedInstance].deviceToken instead.
@property (nonatomic, strong) NSString *pushToken DEPRECATED_MSG_ATTRIBUTE("Use +[ThingSmartSDK sharedInstance].deviceToken instead.");

/// Pushes deviceToken.
@property (nonatomic, strong) NSData *deviceToken;


/// Sets the device token pushing and error information.
/// @param token The device token.
/// @param error An error occurs while processing the request.
- (void)setDeviceToken:(nullable NSData *)token withError:(nullable NSError *)error;

/// Sets the device token pushing and error information.
/// @param token The device token.
/// @param error An error occurs while processing the request.
/// @param success The success callback.
/// @param failure The failure callback.
- (void)setDeviceToken:(nullable NSData *)token withError:(nullable NSError *)error success:(__nullable ThingSuccessID)success failure:(__nullable ThingFailureError)failure;


/// Indicates whether the app messages pushing function is enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getPushStatusWithSuccess:(__nullable ThingSuccessBOOL)success failure:(__nullable ThingFailureError)failure;


/// Enables or disables app message pushing.
/// @param enable A Boolean value indicates whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setPushStatusWithStatus:(BOOL)enable success:(__nullable ThingSuccessHandler)success failure:(__nullable ThingFailureError)failure;


/// Indicates whether device alert notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevicePushStatusWithSuccess:(__nullable ThingSuccessBOOL)success failure:(__nullable ThingFailureError)failure;


/// Enables or disables app device alert pushing messages.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setDevicePushStatusWithStauts:(BOOL)enable success:(__nullable ThingSuccessHandler)success failure:(__nullable ThingFailureError)failure;


/// Indicates whether app home notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getFamilyPushStatusWithSuccess:(__nullable ThingSuccessBOOL)success failure:(__nullable ThingFailureError)failure;


/// Enables or disables app home push messages.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setFamilyPushStatusWithStauts:(BOOL)enable success:(__nullable ThingSuccessHandler)success failure:(__nullable ThingFailureError)failure;


/// Indicates whether app message notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getNoticePushStatusWithSuccess:(__nullable ThingSuccessBOOL)success failure:(__nullable ThingFailureError)failure;


/// Enables or disables app message pushing.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setNoticePushStatusWithStauts:(BOOL)enable success:(__nullable ThingSuccessHandler)success failure:(__nullable ThingFailureError)failure;


/// Indicates whether app marketing messages are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getMarketingPushStatusWithSuccess:(__nullable ThingSuccessBOOL)success failure:(__nullable ThingFailureError)failure;


/// Enables or disables app marketing message pushing.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setMarketingPushStatusWithStauts:(BOOL)enable success:(__nullable ThingSuccessHandler)success failure:(__nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
