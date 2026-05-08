
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceRebootTimer : NSObject <NSCopying>

/// timer id
@property (nonatomic, copy) NSString *tid;

/// time to reboot, format: HH:mm
@property (nonatomic, copy) NSString *time;

/// days to repeat,  0000000, from Sunday to Saturday, 1 means repeat, 0 means not repeat
/// e.g. 1000000 means repeat on Sunday, 1100000 means repeat on Sunday and Monday, 1111111 means repeat every day, 0000000 means not repeat
@property (nonatomic, copy) NSString *loops;

/// status of the timer, true means enable, false means disable
@property (nonatomic, assign) BOOL status;

- (BOOL)isSame:(ThingDeviceRebootTimer *)timer;

- (void)migrate:(ThingDeviceRebootTimer *)timer;

@end

NS_ASSUME_NONNULL_END
