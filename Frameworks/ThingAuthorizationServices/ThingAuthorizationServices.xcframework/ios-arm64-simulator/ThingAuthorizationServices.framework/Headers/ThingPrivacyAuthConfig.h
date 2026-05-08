
#import <Foundation/Foundation.h>
#import "ThingNotificationsAuthProtocol.h"

typedef NS_OPTIONS(NSInteger, ThingPrivacyAuthType) {
    ThingPrivacyAuthTypeLocation,
    ThingPrivacyAuthTypePhotots,
    ThingPrivacyAuthTypeCamera,
    ThingPrivacyAuthTypeMicrophone,
    ThingPrivacyAuthTypeBluetooth,
    ThingPrivacyAuthTypeHomeKit,
    ThingPrivacyAuthTypeLocalNetwork,
    ThingPrivacyAuthTypeNotification,
    ThingPrivacyAuthTypeContact,
};

typedef NS_ENUM(NSInteger, ThingPrivacyAuthStatus) {
    ThingPrivacyAuthStatusUnable = -1,
    ThingPrivacyAuthStatusNotDetermined,
    ThingPrivacyAuthStatusAllowed,
    ThingPrivacyAuthStatusRefused
};

typedef void(^ThingPrivacyAuthCheckCompletionBlock)(void);

typedef UITableViewCell ThingCommonActionSheetCell;

@interface ThingPrivacyAuthConfig : NSObject

/// Permission type
@property (nonatomic) ThingPrivacyAuthType type;

/// Title, default text will be used if not specified
@property (nonatomic, strong) NSString *title;

/// Description, if not specified, the default text will be used
@property (nonatomic, strong) NSString *desc;

/// Picture, use the default picture if not uploaded
@property (nonatomic, strong) UIImage *iconImage;

/// Indicator image when permission is disabled. If not passed, the default image will be used.
@property (nonatomic, strong) UIImage *indicateImage;

/// When type == ThingPrivacyAuthTypeNotification, use this property to set the type of notification permission requested.
@property (nonatomic) ThingUNAuthorizationOptions notificationOptions;

@property (nonatomic, copy) ThingPrivacyAuthCheckCompletionBlock statusBlock;

+ (instancetype)configWithAuthType:(ThingPrivacyAuthType)type;

@end
