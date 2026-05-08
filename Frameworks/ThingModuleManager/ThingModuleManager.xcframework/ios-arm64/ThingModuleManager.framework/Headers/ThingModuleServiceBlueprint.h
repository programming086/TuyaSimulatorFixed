
#import <Foundation/Foundation.h>

#import "ThingModuleBaseBlueprint.h"

@class ThingModuleServiceInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingModuleServiceBlueprint <ThingModuleBaseBlueprint>

/**
 * Registers a service with the specified service information.
 *
 * Note: Services cannot be registered if there is already a service with the same protocol.
 *
 * @param serviceInfo The service information containing the protocol and implementation class.
 */
- (void)registService:(ThingModuleServiceInfo *)serviceInfo;

/**
 * Unregisters a service for a specific protocol.
 *
 * @param protocol The protocol for which the service should be unregistered.
 */
- (void)unregistServiceOfProtocol:(Protocol *)protocol;

/**
 * Retrieves the service implementation for a given protocol.
 *
 * @param protocol The protocol associated with the service.
 * @return The service implementation object, or nil if no service is registered for the protocol.
 */
- (nullable id)serviceOfProtocol:(Protocol *)protocol;

/**
 * Retrieves the service information for a specific protocol.
 *
 * @param protocol The protocol for which service information is requested.
 * @return An instance of ThingModuleServiceInfo corresponding to the protocol, or nil if not found.
 */
- (nullable ThingModuleServiceInfo *)serviceInfoOfProtocol:(Protocol *)protocol;

/**
 * Retrieves the singleton instance of the specified module class.
 *
 * This method ensures that the module's instance is a singleton to avoid repeated creation.
 *
 * @param cls The class of the module.
 * @return The singleton instance of the module class, or nil if not instantiated.
 */
- (nullable id)implOfModuleClass:(Class)cls;

/**
 * Releases the singleton instance of the specified module class.
 *
 * @param cls The class of the module whose instance should be released.
 */
- (void)releaseImplOfModuelClass:(Class)cls;

/**
 * Registers a callback for unhandled service calls.
 *
 * This method is used to handle cases where a service is called that has not been registered.
 *
 * @param service The protocol of the unhandled service.
 * @param callback A block that executes with information about the unhandled service and intended method.
 */
- (void)registerUnhandledService:(Protocol *)service
                        invokeCb:(id(^)(Protocol *service, SEL method))callback;

@end

NS_ASSUME_NONNULL_END

