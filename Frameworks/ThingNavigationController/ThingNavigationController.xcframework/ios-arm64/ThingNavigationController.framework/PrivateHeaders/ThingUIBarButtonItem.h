
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingUIBarButtonItem : UIBarButtonItem

@property (nonatomic) CGFloat thing_leftEdge;
@property (nonatomic) CGFloat thing_rightEdge;
@property (nonatomic) UIOffset thing_offset;
@property (nonatomic) BOOL isPlaceholder;

@end

NS_ASSUME_NONNULL_END
