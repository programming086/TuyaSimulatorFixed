//
//  ThingPanelProtocol.h
//  ThingModuleServices
//
//  Created by ThingInc on 2018/4/13.
//

#ifndef ThingPanelProtocol_h
#define ThingPanelProtocol_h

#import <UIKit/UIKit.h>
@class ThingSmartDeviceModel;
@class ThingSmartGroupModel;

NS_ASSUME_NONNULL_BEGIN

static NSNotificationName const kNotificationPanelDidRemoveDevice = @"kNotificationPanelDidRemoveDevice";///<  面板监听调用设备移除接口成功的消息通知

@protocol ThingPanelProtocol <NSObject>

/**
 * 清除面板缓存
 */
- (void)cleanPanelCache;

/**
 * 跳转面板，push 的方式
 *
 * @param deviceModel 设备模型
 * @param groupModel 群组模型
 * @param initialProps  自定义初始化参数，会以 'extraInfo' 为 key 设置进 RN 应用的 initialProps 中
 * @param contextProps  自定义面板上下文，会以 'extraInfo' 为 key 设置进 Panel Context 中
 * @param completion 完成跳转后的结果回调
 */
- (void)gotoPanelViewControllerWithDevice:(nullable ThingSmartDeviceModel *)deviceModel
                                    group:(nullable ThingSmartGroupModel *)groupModel
                             initialProps:(nullable NSDictionary *)initialProps
                             contextProps:(nullable NSDictionary *)contextProps
                               completion:(void(^ _Nullable)(NSError * _Nullable error))completion __deprecated_msg("Use -[TYPanelProtocol getPanelViewControllerWithDeviceModel:initialProps:contextProps:completionHandler:] or -[TYPanelProtocol getPanelViewControllerWithGroupModel:initialProps:contextProps:completionHandler:] instead");

/**
 * 跳转面板，present 的方式
 *
 * @param deviceModel 设备模型
 * @param groupModel 群组模型
 * @param initialProps  自定义初始化参数，会以 'extraInfo' 为 key 设置进 RN 应用的 initialProps 中
 * @param contextProps  自定义面板上下文，会以 'extraInfo' 为 key 设置进 Panel Context 中
 * @param completion 完成跳转后的结果回调
 */
- (void)presentPanelViewControllerWithDevice:(nullable ThingSmartDeviceModel *)deviceModel
                                       group:(nullable ThingSmartGroupModel *)groupModel
                                initialProps:(nullable NSDictionary *)initialProps
                                contextProps:(nullable NSDictionary *)contextProps
                                  completion:(void (^ _Nullable)(NSError * _Nullable error))completion __deprecated_msg("Use -[TYPanelProtocol getPanelViewControllerWithDeviceModel:initialProps:contextProps:completionHandler:] or -[TYPanelProtocol getPanelViewControllerWithGroupModel:initialProps:contextProps:completionHandler:] instead");

/**
 * 获取面板控制器
 *
 * @param deviceModel 设备模型
 * @param groupModel 群组模型
 * @param initialProps  自定义初始化参数，会以 'extraInfo' 为 key 设置进 RN 应用的 initialProps 中
 * @param contextProps  自定义面板上下文，会以 'extraInfo' 为 key 设置进 Panel Context 中
 * @param completionHandler 回调返回视图控制器
 */
- (void)getPanelViewControllerWithDeviceModel:(nullable ThingSmartDeviceModel *)deviceModel
                                   groupModel:(nullable ThingSmartGroupModel *)groupModel
                                 initialProps:(nullable NSDictionary *)initialProps
                                 contextProps:(nullable NSDictionary *)contextProps
                            completionHandler:(void (^ _Nullable)(__kindof UIViewController * _Nullable panelViewController, NSError * _Nullable error))completionHandler __deprecated_msg("Use -[TYPanelProtocol getPanelViewControllerWithDeviceModel:initialProps:contextProps:completionHandler:] or -[TYPanelProtocol getPanelViewControllerWithGroupModel:initialProps:contextProps:completionHandler:] instead");

/**
 * 获取设备面板控制器
 *
 * @param deviceModel 设备模型
 * @param initialProps  自定义初始化参数，会以 'extraInfo' 为 key 设置进 RN 应用的 initialProps 中
 * @param contextProps  自定义面板上下文，会以 'extraInfo' 为 key 设置进 Panel Context 中
 * @param completionHandler 回调返回视图控制器
 */
- (void)getPanelViewControllerWithDeviceModel:(ThingSmartDeviceModel *)deviceModel
                                 initialProps:(nullable NSDictionary *)initialProps
                                 contextProps:(nullable NSDictionary *)contextProps
                            completionHandler:(void (^ _Nullable)(__kindof UIViewController * _Nullable panelViewController, NSError * _Nullable error))completionHandler;

/**
 * 获取群组面板控制器
 *
 * @param groupModel 群组模型
 * @param initialProps  自定义初始化参数，会以 'extraInfo' 为 key 设置进 RN 应用的 initialProps 中
 * @param contextProps  自定义面板上下文，会以 'extraInfo' 为 key 设置进 Panel Context 中
 * @param completionHandler 回调返回视图控制器
 */
- (void)getPanelViewControllerWithGroupModel:(ThingSmartGroupModel *)groupModel
                                initialProps:(nullable NSDictionary *)initialProps
                                contextProps:(nullable NSDictionary *)contextProps
                           completionHandler:(void (^ _Nullable)(__kindof UIViewController * _Nullable panelViewController, NSError * _Nullable error))completionHandler;
/**
 * RN 版本号
 */
- (NSString *_Nonnull)rnVersionForApp;

@end
NS_ASSUME_NONNULL_END

#endif /* ThingPanelProtocol_h */
