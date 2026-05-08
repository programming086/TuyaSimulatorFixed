
#import <Foundation/Foundation.h>

#import "ThingModuleServiceBlueprint.h"
#import "ThingModuleConfigBlueprint.h"
#import "ThingModuleRouteBlueprint.h"
#import "ThingModuleApplicationBlueprint.h"
#import "ThingModuleTabBarBlueprint.h"
#import "ThingModuleNotifyBlueprint.h"
#import "ThingModuleLaunchTaskBlueprint.h"

#import "ThingModuleRegisterProtocol.h"


#import "ThingModuleMixBridge.h"

#define Thing_ServiceImpl(prot) ((id<prot>)[ThingModule serviceOfProtocol:@protocol(prot)])

#define Thing_RouteService [ThingModule routeService]
#define Thing_ApplicationService [ThingModule applicationService]
#define Thing_TabService [ThingModule tabService]
#define Thing_NotifyService [ThingModule notifyService]
#define Thing_ConfigService [ThingModule configService]


extern ThingModuleServiceInfo  *_Nullable ThingModuleServiceInfoMake(Protocol* _Nonnull, Class _Nonnull);
/**
 * [V2] Creates an instance of ThingModuleServiceInfo.
 *
 * @param prot The protocol name.
 * @param cls The class name.
 *
 * @return A pointer to the ThingModuleServiceInfo instance.
 */
#ifndef ThingMMakeService
#define ThingMMakeService(prot,cls) ThingModuleServiceInfoMake(@protocol(prot),[cls class])
#endif


@interface ThingModule : NSObject

#pragma mark - Service

+ (nullable id)serviceOfProtocol:(nonnull Protocol *)protocol OBJC_DEPRECATED("Deprecated after version 2.0. Please use `serviceOfOptionalProtocol:` or `serviceOfRequiredProtocol:`");

+ (nullable id)serviceOfOptionalProtocol:(nonnull Protocol *)protocol;
+ (nullable id)serviceOfRequiredProtocol:(nonnull Protocol *)protocol;


+ (void)registService:(nonnull Class)implCls withProtocol:(nonnull Protocol *)protocol;

#pragma mark - Module
+ (nullable id)moduleImplOfClass:(nonnull Class)cls;

#pragma mark - CoreService
+ (nullable id<ThingModuleServiceBlueprint>)moduleService;
+ (nullable id<ThingModuleConfigBlueprint>)configService;
+ (nullable id<ThingModuleRouteBlueprint>)routeService;
+ (nullable id<ThingModuleApplicationBlueprint>)applicationService;
+ (nullable id<ThingModuleTabBarBlueprint>)tabService;
+ (nullable id<ThingModuleNotifyBlueprint>)notifyService;
+ (nullable id<ThingModuleLaunchTaskBlueprint>)taskService;

@end
