//
//  ThingAddGroupResultView.h
//  ThingGroupHandleModule
//
//  Created by Lucca on 2018/9/13.
//

#import <UIKit/UIKit.h>

@class ThingSmartGroupDevListModel;

@interface ThingAddGroupResultView : UIView

- (void)showWithTitle:(NSString *)title
       addFailureList:(NSArray<ThingSmartGroupDevListModel *> *)failureAddList
    deleteFailureList:(NSArray<ThingSmartGroupDevListModel *> *)failureDeleteList
            doneBlock:(void(^)(void))doneBlock;

@end
