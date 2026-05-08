
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#ifndef H_ThingMachRegisterDefine
#define H_ThingMachRegisterDefine

#define _THING_MACH_SECTION __attribute__((used, section("__DATA, _ThingMOV3_") ))
#define _ThingMachRegisterBlockSectionNameV3 "_ThingMOV3_" // This definition must not be changed

typedef Class _Nullable (^_ThingMachRegisterClassBlock)(NSString * t, NSString * k, NSUInteger p);
typedef id _Nullable (^_ThingMachRegisterCreatorBlock)(NSString * t, NSString * k, NSUInteger p, id defaultValue);

/// When Address Sanitizer is turned on, align must be specified
typedef struct __attribute__((aligned(64))){
    NSUInteger priority; //Higher priority overrides lower priority
    const char * type;
    const char * Key;
    _ThingMachRegisterClassBlock classBlock;
    _ThingMachRegisterCreatorBlock creatorBlock;
} _ThingMachRegisterBlockStructV3;

/// The fallback processing of the registered category will be called when the category instance is obtained, used for protocol checking, null processing, etc.
#define _ThingMachRegisterFilter(type, creatorBlock)  \
_ThingMachRegisterBlock(__ThingMRFilterType__, type, 0,\
NULL,\
(creatorBlock)\
)

/// Basic registration + anti-duplicate definition, not applicable to code snippets
#define _ThingMachRegisterBlock(type, Key, priority, classBlock, creatorBlock) \
_ThingMachRegisterBase(type, Key, priority, classBlock, creatorBlock); \
@interface __ThingMachRC_##type##_##Key##_##priority : NSObject /*Detect duplicate names and strengthen registration
*/ \
@end \
@implementation __ThingMachRC_##type##_##Key##_##priority \
@end

/// Basic registration, can be used anywhere (recommended to be placed in .m files)
/// type：type
/// Key：The only id under this type
/// priority：Priority, the registration class has a unique key value [type + Key + priority]; when [type + Key] are equal, only the higher priority priority registration will take effect
/// classBlock：Returns the registered class
/// instanceBlock：Returns an instance of the registered class
#define _ThingMachRegisterBase(type, Key, priority, classBlock, creatorBlock) \
static _ThingMachRegisterBlockStructV3 _ThingMachRS_##type##_##Key##_##priority _THING_MACH_SECTION = { \
priority, \
#type, \
#Key, \
(classBlock), \
(creatorBlock) \
};
#endif


NS_ASSUME_NONNULL_END
