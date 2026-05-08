
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Enumeration representing the status of a login terminal (device).
 */
typedef NS_ENUM(NSUInteger, ThingSmartLoginTerminalStatus) {
    /** The terminal is invalid (e.g., logged out or deactivated). */
    ThingSmartLoginTerminalStatusInvalid = 0,
    /** The terminal is valid and currently logged in. */
    ThingSmartLoginTerminalStatusValid = 1,
};

/**
 * A model representing a login terminal (device) associated with a user's account.
 */
@interface ThingSmartLoginTerminalModel : NSObject

/**
 * The unique identifier of the terminal.
 */
@property (nonatomic, strong) NSString *terminalId;

/**
 * The operating system of the terminal (e.g., "iOS", "Android").
 */
@property (nonatomic, strong) NSString *os;

/**
 * The specific version or system of the operating system (e.g., "iOS 15.0", "Android 12").
 */
@property (nonatomic, strong) NSString *osSystem;

/**
 * The platform or device type (e.g., "iPhone", "iPad", "Samsung Galaxy").
 */
@property (nonatomic, strong) NSString *platform;

/**
 * The status of the terminal, represented by the `ThingSmartLoginTerminalStatus` enum.
 * Indicates whether the terminal is currently valid (logged in) or invalid (logged out).
 */
@property (nonatomic, assign) ThingSmartLoginTerminalStatus status;

/**
 * The timestamp of when the terminal logged in, represented as a time interval since the reference date.
 */
@property (nonatomic, assign) NSTimeInterval loginTime;
@end

NS_ASSUME_NONNULL_END
