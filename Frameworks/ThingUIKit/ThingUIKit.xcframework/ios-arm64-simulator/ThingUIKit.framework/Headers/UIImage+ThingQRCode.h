//
//  UIImage+ThingQRCode.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/5/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (ThingQRCode)

/**
 [^en]Create QRCode image with str[$]
 */
+ (UIImage *)thing_qrCodeWithString:(NSString *)str width:(CGFloat)width;

+ (UIImage *)thing_qrCodeWithString:(NSString *)str inputCorrectionLevel:(NSString *)inputCorrectionLevel width:(CGFloat)width;

@end

NS_ASSUME_NONNULL_END
