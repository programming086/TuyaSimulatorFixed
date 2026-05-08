
#import <Foundation/Foundation.h>

/// Same as EAnnotationPriority
typedef enum {
    ThingModuleRoutePriorityMin = -1024,
    ThingModuleRoutePriorityLow = -16,
    ThingModuleRoutePriorityBase = 0,
    ThingModuleRoutePriorityHigher = 16,
    ThingModuleRoutePriorityMax = 1024,
} ThingModuleRoutePriority;

@protocol ThingModuleRouteRegisterProtocol <NSObject>

@optional

/**
 * Registers module routes.
 *
 * This method should return an array of route strings that the module will handle. 
 * Each route corresponds to a specific path or endpoint managed by the module.
 *
 * @return An array of route strings the module can handle.
 */
- (NSArray<NSString *> *)registModuleRoutes;

/**
 * Registers priorities for routes.
 *
 * This method allows specifying the priority for each route, with higher values indicating higher priority.
 * Routes with higher priority will be matched and handled first.
 *
 * Example:
 * @{
 *    @"ThingPageName": @(ThingModuleRoutePriorityBase)
 * }
 *
 * @return A dictionary mapping route names to their priority levels.
 */
- (NSDictionary<NSString *, NSNumber *> *)registPriorityForRoutes;

/**
 * Handles a routing event.
 *
 * This method processes routing events based on the provided URL components and parameters.
 *
 * @param scheme The URL scheme used in the route (e.g., "http", "thing").
 * @param host The host part of the URL (e.g., "example.com").
 * @param path The path component of the URL.
 * @param params A dictionary of parameters passed along with the route.
 * @return YES if the route has been handled successfully, NO otherwise.
 */
- (BOOL)handleRouteWithScheme:(NSString *)scheme
                         host:(NSString *)host
                         path:(NSString *)path
                       params:(NSDictionary *)params;

/**
 * Handles a routing event with a callback.
 *
 * This method processes the routing event just like the previous one, but additionally provides a callback block
 * to return a result upon completion of route handling.
 *
 * @param scheme The URL scheme used in the route.
 * @param host The host part of the URL.
 * @param path The path component of the URL.
 * @param params A dictionary of parameters passed along with the route.
 * @param callBack A block to be executed with the result of the routing operation, if applicable.
 * @return YES if the route has been handled successfully, NO otherwise.
 */
- (BOOL)handleRouteWithScheme:(NSString *)scheme
                         host:(NSString *)host
                         path:(NSString *)path
                       params:(NSDictionary *)params
                     callBack:(void(^)(NSDictionary *result))callBack;

@end
