
#ifndef ThingFoundationKitMacro_h
#define ThingFoundationKitMacro_h

#ifndef thing_weakify
    #define thing_weakify(object)  __weak __typeof__(object) weak##_##object = object;
#endif

#ifndef thing_strongify
    #define thing_strongify(object)  __typeof__(object) object = weak##_##object;
#endif

#ifndef Thing_StringFromSEL
    #define Thing_StringFromSEL(name) NSStringFromSelector(@selector(name))
#endif

#ifdef DEBUG
    #define ThingFoundationLog(...) NSLog(__VA_ARGS__)
#else
    #define ThingFoundationLog(...)
#endif

#endif /* ThingFoundationKitMacro_h */
