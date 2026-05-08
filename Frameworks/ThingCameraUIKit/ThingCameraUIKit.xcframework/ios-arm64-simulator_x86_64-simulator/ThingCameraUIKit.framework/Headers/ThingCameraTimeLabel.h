
#import <UIKit/UIKit.h>

@interface ThingCameraTimeLabel : UIView

/// background color
@property (nonatomic, strong) UIColor *thing_backgroundColor;

/// time string
@property (nonatomic, copy) NSString *timeStr;

/// text font size
@property (nonatomic, assign) NSInteger fontSize;

/// text color
@property (nonatomic, strong) UIColor *textColor;

/// arrow position, 0->left, 1->right, 2->middle
@property (nonatomic, assign) NSInteger position;

@end

