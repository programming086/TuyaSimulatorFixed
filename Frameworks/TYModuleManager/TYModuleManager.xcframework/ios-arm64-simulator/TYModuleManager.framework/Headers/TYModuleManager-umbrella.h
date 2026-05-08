#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "TYModuleApplicationBlueprint.h"
#import "TYModuleBaseBlueprint.h"
#import "TYModuleConfigBlueprint.h"
#import "TYModuleLaunchTaskBlueprint.h"
#import "TYModuleNotifyBlueprint.h"
#import "TYModuleRouteBlueprint.h"
#import "TYModuleServiceBlueprint.h"
#import "TYModuleTabBarBlueprint.h"
#import "TYModuleConfig.h"
#import "TYModuleMixBridge.h"
#import "TYModule.h"
#import "TYModuleCustomizeManager.h"
#import "TYModuleLifeCycleCallbackProtocol.h"
#import "TYModuleLinkedItem.h"
#import "TYModuleManager.h"
#import "TYModuleRegisterProtocol.h"
#import "UIViewController+Route.h"
#import "TYModuleHookInfo.h"
#import "TYModuleHookRegisterProtocol.h"
#import "TYModuleNotifyRegisterProtocol.h"
#import "TYModuleRouteRegisterProtocol.h"
#import "TYModuleServiceInfo.h"
#import "TYModuleServiceRegisterProtocol.h"
#import "TYTabBarControllerDataSource.h"
#import "TYTabBarControllerDelegate.h"
#import "TYTabBarControllerProtocol.h"
#import "TYTabBarCustomButton.h"
#import "TYModuleTabBarStyleProtocol.h"
#import "TYModuleTabRegisterProtocol.h"
#import "TYTabBarCustomBadgeProtocol.h"
#import "TYTabItemAttribute+Private.h"
#import "TYTabItemAttribute.h"
#import "TYLaunchTaskProtocol.h"
#import "TYModuleLaunchTaskRegisterProtocol.h"

FOUNDATION_EXPORT double TYModuleManagerVersionNumber;
FOUNDATION_EXPORT const unsigned char TYModuleManagerVersionString[];

