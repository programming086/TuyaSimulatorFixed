//
//  ThingDiyHomeExtention.h
//  ThingSmartDeviceKit
//
//  Created by wzm on 2024/3/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDiyHomeExtention : ThingSmartRequest

/// 获取家庭下有隐藏扩展属性的设备、群组列表
/// - Parameters:
///   - gid: 家庭ID
///   - success: 成功回调
///   - failure: 失败回调
- (void)diyHomeFetchHiddenItemsWithGID:(long long)gID
                               success:(void (^_Nullable)(NSArray<NSString *> * deviceIds,
                                                          NSArray<NSString *> * groupIds))success
                               failure:(ThingFailureError _Nullable)failure;


/// 修改家庭下 设备、群组 的隐藏扩展属性
/// - Parameters:
///   - gid: 家庭ID
///   - deviceIds: 设备列表
///   - groupIds: 群组列表
///   - hidden: 是否隐藏
///   - success: 成功回调
///   - failure: 失败回调
- (void)diyHomeModifyHiddenItemsWithGID:(long long)gID
                              deviceIds:(nullable NSArray<NSString *> *)deviceIds
                               groupIds:(nullable NSArray<NSString *> *)groupIds
                                 hidden:(BOOL)hidden
                                success:(ThingSuccessHandler _Nullable)success
                                failure:(ThingFailureError _Nullable)failure;
@end

NS_ASSUME_NONNULL_END
