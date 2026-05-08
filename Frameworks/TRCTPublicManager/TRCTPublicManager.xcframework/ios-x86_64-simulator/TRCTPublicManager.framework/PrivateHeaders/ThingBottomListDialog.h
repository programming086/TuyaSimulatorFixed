//
//  ThingBottomListDialog.h
//  ThingSmartPublic
//
//  Created by 冯晓 on 16/4/11.
//  Copyright © 2016年 Thing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

@protocol ThingBottomListDialogDelegate <NSObject>

- (void)didSelectCell:(NSString *)name;

@end

@interface ThingBottomListDialog : UIView

- (instancetype)initWithFrame:(CGRect)frame titles:(NSArray *)titles selectedString:(NSString *)selectedString changeCallback:(ThingSuccessString)changeCallback;


- (void)show;

@property (nonatomic, weak) id <ThingBottomListDialogDelegate> delegate;

@end
