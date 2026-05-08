
#import <UIKit/UIKit.h>

@class ThingAlignLabelMaker;

typedef NS_ENUM(NSUInteger, ThingAlignLabelType) {
    ThingAlignLabelType_top = 1,    ///< top aligned
    ThingAlignLabelType_left,       ///< left aligned
    ThingAlignLabelType_bottom,     ///< bottom aligned
    ThingAlignLabelType_right,      ///< right aligned
    ThingAlignLabelType_center      ///< Horizontal/Vertical Alignment
};

/// chain call
typedef ThingAlignLabelMaker *(^ThingAlignLabelMakerBlock)(void);

/// Unchained calls
typedef ThingAlignLabelMaker *(^ThingAlignLabelMakerTypeBlock)(ThingAlignLabelType alignType);


@interface ThingAlignLabel : UILabel
/**
 *  Align the text according to the set alignment
 *
 *  @param alignType Align block
 *  @discussion UILabel itself does not support vertical top, and this alignment can be achieved by overriding `textRectForBounds:limitedToNumberOfLines:`
 *  @Example
 *
 *   [titleLabel textAlign:^(ThingAlignLabelMaker *maker) {
 *      maker.top().center();
 *   }];
 */
-(void)textAlign:(void(^)(ThingAlignLabelMaker *maker))alignType;

@end


@interface ThingAlignLabelMaker : NSObject

/* chain call */
-(ThingAlignLabelMakerBlock)top;
-(ThingAlignLabelMakerBlock)left;
-(ThingAlignLabelMakerBlock)bottom;
-(ThingAlignLabelMakerBlock)right;
-(ThingAlignLabelMakerBlock)center;

/* Unchained calls */
-(ThingAlignLabelMakerTypeBlock)addAlignType;

@end


