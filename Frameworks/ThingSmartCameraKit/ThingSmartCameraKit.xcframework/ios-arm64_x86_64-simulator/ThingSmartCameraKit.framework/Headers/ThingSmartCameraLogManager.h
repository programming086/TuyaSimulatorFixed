
#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, ThingSmartCameraSDKType) {
    ThingSmartCameraSDKTypeP2P, //P2PSDK
    ThingSmartCameraSDKTypeAV, //CameraSDK
    ThingSmartCameraSDKTypeCamera //CameraKit
};

@interface ThingSmartCameraLogManager : NSObject

+ (instancetype)sharedInstance;

- (NSArray *)SDKVersions;

- (NSString *)SDKVersionForSDKType:(ThingSmartCameraSDKType)SDKType;

- (void)enableDebug:(BOOL)enabled;

@end

