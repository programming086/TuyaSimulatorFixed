
#import "ThingEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 The ThingEncryptAnimatedImage protocol declares the required methods for animated image
 display with ThingEncryptAnimatedImageView.
 
 Subclass a UIImage and implement this protocol, so that instances of that class
 can be set to ThingEncryptAnimatedImageView.image or ThingEncryptAnimatedImageView.highlightedImage
 to display animation.
 
 */
@protocol ThingEncryptAnimatedImage <NSObject>

@required
/// Total animated frame count.
/// If the frame count is less than 1, then the methods below will be ignored.
- (NSUInteger)animatedImageFrameCount;

/// Animation loop count, 0 means infinite looping.
- (NSUInteger)animatedImageLoopCount;

/// Bytes per frame (in memory). It may used to optimize memory buffer size.
- (NSUInteger)animatedImageBytesPerFrame;

/// Returns the frame image from a specified index.
/// This method may be called on background thread.
/// @param index  Frame index (zero based).
- (nullable UIImage *)animatedImageFrameAtIndex:(NSUInteger)index;

/// Returns the frames's duration from a specified index.
/// @param index  Frame index (zero based).
- (NSTimeInterval)animatedImageDurationAtIndex:(NSUInteger)index;

@optional
/// A rectangle in image coordinates defining the subrectangle of the image that
/// will be displayed. The rectangle should not outside the image's bounds.
/// It may used to display sprite animation with a single image (sprite sheet).
- (CGRect)animatedImageContentsRectAtIndex:(NSUInteger)index;

@end

#if Thing_EI_UIKIT

typedef NS_ENUM(NSInteger, ThingEncryptImageRotation) {
    ThingEncryptImageRotation0 = 0,
    ThingEncryptImageRotation90 = 90,
    ThingEncryptImageRotation180 = 180,
    ThingEncryptImageRotation270 = 270,
};

@interface ThingEncryptAnimatedImageView : UIImageView

/**
 If the image has more than one frame, set this value to `YES` will automatically
 play/stop the animation when the view become visible/invisible.
 
 The default value is `YES`.
 */
@property (nonatomic) BOOL autoPlayAnimatedImage;

/**
 Index of the currently displayed frame (index from 0).
 
 Set a new value to this property will cause to display the new frame immediately.
 If the new value is invalid, this method has no effect.
 
 You can add an observer to this property to observe the playing status.
 */
@property (nonatomic) NSUInteger currentAnimatedImageIndex;

/**
 Whether the image view is playing animation currently.
 
 You can add an observer to this property to observe the playing status.
 */
@property (nonatomic, readonly) BOOL currentIsPlayingAnimation;

/**
 The animation timer's runloop mode, default is `NSRunLoopCommonModes`.
 
 Set this property to `NSDefaultRunLoopMode` will make the animation pause during
 UIScrollView scrolling.
 */
@property (nonatomic, copy) NSString *runloopMode;

/**
 The max size (in bytes) for inner frame buffer size, default is 0 (dynamically).
 
 When the device has enough free memory, this view will request and decode some or
 all future frame image into an inner buffer. If this property's value is 0, then
 the max buffer size will be dynamically adjusted based on the current state of
 the device free memory. Otherwise, the buffer size will be limited by this value.
 
 When receive memory warning or app enter background, the buffer will be released
 immediately, and may grow back at the right time.
 */
@property (nonatomic) NSUInteger maxBufferSize;

/**
 Setting `[UIImageView.image]` to a non-`nil` value clears out existing `animatedImage`.
 And vice versa, setting `animatedImage` will initially populate the `[UIImageView.image]`
 to its `posterImage` and then start animating.
 */
@property (nonatomic, strong) id<ThingEncryptAnimatedImage> animatedImage;

/**
 Property to control the rotation of the image. Need to be called before setting the image.
 */
@property (nonatomic, assign) ThingEncryptImageRotation imageRotation;

@end
#endif
NS_ASSUME_NONNULL_END

