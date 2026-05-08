
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMiniAppExtApiContext <NSObject>

///return context vc
- (UIViewController *)viewControllerForContext;

///return context statusBarHeight
- (CGFloat)statusBarHeightForContext;

///BizParam , e.g. @"devIds",@"productIds",@"i18nTimes"
- (NSDictionary *)contextProperties;

///appid , miniprogramId
- (NSString *)appIDForContext;

///useableWindowWidth
- (CGFloat)useableWindowWidthForContext;

///useableWindowHeight
- (CGFloat)useableWindowHeightForContext;

@optional

///The temp directory, limited 2GB
- (NSString *)tempDirForContext;
///The cache directory, Share 200 MB with the userData directory
- (NSString *)cacheDirForContext;
///The userData directory, Share 200 MB with the cache directory
- (NSString *)userDataDirForContext;
///The Localization directory 
- (NSString *)localizationPathForContext;
///The resource directory 
- (NSString *)resourceDirForContext;
@end

NS_ASSUME_NONNULL_END
