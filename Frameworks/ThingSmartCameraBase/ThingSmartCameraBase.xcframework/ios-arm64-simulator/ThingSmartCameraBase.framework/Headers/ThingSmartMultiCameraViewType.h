
#import <Foundation/Foundation.h>
#import "ThingSmartVideoExtInfoType.h"
#import "ThingSmartMultiCameraLocalizerViewType.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString * ThingMultiCameraScreenMode NS_STRING_ENUM;
FOUNDATION_EXTERN ThingMultiCameraScreenMode const ThingMultiCameraScreenModeShort;
FOUNDATION_EXTERN ThingMultiCameraScreenMode const ThingMultiCameraScreenModeFull;
FOUNDATION_EXTERN ThingMultiCameraScreenMode const ThingMultiCameraScreenModeLandscape;

typedef NSString * ThingMultiCameraLayoutStyle NS_STRING_ENUM;
FOUNDATION_EXTERN ThingMultiCameraLayoutStyle const ThingMultiCameraLayoutStylePiP;
FOUNDATION_EXTERN ThingMultiCameraLayoutStyle const ThingMultiCameraLayoutStyleTile;
FOUNDATION_EXTERN ThingMultiCameraLayoutStyle const ThingMultiCameraLayoutStyleGrid;
FOUNDATION_EXTERN ThingMultiCameraLayoutStyle const ThingMultiCameraLayoutStyleThumbnail;

typedef NS_ENUM(NSUInteger, ThingMultiCameraLensType) {
    ThingMultiCameraLensTypeBall = 0,
    ThingMultiCameraLensTypeBullet
};

typedef NS_ENUM(NSInteger, ThingSmartCameraVideoViewGestureDirection) {
    ThingSmartCameraVideoViewGestureDirectionNone = -1,
    ThingSmartCameraVideoViewGestureDirectionLeft = 0,
    ThingSmartCameraVideoViewGestureDirectionUp,
    ThingSmartCameraVideoViewGestureDirectionRight,
    ThingSmartCameraVideoViewGestureDirectionDown,
    ThingSmartCameraVideoViewGestureDirectionCenter,
};

typedef NSUInteger ThingMultiCameraVideoIndex;

// MARK: - delegate for video view
@protocol ThingSmartCameraVideoViewDelegate <NSObject>

@optional
- (void)cameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView onTap:(UITapGestureRecognizer *)recognizer;
- (void)cameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView onDoubleTap:(UITapGestureRecognizer *)recognizer;
- (void)cameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView onLongPress:(UILongPressGestureRecognizer *)recognizer;
- (void)cameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView onSwipe:(ThingSmartCameraVideoViewGestureDirection)direction isStop:(BOOL)isStop;
- (void)cameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView onZoomScaleChanged:(CGFloat)scale;
- (void)cameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView onZoomScaleChangedByGesture:(CGFloat)scale;
- (void)cameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView onRockerDirectionChanged:(ThingSmartCameraVideoViewGestureDirection)direction isStop:(BOOL)isStop;

@end

// MARK: - data source for video view
@protocol ThingSmartCameraVideoViewDataSource <NSObject>

@optional
- (NSArray<UIImage *> *)imagesForRockerUpInCameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView;
- (NSArray<UIImage *> *)imagesForRockerDownInCameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView;
- (NSArray<UIImage *> *)imagesForRockerLeftInCameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView;
- (NSArray<UIImage *> *)imagesForRockerRightInCameraVideoView:(UIView<ThingSmartVideoViewType> *)videoView;

@end

@protocol ThingSmartMultiCameraViewDelegate;
@protocol ThingSmartMultiCameraViewDataSource;
// MARK: - view type for multi camera view
@protocol ThingSmartMultiCameraViewType <NSObject>

@property (nonatomic, weak) id<ThingSmartMultiCameraViewDelegate> delegate;

@property (nonatomic, strong, readonly) ThingMultiCameraLayoutStyle currentLayoutStyle;
@property (nonatomic, strong, readonly) ThingMultiCameraScreenMode currentScreenMode;
@property (nonatomic, assign) ThingMultiCameraVideoIndex selectedVideoIndex;
@property (nonatomic, assign) BOOL enableLocalizer;

