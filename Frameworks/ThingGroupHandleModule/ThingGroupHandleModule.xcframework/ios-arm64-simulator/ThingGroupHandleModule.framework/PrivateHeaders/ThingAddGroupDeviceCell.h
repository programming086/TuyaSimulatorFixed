//
//  ThingAddGroupDeviceCell.h
//  ThingSmart
//
//  Created by 冯晓 on 15/12/14.
//  Copyright © 2015年 Thing. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ThingAddGroupDeviceCell;
@protocol ThingAddGroupDeviceCellDelegate <NSObject>

- (void)didSelectCell:(ThingAddGroupDeviceCell *)cell checked:(BOOL)checked;

@end

@interface ThingAddGroupDeviceCell : ThingTableViewCell


@property (nonatomic,strong) UIButton    *checkButton;
@property (nonatomic,weak) id <ThingAddGroupDeviceCellDelegate> delegate;

- (void)setItem:(ThingSmartGroupDevListModel *)item;

@end
