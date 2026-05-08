
#import <UIKit/UIKit.h>

#import "ThingMenuListViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingMenuListDefaultCellData : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) UIImage *image;

/// Set picture color
@property (nonatomic, strong, nullable) UIColor *tintColor;

/// Set title font
@property (nonatomic, strong, nullable) UIFont *titleFont;


+ (instancetype)dataWithTitle:(NSString *)title image:(UIImage *)image;
+ (instancetype)dataWithTitle:(NSString *)title image:(UIImage *)image tintColor:(UIColor *)tintColor;

@end

@interface ThingMenuListDefaultCell : UITableViewCell <ThingMenuListCellProtocol>

@end

NS_ASSUME_NONNULL_END
