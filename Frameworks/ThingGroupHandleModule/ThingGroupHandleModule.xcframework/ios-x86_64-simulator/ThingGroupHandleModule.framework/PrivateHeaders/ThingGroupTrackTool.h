//
//  ThingGroupTrackTool.h
//  ThingGroupHandleModule
//
//  Created by yuheng on 2022/6/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const Thing_EVENT_SKYE_GROUP;

@interface ThingGroupTrackTool : NSObject

+ (void)trackEvent:(NSString *)eventName
        attributes:(NSDictionary *)attributes
             infos:(NSDictionary *)infos
     forIdentifier:(NSString *)identifier
          deviceId:(nullable NSString *)deviceId
           groupId:(nullable NSString *)groupId;

@end

NS_ASSUME_NONNULL_END
