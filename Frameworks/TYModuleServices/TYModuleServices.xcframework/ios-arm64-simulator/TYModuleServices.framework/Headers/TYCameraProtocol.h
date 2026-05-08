//
//  TYCameraProtocol.h
//  Pods
//
//  Created by TuyaInc on 2018/5/12.
//

#ifndef TYCameraProtocol_h
#define TYCameraProtocol_h

#import <UIKit/UIKit.h>

@class TuyaSmartDeviceModel, TuyaSmartCameraDevice;

@protocol TYCameraProtocol <NSObject>

/**
是否需要 IPC 能力
@param deviceModel 设备模型

*/
- (BOOL)needCameraFeatures:(TuyaSmartDeviceModel *)deviceModel;

/**
 获取摄像头Native面板
 @param devId 摄像头设备的devId
 @param uiName 摄像头设备的uiName，不同的uiName对应不同版本的面板
 */
- (UIViewController *)viewControllerWithDeviceId:(NSString *)devId uiName:(NSString *)uiName;

/**
 收到门铃呼叫通知的时候，弹出呼叫页面
 @param devId 门铃设备的devId
 @param type 通知透传的消息中携带的 type 数据
 */
- (void)showCameraCallViewWithDevId:(NSString *)devId type:(NSString *)type;

- (void)dismissCameraFloatingView;

@optional

- (void)deviceGotoMultiPlayPanel:(TuyaSmartDeviceModel *)deviceModel;

- (void)deviceGotoCameraNewPlayBackPanel:(TuyaSmartDeviceModel *)deviceModel;

- (void)deviceGotoCameraCloudStoragePanel:(TuyaSmartDeviceModel *)deviceModel;

- (void)deviceGotoCameraMessageCenterPanel:(TuyaSmartDeviceModel *)deviceModel;

- (void)deviceGotoPhotoLibrary:(TuyaSmartDeviceModel *)deviceModel;

- (void)deviceGotoAlarmSettingPanel:(TuyaSmartDeviceModel *)deviceModel;

- (void)deviceGotoCameraNewPlayBackPanel:(TuyaSmartDeviceModel *)deviceModel withParams:(NSDictionary *)params;

- (void)deviceGotoCameraCloudStoragePanel:(TuyaSmartDeviceModel *)deviceModel withParams:(NSDictionary *)params;

- (void)device:(TuyaSmartDeviceModel *)deviceModel gotoPhotoLibraryWithParams:(NSDictionary *)params;

- (void)device:(TuyaSmartDeviceModel *)deviceModel gotoCameraDevicePhotoLibraryWithParams:(NSDictionary *)params;

- (void)device:(TuyaSmartDeviceModel *)deviceModel gotoCameraMessageCenterWithParams:(NSDictionary *)params;

- (void)deviceOpenFloatWindow:(TuyaSmartCameraDevice *)cameraDevice;

- (unsigned long long)allCameraDevicesAlbumFilesSize;

- (void)device:(NSString *)devId enableConnectOptimize:(BOOL)enable;

@end

#endif /* TYCameraProtocol_h */
