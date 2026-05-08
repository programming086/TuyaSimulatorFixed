//
//  ThingGroupNotificationHelper.h
//  ThingGroupHandleModule
//
//  Created by yuheng on 2022/9/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupNotificationHelper : NSObject

+ (void)groupCreateNotificationWithGroupId:(NSString *)groupId empty:(BOOL)empty;

@end

NS_ASSUME_NONNULL_END
