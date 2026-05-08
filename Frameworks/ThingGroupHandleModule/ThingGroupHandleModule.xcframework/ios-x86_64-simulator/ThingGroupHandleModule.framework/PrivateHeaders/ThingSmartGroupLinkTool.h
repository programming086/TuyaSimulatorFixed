//
//  ThingSmartGroupLinkTool.h
//  ThingGroupHandleModule
//
//  Created by 尼诺 on 2021/10/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartGroupLinkTool : NSObject

#pragma mark - home 相关信息

+ (long long)getCurrentSpaceId;

+ (NSArray<ThingSmartDeviceModel*> *)deviceListForCurrentSpace;

+ (NSArray<ThingSmartGroupModel *> *)groupListForCurrentSpace;

+ (NSString *)getsubSpaceNameWithDevice:(ThingSmartDevice *)device;

#pragma mark - 可定制实现

+ (BOOL)gotoGroupPanel:(ThingSmartGroupModel *)group;

@end

NS_ASSUME_NONNULL_END
