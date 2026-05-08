
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingModuleHookProxy : NSProxy

@property (nonatomic, strong, readonly) NSString *prot;
@property (nonatomic, weak, readonly) id nativeImpl;

@property (nonatomic, strong, readonly) NSMapTable<NSString *, id> *hookMap; /**< sel, hookImpl */

- (instancetype)initWithProtocol:(Protocol *)prot nativeImpl:(id)impl;

@end

NS_ASSUME_NONNULL_END
