
#import <Foundation/Foundation.h>

@class ThingSmartPairConfiguration;

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartPairUtil : NSObject

+ (BOOL)validIPSegment;

+ (BOOL)isStaticIPConfig:(ThingSmartPairConfiguration *)cofig;

+ (BOOL)isStaticIPConfigParamCorrect:(ThingSmartPairConfiguration *)cofig;

@end

NS_ASSUME_NONNULL_END
