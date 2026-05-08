//
//  TYRegisterRouterProtocol.h
//  TYAnnotationFoundation
//
//  Created by Storm on 2022/2/6.
//

#import "TYBaseAnnotation.h"

@protocol TYRegisterLaunchProtocol <NSObject>

@optional

//路由优先级，默认是EAnnotationPriorityBase（0）
+ (NSNumber *)launchPriority;
+ (void)launchAnnotationTask;

@end
