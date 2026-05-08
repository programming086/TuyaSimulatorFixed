
#import <Foundation/Foundation.h>
#import "ThingSmartDeviceModel+InductiveUnlock.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, UnlockStatus) {
    UnlockStatusTurnOn = 0,
    UnlockStatusTurnOff = 1,
};

NS_SWIFT_NAME(InductiveUnlockDelegate)
@protocol ThingSmartODInductiveUnlockDelegate <NSObject>

- (void)listenUnlockStatusCallback:(UnlockStatus)status;

@end

NS_SWIFT_NAME(InductiveUnlock)
@interface ThingSmartODInductiveUnlock : NSObject

@property (nonatomic, weak) id<ThingSmartODInductiveUnlockDelegate> delegate;

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/// get InductiveUnlockType, Including Cloud Capability Configuration Detection
/// - Parameters:
///   - devId: device ID
///   - completionBlock: completion callback
///   - errorBlock: error callback
- (void)getInductiveUnlockType:(NSString *)devId
                    completion:(void(^)(InductiveUnlockType type))completionBlock
                         error:(void(^)(NSError* error))errorBlock;

@end

NS_ASSUME_NONNULL_END
