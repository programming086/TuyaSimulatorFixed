//
//  TYSocialProtocol.h
//  TYSocialOverseas
//
//  Created by TuyaInc on 2018/11/29.
//

#ifndef TYSocialProtocol_h
#define TYSocialProtocol_h

#import <Foundation/Foundation.h>

@class TYSocialShareModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TYSocialType) {
    TYSocialWechat          = 0,
    TYSocialWechatMoment    = 1,
    TYSocialQQ              = 2,
    TYSocialQQSpace         = 3,
    TYSocialEmail           = 7,
    TYSocialSMS             = 8,
    TYSocialMore            = 11,
};

typedef NS_ENUM(NSUInteger, TYSocialShareContentType) {
    TYSocialShareContentText,
    TYSocialShareContenttImage,
    TYSocialShareContentH5,
    TYSocialShareContentImageUrl,
    TYSocialShareContentFileURL
};

typedef void (^TYSuccessHandler)(void);
typedef void (^TYFailureHandler)(void);

@protocol TYSocialProtocol <NSObject>

@optional

// register
- (void)registerWithType:(TYSocialType)type appKey:(NSString *)appKey appSecret:(NSString *)appSecret universalLink:(NSString *)universalLink;

// share
- (void)shareTo:(TYSocialType)type shareModel:(TYSocialShareModel *)shareModel success:(TYSuccessHandler)success failure:(TYFailureHandler)failure;

// avaliable or not
- (BOOL)avaliableForType:(TYSocialType)type;

// openURL
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<NSString *,id> *)options;

// continueUserActivity
- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;

@end

NS_ASSUME_NONNULL_END

#endif /* TYSocialProtocol_h */

