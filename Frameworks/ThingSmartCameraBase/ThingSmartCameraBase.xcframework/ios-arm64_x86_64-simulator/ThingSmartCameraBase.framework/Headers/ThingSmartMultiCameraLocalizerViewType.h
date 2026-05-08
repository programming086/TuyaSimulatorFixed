
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartMultiCameraLocalizerViewDelegate, ThingSmartMultiCameraLocalizerViewDataSource;
@protocol ThingSmartMultiCameraLocalizerViewType <NSObject>

@property (nonatomic, weak) id<ThingSmartMultiCameraLocalizerViewDelegate> delegate;

- (void)showLocalizerWithShowTip:(BOOL)showTip;
- (void)hideLocalizer;

@end


@protocol ThingSmartMultiCameraLocalizerViewDelegate <NSObject>

@optional
/// this point's x & y is a percentage value between 0 and 100  in its superview
-(void)localizerView:(UIView<ThingSmartMultiCameraLocalizerViewType> *)localizerView onLocateAt:(CGPoint)point;

@end


@protocol ThingSmartMultiCameraLocalizerViewDataSource <NSObject>

@optional
- (UIColor *)colorForLocalizerDashLineView:(UIView<ThingSmartMultiCameraLocalizerViewType> *)localizerView NS_SWIFT_NAME(colorForLocalizerDashLineView(_:));
- (UIImage *)imageForLocalizerCrosshairView:(UIView<ThingSmartMultiCameraLocalizerViewType> *)localizerView NS_SWIFT_NAME(imageForLocalizerCrosshairView(_:));
- (CGFloat)lineWidthForLocalizerDashLineView:(UIView<ThingSmartMultiCameraLocalizerViewType> *)localizerView NS_SWIFT_NAME(lineWidthForLocalizerDashLineView(_:));
- (CGSize)sizeForLocalizerCrosshairImageView:(UIView<ThingSmartMultiCameraLocalizerViewType> *)localizerView NS_SWIFT_NAME(sizeForLocalizerCrosshairImageView(_:));
- (NSString *)tipMessageForLocalizerView:(UIView<ThingSmartMultiCameraLocalizerViewType> *)localizerView NS_SWIFT_NAME(tipMessageForLocalizerView(_:));
- (NSArray<NSNumber *> *)lineDashPatternForLocalizerDashLineView:(UIView<ThingSmartMultiCameraLocalizerViewType> *)localizerView NS_SWIFT_NAME(lineDashPatternForLocalizerDashLineView(_:));

@end

NS_ASSUME_NONNULL_END

