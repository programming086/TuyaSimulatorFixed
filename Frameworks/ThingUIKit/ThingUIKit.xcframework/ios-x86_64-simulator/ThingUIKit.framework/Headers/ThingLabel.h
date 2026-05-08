
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLabel : UILabel

#pragma mark - EdgeInsets
/**
 [^en]label edge insets, negative means 'outset'[$en]
 */
@property (nonatomic) UIEdgeInsets thing_edgeInsets;


#pragma ParagraphStyle

@property (nonatomic) CGFloat thing_lineSpace; ///< [^en]line space[$en]
@property (nonatomic) CGFloat thing_wordSpace; ///< [^en]word space[$en]

@property (nonatomic, strong) NSMutableParagraphStyle *thing_paragraphStyle;

- (void)thing_refreshParagraphStyleImmediately;

@end

NS_ASSUME_NONNULL_END
