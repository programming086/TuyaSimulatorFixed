//
//  ThingCameraProtocol.h
//  Pods
//
//  Created by ThingInc on 2018/5/12.
//

#ifndef ThingRNCameraProtocol_h
#define ThingRNCameraProtocol_h

#import <UIKit/UIKit.h>

@protocol ThingRNCameraProtocol <NSObject>

/**
 获取摄像头RN面板
 当使用该协议方法获取摄像头RN面板时，请使用 `ThingPanelProtocol` 协议的 `getPanelViewControllerWithDeviceModel:initialProps:contextProps:completionHandler:` 方法
 @param devId 摄像头设备的devId
 */
- (UIViewController *)cameraRNPanelViewControllerWithDeviceId:(NSString *)devId;

@end

#endif /* ThingRNCameraProtocol_h */
