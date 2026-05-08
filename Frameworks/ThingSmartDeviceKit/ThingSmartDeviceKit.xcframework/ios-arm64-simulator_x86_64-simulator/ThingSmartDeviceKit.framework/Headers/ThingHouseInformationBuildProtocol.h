//
//  ThingHouseInformationBuildProtocol.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingHIResultHandler)(void);

/// 全屋数据加载流程回调 后续整改预留
@protocol ThingHouseInformationCycleProtocol <NSObject>

@end

/// 全屋数据染色
@protocol ThingHouseInformationDyeProtocol <NSObject>


/// 第一阶段阻塞式的数据返回后的数据染色
/// @param dataList 返回请求ThingApiMergeModel数组
/// @param homeID 房间ID
/// @param result 结果回调
- (void)dyeProcessStage1:(NSArray *)dataList homeID:(long long)homeID result:(ThingHIResultHandler)result;

/// 第一阶段非阻塞式的数据返回后的数据染色
/// @param dataList 返回请求ThingApiMergeModel数组
/// @param homeID 房间ID
/// @param result 结果回调
- (void)dyeProcessStage2:(NSArray *)dataList homeID:(long long)homeID result:(ThingHIResultHandler)result;

@end

@protocol ThingHouseInformationBuildProtocol <ThingHouseInformationCycleProtocol, ThingHouseInformationDyeProtocol>

@end

NS_ASSUME_NONNULL_END
