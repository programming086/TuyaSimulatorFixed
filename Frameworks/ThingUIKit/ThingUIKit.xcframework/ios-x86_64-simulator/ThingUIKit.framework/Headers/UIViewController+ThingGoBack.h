//
//  UIViewController+ThingGoBack.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/10/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (ThingGoBack)

/*
 [^en]go back to previous page，including present page[$en]
 */
- (void)thing_goBackToPreviousPage:(BOOL)animated;

- (void)thing_goBackToPreviousPage:(BOOL)animated completion:(dispatch_block_t)completion;

- (void)thing_goBackToFirstPage:(BOOL)animated;

- (void)thing_goBackToFirstPage:(BOOL)animated completion:(dispatch_block_t)completion;

- (void)thing_popOrDismissWithCompletion:(void(^)(void))completion;

@end

NS_ASSUME_NONNULL_END
