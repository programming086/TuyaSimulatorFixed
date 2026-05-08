//
//  TYActivatorExternalExtensionProtocol.h
//  TYModuleServices
//
//  Created by huangjj on 2020/7/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol TYActivatorExternalExtensionProtocol <NSObject>

/**
 *  Back action form category View Controller
 *  Need to implement when additional operations are needed
 */
- (BOOL)categoryViewControllerCustomBackAction;

///  Go to custom View Controller from different pages
///  Need to implement when additional operations are needed
///  配网完成页面点击跳转至自定义页面,默认为跳转首页-打开设备面板
///  @param userInfo 可传字段
///      1. 是否为虚拟设备：isVirtualDevice: NSNumber，不传则表示真实设备
///      2. 设备数组：deviceArray: [TYActivatorResultModel]
///      3. 设备添加失败的数量：failureDeviceCount: NSNumber
///      4. 设备添加失败的错误提示：failureList: [TYSmartActivatorModel]
///      5. 设备ID数组：devIDList: [NSString]
/// @return YES 配网完成不回到首页；NO 默认行为（回到首页，只有一个设备情况下，会接着跳转到面板）
- (BOOL)gotoCustomVC:(NSDictionary *_Nullable)userInfo;


@end


