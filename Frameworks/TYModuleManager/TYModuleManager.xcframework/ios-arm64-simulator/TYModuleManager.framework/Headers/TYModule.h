//
//  TYModule.h
//  TYModuleManager
//
//  Created by TuyaInc on 2018/8/28.
//

#import <Foundation/Foundation.h>

#import "TYModuleServiceBlueprint.h"
#import "TYModuleConfigBlueprint.h"
#import "TYModuleRouteBlueprint.h"
#import "TYModuleApplicationBlueprint.h"
#import "TYModuleTabBarBlueprint.h"
#import "TYModuleNotifyBlueprint.h"
#import "TYModuleLaunchTaskBlueprint.h"

#import "TYModuleRegisterProtocol.h"

// 一个用来提供涂鸦的Native方法的调用的类
#import "TYModuleMixBridge.h"

#define TY_ServiceImpl(prot) ((id<prot>)[TYModule serviceOfProtocol:@protocol(prot)])

#define TY_RouteService [TYModule routeService]
#define TY_ApplicationService [TYModule applicationService]
#define TY_TabService [TYModule tabService]
#define TY_NotifyService [TYModule notifyService]
#define TY_ConfigService [TYModule configService]


extern TYModuleServiceInfo  *_Nullable TYModuleServiceInfoMake(Protocol* _Nonnull, Class _Nonnull);
/**
 *【V2】创建 TYModuleServiceInfo 实例
 *
 * @param prot 协议名称
 * @param cls 类名
 *
 * @return TYModuleServiceInfo*
 */
#ifndef TYMMakeService
#define TYMMakeService(prot,cls) TYModuleServiceInfoMake(@protocol(prot),[cls class])
#endif


/**
 TYModule类主要用于提供一些快捷的方法，便于书写
 没有其它实质意义
 */
@interface TYModule : NSObject

#pragma mark - Service

+ (nullable id)serviceOfProtocol:(nonnull Protocol *)protocol OBJC_DEPRECATED("组件2.0 之后弃用。请使用 `serviceOfOptionalProtocol:` 或者 `serviceOfRequiedProtocol`");

+ (nullable id)serviceOfOptionalProtocol:(nonnull Protocol *)protocol;
+ (nullable id)serviceOfRequiredProtocol:(nonnull Protocol *)protocol;


+ (void)registService:(nonnull Class)implCls withProtocol:(nonnull Protocol *)protocol;

#pragma mark - Module
+ (nullable id)moduleImplOfClass:(nonnull Class)cls;

#pragma mark - CoreService
+ (nullable id<TYModuleServiceBlueprint>)moduleService;
+ (nullable id<TYModuleConfigBlueprint>)configService;
+ (nullable id<TYModuleRouteBlueprint>)routeService;
+ (nullable id<TYModuleApplicationBlueprint>)applicationService;
+ (nullable id<TYModuleTabBarBlueprint>)tabService;
+ (nullable id<TYModuleNotifyBlueprint>)notifyService;
+ (nullable id<TYModuleLaunchTaskBlueprint>)taskService;

@end
