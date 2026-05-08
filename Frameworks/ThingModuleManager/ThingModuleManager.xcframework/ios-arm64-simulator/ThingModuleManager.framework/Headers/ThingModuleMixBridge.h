
#import <Foundation/Foundation.h>

#define ThingNative ((id)[ThingModuleMixBridge bridgeTargetOfObj:self])
#define ThingNativeTarget(obj) ((id)[ThingModuleMixBridge bridgeTargetOfObj:obj])

@interface ThingModuleMixBridge : NSObject

/**
 * Determines whether the given object is a class or an instance.
 *
 * This method returns the class of the object if it's a class object,
 * or the instance itself if it's an instance of a class.
 *
 * @param obj The object to evaluate.
 * @return The class if the object is a class, otherwise the instance itself.
 */
+ (id)bridgeTargetOfObj:(id)obj;
+ (instancetype)shareInstance;

- (void)hookService:(Protocol *)prot ofSelector:(SEL)sel withModuleCls:(Class)moduleCls;

@end
