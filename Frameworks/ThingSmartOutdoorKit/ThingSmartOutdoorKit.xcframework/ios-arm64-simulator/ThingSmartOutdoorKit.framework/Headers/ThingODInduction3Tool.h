
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BTInductiveUnlockTool)
@interface ThingODInduction3Tool : NSObject

+ (NSString *)udidMixUID;

+ (NSArray<NSString *> *)pairedListFromDPValue:(NSString *)value;

+ (BOOL)pairedWithDPValue:(NSString *)value;

+ (NSUInteger)sensitivityLevelWithDPValue:(NSString *)value;

@end

NS_ASSUME_NONNULL_END
