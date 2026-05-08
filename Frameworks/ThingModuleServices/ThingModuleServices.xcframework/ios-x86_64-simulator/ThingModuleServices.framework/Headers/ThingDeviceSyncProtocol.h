//
//  ThingDeviceSyncProtocol.h
//  ThingDeviceSyncModule
//
//  Created by Misaka on 2018/11/9.
//  Copyright © 2018 misakatao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingDeviceSyncProtocol <NSObject>

typedef NS_ENUM(NSInteger, ThingDeviceSyncControlState) {
    ThingDeviceSyncControlStateNone = 0,          // 设备Bean不存在
    ThingDeviceSyncControlStateSupport,           // 支持多控关联
    ThingDeviceSyncControlStateNotSupport,        // 不支持多控关联
};

/**
 跳转到多控关联设备关联页面
 
 @param devId 主设备的设备ID
 
 @result ThingDeviceSyncControlState 主设备的多控关联状态
 */
- (ThingDeviceSyncControlState)gotoMultiControl:(NSString *)devId;

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
