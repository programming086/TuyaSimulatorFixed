//
//  TYRCTCameraTimeLineViewManager.h
//
//  Auto-Created on 2021/05/28.
//  Copyright © 2021年 Tuya. All rights reserved.
//


#if __has_include(<React/RCTViewManager.h>)
#import <React/RCTViewManager.h>
#else
#import "RCTViewManager.h"
#endif


/**
IPC

@version: 1.4.0-rc.2
@owner: fulang@tuya.com misaka@tuya.com lial@tuya.com chenbj@tuya.com
@platform: all
*/
@interface TYRCTCameraTimeLineViewManager : RCTViewManager


@end

@protocol TYRCTCameraTimeLineViewManagerViewProtocol <NSObject>

/**
更新 UI

@available 1.0.0
*/
@property (nonatomic, copy) RCTBubblingEventBlock onChange;

@end
