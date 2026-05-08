//
// ThingLightingColorUtil.h
// ThingSmartCommercialLightingSdk
//
// Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief You can use it when you need to obtain the conversion tool of rgb and hsv.
@interface ThingLightingColorUtil : NSObject


/// Convert from color to hsv values.
/// @param color Color
/// @return Hsv values
+ (NSArray *)hsvWithColor:(UIColor *)color;


/// Convert from hsv values to color.
/// @param hue Hue value
/// @param saturation Saturation value
/// @param brightness Brightness value
/// @return UIColor instance
+ (UIColor *)colorWithHue:(NSInteger)hue saturation:(NSInteger)saturation brightness:(NSInteger)brightness;


/// Convert from rgba values to hsv values.
/// @param red Red value
/// @param green Green value
/// @param blue Blue value
/// @param alpha Alpha value
/// @return Hsv values
+ (NSArray *)hsvWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(NSInteger)alpha;


/// Convert from hsv values to rgba values.
/// @param hue  Hue value
/// @param saturation Saturation value
/// @param brightness Brightness value
/// @return Rgb values
+ (NSArray *)rgbWithHue:(NSInteger)hue saturation:(NSInteger)saturation brightness:(NSInteger)brightness;


/// Convert from rgb hex string to hsv values.
/// @param hexString Rgb hex string
/// @return Hsv values
+ (NSArray *)hsvWithRgbHexString:(NSString *)hexString;


/// Convert from hsv string to rgb values.
/// @param hsvString Hsv string
/// @return Rgb values
+ (NSArray *)rgbWithHsvString:(NSString *)hsvString;


/// Convert from hsv values to hsv string.
/// @param hue Hue value
/// @param saturation Saturation value
/// @param brightness Brightness value
/// @return Encoded hsv string
+ (NSString *)encodeNewHsvWithHue:(NSInteger)hue saturation:(NSInteger)saturation brightness:(NSInteger)brightness;


/// Convert from hsv string to hsv value.
/// @param hsvString Encoded hsv string
/// @return Hsv values
+ (NSArray *)decodeNewHsvWithHsvString:(NSString *)hsvString;


/// Convert from rgb hex string to color.
/// @param hexString Rgb hex string
/// @return UIColor instance
+ (UIColor *)colorWithRgbHexString:(NSString *)hexString;


/// Convert from kelvin to rgb hex string.
/// @param brightness Brightness value
/// @param temperature Temperature value
/// @return Rgb hex string
+ (NSString *)rgbWithBrightness:(NSInteger)brightness temperature:(NSInteger)temperature;


/// Convert from kelvin to color.
/// @param brightness Brightness value
/// @param temperature Temperature value
/// @return UIColor instance
+ (UIColor *)hsvColorWithBrightness:(NSInteger)brightness temperature:(NSInteger)temperature;


/// Convert from kelvin to hsv values.
/// @param brightness Brightness value
/// @param temperature Temperature value
/// @return Hsv values
+ (NSArray *)hsvWithBrightness:(NSInteger)brightness temperature:(NSInteger)temperature;


/// Convert from rgb value to rgb hex string.
/// @param red Red value
/// @param green Green value
/// @param blue Blue value
/// @return Rgb hex string
+ (NSString *)rgbHexStringWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue;



@end

NS_ASSUME_NONNULL_END
