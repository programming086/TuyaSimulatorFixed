
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartAccountAuthenticationModel : NSObject

/**
 * A unique code used for logging out a specific device or session.
 * This code is typically obtained after validating the user's account.
 */
@property (nonatomic, strong) NSString *logoutCode;

/**
 * The expiration time of the logout code, represented as a time interval since the reference date.
 * After this time, the logout code becomes invalid and cannot be used to terminate a session.
 */
@property (nonatomic, assign) NSTimeInterval expireTime;
@end

NS_ASSUME_NONNULL_END
