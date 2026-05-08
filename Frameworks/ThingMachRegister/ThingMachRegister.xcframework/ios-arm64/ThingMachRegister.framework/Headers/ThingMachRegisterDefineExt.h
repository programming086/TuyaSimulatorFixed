#import "ThingMachRegisterDefine.h"
#import "ThingMachRegisterManager.h"

/// Plug-and-play registration, using Mach-O method, supports general registration and result filtering, thread-safe
///
/// 1. Universal registration：
/// The registration class has a unique key value [type + Key + priority]; the default priority value is 0. When [type + Key] are equal, only the higher priority registration will take effect.
/// _ThingMachRegister uses [[className alloc] init] to create a registered class instance. If you want to customize the instance creation method, such as returning a singleton, you can use _ThingMachRegisterBlock to customize it.
///
/// When used in business, business modules can declare some of their own shortcut methods, such as (MyType module):
/// Case A  Ordinary registration：
///     // Declaration Registration Class Shortcut Operation
///     #define _MyMachRegister(Key, className)  _ThingMachRegister(MyType, Key, className)
///
///     // Declaration Get a shortcut operation to an instance
///     #define _MyMachRegisterFetch(Key)  _ThingMachRegisterFetch(MyType, Key)
///
///     // usage
///     register：_MyMachRegister(myKey, myClassName);
///     get1：id myClassInstance = _MyMachRegisterFetch(myKey);
///     get2：id myClassInstance = [[ThingMachRegisterManager shareInstance] generateWithType:@"MyType" key:@"myKey"];
///
/// Case B Register a class with a protocol (ThingMyProtocol):
///     // Declaration Register a shortcut operation with a protocol class
///     #define _MyMachRegisterWithProtocol(Key, className) \
///     _ThingMachRegisterWithCreator(MyProtocolType, Key, className, \
///     (^id<ThingMyProtocol>(NSString * t, NSString * k, NSUInteger p, id defaultV) { \
///         return [[className alloc] init];\
///     }))
///
/// 2. Results are filtered：
/// When you need to filter the general registration results of a category, such as empty bottom line, protocol satisfaction judgment, etc., you can use result filtering for this category.
///
/// usage：
///     _ThingMachRegisterFilter(MyProtocolType,  (^id _Nonnull (NSString * type, NSString * key, NSUInteger p, id defaultV) {
///         return [defaultV conformsToProtocol:@protocol(ThingMyProtocol)] ? result : nil;
///     }));
///
/// 3. Notice:
///   Because we will use "_" as a link character, it is not recommended to use "_" in type and Key.

#ifndef H_ThingMachRegisterExt
#define H_ThingMachRegisterExt

/// Quick registration
#define _ThingMachRegister(type, Key, className) \
_ThingMachRegisterBlock(type, Key, 0,\
(^Class _Nullable (NSString * t, NSString * k, NSUInteger p) { \
return className.class;\
}),\
(^id _Nonnull (NSString * t, NSString * k, NSUInteger p, id defaultV) { \
return [[className alloc] init];\
}))

/// Personalized registration
#define _ThingMachRegisterWithCreator(type, Key, className, creatorBlock) \
_ThingMachRegisterBlock(type, Key, 0,\
(^Class _Nullable (NSString * t, NSString * k, NSUInteger p) { \
return className.class;\
}),\
(creatorBlock))

/// Get an instance of a registered class
#define _ThingMachRegisterFetch(type, Key) [[ThingMachRegisterManager shareInstance] generateWithType:@#type key:@#Key]
#endif
