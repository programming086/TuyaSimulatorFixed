//
//  ThingCameraProtocol.h
//  Pods
//
//  Created by ThingInc on 2018/5/12.
//

#ifndef ThingCameraProtocol_h
#define ThingCameraProtocol_h

#import <UIKit/UIKit.h>

@class ThingSmartDeviceModel;

@protocol ThingCameraProtocol <NSObject>

/**
 获取摄像头Native面板
 @param devId 摄像头设备的devId
 @param uiName 摄像头设备的uiName，不同的uiName对应不同版本的面板
 */
- (UIViewController *)viewControllerWithDeviceId:(NSString *)devId uiName:(NSString *)uiName DEPRECATED_MSG_ATTRIBUTE("viewControllerWithDeviceId:uiName: is deprecated, use `getPanelViewControllerWithDeviceModel:initialProps:contextProps:completionHandler:` in `TYPanelProtocol` instead");

@optional

- (void)deviceGotoCameraNewPlayBackPanel:(ThingSmartDeviceModel *)deviceModel;

- (void)deviceGotoCameraCloudStoragePanel:(ThingSmartDeviceModel *)deviceModel;

- (void)deviceGotoCameraMessageCenterPanel:(ThingSmartDeviceModel *)deviceModel;

- (void)deviceGotoPhotoLibrary:(ThingSmartDeviceModel *)deviceModel;

@end

#endif /* ThingCameraProtocol_h */
