
#ifndef ThingAssert_h
#define ThingAssert_h

#ifdef __OPTIMIZE__

/* relese */

#define ThingAssertCond(__cond)             do {} while (0)
#define ThingAssertCondDesc(__cond, __desc) do {} while (0)
#define ThingAssertCondDescs(__cond, __desc, ...) do {} while (0)

#else

/* debug */

#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/sysctl.h>

// Check if the process is being debugged by Xcode
// Reference: https://developer.apple.com/library/archive/qa/qa1361/_index.html
static inline bool AmIBeingDebugged(void)
    // Returns true if the current process is being debugged (either
    // running under the debugger or has a debugger attached post facto).
{
    int                 junk;
    int                 mib[4];
    struct kinfo_proc   info;
    size_t              size;

    // Initialize the flags so that, if sysctl fails for some bizarre
    // reason, we get a predictable result.

    info.kp_proc.p_flag = 0;

    // Initialize mib, which tells sysctl the info we want, in this case
    // we're looking for information about a specific process ID.

    mib[0] = CTL_KERN;
    mib[1] = KERN_PROC;
    mib[2] = KERN_PROC_PID;
    mib[3] = getpid();

    // Call sysctl.

    size = sizeof(info);
    junk = sysctl(mib, sizeof(mib) / sizeof(*mib), &info, &size, NULL, 0);
    assert(junk == 0);

    // We're being debugged if the P_TRACED flag is set.

    return ( (info.kp_proc.p_flag & P_TRACED) != 0 );
}

/*
 Replace system assertion macros to trigger a breakpoint in Xcode when an assertion is encountered,
 allowing for convenient preservation of the call stack's context.
 For more background information, visit: https://registry.code.thing-inc.top/thingIOS/ThingFoundationKit/issues/1
 */

/* break */
#if TARGET_IPHONE_SIMULATOR && XCODE_VERSION_MAJOR > 1200
    #define Thing_ASSERT_BREAK_POINT asm("int3");
#elif TARGET_OS_IPHONE
/// 为了避免测试使用 DEBUG 遇到断言导致闪退， 仅在 Xcode 环境中 DEBUG 时才生效
    #define Thing_ASSERT_BREAK_POINT \
        do { \
            if(AmIBeingDebugged()) { \
                raise(SIGINT); \
            } \
        } while(0)
#else
    #define Thing_ASSERT_BREAK_POINT do {} while (0)
#endif

/* thing style assert */
#define ThingAssertCond(__cond)              ThingAssertCondDesc(__cond, @"")
#define ThingAssertCondDesc(__cond, __desc)  ThingAssertCondDescs(__cond, __desc)
#define ThingAssertCondDescs(__cond, __desc, ...)  do { \
    if (!(__cond)) { \
        NSLog((@"trigger thing assert %s [line:%d]" __desc), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__); \
        Thing_ASSERT_BREAK_POINT; \
    } \
} while (0)


#endif /* __OPTIMIZE__ */

#endif /* ThingAssert_h */
