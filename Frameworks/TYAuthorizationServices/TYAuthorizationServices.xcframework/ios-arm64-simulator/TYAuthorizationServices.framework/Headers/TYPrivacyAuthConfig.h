//
//  TYPrivacyAuthConfig.h
//  Pods
//
//  Created by kaier on 2022/1/5.
//

#import <Foundation/Foundation.h>
#import "TYNotificationsAuthProtocol.h"

typedef NS_OPTIONS(NSInteger, TYPrivacyAuthType) {
    TYPrivacyAuthTypeLocation,
    TYPrivacyAuthTypePhotots,
    TYPrivacyAuthTypeCamera,
    TYPrivacyAuthTypeMicrophone,
    TYPrivacyAuthTypeBluetooth,
    TYPrivacyAuthTypeHomeKit,
    TYPrivacyAuthTypeLocalNetwork,
    TYPrivacyAuthTypeNotification,
    TYPrivacyAuthTypeContact,
};

typedef NS_ENUM(NSInteger, TYPrivacyAuthStatus) {
    TYPrivacyAuthStatusUnable = -1,
    TYPrivacyAuthStatusNotDetermined,
    TYPrivacyAuthStatusAllowed,
    TYPrivacyAuthStatusRefused
};

typedef void(^TYPrivacyAuthCheckCompletionBlock)(void);

typedef UITableViewCell TYCommonActionSheetCell;

@interface TYPrivacyAuthConfig : NSObject

/// 权限类型
@property (nonatomic) TYPrivacyAuthType type;

/// 标题，不传使用默认文案
@property (nonatomic, strong) NSString *title;

/// 描述，不传使用默认文案
@property (nonatomic, strong) NSString *desc;

/// 图片，不传使用默认图片
@property (nonatomic, strong) UIImage *iconImage;

/// 权限关闭状态时的指示图片，不传使用默认图片
@property (nonatomic, strong) UIImage *indicateImage;

/// 当 type == TYPrivacyAuthTypeNotification 时，使用该属性设置请求通知权限的类型
@property (nonatomic) TYUNAuthorizationOptions notificationOptions;

@property (nonatomic, copy) TYPrivacyAuthCheckCompletionBlock statusBlock;

+ (instancetype)configWithAuthType:(TYPrivacyAuthType)type;

@end
