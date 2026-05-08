
#ifndef ThingSmartSDK_Log_h
#define ThingSmartSDK_Log_h

#import "ThingSmartSDK.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSDK (Log)

/// Debug mode, default is false. Verbose log will print into console if opened.
@property (nonatomic, assign) BOOL debugMode;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSmartSDK_Log_h */
