
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSearchBarContainer : UIView

@property (nonatomic, weak) UISearchBar *searhBar;

- (instancetype)initWithSearchBar:(UISearchBar *)searchBar;

@end

NS_ASSUME_NONNULL_END
