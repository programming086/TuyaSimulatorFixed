
#import <UIKit/UIKit.h>

#import "ThingUIBarButtonItem.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ThingNavigationBarItemContainerPosition_Center,
    ThingNavigationBarItemContainerPosition_Left,
    ThingNavigationBarItemContainerPosition_Right,
} ThingNavigationBarItemContainerPosition;

@interface ThingNavigationBarItemContainer : UIButton

@property (nonatomic) UIEdgeInsets thing_layoutAlignmentInsets;

- (instancetype)initWithItems:(NSArray<ThingUIBarButtonItem *> *)array alignment:(ThingNavigationBarItemContainerPosition)alignment;

+ (instancetype)containerWithItems:(NSArray<ThingUIBarButtonItem *> *)array alignment:(ThingNavigationBarItemContainerPosition)alignment;

@end

NS_ASSUME_NONNULL_END
