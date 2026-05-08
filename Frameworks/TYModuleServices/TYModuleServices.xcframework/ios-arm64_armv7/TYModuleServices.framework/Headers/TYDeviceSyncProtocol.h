//
//  TYDeviceSyncProtocol.h
//  TYDeviceSyncModule
//
//  Created by Misaka on 2018/11/9.
//  Copyright © 2018 misakatao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYDeviceSyncProtocol <NSObject>

typedef NS_ENUM(NSInteger, TYDeviceSyncControlState) {
    TYDeviceSyncControlStateNone = 0,          // 设备Bean不存在
    TYDeviceSyncControlStateSupport,           // 支持多控关联
    TYDeviceSyncControlStateNotSupport,        // 不支持多控关联
};

/**
 跳转到多控关联设备关联页面
 
 @param devId 主设备的设备ID
 
 @result TYDeviceSyncControlState 主设备的多控关联状态
 */
- (TYDeviceSyncControlState)gotoMultiControl:(NSString *)devId;

/**
 判断当前主设备是否支持多控关联
 
 @param devId 主设备的设备ID
 
 @result BOOL 主设备是否支持多控关联
 */
- (BOOL)isSupportMultiControl:(NSString *)devId;

/**
 跳转到关联设备中心

 @param devId 主设备的 devId
 */
- (void)gotoDeviceSyncListViewControllerWithDevId:(NSString *)devId;

/**
 跳转到多控关联设备中心

 @param devId 设备的 devId
 */
- (void)gotoDeviceBindViewControllerWithDevId:(NSString *)devId;

@end

NS_ASSUME_NONNULL_END
