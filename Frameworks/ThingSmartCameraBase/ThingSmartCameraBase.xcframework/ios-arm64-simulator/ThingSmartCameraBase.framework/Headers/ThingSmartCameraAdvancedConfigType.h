
#import <Foundation/Foundation.h>
#import "ThingSmartCameraSplitInfoJsonDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCameraAdvancedConfig <NSObject>

@property (nonatomic, assign, readonly) BOOL isSupportedVideoSplitting;

@property (nonatomic, copy, readonly) NSString *cameraSplitVideoInfoJson;

@property (nonatomic, strong, readonly) thing_ipc_split_video_sum_info *split_video_sum_info;

@end

NS_ASSUME_NONNULL_END
