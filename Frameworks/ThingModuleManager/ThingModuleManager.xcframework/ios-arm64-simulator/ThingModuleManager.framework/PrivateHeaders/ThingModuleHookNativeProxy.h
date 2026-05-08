
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingModuleHookNativeProxy : NSProxy

@property (nonatomic, weak, readonly) id hookImpl;

@property (nonatomic, strong, readonly) NSMapTable<NSString *, id> *nativeMap; /**< sel, nativeImpl */

- (instancetype)initWithHookImpl:(id)impl;

@end

NS_ASSUME_NONNULL_END
