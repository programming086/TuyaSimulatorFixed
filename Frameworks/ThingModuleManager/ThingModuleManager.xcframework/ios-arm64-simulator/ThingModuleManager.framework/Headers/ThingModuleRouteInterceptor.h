
#ifndef ThingModuleRouteInterceptor_h
#define ThingModuleRouteInterceptor_h

/**
 * Route interception protocol for handling pre and post routing events.
 * Note: Only one ThingModuleRouteInterceptor can be registered per host.
 * Multiple registrations for the same host will be overridden by the last registration.
 */
@protocol ThingModuleRouteInterceptor <NSObject>

/**
 * Intercept route before normal handling.
 * @param scheme The URL scheme
 * @param host The URL host, which must be unique for each interceptor
 * @param path The URL path (optional)
 * @param params Route parameters (optional)
 * @param callBack Callback block for async results (optional)
 * @return YES to take over routing and skip normal handling, NO to continue with normal flow
 */
- (BOOL)beforeInterceptRouteWithScheme:(NSString *)scheme
                                  host:(NSString *)host
                                  path:(NSString *_Nullable)path
                                params:(NSDictionary *_Nullable)params
                              callBack:(void(^_Nullable)(NSDictionary *result))callBack;

/**
 * Called after route has been handled, regardless of the handling result.
 * @param scheme The URL scheme
 * @param host The URL host, which must be unique for each interceptor
 * @param path The URL path (optional)
 * @param params Route parameters (optional)
 * @param callBack Callback block for async results (optional)
 * @param result The result of route handling - YES if successful, NO if failed
 */
- (void)afterInterceptRouteWithScheme:(NSString *)scheme
                                 host:(NSString *)host
                                 path:(NSString *_Nullable)path
                               params:(NSDictionary *_Nullable)params
                             callBack:(void(^_Nullable)(NSDictionary *result))callBack
                               result:(BOOL)result;

@end

#endif /* ThingModuleRouteInterceptor_h */
