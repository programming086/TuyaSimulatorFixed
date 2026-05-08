//
//  ThingSmartCameraCloudDelegate.h
//  ThingSmartCameraKitLite
//
//  Created by MokZF on 2025/1/15.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <ThingCameraSDK/ThingCameraDefines.h>
#import "ThingSmartCameraKitLite.h"

@class ThingSmarCameraLiteCloudManager;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCameraCloudDelegate <NSObject>

/// receive cloud play back YUV data
/// - Parameters:
///   - player: player
///   - frameBuffer: YUV buffer
///   - frameInfo: frame info
- (void)cloudVideoPlayer:(ThingSmarCameraLiteCloudManager *)player didReceivedFrame:(CMSampleBufferRef)frameBuffer videoFrameInfo:(ThingSmartVideoFrameInfo)frameInfo;

/// cloud play load error callback
/// - Parameters:
///   - player: player
///   - message: error message
- (void)cloudVideoPlayer:(ThingSmarCameraLiteCloudManager *)player cloudDataloadFail:(const char *)message;


@end

NS_ASSUME_NONNULL_END
