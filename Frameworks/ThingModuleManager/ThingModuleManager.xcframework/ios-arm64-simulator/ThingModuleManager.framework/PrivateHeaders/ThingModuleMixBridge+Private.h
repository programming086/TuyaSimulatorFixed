
#import "ThingModuleMixBridge.h"

#import "ThingModuleHookProxy.h"
#import "ThingModuleHookNativeProxy.h"

@interface ThingModuleMixBridge ()

- (void)loadMixMap;
- (void)generateMixForward;

- (void)mixClass:(Class)cls withNative:(Class)native;

- (ThingModuleHookProxy *)hookProxyOfProtocol:(Protocol *)prot;

@end
