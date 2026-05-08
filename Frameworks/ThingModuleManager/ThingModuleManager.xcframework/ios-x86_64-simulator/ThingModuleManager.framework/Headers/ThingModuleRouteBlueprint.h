
#import <Foundation/Foundation.h>

#import "ThingModuleRouteInterceptor.h"
#import "ThingModuleBaseBlueprint.h"
#import <ThingAnnotationFoundation/ThingAnnotationFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingModuleRouteInfo;

@protocol ThingModuleRouteBlueprint <ThingModuleBaseBlueprint>

/**
 * Registers a route for a specific module.
 *
 * The scheme, path, and query components of the route will be ignored.
 *
 * @param route The route string to register.
 * @param module The module associated with this route.
 */
- (void)registRoute:(NSString *)route forModule:(id)module;
- (void)unregistRoute:(NSString *)route;

- (void)registRoute:(NSString *)route inViewController:(Class)vc;

- (nullable id)moduleOfRoute:(NSString *)route;


- (BOOL)canOpenRoute:(NSString *)route;

/**
 * Opens a route with optional parameters.
 *
 * The scheme, path, and query components will be passed to the handler implementation.
 *
 * @param route The route string to open.
 * @param params An optional dictionary of parameters to pass to the handler.
 * @return YES if the route was successfully opened; NO otherwise.
 */
- (BOOL)openRoute:(NSString *)route withParams:(nullable NSDictionary *)params;

/**
 * Opens a route with optional parameters and a callback.
 *
 * The scheme, path, query, and callBack will be passed to the handler implementation.
 * Note: Because of integration with Flutter, the result in callBack must be serializable.
 *
 * @param route The route string to open.
 * @param params An optional dictionary of parameters to pass to the handler.
 * @param callBack A block executed with the result, which must be serializable.
 * @return YES if the route was successfully opened; NO otherwise.
 */
- (BOOL)openRoute:(NSString *)route withParams:(nullable NSDictionary *)params callBack:(void(^)(NSDictionary *result))callBack;

- (void)registerUnhandledRoute:(BOOL(^)(NSString *scheme, NSString *host, NSString *path, NSDictionary *params))callback;


/**
 * Registers a route interceptor for a specific host.
 *
 * This method associates an interceptor with a specific host in the routing system.
 * When a route with the specified host is processed, the interceptor will be called
 * before and after the route handling. Only one interceptor can be registered per host.
 * If an interceptor is already registered for the host, it will be replaced.
 *
 * @param interceptor The interceptor object that conforms to ThingModuleRouteInterceptor protocol.
 * @param host The host string to intercept (case-insensitive).
 */
- (void)registerInterceptor:(id<ThingModuleRouteInterceptor>)interceptor forHost:(NSString *)host;

/**
 * Unregisters a route interceptor for a specific host.
 *
 * This method removes the interceptor associated with the specified host.
 * After calling this method, routes with this host will no longer be intercepted.
 * If no interceptor exists for the host, this method does nothing.
 *
 * @param host The host string to stop intercepting (case-insensitive).
 */
- (void)unregisterInterceptorForHost:(NSString *)host;

@end

NS_ASSUME_NONNULL_END
