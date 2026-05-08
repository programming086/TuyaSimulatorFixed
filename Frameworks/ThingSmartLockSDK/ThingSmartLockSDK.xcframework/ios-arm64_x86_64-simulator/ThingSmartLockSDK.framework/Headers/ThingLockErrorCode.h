//
//  ThingLockErrorCode.h
//  Pods
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#ifndef ThingLockErrorCode_h
#define ThingLockErrorCode_h

typedef NS_ENUM(NSUInteger, ThingLockErrorCode) {
    ThingLockNoneErrorCode = 11000,
    ThingLockOtherErrorCode,
    ThingLockSiteErrorCode,
    ThingLockDeviceIdErrorCode,
    ThingLockErrorEKeyNameErrorCode,
    ThingLockAccountErrorCode,
    ThingLockEffectiveTimeErrorCode,
    ThingLockInvalidTimeTimeErrorCode,
    ThingLockWorkDayErrorCode,
    ThingLockStartTimeErrorCode,
    ThingLockEndTimeErrorCode,
    ThingLockNameErrorCode,
    ThingLockOfflineErrorCode,
    ThingLockNotFindErrorCode, // 不存在，卡片、指纹等
    ThingLockDeleteFailErrorCode, // 删除失败
    ThingLockInputErrorCode, // 录入失败
    ThingLockCancelErrorCode, // 录入取消
    ThingLockPermissionErrorCode, // 权限错误
    ThingLockPairingErrorCode, // 主机配对失败
    ThingLockUnlockFailErrorCode, // 开锁失败
    ThingLockLockFailErrorCode, // 关锁失败
    ThingLockLockedErrorCode, // 锁是关闭状态
    ThingLockLockUnsupportErrorCode, // 不支持关锁
    ThingLockPasswordLenghtErrorCode, // 密码长度错误
    ThingLockPasswordFormatErrorCode, // 密码错误（纯数字）
    ThingLockPasswordDuplicationErrorCode, // 密码重复
    ThingLockTimeoutErrorCode, // 超时
};


#endif /* ThingLockErrorCode_h */
