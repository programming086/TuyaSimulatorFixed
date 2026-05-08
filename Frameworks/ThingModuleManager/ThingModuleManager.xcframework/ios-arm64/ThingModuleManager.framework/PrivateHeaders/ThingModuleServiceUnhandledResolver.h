
#import <Foundation/Foundation.h>


@interface ThingModuleServiceUnhandledResolver : NSObject
@property (nonatomic, readonly) Protocol *serviceProtocol;

- (instancetype)initWithServiceProtocol:(Protocol *)ptl
                   methodInvokeProvider:(id(^)(SEL method))providerBlock;

@end
