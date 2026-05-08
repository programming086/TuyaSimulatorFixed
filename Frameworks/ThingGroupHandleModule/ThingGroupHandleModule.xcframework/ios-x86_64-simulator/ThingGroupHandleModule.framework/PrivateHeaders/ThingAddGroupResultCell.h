//
//  ThingAddGroupResultCell.h
//  ThingGroupHandleModule
//
//  Created by Lucca on 2018/9/13.
//

#import <UIKit/UIKit.h>

@class ThingSmartGroupDevListModel;
@interface ThingAddGroupResultCell : ThingTableViewCell


- (void)configureWithModel:(ThingSmartGroupDevListModel *)model subTitle:(NSString *)subTitle;

@end
