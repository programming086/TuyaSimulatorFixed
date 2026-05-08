//
//  ThingBleMeshGroupFailureView.h
//  ThingSmartKitExample
//
//  Created by XuChengcheng on 2017/11/16.
//  Copyright © 2017年 thing. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ThingGroupFailureView : UIView

@property (nonatomic, strong) UIButton *closeBtn;

- (void)showWithTitle:(NSString *)title actList:(NSDictionary *)actList;

@end
