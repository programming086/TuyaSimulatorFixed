
#import <UIKit/UIKit.h>
#import "ThingEncryptWebImageCompat.h"
#import "ThingEncryptAnimatedImageView.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingEncryptSpriteSheetImage : UIImage <ThingEncryptAnimatedImage>

/**
 Creates and returns an image object.
 
 @param image          The sprite sheet image (contains all frames).
 
 @param contentRects   The sprite sheet image frame rects in the image coordinates.
     The rectangle should not outside the image's bounds. The objects in this array
     should be created with [NSValue valueWithCGRect:].
 
 @param frameDurations The sprite sheet image frame's durations in seconds.
     The objects in this array should be NSNumber.
 
 @param loopCount      Animation loop count, 0 means infinite looping.
 
 @return An image object, or nil if an error occurs.
 */
- (nullable instancetype)initWithSpriteSheetImage:(UIImage *)image
                                     contentRects:(NSArray<NSValue *> *)contentRects
                                   frameDurations:(NSArray<NSNumber *> *)frameDurations
                                        loopCount:(NSUInteger)loopCount;

@property (nonatomic, readonly) NSArray<NSValue *> *contentRects;
@property (nonatomic, readonly) NSArray<NSValue *> *frameDurations;
@property (nonatomic, readonly) NSUInteger loopCount;

/**
 Get the contents rect for CALayer.
 See "contentsRect" property in CALayer for more information.
 
 @param index Index of frame.
 @return Contents Rect.
 */
- (CGRect)contentsRectForCALayerAtIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
