//
//  TYMenuListDefaultCell.h
//  TYUIKit
//
//  Created by TuyaInc on 2019/12/5.
//

#import <UIKit/UIKit.h>

#import "TYMenuListViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYMenuListDefaultCellData : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) UIImage *image;

/// 设置图片颜色
@property (nonatomic, strong, nullable) UIColor *tintColor;

/// 设置标题字体
@property (nonatomic, strong, nullable) UIFont *titleFont;


+ (instancetype)dataWithTitle:(NSString *)title image:(UIImage *)image;
+ (instancetype)dataWithTitle:(NSString *)title image:(UIImage *)image tintColor:(UIColor *)tintColor;

@end

@interface TYMenuListDefaultCell : UITableViewCell <TYMenuListCellProtocol>

@end

NS_ASSUME_NONNULL_END
