
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// General error
extern NSErrorDomain const ThingDeviceDetailKitErrorDomain;

typedef NS_ENUM(NSInteger, ThingDeviceDetailKitError) {
    //base
    ThingDeviceDetailKitGeneralError = -10000, //general error
    
    //device
    ThingDeviceDetailKitDeviceError = -10010, //device error
    ThingDeviceDetailKitDeviceNullError = -10011, //device is nil
    ThingDeviceDetailKitDeviceOfflineError = -10012, //device is offline
    
    //group
    ThingDeviceDetailKitGroupError = -10020, //group error
    ThingDeviceDetailKitGroupNullError = -10021, //group is nil
    
    
    //timer
    ThingDeviceDetailKitTimerError = -10030, //timer error
    ThingDeviceDetailKitTimerExtraError = -10031, //get data extra of timer fail
    ThingDeviceDetailKitTimerBleTransmissionTimeoutError = -10032, //ble transmission time out
    ThingDeviceDetailKitTimerBleDataParseError = -10033, //ble data parse error
    ThingDeviceDetailKitTimerDeviceCannotSyncError = -10034, //device can not sync
    
    //channel
    ThingDeviceDetailKitChannelError = -10040, //channel error
    ThingDeviceDetailKitChannelSetupTimeoutError = -10041, //settup channel time out
    ThingDeviceDetailKitChannelSetupSubDeviceExistError = -10042, //sub device exist
    ThingDeviceDetailKitChannelSetupDeviceCloudOfflineError = -10043, //device cloud offline
    ThingDeviceDetailKitChannelSetupUnsupportError = -10044, //not support
    ThingDeviceDetailKitChannelSetupDeviceSizeError = -10045, //device size error
    
    //reboot
    ThingDeviceDetailKitRebootError = -10050, //reboot error
    ThingDeviceDetailKitRebootDeviceOfflineError = -10051, //device LAN and Cloud offline
    ThingDeviceDetailKitRebootTimeoutError = -10052, //reboot time out
    ThingDeviceDetailKitRebootDeviceError = -10053, //reboot generate error

    
    //share
    ThingDeviceDetailKitShareError = -10060, //share error
    ThingDeviceDetailKitShareUserAccountNil = -10061, //user account is nil
    ThingDeviceDetailKitShareSpaceIdNil = -10062, //space is nil
    
    
    //anti-misoperation
    ThingDeviceDetailKitAntiMisoperationError = -10070, //anti-misoperation error
    ThingDeviceDetailKitAntiMisoperationTimeoutError = -10071, //anti-misoperation time out
    
    
    //subdevice replace
    ThingDeviceDetailKitSubDeviceReplaceError = -10080, //subdevice replace error
    ThingDeviceDetailKitSubDeviceReplaceParamsError = -10081, //params error
    ThingDeviceDetailKitSubDeviceReplaceNetworkError = -10082, //network error
    ThingDeviceDetailKitSubDeviceReplaceTimeoutError = -10083, //timeout error
    ThingDeviceDetailKitSubDeviceReplaceFailError = -10084, //fail error

};



/// Bluetooth protocol layer error
extern NSErrorDomain const ThingDeviceTimerBleSyncErrorDomain;

/// Reason for operation failure
typedef NS_ENUM(NSInteger, ThingDeviceTimerBleSyncErrorCode) {
    /// Unable to retrieve error code (data is empty or data bytes are too short)
    ThingTimerBleTimerProtocolErrorCode_DataError = -1,
    /// Protocol layer defines only one error code 0x01
    ThingTimerBleTimerProtocolErrorCode_Unknow  = 0x01
};

NS_ASSUME_NONNULL_END
