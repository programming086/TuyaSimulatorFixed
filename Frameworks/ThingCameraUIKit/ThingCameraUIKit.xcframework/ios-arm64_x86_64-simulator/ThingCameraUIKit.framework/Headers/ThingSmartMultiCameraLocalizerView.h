
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartMultiCameraLocalizerViewType.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMultiCameraLocalizerView : UIView <ThingSmartMultiCameraLocalizerViewType>

@property (nonatomic, weak) id<ThingSmartMultiCameraLocalizerViewDataSource> dataSource;

@end

NS_ASSUME_NONNULL_END
