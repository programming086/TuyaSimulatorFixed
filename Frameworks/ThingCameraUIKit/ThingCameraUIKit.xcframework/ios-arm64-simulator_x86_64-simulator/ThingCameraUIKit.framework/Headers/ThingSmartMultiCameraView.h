
#import <UIKit/UIKit.h>
#import <ThingSmartCameraBase/ThingSmartMultiCameraViewType.h>
#import <ThingSmartCameraBase/ThingSmartCameraAdvancedConfigType.h>
#import "ThingSmartCameraVideoView.h"
#import "ThingSmartMultiCameraLocalizerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMultiCameraView : UIView <ThingSmartMultiCameraViewType>

@property (nonatomic, weak) id<ThingSmartMultiCameraViewDataSource> dataSource;

@property (nonatomic, assign) ThingSmartCameraVideoViewDoubleTapZoomMode doubleTapZoomMode;

@property (nonatomic, assign) BOOL enableSwipeGesture;
@property (nonatomic, assign, nullable) NSDictionary *rockerParams;

- (instancetype)initWithAdvancedConfig:(id<ThingSmartCameraAdvancedConfig>)advancedConfig;

- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
