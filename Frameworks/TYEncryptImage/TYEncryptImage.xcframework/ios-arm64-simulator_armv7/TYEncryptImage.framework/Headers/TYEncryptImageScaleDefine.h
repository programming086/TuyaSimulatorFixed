//
//  TYEncryptImageScaleDefine.h
//  TYEncryptImage
//
//  Created by Jake Hu on 2021/1/7.
//

#import <Foundation/Foundation.h>
#import "TYEncryptWebImageCompat.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYEncryptImageScaleDefine : NSObject

#pragma mark - Image scale

/**
Return the image scale factor for the specify key, supports file name and url key.
This is the built-in way to check the scale factor when we have no context about it. Because scale factor is not stored in image data (It's typically from filename).

@param key The image cache key
@return The scale factor for image
*/
FOUNDATION_EXPORT CGFloat TYImageScaleFactorForKey(NSString * _Nullable key);

@end

NS_ASSUME_NONNULL_END
