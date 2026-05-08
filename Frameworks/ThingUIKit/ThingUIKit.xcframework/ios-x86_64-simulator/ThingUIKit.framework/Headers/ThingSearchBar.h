
#import <UIKit/UIKit.h>

#import "ThingSearchBarAppearance.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSearchBarDelegate <UISearchBarDelegate>

@optional
- (void)thing_searchBarCancelButtonInitial;

@end


/**
 Available After ThingSmart 3.9.0+
 */
@interface ThingSearchBar : UISearchBar

@property(nonatomic, weak) id<ThingSearchBarDelegate> _Nullable delegate;

@property (nonatomic, getter = thing_isActive) BOOL thing_active;

@property (nonatomic, weak, readonly)  UITextField * thing_textField;
@property (nonatomic) UIEdgeInsets thing_textFieldInsets;

/**
 cancel button will not create until it show, so getter method may return nil
 you can use delegate method -thing_searchBarCancelButtonInitial to capture it
 */
@property (nonatomic, weak, readonly)  UIButton * _Nullable thing_cancelButton;
@property (nonatomic) UIEdgeInsets thing_cancelButtonInsets;

@property (nonatomic, strong) UIColor * _Nullable thing_seperatorColor __deprecated_msg("Use ty_separatorColor instead");
@property (nonatomic, strong) UIColor * _Nullable thing_separatorColor;

@end

NS_ASSUME_NONNULL_END
