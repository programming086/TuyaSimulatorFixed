//
//  TYRegisterRouterProtocol.h
//  TYAnnotationFoundation
//
//  Created by Storm on 2022/2/6.
//

#import "TYBaseAnnotation.h"

@protocol TYRegisterAPIProtocol <NSObject>

//协议优先级，默认是EAnnotationPriorityBase（0）
+ (NSNumber *)APIPriority:(NSString *)api;//EAnnotationPriority

@end
