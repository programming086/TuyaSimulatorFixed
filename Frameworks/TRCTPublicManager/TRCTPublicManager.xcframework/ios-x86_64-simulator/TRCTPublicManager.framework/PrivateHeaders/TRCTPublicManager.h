//
//  TRCTPublicManager.h
//
//  Auto-Created on 2024/05/06.
//  Copyright © 2024年 Thing. All rights reserved.
//


#import <Foundation/Foundation.h>
#if __has_include(<React/RCTBridgeModule.h>)
#import <React/RCTBridgeModule.h>
#else
#import "RCTBridgeModule.h"
#endif
#if __has_include(<React/RCTEventEmitter.h>)
#import <React/RCTEventEmitter.h>
#else
#import "RCTEventEmitter.h"
#endif


/**
TRCTPublicManager

@version: 1.8.0-fix-scene-window.3
@platform: all
*/
@interface TRCTPublicManager : RCTEventEmitter


/**
App 进入后台（安卓逻辑为页面消失）

@available 1.0.0
@param body nil
*/
- (void)sendEvent_enterBackgroundEvent:(NSDictionary *)body;

/**
App 进入前台（安卓逻辑为页面出现）

@available 1.0.0
@param body nil
*/
- (void)sendEvent_enterForegroundEvent:(NSDictionary *)body;

/**
网络状态变化

@available 1.0.0
@param body { "state":1 }
*/
- (void)sendEvent_networkStateChange:(NSDictionary *)body;

/**
添加家庭成员

@available 1.0.0
@param body 结构：
{ "homeId":homeId, "nickName":nickName, "role":role, "memberId":memberId, "headPic":headPic, "account":account }
失败情况：{ "error":errorMsg }
*/
- (void)sendEvent_addMember:(NSDictionary *)body;

/**
关联账号

@available 1.0.0
@param body 结构：
{ "id":memberId, "countryCode":countryCode, "userAccount":userAccount, "role":role }
失败情况：{ "error":errorMsg }
*/
- (void)sendEvent_linkMember:(NSDictionary *)body;

/**
二维码扫描

@available 1.0.0
@param body { "result":result, "source":source }
*/
- (void)sendEvent_scanResult:(NSDictionary *)body;

/**
音频变化

@available 1.0.0
@param body { "volume":8 }
*/
- (void)sendEvent_audioRecorderChange:(NSDictionary *)body;

/**
红点已读后，发送事件同步 RN 侧隐藏红点。

@available 1.1.0
@param body { "pid" : "xxxx", "visible" : false }
*/
- (void)sendEvent_onRedPointRefreshEvent:(NSDictionary *)body;

@end


