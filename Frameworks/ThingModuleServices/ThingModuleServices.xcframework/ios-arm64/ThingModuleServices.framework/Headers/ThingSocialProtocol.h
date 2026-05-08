//
//  ThingSocialProtocol.h
//  ThingSocialOverseas
//
//  Created by ThingInc on 2018/11/29.
//

#ifndef ThingSocialProtocol_h
#define ThingSocialProtocol_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ThingSocialShareModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingSocialType) {
    ThingSocialWechat          = 0,
    ThingSocialWechatMoment    = 1,
    ThingSocialQQ              = 2,
    ThingSocialQQSpace         = 3,
    ThingSocialEmail           = 7,
    ThingSocialSMS             = 8,
    ThingSocialMore            = 11,
};

typedef NS_ENUM(NSUInteger, ThingSocialShareContentType) {
    ThingSocialShareContentText,
    ThingSocialShareContenttImage,
    ThingSocialShareContentH5,
    ThingSocialShareContentImageUrl,
    ThingSocialShareContentFileURL
};

typedef void (^ThingSuccessHandler)(void);
typedef void (^ThingFailureHandler)(void);

@protocol ThingSocialProtocol <NSObject>

@optional

// register
- (void)registerWithType:(ThingSocialType)type appKey:(NSString *)appKey appSecret:(NSString *)appSecret universalLink:(NSString *)universalLink;

// share
- (void)shareTo:(ThingSocialType)type shareModel:(ThingSocialShareModel *)shareModel success:(ThingSuccessHandler)success failure:(ThingFailureHandler)failure;

// avaliable or not
- (BOOL)avaliableForType:(ThingSocialType)type;

// openURL
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<NSString *,id> *)options;

// continueUserActivity
- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSocialProtocol_h */

