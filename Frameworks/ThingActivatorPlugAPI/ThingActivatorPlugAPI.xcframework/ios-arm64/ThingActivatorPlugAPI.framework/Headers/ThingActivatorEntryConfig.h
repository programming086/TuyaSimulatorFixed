
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorEntryConfig : NSObject<NSCopying>

/// The ID of the space to which newly added devices will be assigned
@property (nonatomic, copy, nullable) NSNumber *spaceID;

/// Source view controller, return to this controller after completing operations
@property (nonatomic, strong, nullable) UIViewController *fromVC;

/// Default configuration
@property (class, nonatomic, strong, readonly) ThingActivatorEntryConfig *defaultConfig;
@end

NS_ASSUME_NONNULL_END
