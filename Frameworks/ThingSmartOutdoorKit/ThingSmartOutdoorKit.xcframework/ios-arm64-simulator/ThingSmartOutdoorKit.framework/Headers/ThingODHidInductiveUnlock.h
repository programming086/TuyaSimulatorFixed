
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, HidBindStatus) {
    HidBindStatusBind = 0,
    HidBindStatusUnbind = 1
} NS_SWIFT_NAME(HIDBindStatus);

@class ThingODHidInductiveUnlock;

NS_SWIFT_NAME(HIDInductiveUnlockDelegate)
@protocol ThingODHidInductiveUnlockDelegate <NSObject>

- (void)hidInductiveUnlock:(ThingODHidInductiveUnlock *)hidInductiveUnlock deviceID:(NSString *)deviceID status:(HidBindStatus)status;

@optional
- (void)listenHidBindStatusCallback:(HidBindStatus)status DEPRECATED_MSG_ATTRIBUTE("use hidInductiveUnlock:deviceID:pairStatus: instead.");
@end

NS_SWIFT_NAME(HIDInductiveUnlock)
@interface ThingODHidInductiveUnlock : NSObject

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

- (void)addDelegate:(id<ThingODHidInductiveUnlockDelegate>)delegate;

- (void)removeDelegate:(id<ThingODHidInductiveUnlockDelegate>)delegate;
/**
 * @brief Get the {@link hid bind ability} of device
 *
 * @param devId device id
 */
- (BOOL)supportHIDAbility:(NSString *)devId;

/**
 * @brief Get the {@link unlock status} of device
 *
 * @param devId device id
 */
- (BOOL)getUnlockStatus:(NSString *)devId;

/**
 * @brief Get the {@link hid bind status} of device
 *
 * @param devId device id
 */
- (BOOL)getHidBindStatus:(NSString *)devId;

/**
 * @brief Turn on the inductive unlock
 *
 * @param devId device id
 * @param finishedBlock unlock result
 * @param errorBlock error message
 */
- (void)turnOnHidInductiveUnlock:(NSString *)devId
                        finished:(void(^_Nullable)(void))finishedBlock
                           error:(void(^)(NSError* error))errorBlock;

/**
 * @brief Turn off the inductive unlock
 *
 * @param devId device id
 * @param finishedBlock unlock result
 * @param errorBlock error message
 */
- (void)turnOffHidInductiveUnlock:(NSString *)devId
                         finished:(void(^_Nullable)(void))finishedBlock
                            error:(void(^)(NSError* error))errorBlock;

/**
 * @brief Record Fortify Distance
 *
 * @param devId device id
 * @param finishedBlock record result
 * @param errorBlock error message
 */
- (void)recordFortifyDistance:(NSString *)devId
                     finished:(void(^_Nullable)(void))finishedBlock
                        error:(void(^)(NSError* error))errorBlock;

/**
 * @brief Record Disarm Distance
 *
 * @param devId device id
 * @param finishedBlock record result
 * @param errorBlock error message
 */
- (void)recordDisarmDistance:(NSString *)devId
                    finished:(void(^_Nullable)(void))finishedBlock
                       error:(void(^)(NSError* error))errorBlock;

@end

NS_ASSUME_NONNULL_END
