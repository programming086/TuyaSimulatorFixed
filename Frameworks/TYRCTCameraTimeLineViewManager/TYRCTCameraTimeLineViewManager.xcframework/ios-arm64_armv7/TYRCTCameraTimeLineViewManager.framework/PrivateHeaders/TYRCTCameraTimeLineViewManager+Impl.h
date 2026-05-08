//
//  TYRCTCameraTimeLineViewManager+Impl.h
//
//  Auto-Created on 2021/05/28.
//  Copyright © 2021年 Tuya. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "TYRCTCameraTimeLineViewManager.h"
#import <TYPanelContext/TYRCTPanelContextModule.h>



/**
IPC

@version: 1.4.0-rc.2
@owner: fulang@tuya.com misaka@tuya.com lial@tuya.com chenbj@tuya.com
@platform: all
*/
@interface TYRCTCameraTimeLineViewManager (Impl) <TYRCTPanelContextModule>

/**
 * Return a view witch conform to protocol <TYRCTCameraTimeLineViewManagerViewProtocol>
 */
- (UIView *)view;


////////////////////////////////////////////////////////////////////////////////
// Tuya RN UI Component Property Setters
////////////////////////////////////////////////////////////////////////////////

/**
action 属性

@available 1.0.0
*/
- (void)impl_set_action:(NSInteger)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
playbackDay 回放日期

@available 1.0.0
*/
- (void)impl_set_playbackDay:(NSString*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
currentTime 当前时间

@available 1.0.0
*/
- (void)impl_set_currentTime:(NSString*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
orientation 设备方向

@available 1.0.0
*/
- (void)impl_set_orientation:(NSInteger)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
timePieceList 时间片数据

@available 1.0.0
*/
- (void)impl_set_timePieceList:(NSArray*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
背景颜色

@available 1.2.0
*/
- (void)impl_set_backColor:(NSString*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
长刻度线的颜色

@available 1.2.0
*/
- (void)impl_set_longScaleLineColor:(NSString*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
短刻度线的颜色

@available 1.2.0
*/
- (void)impl_set_shortScaleLineColor:(NSString*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
中间基线的颜色

@available 1.2.0
*/
- (void)impl_set_middleLineColor:(NSString*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
时间标签文字的颜色

@available 1.2.0
*/
- (void)impl_set_timeTextColor:(NSString*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;

/**
时间片数据源的绘制颜色

@available 1.2.0
*/
- (void)impl_set_timePiecesSourceColor:(NSString*)value forView:(__kindof UIView*)view withDefaultView:(__kindof UIView*)defaultView;


@end
