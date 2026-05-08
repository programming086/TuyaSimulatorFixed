
#import <Foundation/Foundation.h>
@class ThingGatewayTransferManager;

NS_ASSUME_NONNULL_BEGIN




/// The status of transfer
typedef NS_ENUM(NSUInteger, ThingGatewayTransferStatus) {
    ThingGatewayTransferStatusUnknown = 0,
    ThingGatewayTransferStatusDeviceConfigInit = 1,
    ThingGatewayTransferStatusDeviceDataInit = 2,
    ThingGatewayTransferStatusOsConfigInit = 3,
    ThingGatewayTransferStatusFinish = 4,
    ThingGatewayTransferStatusFailed = 5,
    ThingGatewayTransferStatusNone = 6,
};



/// The status model of transfer
@interface ThingGatewayTransferInfo: NSObject

/// The device id of the faulty gateway
@property (nonatomic, strong) NSString *targetDeviceId;

/// The device name of the faulty gateway
@property (nonatomic, strong) NSString *targetDeviceName;

/// The device id of the source gateway
@property (nonatomic, strong) NSString *sourceDeviceId;

/// The status of transfer
@property (nonatomic, assign) ThingGatewayTransferStatus status;

/// The failed code, returned when failed
@property (nonatomic, strong) NSString *failedCode;

/// the time in millisecond when status changed.
@property (nonatomic, assign) double time;

@end





/// The delegate of the ThingGatewayTransferManager
@protocol ThingGatewayTransferManagerDelegate <NSObject>
- (void)transferManager:(ThingGatewayTransferManager *)manager statusDidUpdate:(ThingGatewayTransferInfo *)model;
@end





@interface ThingGatewayTransferManager : NSObject

/// Determine whether the device support transfer or not. True if can otherwise false
/// - Parameters:
///   - deviceId: the id of the device which you want to transfer.
///   - success: success callback
///   - failure: failure callback with error
+ (void)deviceSupportsTransfer:(NSString *)deviceId success:(void(^)(BOOL support))success failure:(void(^)(NSError *error))failure;



/// Get the transfer info of the device
/// You can only call this method when the 'deviceSupportsTransfer:success:failure:' or 'deviceSupportsTransferWithSuccess:failure:' success with true.
/// - Parameters:
///   - deviceId: the id of the device which you want to transfer.
///   - success: success callback with ThingGatewayTransferInfo
///   - failure: failure callback with error
+ (void)deviceTransferInfoWithDeviceId:(NSString *)deviceId success:(void(^)(ThingGatewayTransferInfo *model))success failure:(void(^)(NSError *error))failure;


/// Get the gateways
/// You can only call this method when the 'deviceSupportsTransfer:success:failure:' or 'deviceSupportsTransferWithSuccess:failure:' success with true.
/// - Parameters:
///   - deviceId: the id of the device which you want to transfer.
///   - success: success callback with the device id of gateways
///   - failure: failure callback with error
+ (void)gatewaysWithDeviceId:(NSString *)deviceId success:(void(^)(NSArray<NSString *> *gatewayIds))success failure:(void(^)(NSError *error))failure;


/// Transfer the device to the specified gateway
/// You can only call this method when the 'deviceSupportsTransfer:success:failure:' or 'deviceSupportsTransferWithSuccess:failure:' success with true.
/// - Parameters:
///   - from: the device id of the gateway, which is one of the result returned by 'retrieveDeviceTransferGatewaysWithSuccess:failure:'
///   - to: the device id of the current gateway
///   - success: success callback
///   - failure: failure callback with error
+ (void)transferFromGateway:(NSString *)from toGateway:(NSString *)to success:(void(^)(ThingGatewayTransferInfo *model))success failure:(void(^)(NSError *error))failure;




/// Init a ThingGatewayTransferManager
/// - Parameter deviceId: the id of the device which you want to transfer.
- (instancetype)initWithDeviceId:(NSString *)deviceId;


/// Add a listener
/// - Parameter listener: the listener which confirm ThingGatewayTransferManager
- (void)addListener:(id<ThingGatewayTransferManagerDelegate>)listener;

/// Remove a listener
/// - Parameter listener: the listener which confirm ThingGatewayTransferManager
- (void)removeListener:(id<ThingGatewayTransferManagerDelegate>)listener;

/// Determine whether the device support transfer or not. True if can otherwise false
/// - Parameters:
///   - success: success callback
///   - failure: failure callback with error
- (void)deviceSupportsTransferWithSuccess:(void(^)(BOOL support))success failure:(void(^)(NSError *error))failure;

/// Get the transfer info of the device
/// You can only call this method when the 'deviceSupportsTransfer:success:failure:' or 'deviceSupportsTransferWithSuccess:failure:' success with true.
/// - Parameters:
///   - success: success callback with ThingGatewayTransferInfo
///   - failure: failure callback with error
- (void)deviceTransferInfoWithSuccess:(void(^)(ThingGatewayTransferInfo *model))success failure:(void(^)(NSError *error))failure;


/// Get the gateways
/// You can only call this method when the 'deviceSupportsTransfer:success:failure:' or 'deviceSupportsTransferWithSuccess:failure:' success with true.
/// - Parameters:
///   - success: success callback with the device id of gateways
///   - failure: failure callback with error
- (void)gatewaysWithSuccess:(void(^)(NSArray<NSString *> *gatewayIds))success failure:(void(^)(NSError *error))failure;


/// Transfer the device to the specified gateway
/// You can only call this method when the 'deviceSupportsTransfer:success:failure:' or 'deviceSupportsTransferWithSuccess:failure:' success with true.
/// - Parameters:
///   - gatewayId: the device id of the gateway, which is one of the result returned by 'retrieveDeviceTransferGatewaysWithSuccess:failure:'
///   - success: success callback
///   - failure: failure callback with error
- (void)transferFromGateway:(NSString *)gatewayId success:(void(^)(ThingGatewayTransferInfo *model))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
