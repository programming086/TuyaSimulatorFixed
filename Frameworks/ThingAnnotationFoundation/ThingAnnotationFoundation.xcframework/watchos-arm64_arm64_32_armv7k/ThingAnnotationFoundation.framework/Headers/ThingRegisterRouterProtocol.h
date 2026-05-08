
#import "ThingBaseAnnotation.h"

@protocol ThingRegisterRouterProtocol <NSObject>

@optional
//The route processing function returns YES if it is considered processed, otherwise it uses the default logic.
//For example, if the logic for processing routes is very complex, you can implement the processing in this method and return YES, instead of using the default push implementation.
+ (BOOL)routerDistribute:(NSString *)router;

//Routing priority, default is EAnnotationPriorityBase (0)
+ (NSNumber *)routerPriority:(NSString *)router;

//Routing pre-judgment, when the conditions are met, returns YES, indicating processing, otherwise no processing
+ (BOOL)routerPrepose:(NSString *)router withParams:(NSDictionary *)params;
//{
//    return [query thing_safeObjectForKey:@"groupId"] > 0 ? YES : NO;
//}

//By default, the object VC is created with init, and you can customize initWithRouterParams to initialize and assign values
- (instancetype)initWithRouterParams:(NSDictionary *)params;

//Routing post-judgment, you can set some properties
+ (void)routerStposition:(id)vc withParams:(NSDictionary *)params;
//{
//    Vc.groupId = [query thing_safeObjectForKey:@"groupId"];
//    VC.dealBlock = params["XX"];
//}

//default is push，YES is present
+ (BOOL)isPresentVC:(NSString *)router;
//default YES
+ (BOOL)isAnimated:(NSString *)router;

@end
