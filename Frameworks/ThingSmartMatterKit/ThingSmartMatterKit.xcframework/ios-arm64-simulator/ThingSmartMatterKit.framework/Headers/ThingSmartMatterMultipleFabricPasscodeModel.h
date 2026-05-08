
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The Model used for Matter Multiple Fabric Flow.
///
/// - Use `-getMultipleFabricPasscodeCompletion:` or `-getMultipleFabricPasscodeForceRefreshCompletion` to get this model.
/// - Use `-sendEnhancedCommissioningCommandWithFabricPasscodeModel:success:failure:` to open ECM pairing window.
@interface ThingSmartMatterMultipleFabricPasscodeModel : NSObject

/// Avaliable fabric count.
@property (nonatomic, assign) NSUInteger limitCount;
/// Setup Code. (000000001-99999998)
@property (nonatomic, assign) NSUInteger passcode;
/// PBKDF Iterations. (1000~100000)
@property (nonatomic, assign) NSUInteger iteration;
/// passcode expired time
@property (nonatomic, assign) NSUInteger expired;
/// The window open timeout. 180 s ~ 900 s.
@property (nonatomic, assign) NSUInteger duration;
/// Device discriminator. (0x000-0xfff)
@property (nonatomic, assign) NSUInteger discriminator;
/// Pass code version.
@property (nonatomic, assign) NSUInteger version;
/// Matter vendor id. (aka: vid)
@property (nonatomic, strong) NSNumber *vendorId;
/// Matter product id. (aka: pid)
@property (nonatomic, strong) NSNumber *pid;
/// Device discovery capability.
@property (nonatomic, assign) NSUInteger discoveryCapabilities;

@end

NS_ASSUME_NONNULL_END
