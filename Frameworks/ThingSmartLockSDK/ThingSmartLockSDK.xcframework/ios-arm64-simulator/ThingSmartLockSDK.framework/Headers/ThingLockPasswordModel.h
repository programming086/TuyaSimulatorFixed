//
//  ThingLockPasswordModel.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, LockPasswordType) {
    ThingLockPasswordLimitOnlineType = 1,
    ThingLockPasswordOnceOfflineType,
    ThingLockPasswordLimitOfflineType,
    ThingLockPasswordPermanentOnlineType,
};

typedef NS_ENUM(NSUInteger, ThingLockActionStatus) {
    ThingLockCreatingStatus = 1001, // 创建中
    ThingLockCreatFailStatus,// 创建失败
    ThingLockDeletingStatus, // 删除中
    ThingLockWaitEffectStatus, // 待生效
    ThingLockEffectiveStatus, // 已生效
    ThingLockInvalidStatus, // 已过期
    ThingLockEffectiveDeleteFailStatus, // 生效中（删除失败）
    ThingLockInvalidDeleteFailStatus, // 已过期（删除失败）
    ThingLockWaitEffectDeleteFailStatus, // 待生效（删除失败）
    ThingLockDeleteFailStatus, // 删除失败
};


@class ThingLiveCycleModel;

@interface ThingLockPasswordModel : NSObject

@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *passwordName;
@property (nonatomic, strong) NSString *periodType;
@property (nonatomic, strong) NSString *passwordId;
@property (nonatomic, assign) ThingLockActionStatus status;
@property (nonatomic, assign) LockPasswordType passwordType;
@property (nonatomic, strong) NSString *operatorName;
@property (nonatomic, strong) NSString *lockId;
@property (nonatomic, strong) ThingLiveCycleModel *liveCycle;

@end

NS_ASSUME_NONNULL_END
