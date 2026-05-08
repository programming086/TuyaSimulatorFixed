//
//  TYValueAddedServiceProtocol.h
//  TYModuleServices
//
//  Created by TuyaInc on 2019/5/28.
//

#ifndef TYValueAddedServiceProtocol_h
#define TYValueAddedServiceProtocol_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, ThingPersonalServiceType) {
    ThingPersonalServiceTypePushCall,
    ThingPersonalServiceTypePushSMS,
};


@protocol TYValueAddedServiceProtocol <NSObject>

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
- (BOOL)ty_application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^ __nonnull)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler API_AVAILABLE(ios(8.0));


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

/**
 * request personal service page with `ThingPersonalServiceType`
 * You should replace personal service page every time after logged user changed.
 * @param type personal service page
 */
- (void)requestPersonalService:(ThingPersonalServiceType)type completionBlock:(void(^)(__kindof UIViewController *page, NSError *error))callback;

@end


#endif /* TYValueAddedServiceProtocol_h */
