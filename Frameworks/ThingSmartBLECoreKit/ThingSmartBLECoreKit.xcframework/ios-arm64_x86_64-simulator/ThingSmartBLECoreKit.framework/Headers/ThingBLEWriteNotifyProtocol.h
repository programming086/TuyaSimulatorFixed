
#ifndef ThingBLEWriteNotifyProtocol_h
#define ThingBLEWriteNotifyProtocol_h

#import "ThingBLECryptologyProtcol.h"
#import "ThingSmartBLEMutliTsfDefine.h"

@class ThingBLEWriteNotify;
@protocol ThingBLEWriteNotifyDelegate <NSObject>

@optional

- (void)didPackagedNotifyData:(NSData *)data;

- (void)didPackagedNotifyType:(frame_type_t)type data:(NSData *)data;

@end

@protocol ThingBLEDeviceInfoProtocol;
@protocol ThingBLEWriteNotifyProtocol <NSObject>

@property (nonatomic, strong) ThingBLEWriteNotify *writeNotify;

@property(nonatomic, weak) id<ThingBLEWriteNotifyDelegate> delegate;/// < 接受数据代理

/// 向蓝牙设备下发数据
/// @param deviceInfo deviceInfo
/// @param type type
/// @param data data
/// @param success success
/// @param failure failure

- (void)writeDataWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                           type:(ThingBLEConfigType)type
                           data:(NSData *)data
                        success:(ThingSuccessData)success
                        failure:(ThingFailureError)failure;

@end

#endif /* ThingBLEWriteNotifyProtocol_h */
