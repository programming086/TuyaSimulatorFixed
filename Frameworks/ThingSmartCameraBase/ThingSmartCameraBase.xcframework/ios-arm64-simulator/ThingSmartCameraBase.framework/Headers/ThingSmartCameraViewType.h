
#import <Foundation/Foundation.h>

#import "ThingSmartVideoViewType.h"

@protocol ThingSmartCameraViewType;
@protocol ThingSmartCameraViewDelegate <NSObject>

- (void)didTapCameraView:(id<ThingSmartCameraViewType>)cameraView reponse:(id)reponse;

//response, NSDictionary, @{ zoomStatus scaleStatus currentVideoScale }
- (void)didZoomFreeCameraView:(id<ThingSmartCameraViewType>)cameraView reponse:(id)reponse;

@end

@protocol ThingSmartCameraViewType <ThingSmartVideoViewType>

@property (nonatomic, assign) int scaleMode;


@property (nonatomic, assign) BOOL isScalable;


@property (nonatomic, assign) float maxScaleFactor;


@property (nonatomic, assign) float scaleFactor;


@property (nonatomic, assign) float rotateZ;


@property (nonatomic, assign) BOOL enableFeatureTracking;


@property (nonatomic, assign) CGSize videoFrameSize;


@property (nonatomic, assign) BOOL isPTZControllable;

@property (nonatomic, strong) NSDictionary *rockerDirectionsParams;


@property (nonatomic, copy) NSDictionary *extParams;


@property (nonatomic, strong, readonly) id <ThingSmartVideoViewType> videoView;


@property (nonatomic, weak) id <ThingSmartCameraViewDelegate> delegate;

@end
