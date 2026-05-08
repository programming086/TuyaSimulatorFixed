
#import <UIKit/UIKit.h>
#import "ThingSegmentCell.h"

@class ThingSegmentedControl;

typedef enum : NSUInteger {
    ThingSegmentTypeOnlyTitle,
    ThingSegmentTypeOnlyImage,
    ThingSegmentTypeTitleImage,
} ThingSegmentType;

typedef enum : NSUInteger {
    ThingSegmentIndicatorStyleLine,
    ThingSegmentIndicatorStyleNone
} ThingSegmentIndicatorStyle;

typedef enum : NSUInteger {
    ThingSegmentIndicatorAnimationTranslate,
    ThingSegmentIndicatorAnimationExtend
} ThingSegmentIndicatorAnimation;


typedef enum : NSUInteger {
    ThingSegmentIndicatorPositionTop,
    ThingSegmentIndicatorPositionBottom
} ThingSegmentIndicatorPosition;

typedef enum : NSUInteger {
    ThingSegmentAlignmentLeft,
    ThingSegmentAlignmentCenter,
    ThingSegmentAlignmentRight
} ThingSegmentAlignment;

typedef CGFloat ThingSegmentLength;

UIKIT_EXTERN ThingSegmentLength const ThingSegmentLengthDynamic;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSegmentControlDelegate <NSObject>

- (void)segmentedControl:(ThingSegmentedControl *)segmentControl didSelectAtIndex:(NSInteger)index;

@end

@interface ThingSegmentedControl : UIView

#pragma mark - ThingSegmentedControl


/**
 lineView will animate with contentScrollView's scroll
 if you want to animate lineView, set the paging container scrollview to contentScrollView
 Default: nil
 */
@property (nonatomic, strong, nullable) UIScrollView *contentScrollView;

/** Default is ThingSegmentTypeTitle */
@property (nonatomic, assign) ThingSegmentType segmentType;

/** Default is 0 index */
@property (nonatomic, assign) NSInteger    defaultSelectedIndex;

/** Default is 0.f */
@property (nonatomic, assign) CGFloat      contentEdgeInsetLeft;

/** Default is 0.f */
@property (nonatomic, assign) CGFloat      contentEdgeInsetRight;

/**
 when content's size.width < self.width, the alignment of content
 Default: ThingSegmentAlignmentLeft
 */
@property (nonatomic, assign) ThingSegmentAlignment         contentAlignment;

@property (nonatomic, weak) id<ThingSegmentControlDelegate> delegate;

/**
 current selected index
 */
@property (nonatomic, assign, readonly) NSInteger        selectedIndex;

/** collection view */
@property (nonatomic, strong, readonly) UICollectionView *collectionView;

#pragma mark - item properties

/**
 the width to increment the item. for example:if itemWidthIncrement = 10, item.width = title.size.width + 10
 Default: 10.f
 */
@property (nonatomic, assign) CGFloat itemWidthIncrement;

/**
 item's spacing
 Default: 20.f
 */
@property (nonatomic, assign) CGFloat itemSpacing;

/**
 should average every item if content.width < self.width
 Default: NO
 */
@property (nonatomic, assign) BOOL    averageCellSpacingEnabled;

/**
 backgroud color should change animate with scroll
 Default: YES
 */
@property (nonatomic, assign) BOOL    itemWidthZoomScrollGradientEnabled;

/**
 should animate when select item
 Default: YES
 */
@property (nonatomic, assign) BOOL    selectedAnimationEnabled;

/**
 item'width if itemWidth is ThingSegmentLengthDynamic, itemWidth is the title's size
 Default: ThingSegmentLengthDynamic
 */
@property (nonatomic, assign) ThingSegmentLength itemWidth;

@property (nonatomic, assign) ThingSegmentLength maxItemWidth;
/**
 the animation time when select item
 Default: 0.25s
 */
@property (nonatomic, assign) NSTimeInterval  selectedAnimationDuration;

#pragma mark - indicator properties

/**
 item vertical offset, negative number direction is up, positive number direction is down
 Default: 0.f
 */
