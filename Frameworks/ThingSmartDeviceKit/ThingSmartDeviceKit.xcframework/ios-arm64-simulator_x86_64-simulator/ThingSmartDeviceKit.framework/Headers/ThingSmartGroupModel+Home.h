//
//  ThingSmartGroupModel+Home.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartGroupModel (Home)

/// 根据GroupID获取当前的GroupModel
/// - Parameter GroupID: GroupID String类型
+ (ThingSmartGroupModel *)groupModelWithGroupID:(NSString *)groupID;

@end

NS_ASSUME_NONNULL_END
