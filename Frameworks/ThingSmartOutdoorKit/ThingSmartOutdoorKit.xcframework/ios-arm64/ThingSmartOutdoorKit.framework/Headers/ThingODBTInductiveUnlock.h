
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BTUnlockPairStatus) {
    BTUnlockPairStatusCancelParing = 0,
    BTUnlockPairStatusPublishBoardcast = 1,
    BTUnlockPairStatusPairedSuccess = 2,
    BTUnlockPairBindStatusSuccess = 3,
    BTUnlockPairBindStatusFailed = 4
};

@class ThingODBTInductiveUnlock;

NS_SWIFT_NAME(BTInductiveUnlockDelegate)
@protocol ThingODBTInductiveUnlockDelegate <NSObject>

- (void)btInductiveUnlock:(ThingODBTInductiveUnlock *)btInductiveUnlock deviceID:(NSString *)deviceID status:(BTUnlockPairStatus)status;

@optional
- (void)listenBTUnlockStatusCallback:(BTUnlockPairStatus)status DEPRECATED_MSG_ATTRIBUTE("use btInductiveUnlock:deviceID:pairStatus: instead.");
@end

NS_SWIFT_NAME(BTInductiveUnlock)
@interface ThingODBTInductiveUnlock : NSObject

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

- (void)addDelegate:(id<ThingODBTInductiveUnlockDelegate>)delegate;

- (void)removeDelegate:(id<ThingODBTInductiveUnlockDelegate>)delegate;
/**
 * @brief Get the {@link paired status} of device
 *
 * @param devId device id
 */
- (BOOL)checkPairedStatus:(NSString *)devId;

/**
 * @brief Turn on the inductive unlock
 *
 * @param devId device id
 * @param finishedBlock unlock result
 * @param errorBlock error message
 */
- (void)turnOnBTInductiveUnlock:(NSString *)devId
                       finished:(void(^_Nullable)(void))finishedBlock
                          error:(void(^)(NSError* error))errorBlock;

/**
 * @brief Turn off the inductive unlock
 *
 * @param devId device id
 * @param finishedBlock unlock result
 * @param errorBlock error message
 */
- (void)turnOffBTInductiveUnlock:(NSString *)devId
                        finished:(void(^_Nullable)(void))finishedBlock
                           error:(void(^)(NSError* error))errorBlock;

/**
 * @brief get the {@link unlock distance} of device
 *
 * @param devId device id
 */
- (NSUInteger)getInductiveUnlockDistance:(NSString *)devId;

/**
 * @brief Set the  {@link inductive unlock distance} of device
 *
 * @param devId device id
 * @param distance  inductive unlock distance
 * @param finishedBlock unlock result
 * @param errorBlock error message
 */
- (void)setInductiveUnlockDistance:(NSString *)devId
                          distance:(NSInteger)distance
                          finished:(void(^_Nullable)(void))finishedBlock
                             error:(void(^)(NSError* error))errorBlock;
@end

NS_ASSUME_NONNULL_END
