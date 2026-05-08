#import <Foundation/Foundation.h>
#import "ThingCameraDefines.h"

/**
 * Configuration class for ThingMediaProcessOption
 */
@interface ThingMediaProcessOption : NSObject

@property (nonatomic, assign, readonly) CGSize targetSize; // Target size for processing. Only effective if useFirstVideoResolution is false.

@property (nonatomic, readonly) NSInteger targetWidth; // Target width for processing. Only effective if useFirstVideoResolution is false.
@property (nonatomic, readonly) NSInteger targetHeight; // Target height for processing. Only effective if useFirstVideoResolution is false.
@property (nonatomic, readonly) BOOL useFirstVideoResolution; // Whether to use the first video resolution. Overrides targetWidth and targetHeight if set to true.
@property (nonatomic, readonly) ThingRotateMode rotation; // Mode for rotation

// Chainable methods for configuration
- (ThingMediaProcessOption * (^)(CGSize targetSize))configurateTargetSize;
- (ThingMediaProcessOption * (^)(BOOL useFirstVideoResolution))configurateUseFirstVideoResolution;
- (ThingMediaProcessOption * (^)(ThingRotateMode rotation))configurateRotation;

// Factory method for creating an instance
+ (instancetype)configInstance;

@end
