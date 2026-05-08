//
//  ThingValueAddedServiceProtocol.h
//  ThingModuleServices
//
//  Created by ThingInc on 2019/5/28.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@protocol ThingValueAddedServiceProtocol <NSObject>

@optional

typedef void (^failureBlock)(NSError *error);

typedef void (^successBoolBlock)(BOOL result);

/**
 * jump to Amazon link home page
 * @params success callback
 * @params failure callback
 */
- (void)goToAmazonAlexaLinkViewControllerSuccess:(successBoolBlock)success
                                         failure:(failureBlock)failure;

/**
 * jump to Google link home page
 * @params success callback
 * @params failure callback
 */
- (void)goToGoogleAssitantLinkViewControllerSuccess:(successBoolBlock)success
                                            failure:(failureBlock)failure;

/// Call it inside method application:continueUserActivity:restorationHandler: in Appdelegate.m
- (BOOL)thing_application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^ __nonnull)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler API_AVAILABLE(ios(8.0));


/**
 * get all third party voice binded list
 * @param success callback
 * @param failure callback
 */
- (void)getAllThirdPartyVoiceBindingStatus:(void (^_Nullable)(id _Nullable result))success failure:(failureBlock _Nullable )failure;


/**
 * to deactive third party
 * @param statusData  from  getAllThirdPartyVoiceBindingStatus
 */
- (void)goToDeactiveViewController:(NSDictionary *_Nullable)statusData;


@end

