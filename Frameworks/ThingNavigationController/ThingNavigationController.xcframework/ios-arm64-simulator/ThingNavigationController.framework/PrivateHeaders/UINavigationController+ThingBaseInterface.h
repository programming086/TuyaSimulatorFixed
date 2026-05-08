//
//  UINavigationController+ThingBaseInterface.h
//  ThingNavigationController
//
//  Created by ThingInc on 2019/9/17.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationController (ThingBaseInterface)

@property (nonatomic) BOOL thing_refreshEnable;
@property (nonatomic) BOOL thing_inPushAnimation;

// key: sel  value: target
@property (nonatomic, strong, readonly) NSMapTable<NSString *, id> *thing_pushFinishRefresh;

- (void)_thing_refreshBackAndLeftItems;
- (void)_thing_refreshCenterItem;
- (void)_thing_refreshRightItem;

@end

NS_ASSUME_NONNULL_END
