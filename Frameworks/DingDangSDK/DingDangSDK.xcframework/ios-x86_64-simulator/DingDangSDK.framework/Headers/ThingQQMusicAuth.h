
#import <TVSCore/TVSCore.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// QQ音乐授权成功以后会发生该通知
#define Thing_QQMUSIC_AUTH_SUCCESS @"ThingQQMusicAuthSuccess"

@interface ThingQQMusicAuth : NSObject

+ (instancetype)sharedInstance;

+ (BOOL)qqMusicHandleOpenURL:(NSURL *)url;

- (void)registerWithAppId:(NSString *)appId appSecret:(NSString *)appSecret qqAppId:(NSString *)qqAppId;

- (void)qqAuthWithPid:(NSString *)pid sn:(NSString *)sn qqLoginCallBack:(void (^)(void))qqLoginCallBack success:(void (^)(void))success failure:(void (^)(NSError * error))failure;

- (void)isDeviceBindedWithPid:(NSString *)pid sn:(NSString *)sn success:(void (^)(BOOL isBind))success;

@end

NS_ASSUME_NONNULL_END
