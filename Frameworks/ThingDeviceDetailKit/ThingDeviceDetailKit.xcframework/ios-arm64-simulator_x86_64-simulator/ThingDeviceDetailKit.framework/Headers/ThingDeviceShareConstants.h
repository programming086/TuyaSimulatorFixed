
#import <Foundation/Foundation.h>
#import <ThingSmartShareKit/ThingSmartShareKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceShareResult : NSObject

/// The relationship ID.
@property (nonatomic, assign) NSInteger memberId;

/// The nickname.
@property (nonatomic, strong) NSString  *nickName;

/// The username that is the phone number or email address.
@property (nonatomic, strong) NSString  *userName;

@end


@interface ThingDeviceShareInfo : NSObject

@property (nonatomic, copy) NSString *content;

@property (nonatomic, copy) NSString *code;

@property (nonatomic, copy) NSString *shortUrl;

@end


typedef NS_ENUM(NSInteger, ThingDeviceShareType) {
    ThingDeviceShareTypeAccount = 0,
    ThingDeviceShareTypeQQ = 1,
    ThingDeviceShareTypeWechat = 2,
    ThingDeviceShareTypeMessage = 3,
    ThingDeviceShareTypeEmail = 4,
    ThingDeviceShareTypeCopy = 5,
    ThingDeviceShareTypeMore = 6,
    ThingDeviceShareTypeContact = 7,
};


@interface ThingDeviceShareCodeInfo : NSObject

@property (nonatomic, copy) NSString *appId;
/// Device/Group id
@property (nonatomic, copy) NSString *resId;
/// Resource type: 1 Device type, 2 Group type
@property (nonatomic, assign) ThingShareResType resType;
/// Device/Group icon
@property (nonatomic, copy) NSString *resIcon;
/// Device/Group name
@property (nonatomic, copy) NSString *resName;

/// Name of the sharer
@property (nonatomic, copy) NSString *nickName;
/// Sharing channels
@property (nonatomic, assign) ThingDeviceShareType shareSource;
/// Group id of the sharer
@property (nonatomic, assign) long long groupId;

@end



@interface ThingDeviceSharer : NSObject

/// The relationship ID.
@property (nonatomic, assign) NSInteger memberId;

/// The nickname.
@property (nonatomic, strong) NSString  *nickName;

/// The username that is the phone number or email address.
@property (nonatomic, strong) NSString  *userName;


@end


@interface ThingDeviceSharerDetail : NSObject

/// The shared devices
@property (nonatomic, strong) NSArray <ThingSmartShareDeviceModel *> *devices;

/// The account information, email, or phone number.
@property (nonatomic, strong) NSString *mobile;

/// The user nickname.
@property (nonatomic, strong) NSString *name;

/// The remarks.
@property (nonatomic, strong) NSString *remarkName;

@end



NS_ASSUME_NONNULL_END
