
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingModuleServiceInfo;

FOUNDATION_EXTERN ThingModuleServiceInfo * ThingModuleServiceInfoMake(Protocol *protocol, Class implCls);

@interface ThingModuleServiceInfo : NSObject <NSCopying>

@property (nonatomic, strong) Protocol *protocol; /**< The protocol that the service conforms to. */
@property (nonatomic, strong) Class implClass;   /**< The class that provides the service implementation. */

@property (nonatomic, getter=isSingleton, readonly) BOOL singleton;   /**< Indicates whether the service is a singleton. If true, the instance will be retained within the module manager. [default:YES] */

+ (ThingModuleServiceInfo *)serviceInfoWith:(Protocol *)protocol implClass:(Class)implCls;

@end

NS_ASSUME_NONNULL_END
