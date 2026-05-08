//
// ThingLampAreaFilterProtocol.h
// ThingLampModuleServices
//
// Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingAreaModel;

@protocol ThingLampAreaFilterProtocol <NSObject>

/// 区域筛选弹窗
/// @param title 弹窗顶部文案
/// @param bottomTitle 弹窗底部按钮文案
/// @param needDeviceCountShow 是否显示设备数量
/// @param needAllArea 是否显示全部区域
/// @param needUnassignedArea 是否显示未分区
/// @param needPublicArea 是否显示公共区域
/// @param size 弹窗大小
/// @param sourceViewController 弹窗源控制器
/// @param showCompletion 弹窗完成回调
/// @param callback 筛选完成回调
- (void)areaFilterWithTitle:(NSString *)title
                bottomTitle:(NSString *)bottomTitle
        needDeviceCountShow:(BOOL)needDeviceCountShow
                needAllArea:(BOOL)needAllArea
         needUnassignedArea:(BOOL)needUnassignedArea
             needPublicArea:(BOOL)needPublicArea
                       size:(CGSize)size
       sourceViewController:(UIViewController *)sourceViewController
             showCompletion:(void(^)(void))showCompletion
                   callback:(void(^)(NSArray<ThingLightingAreaModel *> *))callback;



/// 区域筛选弹窗
/// @param title 标题
/// @param requestButtonTitle 确认按钮标题
/// @param defaultAreas 默认选中区域
/// @param enabledFinalStage 是否开启只有在末级才能结束
/// @param enabledFinalStageTitle 末级提示
/// @param enabledDeviceCount 是否启用设备数量
/// @param enabledAllArea 是否启用所有区域
/// @param enabledUndistributedArea 是否启用未分配空间
/// @param enabledPubilcArea 是否启用公共空间
/// @param contentSize 内容大小
/// @param sourceViewController 弹窗控制器
/// @param completion 完成回调
/// @param didSelectCompletion 选中回调
- (void)areaFilterWithTitle:(NSString *)title
         requestButtonTitle:(NSString *)requestButtonTitle
               defaultAreas:(nullable NSArray<ThingLightingAreaModel*>*)defaultAreas
          enabledFinalStage:(BOOL)enabledFinalStage
     enabledFinalStageTitle:(NSString *)enabledFinalStageTitle
         enabledDeviceCount:(BOOL)enabledDeviceCount
             enabledAllArea:(BOOL)enabledAllArea
   enabledUndistributedArea:(BOOL)enabledUndistributedArea
          enabledPublicArea:(BOOL)enabledPubilcArea
                contentSize:(CGSize)contentSize
       sourceViewController:(UIViewController *)sourceViewController
              didCompletion:(void(^)(void))completion
                  didSelect:(void(^)(NSArray<ThingLightingAreaModel*>*))didSelectCompletion;

@end

NS_ASSUME_NONNULL_END
