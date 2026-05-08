
//#import "TUNINativeModuleKit.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TUNINativeModuleKit;
@interface TUNINativeBridgeContext : NSObject

@property (nonatomic, weak) UIViewController *customViewController;
@property (nonatomic, assign) CGFloat customStatusBarHeight;
@property (nonatomic, strong) NSDictionary *customContextProperties;
@property (nonatomic, strong) NSString *customAppID;
@property (nonatomic, assign) CGFloat customUsableWindowWidth;
@property (nonatomic, assign) CGFloat customUsableWindowHeight;
@property (nonatomic, strong) NSDictionary *customRequestHeaders;
@property (nonatomic, strong) NSString *customCacheDir;
@property (nonatomic, strong) NSString *customUserDataDir;
@property (nonatomic, strong) NSString *customLocalizationPath;
@property (nonatomic, strong) NSString *customResourceDir;

@end

NS_ASSUME_NONNULL_END
