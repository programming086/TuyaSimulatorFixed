
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (ThingUIKit)

/// Determine whether the view is in the display area
/// - Parameter view: Must be a subview of the current scroll view
/// @return Returns NO if part of the display is shown or not shown.
- (BOOL)thing_isVisibleInView:(UIView*)view;

@end

NS_ASSUME_NONNULL_END
