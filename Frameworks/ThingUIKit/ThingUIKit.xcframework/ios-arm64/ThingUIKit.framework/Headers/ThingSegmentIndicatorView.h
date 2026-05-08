
#import <UIKit/UIKit.h>
#import "ThingSegmentCell.h"
#import "ThingSegmentedControl.h"

@interface ThingIndicatorModel : NSObject
@property (nonatomic, assign) NSInteger   selectedIndex;
@property (nonatomic, assign) CGRect      selectedCellFrame;
@property (nonatomic, assign) NSInteger   leftIndex;
@property (nonatomic, assign) CGRect      leftCellFrame;
@property (nonatomic, assign) NSInteger   rightIndex;
@property (nonatomic, assign) CGRect      rightCellFrame;
@property (nonatomic, assign) CGFloat     percent;
@property (nonatomic, assign) NSInteger   lastSelectedIndex;

@property (nonatomic, assign) ThingSegmentItemSelectType    selectedType;

@end

@interface ThingSegmentIndicatorView : UIView

@property (nonatomic, assign) BOOL scrollEnabled;

@property (nonatomic, assign) CGFloat veticalOffset;

@property (nonatomic, assign) ThingSegmentIndicatorPosition segmentPosition;

@property (nonatomic, assign) ThingSegmentIndicatorAnimation animation;

@property (nonatomic, assign) CGFloat indicatorLineViewHeight;

@property (nonatomic, assign) CGFloat scrollAnimationDuration;

@property (nonatomic, assign) CGFloat indicatorLineWidth;

@property (nonatomic, assign) CGFloat indicatorLineViewCornerRadius;

@property (nonatomic, strong) UIColor *indicatorLineViewColor;

- (void)refreshState:(ThingIndicatorModel *)model;

- (void)contentScrollViewDidScroll:(ThingIndicatorModel *)model;

- (void)selectedCell:(ThingIndicatorModel *)model;

@end

