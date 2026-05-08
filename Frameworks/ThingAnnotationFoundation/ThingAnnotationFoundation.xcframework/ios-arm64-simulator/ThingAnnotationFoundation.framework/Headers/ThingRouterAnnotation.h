
#import "ThingBaseAnnotation.h"
#import "ThingRegisterRouterProtocol.h"
#pragma mark ThingAnnotation

/*
 Route registration annotation, two parameters: 1. Route name 2. Processing VC
 If VC does not implement TYRegisterRouterProtocol, it means that the current route generates an IMPLVC by default for processing. Otherwise, TYRegisterRouterProtocol under IMPLVC will be called to select processing.
 Under what circumstances do you need to implement TYRegisterRouterProtocol?
 1. The route to be processed has some pre-judgment, for example, it will be processed only when certain conditions are met, otherwise the route will not be processed. At this time, the routerPreposing protocol method can be implemented.
 2. The route is not directly processed by VC, but by a certain method, then implement the routerDistribute protocol method and return YES
 Example: ThingRegisterRouterAnnotation(tp_login, ThingDebuggerNativeLoginViewController)
 */
#define ThingRegisterRouterAnnotation(Router, IMPLVC)    __ThingRouterAnnotation(Router,IMPLVC)

//More complex routing, similar to Router=thing://login
#define ThingRegisterRouterNameAnnotation(Name, Router, IMPLVC)    __ThingRouterNameAnnotation(Name, Router,IMPLVC)

//example：ThingRequireAPIAnnotation(tp_login)
#define ThingRequiredRouteAnnotation(Router)



#pragma mark ThingAnnotationIMPL
#define ThingRouterSectionName "__RouterSection"

typedef void(^registerRouter)(NSDictionary *params);
typedef void(^ThingAnnotationRegisterRouterBlock)(NSString *router, id vc);

extern NSMutableArray *getRouterSectionData(void);


typedef struct __attribute__((packed)) {
    const char * router;
    const char * viewcontroller;
} _ThingMachRegisterRouterStruct;

#define __ThingRouterAnnotation(Name,VC) \
static _ThingMachRegisterRouterStruct  __##Name __attribute__((used, section("__RouterSection, Router"))) = {\
#Name,\
#VC,\
};


#define __ThingRouterNameAnnotation(RouterName, Name, VC) \
static _ThingMachRegisterRouterStruct  __##RouterName __attribute__((used, section("__RouterSection, Router"))) = {\
Name,\
#VC,\
};








