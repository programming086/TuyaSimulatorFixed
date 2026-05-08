
#pragma mark ThingAnnotation

#import <UIKit/UIKit.h>
#import "ThingRegisterLaunchProtocol.h"
#import <ThingMachRegister/ThingMachRegister.h>

/*
 exp:
 
 ThingLaunchAnnotation(ThingAPMModuleLaunchTask)
 
 @implementation ThingAPMModuleLaunchTask
 
 - (void)start {
     ...
 }
 
 + (ThingLaunchTaskPriority)priority {
     return ThingLaunchTaskPriority_Hight;
 }

 + (ThingLaunchTaskRunMode)runMode {
     return ThingLaunchTaskRunMode_AsyncOnMain;
 }

 @end
*/

#define ThingLaunchAnnotation(IMPL) __ThingLaunchAnnotation(IMPL)

//typedef struct __attribute__((packed)) {
//    const char * impl;
//} _ThingMachRegisterLaunchStruct;
#define __ThingLaunchAnnotation(IMPL) \
_ThingMachRegisterBlock(__Launch, IMPL, 0,\
NULL,\
(^id _Nonnull (NSString * t, NSString * k, NSUInteger p, id defaultV) { \
return @#IMPL;\
}))

@interface ThingLaunchTaskAnnotationObject: NSObject

/// IMPL is the name of the class that implements ThingRegisterLaunchProtocol
@property (strong) NSString *impl;

+ (NSArray<ThingLaunchTaskAnnotationObject *> *)allTasks;

@end