@property (nonatomic, assign) CGFloat         indicatorVerticalOffset;


/**
 indicator line view's color
 Default: UIColor.black
 */
@property (nonatomic, strong) UIColor         *indicatorColor;

/**
 indicator line view's width
 Default: ThingSegmentLengthDynamic
 */
@property (nonatomic, assign) ThingSegmentLength indicatorWidth;


/**
 indicator line view's height
 Default: 3.f
 */
@property (nonatomic, assign) ThingSegmentLength indicatorLineViewHeight;

/**
 indicator line view's style
 Default: ThingSegmentIndicatorStyleLine
 */
@property (nonatomic, assign) ThingSegmentIndicatorStyle    indicatorStyle;

/**
 indicator line view's position
 Default: ThingSegmentIndicatorPositionBottom
 */
@property (nonatomic, assign) ThingSegmentIndicatorPosition indicatorPosition;

#pragma mark - image properties

/** image's name in app bunlde */
@property (nonatomic, strong) NSArray <NSString *> *imageNames;

/** image's url from network */
@property (nonatomic, strong) NSArray <NSURL *> *imageUrls;

/** space between image and title */
@property (nonatomic, assign) CGFloat imageTitleSpacing;

/**
 default is UIImageRenderingModeAlwaysTemplate
 */
@property (nonatomic, assign) UIImageRenderingMode imageRenderMode;
/**
default is main bundle
*/
@property (nonatomic, strong) NSBundle *imageBundle;

/**
 segment don't load image,
 please load image with the url with yourself
 */
@property (nonatomic, strong) void(^imageLoadBlock)(NSURL *imageUrl);

/** image's size */
@property (nonatomic, assign) CGSize imageSize;



#pragma mark - title properties

@property (nonatomic, strong) NSArray <NSString *> *titles;

@property (nonatomic, strong) UIFont   *titleFont;

@property (nonatomic, strong) UIColor  *titleColor;

@property (nonatomic, strong) UIFont   *titleSelectedFont;

@property (nonatomic, strong) UIColor  *titleSelectedColor;

@property (nonatomic, assign) BOOL    titleLabelMaskEnabled;

@property (nonatomic, assign) BOOL    titleLabelZoomEnabled;

@property (nonatomic, assign) BOOL    titleLabelStrokeWidthEnabled;

@property (nonatomic, assign) CGFloat titleLabelSelectedStrokeWidth;

@property (nonatomic, assign) BOOL    titleColorGradientEnabled;

@property (nonatomic, assign) BOOL    titleLabelZoomScrollGradientEnabled;

#pragma mark - seperateor properties

@property (nonatomic, assign) CGSize  separatorLineSize;

@property (nonatomic, strong) UIColor *separatorLineColor;

@property (nonatomic, assign) BOOL    separatorLineShowEnabled;

#pragma mark - background color properties

@property (nonatomic, strong) UIColor *cellBackgroundSelectedColor;

@property (nonatomic, strong) UIColor *cellBackgroundUnselectedColor;

@property (nonatomic, assign) CGFloat cellLayerRadius;

@property (nonatomic, assign) BOOL    cellBackgroundColorGradientEnabled;

- (void)showRedPointAtIndexs:(NSArray<NSNumber *> *)indexs;

- (void)showRedPointAtIndex:(NSInteger)index;

- (void)hideRedPointAtIndex:(NSInteger)index;

/**
 Select at index
 will not tiger delegate callback

 @param index index
 */
- (void)selectAtIndex:(NSInteger)index;

/**
 Select at index
 will tiger delegate callback
 
 @param index index
 */
- (void)clickSelectItemAtIndex:(NSInteger)index;

/**
 Select at index
 only type is ThingSegmentItemSelectTypeClick, will tiger delegate callback
 
 @param index index
 */
- (void)selectCellAtIndex:(NSInteger)index selectedType:(ThingSegmentItemSelectType)ThingSegmentItemSelectTypeScroll;
- (void)selectCellAtIndex:(NSInteger)targetIndex selectedType:(ThingSegmentItemSelectType)selectedType animated:(BOOL)animated;
@end

NS_ASSUME_NONNULL_END


