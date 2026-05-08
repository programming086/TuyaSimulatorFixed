
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterFabricShareModel : NSObject

/// QR code.
@property (nonatomic, copy) NSString *qrCodeStr;
/// setup code.
@property (nonatomic, copy) NSString *setupCode;
/// The window open timeout. 180 s ~ 900 s.
@property (nonatomic, assign) NSUInteger duration;

@end

NS_ASSUME_NONNULL_END
