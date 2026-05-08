
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartCameraSDK : NSObject

@property (class, nonatomic, strong, readonly) ThingSmartCameraSDK *sharedInstance;

/// Debug mode, default is false. Verbose log will print into console if opened.
@property (nonatomic, assign) BOOL debugMode;

@end

NS_ASSUME_NONNULL_END
