
#import <Foundation/Foundation.h>
#import "ThingMiniAppCoreProtocol.h"
#import "ThingMiniAppDebugProtocol.h"
#import "ThingMiniAppWidgetProtocol.h"
#import "ThingMiniAppInitialProtocol.h"
#import "ThingMiniAppDevelopProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingMiniAppClient : NSObject

/// core function for miniapp
+ (id<ThingMiniAppCoreProtocol>)coreClient;

/// debug function for miniapp
+ (id<ThingMiniAppDebugProtocol>)debugClient;

/// initial function for miniapp
+ (id<ThingMiniAppInitialProtocol>)initialClient;

/// widget function for miniapp
+ (id<ThingMiniAppWidgetProtocol>)widgetClient;

/// develop function for miniapp
+ (id<ThingMiniAppDevelopProtocol>)developClient;

@end

NS_ASSUME_NONNULL_END
