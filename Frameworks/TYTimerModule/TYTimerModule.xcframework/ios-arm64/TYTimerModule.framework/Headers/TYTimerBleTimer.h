//
//  TYTimerBleTimer.h
//  TYTimerModule
//
//  Created by jesse on 2021/7/16.
//

#import <Foundation/Foundation.h>
#import "TYTimerBleTimerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// public 的 error domain
/// 蓝牙定时错误
extern NSErrorDomain const TYTimerBleTimerErrorDomain;

typedef NS_ENUM(NSInteger, TYTimerBleTimerErrorCode) {
    /// 【通道层】mqtt和蓝牙通道都不可达
    TYTimerBleTimerErrorCode_PiplelineUnreachable = 1,
    /// 【云端】云端设定失败
    TYTimerBleTimerErrorCode_Cloud,
    /// 【协议层】读取/设置/移除 设定定时任务失败
    TYTimerBleTimerErrorCode_Protocol,
    /// 【业务层】超时，超时时间：`TYTimerBleTimerImplErrorTimeout`
    TYTimerBleTimerErrorCode_Timeout,
    /// 【云端】云端获取定时执行时间错误
    TYTimerBleTimerErrorCode_CloudDate,
};

/// 蓝牙定时（根据 mqtt/ble 通道可用性选择“蓝牙定时”还是“设备定时”）
@interface TYTimerBleTimer : NSObject

- (instancetype)initWithParam:(TYBleTimerParameter *)param;

/// 获取定时列表
/// @param success success 定时模型
/// @param failure failure
- (void)getTimerListSuccess:(void(^)(NSArray<TYTimerModel *> *list))success
                    failure:(TYFailureError)failure;


/// 同步云端和设备的定时任务
/// 以云端为准，同步差异到设备
///
/// 返回云端的定时列表
/// @param success 同步完成的回调（返回云端定时列表）
/// @param failure 同步失败（1. 获取云端定时列表错误）
/// @note 与设备交互失败，也会当作 `success` 处理，并返回云端定时列表
- (void)syncTimerListSuccess:(void(^)(NSArray<TYTimerModel *> *list))success
                     failure:(TYFailureError)failure;


/// 同步云端和设备的定时任务（通过入参 `list`，不调用云端接口获取云端定时列表）
/// 以云端为准，同步差异到设备
///
/// @param list 云端定时列表
/// @param completion 同步完成的回调
///
/// @note 如果是设备定时，直接调用 `completion()` 返回
- (void)syncTimerListWithCloudList:(NSArray<TYTimerModel *> *)list
                        completion:(void(^)(void))completion;

/// 添加定时
/// @param model 定时模型
/// @param success success
/// @param failure failure
- (void)addTimerWithModel:(TYTimerModel *)model
                  success:(TYSuccessInt)success
                  failure:(TYFailureError)failure;


/// 更新定时
/// @param model 定时 model
/// @param success success
/// @param failure failure
- (void)updateTimerWithModel:(TYTimerModel *)model
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;


/// 更新定时开关
///
/// 【蓝牙定时】
/// 如果开关是关闭，会从设备删除定时（不走云端）
/// 如果开关是开启，会先同步开关状态到云端，再设置定时到设备
///
/// @param model 定时 model
/// @param status 开 YES， 关 NO
/// @param success success
/// @param failure failure
- (void)updateTimerStatusWithModel:(TYTimerModel *)model
                            status:(BOOL)status
                           success:(TYSuccessHandler)success
                           failure:(TYFailureError)failure;

/// 移除定时
/// @param model 定时 model
/// @param success success
/// @param failure failure
- (void)removeTimerWithModel:(TYTimerModel *)model
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;

/// 检查通道（MQTT/BLE）可用性
/// 优先 MQTT
/// @return YES 有一个通道在线，NO 没有一个在线
- (BOOL)checkPipelineOnline;

@property (nonatomic, readonly) TYBleTimerParameter *param;

- (void)configParam:(TYBleTimerParameter *)param;
/// YES 内部使用的是蓝牙定时
@property (nonatomic, readonly) BOOL isBleOnline;

@end
NS_ASSUME_NONNULL_END
