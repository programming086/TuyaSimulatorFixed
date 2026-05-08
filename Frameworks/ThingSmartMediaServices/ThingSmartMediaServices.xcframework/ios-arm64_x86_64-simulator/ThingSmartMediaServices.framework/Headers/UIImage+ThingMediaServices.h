//
//  UIImage+ThingMediaServices.h
//  ThingSmartMediaServices
//
//  Created by Aaron on 2022/4/26.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (ThingMediaServices)

+ (UIImage *)imageWithYUVData:(CVPixelBufferRef)pixelBuffer;

@end

NS_ASSUME_NONNULL_END
