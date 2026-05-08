//
//  TRCTPublicManager+Impl.h
//
//  Auto-Created on 2024/05/06.
//  Copyright © 2024年 Thing. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "TRCTPublicManager.h"
#import <ThingPanelContext/TRCTPanelContextModule.h>



/**
TRCTPublicManager

@version: 1.8.0-fix-scene-window.3
@platform: all
*/
@interface TRCTPublicManager (Impl) <TRCTPanelContextModule>


////////////////////////////////////////////////////////////////////////////////
// Thing RN Module Methods
////////////////////////////////////////////////////////////////////////////////

/**
battery

@available 1.0.0
@param callback 回调
*/
- (void)impl_battery:(RCTResponseSenderBlock)callback ;

/**
screenAlwaysOn

@available 1.0.0
@param isEnable 是否长亮
*/
- (void)impl_screenAlwaysOn:(BOOL)isEnable ;

/**
deviceIsCharging

@available 1.0.0
@param callback 回调
*/
- (void)impl_deviceIsCharging:(RCTResponseSenderBlock)callback ;

/**
getNetworkType

@available 1.0.0
@param callback 回调
*/
- (void)impl_getNetworkType:(RCTResponseSenderBlock)callback ;

/**
showLoading

@available 1.0.0
@param param loading框参数
*/
- (void)impl_showLoading:(NSDictionary*)param ;

/**
hideLoading

@available 1.0.0
*/
- (void)impl_hideLoading;

/**
back

@available 1.0.0
*/
- (void)impl_back;

/**
jumpTo

@available 1.0.0
@param url 路由地址
*/
- (void)impl_jumpTo:(NSString*)url ;

/**
openInnerH5

@available 1.1.4
@param url h5链接地址
@param param 业务参数
*/
- (void)impl_openInnerH5:(NSString*)url param:(NSDictionary*)param ;

/**
getMobileInfo

@available 1.0.0
@param callback 回调
*/
- (void)impl_getMobileInfo:(RCTResponseSenderBlock)callback ;

/**
bottomListDialog
从底部弹出的dialog

@available 1.0.0
@param param 弹框参数
@param selected 选中项
@param confirmCallback 确认
*/
- (void)impl_bottomListDialog:(NSArray*)param selected:(NSString*)selected confirmCallback:(RCTResponseSenderBlock)confirmCallback ;

/**
is24Hour
获取系统时间格式是否为24小时制

@available 1.0.0
@param callback 回调
*/
- (void)impl_is24Hour:(RCTResponseSenderBlock)callback ;

/**
showEditDialog
带编辑框的dialog

@available 1.0.0
@param title 标题
@param editString 内容
@param confirmCallback 确认
@param cancelCallback 取消
*/
- (void)impl_showEditDialog:(NSString*)title editString:(NSString*)editString confirmCallback:(RCTResponseSenderBlock)confirmCallback cancelCallback:(RCTResponseSenderBlock)cancelCallback ;

/**
shareMsg

@available 1.0.0
@param map 分享参数
*/
- (void)impl_shareMsg:(NSDictionary*)map ;

/**
simpleConfirmDialog
带标题的确认弹窗

@available 1.0.0
@param title 标题
@param msg 内容
@param confirmCallback 确认
@param cancelCallback 取消
*/
- (void)impl_simpleConfirmDialog:(NSString*)title msg:(NSString*)msg confirmCallback:(RCTResponseSenderBlock)confirmCallback cancelCallback:(RCTResponseSenderBlock)cancelCallback ;

/**
simpleTipDialog
简单的确认提示对话框

@available 1.0.0
@param msg 内容
@param confirmCallback 确认
*/
- (void)impl_simpleTipDialog:(NSString*)msg confirmCallback:(RCTResponseSenderBlock)confirmCallback ;

/**
getWiFiSsid

@available 1.0.0
@param callback 回调
*/
- (void)impl_getWiFiSsid:(RCTResponseSenderBlock)callback ;

/**
getNetType

@available 1.0.0
@param callback 回调
*/
- (void)impl_getNetType:(RCTResponseSenderBlock)callback ;

/**
设置屏幕亮度

@available 1.0.0
@param brightness 亮度值
*/
- (void)impl_screenBrightness:(double)brightness ;

/**
获取屏幕亮度

@available 1.0.0
@param callback 回调
*/
- (void)impl_getCurrentscreenBrightness:(RCTResponseSenderBlock)callback ;

/**
调用系统分享

@available 1.0.0
*/
- (void)impl_shareToSystem;

/**
开启监听 AEAudio

@available 1.0.0
*/
- (void)impl_startListening;

/**
停止监听 AEAudio

@available 1.0.0
*/
- (void)impl_stopListening;

/**
RN 侧获取是否展示红点。

@available 1.1.0
@param pid product id
@param groupId 群组 id，[null/""/"0"]都认为是非群组
@param completion 回调参数Bool类型，表示是否展示，true 展示红点
*/
- (void)impl_getRedPointVisibleForProduct:(NSString*)pid groupId:(NSString*)groupId completion:(RCTResponseSenderBlock)completion ;

/**
查询设备各种权限的授权状态

@available 1.1.3
@param type 定位服务：location.service（手机系统定位服务开关，2、3Android特有）0-关 1-开 2-GPS开、网络关 3-GPS关、网络开
定位：location
通知：notification
蓝牙：bluetooth
电池优化：ignore.battery.optimization（Android特有）
@param success 回调参数Int类型，0：未授权 1：已授权
*/
- (void)impl_getAuthorizationStatus:(NSString*)type success:(RCTResponseSenderBlock)success ;

/**
查询设备定位权限的授权细节

@available 1.1.3
@param success 回调参数Int类型, 0-5按照以下表示
0 不支持或不可用
1 用户从未进行过授权等处理，首次访问相应内容会提示用户进行授权
2 应用没有相关权限，且当前用户无法改变这个权限，比如:家长控制
3 用户拒绝
4 一直允许获取定位
5 在使用时允许定位
*/
- (void)impl_getAccurateLocationAuthorizationStatus:(RCTResponseSenderBlock)success ;

/**
通用跳转系统设置页面

@available 1.1.3
@param type App详情："scope.app"
系统蓝牙："scope.bluetooth"
系统WIFI："scope.wifi"
系统定位服务："scope.location"
系统网络设置："scope.wireless"（Android特有）
App通知设置页："scope.app.notification"（Android特有）
应用忽略电池优化："scope.app.ignore.battery.optimization"（Android特有）
系统电池优化设置页："scope.ignore.battery.optimization"（Android特有）
系统设置主页："scope.default"
默认停留在系统主设置页
*/
- (void)impl_openSystemSettingsPage:(NSString*)type ;

/**
校验web host 是否限制

@available 1.1.2
@param webHost 
@param callback 0 白名单 内部webview，1 黑名单，2灰名单 外部浏览器，-1 无黑白名单，无效查询
*/
- (void)impl_checkWebHost:(NSString*)webHost callback:(RCTResponseSenderBlock)callback ;



@end
