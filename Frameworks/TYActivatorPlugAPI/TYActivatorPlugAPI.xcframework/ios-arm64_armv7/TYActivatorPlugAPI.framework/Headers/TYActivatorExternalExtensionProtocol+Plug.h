//
//  TYActivatorExternalExtensionProtocol.h
//  TYModuleServices
//
//  Created by huangjj on 2020/7/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TYActivatorResultModel.h"

NS_ASSUME_NONNULL_BEGIN
@protocol TYActivatorExternalExtensionProtocol <NSObject>


@optional
/// Back action form category View Controller
/// Need to implement when additional operations are needed
- (BOOL)categoryViewControllerCustomBackAction;

/// Goto custom result dispaly view  配网成功结果展示页面
/// @param resultList list of networked devices
/// @param userInfo userInfo
/// 当前业务逻辑,自动发现部分成功即会跳转至结果展示页面,之后若仍需返回配网,可直接返回上一级, 其他情况返回逻辑自由处理
/// 若自动发现页面仍旧有部分设备未配网完成,userInfo = {@"hasUnactive" : @(1)}
- (void)gotoCustomResultPage:(NSArray<TYActivatorResultModel *> *_Nonnull)resultList userInfo:(NSDictionary * _Nullable)userInfo;


/// Update resultList, only EZ use
/// @param resultList new networked devices
- (void)updateResultLsit:(NSArray<TYActivatorResultModel *> *_Nullable)resultList;


/// Goto custom failure page 跳转至自定义失败反馈页面
/// @param sourceType sourceType 1:popwindow 2:manual
/// @param userInfo custom info
/// userinfo = @{@"linkMode":@(linkModeEZ),@"linkModel":linkModel,@"bluetoothModel",bluetoothModel,...}
- (void)gotoCustomFailurePage:(NSInteger)sourceType userInfo:(NSDictionary * _Nullable)userInfo;



///  Get the default serial index
///  Need to implement when additional operations are needed
///  自定义默认房间选择
- (NSInteger)getDefaultIndexOfDeviceResult;


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
NS_ASSUME_NONNULL_END

