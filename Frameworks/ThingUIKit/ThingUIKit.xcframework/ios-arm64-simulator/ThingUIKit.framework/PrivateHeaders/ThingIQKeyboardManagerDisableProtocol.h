
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define kIQKeyboardManagerClassName @"IQKeyboardManager"

@protocol ThingIQKeyboardManagerDisableProtocol <NSObject>

+ (instancetype)sharedManager;

@property(nonatomic, strong, readonly) NSMutableSet<Class> *disabledDistanceHandlingClasses;
@property(nonatomic, strong, readonly) NSMutableSet<Class> *disabledTouchResignedClasses;

@end

NS_ASSUME_NONNULL_END
