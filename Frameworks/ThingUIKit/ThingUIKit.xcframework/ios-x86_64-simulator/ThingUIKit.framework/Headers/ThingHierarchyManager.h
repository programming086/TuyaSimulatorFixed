
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN UIWindow * Thing_MainWindow(void);

/// [^en]top controller of current view stack, including the presented controller[$en]
UIKIT_EXTERN UIViewController * Thing_TopViewController(void);

NS_ASSUME_NONNULL_END
