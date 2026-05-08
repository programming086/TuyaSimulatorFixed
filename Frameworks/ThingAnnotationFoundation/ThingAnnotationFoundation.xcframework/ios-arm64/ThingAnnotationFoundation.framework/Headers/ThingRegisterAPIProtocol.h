
#import "ThingBaseAnnotation.h"

@protocol ThingRegisterAPIProtocol <NSObject>

//Protocol priority, default is EAnnotationPriorityBase (0)
+ (NSNumber *)APIPriority:(NSString *)api;//EAnnotationPriority

@end
