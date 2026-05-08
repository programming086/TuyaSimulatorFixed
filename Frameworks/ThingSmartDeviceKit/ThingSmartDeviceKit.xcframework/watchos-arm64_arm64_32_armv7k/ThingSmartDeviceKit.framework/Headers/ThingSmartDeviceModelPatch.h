//
//  ThingSmartDeviceModelPatch.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, ThingSmartDeviceModelPatchType) {
    ThingSmartDeviceModelPatchType_batch = 0,//来自首页batch接口
    ThingSmartDeviceModelPatchType_other = 1,
};

@protocol ThingSmartDeviceModelPatchProtocol <NSObject>

@optional

/// 补偿设备原始模型，注意，调用堆栈可能非主线程
/// - Parameter deviceModelMapList: 设备原始模型
- (nullable NSMutableArray<NSMutableDictionary *> *)patchDeviceModelMapList:(nullable NSMutableArray<NSMutableDictionary *> *)deviceModelMapList patchType:(ThingSmartDeviceModelPatchType)patchType;

/// 补偿产品原始模型，注意，调用堆栈可能非主线程
/// - Parameter productModelMapList: 产品原始模型
- (nullable NSMutableArray<NSMutableDictionary *> *)patchProductModelMapList:(nullable NSMutableArray<NSMutableDictionary *> *)productModelMapList patchType:(ThingSmartDeviceModelPatchType)patchType;

/// 补偿设备模型，注意，调用堆栈可能非主线程
/// - Parameter deviceModel: 设备模型
- (void)patchDeviceModel:(ThingSmartDeviceModel *)deviceModel patchType:(ThingSmartDeviceModelPatchType)patchType;
@end


/// 根据元素设备信息、产品信息，组装 DeviceModel ，提供定制补偿数据
@interface ThingSmartDeviceModelPatch : NSObject
+ (instancetype)shareInstance;

/// 添加补偿器
/// - Parameter patcher: 补偿器
- (void)addPatcher:(id<ThingSmartDeviceModelPatchProtocol>)patcher;

/// 删除补偿器
/// - Parameter patcher: 补偿器
- (void)removePatcher:(id<ThingSmartDeviceModelPatchProtocol>)patcher;

/// 构建 DeviceModel，逐个调用补偿器的 patchDeviceModelMapList: 和 patchProductModelMapList:，然后转化模型后再逐个调用补偿器的 patchDeviceModel:
/// - Parameters:
///   - deviceList: 原始设备模型
///   - productList: 原始产品模型
///   - checkProductVer: 是否需要校验设备模型和产品模型里的版本
///   - customBlock: 个性化数据补偿
+ (nullable NSArray<ThingSmartDeviceModel *> *)buildDeviceModelWithDeviceMapList:(nullable NSArray<NSDictionary *> *)deviceList
                                                                  productMapList:(nullable NSArray<NSDictionary *> *)productList
                                                                       patchType:(ThingSmartDeviceModelPatchType)patchType
                                                                 checkProductVer:(BOOL)checkProductVer
                                                                     customBlock:(void (^ _Nullable)(NSDictionary * srcDeviceMap,
                                                                                                     NSDictionary * srcDroductmap,
                                                                                                     NSMutableDictionary * newDeviceMap))customBlock;
@end

NS_ASSUME_NONNULL_END
