    

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingPrivacyAuthCustomConfig : NSObject

/// Title, default text will be used if not specified
@property (nonatomic, copy) NSString *title;

/// Description, if not specified, the default text will be used
@property (nonatomic, copy) NSString *desc;

/// Picture, use the default picture if not uploaded
@property (nonatomic, strong) UIImage *iconImage;

/// Indicator image when permission is disabled. If not passed, the default image will be used.
@property (nonatomic, strong) UIImage *indicateImage;

@end

NS_ASSUME_NONNULL_END
