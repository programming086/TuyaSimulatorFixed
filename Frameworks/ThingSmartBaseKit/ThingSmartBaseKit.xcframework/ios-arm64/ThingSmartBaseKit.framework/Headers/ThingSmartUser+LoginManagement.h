
#import "ThingSmartUser.h"
#import "ThingSmartLoginTerminalModel.h"
#import "ThingSmartAccountAuthenticationRequestModel.h"
#import "ThingSmartAccountAuthenticationModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartUser (LoginManagement)
/**
 * Fetches the status of multi-device login (whether it is enabled or not).
 *
 * @param success A block to be executed if the request succeeds. It returns a BOOL indicating the multi-device login status.
 * @param failure A block to be executed if the request fails. It returns an error object describing the failure.
 */
- (void)getMultiLoginStatusWithSuccess:(nullable ThingSuccessBOOL)success
                               failure:(nullable ThingFailureError)failure;

/**
 * Retrieves the list of devices currently logged in with the user's account.
 *
 * @param success A block to be executed if the request succeeds. It returns an array of `ThingSmartLoginTerminalModel` objects representing the logged-in devices.
 * @param failure A block to be executed if the request fails. It returns an error object describing the failure.
 */
- (void)getLoginTerminalListWithSuccess:(nonnull void(^)( NSArray <ThingSmartLoginTerminalModel *> * __nullable))success
                                failure:(nullable ThingFailureError)failure;

/**
 * Validates the user account to obtain a logout code for terminating a device session.
 *
 * @param requestModel A model containing the account authentication details.
 * @param success A block to be executed if the request succeeds. It returns a `ThingSmartAccountAuthenticationModel` object containing the logout code.
 * @param failure A block to be executed if the request fails. It returns an error object describing the failure.
 */
- (void)getLogoutCodeByAuthorizingAccount:(ThingSmartAccountAuthenticationRequestModel *)requestModel
                                success:(nullable void(^)(ThingSmartAccountAuthenticationModel *))success
                                failure:(nullable ThingFailureError)failure;

/**
 * Forces the termination of a session on a specific device.
 *
 * @param terminalId The unique identifier of the device whose session is to be terminated.
 * @param logoutCode The logout code obtained from the `getLogoutCodeByAuthorizingAccount` method.
 * @param success A block to be executed if the request succeeds. It returns a BOOL indicating whether the session was successfully terminated.
 * @param failure A block to be executed if the request fails. It returns an error object describing the failure.
 */
- (void)terminateSessionOnDevice:(NSString *)terminalId
                      logoutCode:(NSString *)logoutCode
                         success:(nullable ThingSuccessBOOL)success
                         failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
