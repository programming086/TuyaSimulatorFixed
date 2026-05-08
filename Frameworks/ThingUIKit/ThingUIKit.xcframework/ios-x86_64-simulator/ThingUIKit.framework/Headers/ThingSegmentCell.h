
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, ThingSegmentItemSelectType) {
    ThingSegmentItemSelectTypeCode,
    ThingSegmentItemSelectTypeUnknow,
    ThingSegmentItemSelectTypeScroll,
    ThingSegmentItemSelectTypeClick,
};

@interface ThingSegmentCellModel : NSObject

@property (nonatomic, assign) BOOL showRedPoint;

@property (nonatomic, strong) NSString *imageName;

@property (nonatomic, strong) NSBundle *imageBundle;

@property (nonatomic, assign) UIImageRenderingMode imageRenderMode;

@property (nonatomic, strong) NSURL *imageUrl;

@property (nonatomic, assign) CGSize imageSize;

@property (nonatomic, assign) CGFloat titleImageSpacing;

@property (nonatomic, assign) NSUInteger index;

@property (nonatomic, assign) BOOL selected;

@property (nonatomic, assign) CGFloat cellWidth;
@property (nonatomic, assign) CGFloat itemWidthIncrement;

@property (nonatomic, assign) CGFloat cellSpacing;

@property (nonatomic, assign) CGFloat cellWidthNormalZoomScale;

@property (nonatomic, assign) CGFloat cellWidthCurrentZoomScale;

@property (nonatomic, assign) CGFloat cellWidthSelectedZoomScale;

@property (nonatomic, assign) BOOL selectedAnimationEnabled;

@property (nonatomic, assign) NSTimeInterval selectedAnimationDuration;

@property (nonatomic, assign) ThingSegmentItemSelectType selectedType;

@property (nonatomic, assign, getter=isTransitionAnimating) BOOL transitionAnimating;

#pragma mark - title proprties

@property (nonatomic, copy) NSString *title;

@property (nonatomic, strong) UIColor *titleNormalColor;

@property (nonatomic, strong) UIColor *titleCurrentColor;

@property (nonatomic, strong) UIColor *titleSelectedColor;

@property (nonatomic, strong) UIFont *titleFont;

@property (nonatomic, strong) UIFont *titleSelectedFont;

@property (nonatomic, assign) BOOL titleLabelMaskEnabled;

@property (nonatomic, assign) BOOL titleLabelZoomEnabled;

@property (nonatomic, assign) CGFloat titleLabelNormalZoomScale;

@property (nonatomic, assign) CGFloat titleLabelCurrentZoomScale;

@property (nonatomic, assign) CGFloat titleLabelSelectedZoomScale;

@property (nonatomic, assign) BOOL titleLabelStrokeWidthEnabled;

@property (nonatomic, assign) CGFloat titleLabelNormalStrokeWidth;

@property (nonatomic, assign) CGFloat titleLabelCurrentStrokeWidth;

@property (nonatomic, assign) CGFloat titleLabelSelectedStrokeWidth;

#pragma mark - cell 

@property (nonatomic, assign) BOOL sepratorLineShowEnabled;

@property (nonatomic, strong) UIColor *separatorLineColor;

@property (nonatomic, assign) CGSize separatorLineSize;

@property (nonatomic, assign) CGRect backgroundViewMaskFrame;

@property (nonatomic, assign) BOOL cellBackgroundColorGradientEnabled;

@property (nonatomic, strong) UIColor *cellBackgroundUnselectedColor;

@property (nonatomic, strong) UIColor *cellBackgroundSelectedColor;

@property (nonatomic, assign) CGFloat cellLayerRadius;

@end



@interface ThingSegmentCell : UICollectionViewCell

- (void)reloadData:(ThingSegmentCellModel *)cellModel;


@property (nonatomic, strong) UILabel     *titleLabel;

@property (nonatomic, strong) UILabel     *maskTitleLabel;

@property (nonatomic, strong) UIImageView *imageView;

@end

