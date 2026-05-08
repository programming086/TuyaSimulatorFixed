//
//  ThingMallProtocol.h
//  ThingModuleServices
//
//  Created by ThingInc on 2018/6/7.
//

#ifndef ThingMallProtocol_h
#define ThingMallProtocol_h

#import <Foundation/Foundation.h>
#import "ThingMallInfo.h"

typedef NS_ENUM(NSUInteger, ThingMallPageType) {
    ThingMallPageTypeHome,      // Mall home page
    ThingMallPageTypeOrders,    // Mall orders page
};

typedef void(^ThingMallInfoCompletion)(ThingMallInfo * _Nullable mall, NSError * _Nullable error);

@protocol ThingMallProtocol <NSObject>


/**
 * Get the store jump link and switch information.
 * Only one successful request will be executed per app lifecycle, and thereafter the cached data will be returned.
 * Alway use cache fisrt.
 */
- (void)fetchMallInfoWithCompletion:(ThingMallInfoCompletion)completion;

/**
 * Request special mall page with `ThingMallPageType`
 * You should replace mall page every time after logged user changed.
 * @param pageType Mall page type
 */
- (void)requestMallPage:(ThingMallPageType)pageType completionBlock:(void(^)(__kindof UIViewController *page, NSError *error))callback;

/**
 * Request special mall page with url
 * You should replace mall page every time after logged user changed.
 * @param url Mall url
 */
- (void)requestMallPageWithUrl:(NSString *)url completionBlock:(void(^)(__kindof UIViewController *page, NSError *error))callback;

/**
 * After the successful call of the fetchMallInfoWithCompletion method, you can directly obtain the cached information.
 */
- (ThingMallInfo * _Nullable)cachedMallInfo;

/**
 * Mall view controller, may be MiniApp Container，H5 Container
 */
- (UIViewController *)mallViewController;


#pragma mark deprecated

/**
 * Check if mall enable for current logged user.
 * You should check this every time after logged user changed.
 */
- (void)checkIfMallEnableForCurrentUser:(void(^)(BOOL enable, NSError *error))callback __attribute__((deprecated("use fetchMallInfoWithCompletion: instead.")));

/**
 * Request special mall url with `ThingMallPageType`
 * @param pageType Mall page type
 */
- (void)requestMallUrlWithPage:(ThingMallPageType)pageType completionBlock:(void(^)(NSString *url, NSError *error))callback __attribute__((deprecated("use fetchMallInfoWithCompletion: instead.")));


@end

#endif /* ThingMallProtocol_h */
