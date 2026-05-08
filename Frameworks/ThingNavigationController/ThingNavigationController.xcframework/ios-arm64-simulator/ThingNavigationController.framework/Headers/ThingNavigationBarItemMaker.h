
#import <Foundation/Foundation.h>

@interface ThingNavigationBarItemMaker : NSObject

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^titleFont)(UIFont *font);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^status)(UIControlState status);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker * (^normalTitle)(NSString *str);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^normalTitleAttribute)(NSDictionary<NSAttributedStringKey, id> *dic);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker * (^selectTitle)(NSString *str);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^selectTitleAttribute)(NSDictionary<NSAttributedStringKey, id> *dic);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker * (^disableTitle)(NSString *str);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^disableTitleAttribute)(NSDictionary<NSAttributedStringKey, id> *dic);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^normalImage)(UIImage *img);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^selectImage)(UIImage *img);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^disableImage)(UIImage *img);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^renderingMode)(UIImageRenderingMode mode);    /**< In Original mode, normalTintColor only applies to text. */

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^normalBackgroundColor)(UIColor *color);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^selectBackgroundColor)(UIColor *color);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^disableBackgroundColor)(UIColor *color);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^normalBackgroundImage)(UIImage *img);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^selectBackgroundImage)(UIImage *img);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^disableBackgroundImage)(UIImage *img);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^normalTintColor)(UIColor *color);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^selectTintColor)(UIColor *color);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^disableTintColor)(UIColor *color);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^alpha)(CGFloat alpha);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^size)(CGSize size);

/**
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^labelBreakMode)(NSLineBreakMode mode);
/**
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^imageContentMode)(UIViewContentMode mode);
/**
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^clipToBounds)(BOOL clip);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^titleInsets)(UIEdgeInsets insets);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^imageInsets)(UIEdgeInsets insets);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^contentInsets)(UIEdgeInsets insets);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^leftEdge)(CGFloat edge);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^rightEdge)(CGFloat edge);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^offset)(UIOffset offset);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^userInteractionEnabled)(BOOL userInteractionEnabled);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^hitExtend)(UIEdgeInsets hitExtend);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^target)(id target);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^action)(SEL sel);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^tag)(NSInteger tag);

@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^isAccessibilityElement)(BOOL isAccessibilityElement);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^accessibilityIdentifier)(NSString *accessibilityIdentifier);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^accessibilityTraits)(UIAccessibilityTraits traits);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^accessibilityLabel)(NSString *accessibilityLabel);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^accessibilityHint)(NSString *accessibilityHint);
@property (nonatomic, copy, readonly) ThingNavigationBarItemMaker *(^accessibilityValue)(NSString *accessibilityValue);

@end
