
#import <Foundation/Foundation.h>
#import "ThingGroupDef.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupMakerHelper : NSObject

/// Return business type based on device ID
+ (ThingGroupBizType)groupBizTypeFromDeviceId:(NSString *)devId;

/// Return page type based on group ID
+ (ThingGroupBizType)groupBizTypeFromGroupId:(NSString *)groupId;

@end

NS_ASSUME_NONNULL_END
