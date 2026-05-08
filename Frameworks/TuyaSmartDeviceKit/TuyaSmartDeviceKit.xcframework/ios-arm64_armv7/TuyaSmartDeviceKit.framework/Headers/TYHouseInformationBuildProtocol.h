//
//  TYHouseInformationProtocol.h
//  TuyaSmartDeviceKit
//
//  Created by Hiraeth on 2022/2/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TYHIResultHandler)(void);

/// 全屋数据加载流程回调 后续整改预留
@protocol TYHouseInformationCycleProtocol <NSObject>

@end

/// 全屋数据染色
@protocol TYHouseInformationDyeProtocol <NSObject>


/// 第一阶段阻塞式的数据返回后的数据染色
/// @param dataList 返回请求TYApiMergeModel数组
/// @param homeID 房间ID
/// @param result 结果回调
- (void)dyeProcessStage1:(nullable NSArray *)dataList homeID:(long long)homeID result:(nullable TYHIResultHandler)result;

/// 第一阶段非阻塞式的数据返回后的数据染色
/// @param dataList 返回请求TYApiMergeModel数组
/// @param homeID 房间ID
/// @param result 结果回调
- (void)dyeProcessStage2:(nullable NSArray *)dataList homeID:(long long)homeID result:(nullable TYHIResultHandler)result;

@end

@protocol TYHouseInformationBuildProtocol <TYHouseInformationCycleProtocol, TYHouseInformationDyeProtocol>

@end

NS_ASSUME_NONNULL_END