- (NSArray<id<ThingSmartVideoViewIndexPair>> *)videoViewIndexPairs;
- (NSArray<ThingMultiCameraLayoutStyle> *)layoutStylesOnCurrentScreenMode;
- (nullable ThingMultiCameraLayoutStyle)nextLayoutStyle;

- (BOOL)openFloatingWindow;
- (BOOL)closeFloatingWindow;
- (BOOL)exchangePIPWindows;

- (BOOL)switchScreenMode:(ThingMultiCameraScreenMode)screenMode;
- (BOOL)switchLayoutStyle:(ThingMultiCameraLayoutStyle)layoutStyle;

- (BOOL)isSupportLinkedLocalizer;
- (BOOL)showLinkedLocalizerWithShowTip:(BOOL)showTip;
- (BOOL)showLocalizerAtVideoIndex:(ThingMultiCameraVideoIndex)index showTip:(BOOL)showTip;

- (void)showLenNames:(BOOL)show animated:(BOOL)animated;
- (void)renderSelectedThumbnailWithPixelBuffer:(CVPixelBufferRef)pixelBuffer;

@end

// MARK: - delegate for multi camera view
@protocol ThingMultiCameraVideoInfo;
@protocol ThingSmartMultiCameraViewDelegate <ThingSmartMultiCameraLocalizerViewDelegate>

@optional
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onTap:(UITapGestureRecognizer *)recognizer withVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo;
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onDoubleTap:(UITapGestureRecognizer *)recognizer withVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo;
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onLongPress:(UILongPressGestureRecognizer *)recognizer withVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo;
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onSwipe:(ThingSmartCameraVideoViewGestureDirection)direction isStop:(BOOL)isStop withVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo;
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onZoomScaleChanged:(CGFloat)scale
    withVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo;
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onZoomScaleChangedByGesture:(CGFloat)scale withVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo;
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onLayoutStatusChangedTo:(ThingMultiCameraScreenMode)screenMode layoutStyle:(ThingMultiCameraLayoutStyle)layoutStyle;
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onSelectVideoWithInfo:(id<ThingMultiCameraVideoInfo>)videoInfo;
- (void)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView onRockerDirectionChanged:(ThingSmartCameraVideoViewGestureDirection)direction isStop:(BOOL)isStop withVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo;

@end

@protocol ThingSmartMultiCameraViewType;
// MARK: - data source for multi camera view
@protocol ThingSmartMultiCameraViewDataSource <ThingSmartMultiCameraLocalizerViewDataSource>

- (NSString *)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView videoNameWithVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo NS_SWIFT_NAME(multiCameraView(_:videoNameWithVideoInfo:));

@optional
- (UIColor *)multiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView selectedBorderColorWithVideoInfo:(id<ThingMultiCameraVideoInfo>)videoInfo NS_SWIFT_NAME(multiCameraView(_:selectedBorderColorAt:));
- (UIView<ThingSmartMultiCameraLocalizerViewType> *)customLocalizerViewForMultiCameraView:(UIView <ThingSmartMultiCameraViewType> *)multiCameraView NS_SWIFT_NAME(customLocalizerView(for:));

@end

// MARK: - video info for video view
@protocol ThingMultiCameraVideoInfo <NSObject>

@property (nonatomic, assign) ThingMultiCameraVideoIndex videoIndex;
@property (nonatomic, assign) ThingMultiCameraLensType lensType;
@property (nonatomic, assign) CGSize frameSize;

//if lensType is bullet, return false.
@property (nonatomic, assign) BOOL linkedBullet;

@property (nonatomic, assign) BOOL isPTZ;
@property (nonatomic, assign) BOOL isZoomable;
@property (nonatomic, assign) BOOL isLocalizerNode;
@property (nonatomic, copy, nullable) NSString *lenName;
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *supportedDirections;

@end

NS_ASSUME_NONNULL_END
