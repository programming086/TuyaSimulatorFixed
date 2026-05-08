
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSearchController;

@protocol ThingSearchTableCustomProtocol <NSObject>

@required
+ (instancetype)new;
- (__kindof UITableView *)tableViewWithFrame:(CGRect)frame style:(UITableViewStyle)style;

@optional
@property (nonatomic, weak) ThingSearchController *searchController;

- (void)searchControllerStatusDidChanged:(ThingSearchController *)searchController;
- (void)searchController:(ThingSearchController *)searchController textDidChange:(NSString *)searchText;

@end

NS_ASSUME_NONNULL_END
