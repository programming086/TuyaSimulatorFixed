//
//  TYTimerManager.h
//  TYTimerModule
//
//  Created by 后主 on 2021/12/9.
//

#import <Foundation/Foundation.h>
@class TYTimerModel, TuyaSmartDeviceModel, TuyaSmartGroupModel;

NS_ASSUME_NONNULL_BEGIN

@interface TYTimerManager : NSObject

/// 打开定时列表
/// @param category 定时分类
/// @param repeat 0表示需要选择重复，1表示不需要
/// @param data dp 数据
/// {
///     "dpName": dp 点名称，string
///     "dpId": dp 点 id，string
///     "selected": dp 点默认值的 index，t.Integer
///     "rangeKeys": dp 点的值范围，Array<object>
///     "rangeValues": dp 点的显示数据范围，Array<string>
/// }
/// @param uiConfig 配置
/// {
///     "background": string，定时界面导航栏的背景颜色，十六进制，例如：FFFFFF
/// }
- (void)openTimerPageWithCategory:(NSString *)category repeat:(long)repeat data:(NSArray *)data uiConfig:(NSDictionary *)uiConfig devId:(NSString *)devId groupId:(NSString *)groupId;


/// 同步云端和设备的定时任务
/// @param category 定时分类
/// @param success 同步完成的回调
/// @param failure 同步失败
- (void)syncTimerListWithCategory:(NSString *)category devId:(NSString *)devId groupId:(NSString *)groupId success:(void (^)(NSArray<TYTimerModel *> * _Nonnull))success failure:(TYFailureError)failure;


/// 添加定时
/// @param model 定时模型
/// @param category 定时分类
/// @param success success
/// @param failure failure
- (void)addTimerWithModel:(TYTimerModel *)model category:(NSString *)category devId:(NSString *)devId groupId:(NSString *)groupId success:(TYSuccessInt)success failure:(TYFailureError)failure;


/// 更新定时
/// @param model 定时 model
/// @param success success
/// @param failure failure
- (void)updateTimerWithModel:(TYTimerModel *)model devId:(NSString *)devId groupId:(NSString *)groupId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// 更新定时开关
/// @param model 定时 model
/// @param status 开 YES， 关 NO
/// @param success success
/// @param failure failure
- (void)updateTimerStatusWithModel:(TYTimerModel *)model status:(BOOL)status devId:(NSString *)devId groupId:(NSString *)groupId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// 移除定时
/// @param model 定时 model
/// @param success success
/// @param failure failure
- (void)removeTimerWithModel:(TYTimerModel *)model devId:(NSString *)devId groupId:(NSString *)groupId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
