
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingEncryptImageResizeHelper : NSObject
+ (NSString *)resizeImageCacheKey:(NSString *)imageCacheKey
                      scaledWidth:(NSInteger)scaledWidth;

+ (UIImage *)resizeImage:(UIImage *)image
                withSize:(NSInteger)scaledWidth;
@end

NS_ASSUME_NONNULL_END
