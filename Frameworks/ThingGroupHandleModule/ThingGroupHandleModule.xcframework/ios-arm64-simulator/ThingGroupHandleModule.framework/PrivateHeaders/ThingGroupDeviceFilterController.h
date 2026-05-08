//
//  ThingGroupDeviceFilterController.h
//  ThingGroupHandleModule
//
//  Created by 后主 on 2023/11/15.
//

#import <UIKit/UIKit.h>
#import "ThingGroupHandleModuleConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupDeviceFilterController : UIViewController

@property (nonatomic, strong, readonly) ThingGroupHandleModuleRoomRelation *roomRelation;

@property (nonatomic, copy) void(^selectedHandle)(NSArray<id<ThingGroupDeviceFilter>> *filters);

@property (nonatomic, copy) void(^removeHandle)(void);

- (instancetype)initWithRoomRelation:(ThingGroupHandleModuleRoomRelation *)roomRelation filters:(nullable NSArray<id<ThingGroupDeviceFilter>> *)filters;

- (void)showInController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
