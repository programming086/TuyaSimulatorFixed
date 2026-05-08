
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingTextView : UITextView

@property (nonatomic, strong) NSString *placeholder;
@property (nonatomic, strong) NSAttributedString *attributedPlaceholder;

- (CGRect)placeholderRectForBounds:(CGRect)bounds;

@end

NS_ASSUME_NONNULL_END
