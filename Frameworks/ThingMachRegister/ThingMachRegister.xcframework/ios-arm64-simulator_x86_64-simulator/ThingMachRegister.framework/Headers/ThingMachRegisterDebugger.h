
#import <Foundation/Foundation.h>
#import "ThingMachRegisterDefine.h"

#ifndef D_ThingMachRegisterDebugger
#define D_ThingMachRegisterDebugger

#ifdef DEBUG
#define _ThingDebug (1)
#endif

#ifdef _ThingDebug
/// Add <test code>:：
/// You can register a <test code> of type <_ThingDebugCodeType> anywhere in a function. To distinguish the registrant, you need to specify <package> (module name) and <name> (code name).
/// We use <package>_<name> to concatenate the <debugID> of <test code>, so multiple <test code> can have the same <debugID>, and each <debugID> corresponds to a <code switch>
/// Business parties can use <ThingMachRegisterDebugger> to obtain the configuration <ThingMachRegisterDebugCode> of <test code>, perform queries, and modify the switch status of <code switch>
/// When the App runs to the <test code>, it will determine whether the <code switch> state corresponding to the current <debugID> will be executed. If the switch is turned on, the <test code> will be executed immediately, otherwise it will be skipped directly.
/// Note: The switch state should only be modified by the test tool. In order not to affect performance, thread safety issues are not considered.
/// Example：
///
///     - (void)testFunc {
///         _ThingDebugCode(package, name, {
///             NSLog(@"I believe that there is a hero living in everyone's heart.");
///         });
///     }
///
#define _ThingDebugCode(Package, Name, Code) __ThingDebugCode(_ThingDebugCodeType, Package, Name, __LINE__, Code)

#define __ThingDebugCode(Type, Package, Name, Line, Code) \
_ThingMachRegisterBase(Type, \
Package##_##Name, \
Line, \
(^Class _Nullable (NSString * t, NSString * k, NSUInteger p) { \
return ThingMachRegisterDebugCode.class;\
}),\
(^ThingMachRegisterDebugCode * _Nonnull (NSString * t, NSString * k, NSUInteger p, id defaultV) { \
ThingMachRegisterDebugCode * item = [[ThingMachRegisterDebugCode alloc] init]; \
item.package = @#Package; \
item.name = @#Name; \
return item; \
}) \
) /*Register to collect keys*/ \
if ([ThingMachRegisterDebugger debugCodeIsOpenWithPackage:@#Package name:@#Name]){ \
Code; \
}

/// Add <Test Block>:
/// You can register a <testBlock> of type <_ThingDebugBlockType> anywhere in the file. To distinguish the registrant, you need to specify <package> (module name) and <name> (code name).
/// We use <package>_<name> to concatenate the <debugID> of <test code>, so multiple <test code> can have the same <debugID>. When the <debugID> code is executed, all <test blocks> are executed in sequence.
/// The business side can use <ThingMachRegisterDebugger> to obtain the configuration of <Test Block> <ThingMachRegisterDebugBlock> and decide to execute <Test Block>
/// Note: <Test Block> should be actively called by the debugging tool, and the execution thread should be determined by the testing tool. Pay attention to thread safety issues
/// Note: Since the registration list is generated at startup, it is earlier than the instance variables are created, so instance variables such as [self] cannot be accessed.
/// Example：
///
///     _ThingDebugBlock(package, name, {
///         NSLog(@"The thing that I have been searching for throughout my life is right next to you.");
///     });
///     - (void)testFunc {
///     }
///
#define _ThingDebugBlock(Package, Name, Block) __ThingDebugBlock(_ThingDebugBlockType, Package, Name, Block)

#define __ThingDebugBlock(Type, Package, Name, Block) \
_ThingMachRegisterBase(Type, \
Package##_##Name, \
0, \
(^Class _Nullable (NSString * t, NSString * k, NSUInteger p) { \
return ThingMachRegisterDebugBlock.class;\
}),\
(^ThingMachRegisterDebugBlock * _Nonnull (NSString * t, NSString * k, NSUInteger p, id defaultV) { \
ThingMachRegisterDebugBlock * item = [[ThingMachRegisterDebugBlock alloc] init]; \
item.package = @#Package; \
item.name = @#Name; \
item.block = ^(void){Block}; \
return item; \
}) \
)

#else

#define _ThingDebugCode(Package, Name, Code)
#define _ThingDebugBlock(Package, Name, Block)

#endif // if _ThingDebug

#endif // if D_ThingMachRegisterDebugger

NS_ASSUME_NONNULL_BEGIN


@interface ThingMachRegisterDebugConfig : NSObject
@property (nonatomic, strong, readonly) NSString * debugID; //Unique ID
@property (nonatomic, strong) NSString * package;
@property (nonatomic, strong) NSString * name;
@end

#define _ThingDebugCodeType _DCode_
#define _ThingDebugCodeTypeStr @"_DCode_"
@interface ThingMachRegisterDebugCode : ThingMachRegisterDebugConfig
@property (nonatomic, assign) BOOL open;
@end

#define _ThingDebugBlockType _DBlock_
#define _ThingDebugBlockTypeStr @"_DBlock_"
@interface ThingMachRegisterDebugBlock : ThingMachRegisterDebugConfig
@property (nonatomic, copy, nullable) void (^block)(void);
@end

extern NSString * const sThingMachRegisterDebugCodResetAllStatus;

@interface ThingMachRegisterDebugger : NSObject

#pragma mark - DebugCode
/// Configuration of all <test code>
+ (nullable NSArray<__kindof ThingMachRegisterDebugCode *> *)allDebugCode;
/// Get <test code> configuration
+ (nullable ThingMachRegisterDebugCode *)debugCodeWithPackage:(NSString *)package
                                                         name:(NSString *)name;
/// Save <test code> status to cache
+ (void)saveDebugCodeStatusCache;
/// Query <test code> status
+ (BOOL)debugCodeIsOpenWithPackage:(NSString *)package
                              name:(NSString *)name;

#pragma mark - DebugBlock
/// Configuration of all <Test Blocks>
+ (nullable NSArray<__kindof ThingMachRegisterDebugBlock *> *)allDebugBlock;
/// Get <Test Blocks> configuration
+ (nullable NSArray<ThingMachRegisterDebugBlock *> *)debugBlockWithPackage:(NSString *)package
                                                                      name:(NSString *)name;
@end
NS_ASSUME_NONNULL_END
