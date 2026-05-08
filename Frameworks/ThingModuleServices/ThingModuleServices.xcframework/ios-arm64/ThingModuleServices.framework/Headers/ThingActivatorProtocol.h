//
//  ThingActivatorProtocol.h
//  ThingModuleServices
//
//  Created by ThingInc on 2018/4/13.
//

#ifndef ThingActivatorProtocol_h
#define ThingActivatorProtocol_h

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingActivatorCompletionNode) {
    ThingActivatorCompletionNodeNormal
};

@class ThingSmartHome;

@protocol ThingActivatorProtocol <NSObject>

/**
 * Start config
 */
- (void)gotoCategoryViewController;

/**
 *  Obtain device information after each device connection
 *  @param node completion node, default ThingActivatorCompletionNodeNormal
 *  @param customJump default false, set true for process not need to jump to de device panel
 */
- (void)activatorCompletion:(ThingActivatorCompletionNode)node customJump:(BOOL)customJump completionBlock:(void (^)(NSArray * _Nullable deviceList))callback;

/**
 *  Open qrcode view 
 *  @param userInfo reserved parameter
 */
- (void)gotoQRCodeViewControllerWithUserInfo:(nullable NSDictionary *)userInfo;


@end
NS_ASSUME_NONNULL_END

#endif /* ThingActivatorProtocol_h */

