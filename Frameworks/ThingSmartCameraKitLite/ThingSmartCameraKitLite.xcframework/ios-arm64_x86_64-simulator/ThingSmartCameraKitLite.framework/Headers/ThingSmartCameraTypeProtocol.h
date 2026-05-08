//
//  ThingSmartCameraTypeProtocol.h
//  ThingSmartCameraKitLite
//
//  Created by MokZF on 2025/1/6.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import "ThingSmartCameraKitLite.h"

typedef NS_ENUM(NSUInteger, ThingSmartCameraVisualType) {
    ThingSmartCameraVisualTypeConnect = 0,
    ThingSmartCameraVisualTypeDicConnect,
    ThingSmartCameraVisualTypeStartPreview,
    ThingSmartCameraVisualTypeStopPreview
};


@protocol ThingSmartCameraTypeProtocol <NSObject>

@optional

/// connect
- (void)connect;

/// start preview
- (void)startPreview;

/// stop preview
- (void)stopPreview;

/// disconnect
- (void)disconnect;

/// set video mute
/// - Parameter mute: mute
- (void)updateMute:(BOOL)mute;

/// receive mqtt message
/// - Parameter messsage: message
- (void)didReceiveMqttMessage:(NSString *)messsage;

@end


@protocol ThingSmartCameraVirsualDelegate <NSObject>

@optional
/// Them camera did connected
/// @param camera camera
- (void)cameraDidConnected:(id<ThingSmartCameraTypeProtocol>)camera;

/// The camera disconnect
/// @param camera camera
/// @param errorCode error code
- (void)cameraDisconnected:(id<ThingSmartCameraTypeProtocol>)camera specificErrorCode:(NSInteger)errorCode;

/// The camera did begin preivew
/// @param camera camera
- (void)cameraDidBeginPreview:(id<ThingSmartCameraTypeProtocol>)camera;

/// The camera did stop live video.
/// @param camera camera
- (void)cameraDidStopPreview:(id<ThingSmartCameraTypeProtocol>)camera;

/// The operate did occurred error
/// @param camera camera
/// @param errCode error code
/// @param type opera type
- (void)camera:(id<ThingSmartCameraTypeProtocol>)camera didOccurredError:(NSInteger)errCode type:(ThingSmartCameraVisualType)type;

/// Did Receive YUV data form deivce
/// @param cameraDevice camera device
/// @param sampleBuffer YUV Data
/// @param videoFrameInfo Video frame infomation
- (void)camera:(id<ThingSmartCameraTypeProtocol>)cameraDevice didVideoFrameRecvedWithSampleBuffer:(CMSampleBufferRef)sampleBuffer videoFrameInfo:(ThingSmartVideoFrameInfo)videoFrameInfo;
@end
