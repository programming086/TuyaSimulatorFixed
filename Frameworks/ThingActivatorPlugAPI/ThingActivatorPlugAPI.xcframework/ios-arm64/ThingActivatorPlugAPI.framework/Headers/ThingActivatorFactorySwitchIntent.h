
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingActivatorFactoryEnterSource) {
    ThingActivatorFactoryEnterSourceForward, // Switch step in the current linkMode, default case
    ThingActivatorFactoryEnterSourceSwitch,  // Enter step after switching linkMode
};

@interface ThingActivatorFactorySwitchIntent : NSObject
@property (nonatomic, assign) ThingActivatorFactoryEnterSource enterSource; /// Source of entering the step

@property (nonatomic, strong) NSString *stepId;
@end


UIKIT_EXTERN ThingActivatorFactorySwitchIntent *ThingActivatorSwitchIntentInit(NSString *stepId);

NS_ASSUME_NONNULL_END
