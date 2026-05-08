
#import "ThingRegisterAPIProtocol.h"
#import <ThingMachRegister/ThingMachRegister.h>

#pragma mark ThingAnnotation
//Implementing a protocol means providing a protocol
//Example: ThingRegisterApiAnnotation(ThingLoginProtocol, ThingLoginProtocolImpl)
//ThingLoginProtocol is the login protocol ThingLoginProtocolImpl is the login implementation
#define ThingRegisterAPIAnnotation(Protocol, IMPL) ThingRegisterAPIWithPriorityAnnotation(Protocol,IMPL, 0)

#define ThingRegisterAPIWithPriorityAnnotation(Protocol, IMPL,priority ) __ThingInterfaceWithPriorityAnnotation(Protocol,IMPL, priority)

//Yes, optional protocol. Currently, it can only be used for script scanning, and no data needs to be recorded in Macho
//Example: ThingRequireAPIAnnotation(ThingLoginProtocol)
#define ThingRequireAPIAnnotation(Protocol)
#define ThingOptionalAPIAnnotation(Protocol)



#pragma mark ThingAnnotationIMPL

extern NSMutableArray *getProtocolSectionData(void);

#define __ThingInterfaceWithPriorityAnnotation(Protocol,IMPL, priority) \
_ThingMachRegisterBlock(_RegisterAPI_, Protocol, priority,\
NULL,\
(^id _Nonnull (NSString * t, NSString * k, NSUInteger p, id defaultV) { \
return @#IMPL;\
}))
