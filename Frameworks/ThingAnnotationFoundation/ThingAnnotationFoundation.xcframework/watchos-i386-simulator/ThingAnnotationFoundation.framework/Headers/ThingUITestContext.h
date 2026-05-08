
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingUITestContext : NSObject

+ (instancetype)sharedInstance;

//Set environment variables, such as the request object in the startBlock, to prevent the request block from ending directly
- (void)setContextParams:(id)object forKey:(NSString *)key;
- (id)getContextParams:(NSString *)key;

//Set the saved variable, for example, the value to be stored after the request in startBlock.
- (void)setUserdefault:(id)object forKey:(NSString *)key;
- (id)getUserdefault:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
