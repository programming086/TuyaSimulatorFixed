//
//  TYDeviceSyncPlugAPI.h
//  TYDeviceSyncPlugAPI
//
//  Created by 萧然 on 2022/5/25.
//

#ifndef TYDeviceSyncPlugAPI_h
#define TYDeviceSyncPlugAPI_h

NS_ASSUME_NONNULL_BEGIN

@protocol TYDeviceSyncProtocol <NSObject>

#pragma  mark - bizbundle API

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

#pragma  mark - 双控关联
/**
 设备是否支持双控关联

 @param devId 主设备的 devId
 */
- (BOOL)isDeviceSupportDoubleControlWithDevId:(NSString *)devId;

/**
 跳转到双控关联设备中心

 @param devId 主设备的 devId
 */
- (void)gotoDeviceSyncListViewControllerWithDevId:(NSString *)devId;

#pragma  mark - 多控关联
/**
 设备是否支持多控关联

 @param devId 主设备的 devId
 */
- (BOOL)isDeviceSupportMultiControlWithDevId:(NSString *)devId;

/**
 跳转到多控关联设备中心

 @param devId 设备的 devId
 */
- (void)gotoDeviceBindViewControllerWithDevId:(NSString *)devId;
   
#pragma  mark - 设备同步控制
/**
 设备是否支持设备同步控制

 @param devId 主设备的 devId
 */
- (BOOL)isDeviceSupportSyncControlWithDevId:(NSString *)devId;

/**
 跳转到设备同步控制

 @param devId 设备的 devId
 */
- (void)gotoDeviceSyncControControllerWithDevId:(NSString *)devId;

@end

NS_ASSUME_NONNULL_END

#endif /* TYDeviceSyncPlugAPI_h */
