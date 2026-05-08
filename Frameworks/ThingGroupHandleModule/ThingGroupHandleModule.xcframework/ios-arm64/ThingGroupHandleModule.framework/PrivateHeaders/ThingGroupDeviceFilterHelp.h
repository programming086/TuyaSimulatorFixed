//
//  ThingGroupDeviceFilterHelp.h
//  ThingGroupHandleModule
//
//  Created by 后主 on 2023/11/30.
//

#import <Foundation/Foundation.h>
#import "ThingGroupHandleModuleConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupDeviceFilterHelp : NSObject

+ (void)getFilterConditionsWithGid:(long long)gid success:(void(^)(ThingGroupHandleModuleRoomRelation *))success failure:(void(^)(NSError *error))failure;

+ (ThingGroupHandleModuleRoom *)noRoom;

@end

NS_ASSUME_NONNULL_END
