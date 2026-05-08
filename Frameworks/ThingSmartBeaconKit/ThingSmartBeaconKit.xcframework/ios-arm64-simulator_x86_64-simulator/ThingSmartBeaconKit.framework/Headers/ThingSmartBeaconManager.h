

#import <Foundation/Foundation.h>
@class ThingSmartBeaconActiveParamsModel;
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,ThingBeaconResponseAction) {
    ThingBeaconResponseActionAuth = -1,
    ThingBeaconResponseActionCheck,
};

typedef NS_ENUM(NSInteger,ThingBeaconRequestAction) {
    ThingBeaconRequestActionAuth = -1,
    ThingBeaconRequestActionCheck,
    ThingBeaconRequestActionAbandon,
    ThingBeaconRequestActionSubscribe,
    ThingBeaconRequestActionSearch,
};

@class ThingBLEAdvModel;
@class ThingSmartBeaconRequestModel;
@class ThingSmartBeaconResponseModel;
@class ThingSmartDeviceModel;

@protocol ThingSmartBeaconManagerDelegate <NSObject>
@optional
- (void)didDiscoveryDeviceWithUUID:(NSString *)uuid productKey:(nullable NSString *)productKey __deprecated_msg("This method is deprecated, Use didDiscoveryDeviceWithDeviceInfo: instead");

- (void)didDiscoveryDeviceWithDeviceInfo:(ThingBLEAdvModel *)deviceInfo;

/// beacon device report
/// @param responseAction beacon device response action
/// @param deviceId device id
/// @param responseModel response data model
- (void)didReceiveChannelResponseWithAction:(ThingBeaconResponseAction)responseAction deviceId:(NSString *)deviceId responseModel:(ThingSmartBeaconResponseModel *)responseModel;


///  all beacon device List
- (NSArray <ThingSmartDeviceModel *>*)deviceListDataSource;
@end


@protocol ThingSmartBLEManagerDelegate;




@interface ThingSmartBeaconManager : NSObject

@property (nonatomic, assign, readonly) BOOL isPoweredOn;
@property (nonatomic, weak) id<ThingSmartBeaconManagerDelegate,ThingSmartBLEManagerDelegate> delegate;

/// The single instance.
+ (instancetype)sharedInstance;

/// Whether to disable bluetooth capability. Default NO
+ (void)disableBLECapability:(BOOL)disable;

#pragma mark - activate

/// Activates the beacon device. advModel is cached and removed when activated
/// @param advModel The advertisingData model for the beacon device.
/// @param homeId The ID for the current home.
/// @param success Called when the task is finished. DeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)activateBeacon:(ThingBLEAdvModel*)advModel homeId:(long long)homeId success:(void (^)(ThingSmartDeviceModel *deviceModel))success failure:(void(^)(NSError *error))failure __deprecated_msg("This method is deprecated, Use activateBeaconListWithParams:activatedDeviceSuccess:activatedDeviceFailure:activatedFinish: instead");

/// Activates the beacon device list
/// @param paramsModel params model
/// @param deviceSuccess individual device activated success block
/// @param deviceFailure individual devicev activated  failure block
/// @param activatedFinish  all devices activated finish . when there is an error, All devices are abnormal .
- (void)activateBeaconListWithParams:(ThingSmartBeaconActiveParamsModel *)paramsModel
              activatedDeviceSuccess:(void (^)(ThingSmartDeviceModel *deviceModel))deviceSuccess
              activatedDeviceFailure:(void (^)(ThingBLEAdvModel *advModel ,NSError *error))deviceFailure
                     activatedFinish:(void (^)(NSError *error))activatedFinish;

/// update beacon mesh model
/// @param meshModel  mesh model params
- (void)updateBeaconMesh:(ThingSmartBleMeshModel *)meshModel;

/// The end of the pairing process.
- (void)stopActivatingBeacons:(NSArray<ThingBLEAdvModel*>*)beacons;

/// Stop activating all cached beacon devices
- (void)stopActivatingAllBeacons;


#pragma mark - action

/// Publishes the transmitted data.
/// @param deviceId The device ID for the device.
/// @param dps The DP dictionary.
/// @param success Called when the task is finished.
/// @param failure  Called when the task is interrupted by an error.
- (void)publishDpsWithDevicId:(NSString *)deviceId dps:(nonnull NSDictionary *)dps success:(void(^)(void))success failure:(void(^)(NSError *error))failure;


/// Checks and sets the online status of a device.
/// @param deviceModel The device model.
- (void)checkDeviceOnlineStateWithDevice:(ThingSmartDeviceModel *)deviceModel;

/// Checks and sets the online status of all beacon devices.
/// @param deviceModelList The device model list.
- (void)checkAllBeaconDeviceOnlineState:(NSArray<ThingSmartDeviceModel *> *)deviceModelList;

/// Connects to the device and sets the online status of the device.
/// @param deviceId The device ID.
- (void)connectBeaconWithDeviceId:(NSString *)deviceId;


/// Resets the device and enables the pairing status for the device.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)resetWithDevId:(NSString *)devId success:(void(^)(void))success failure:(void(^)(void))failure;

///  The online status of the beacon device.
/// @param uuid The UUID of the beacon device.
- (BOOL)deviceStatueWithUUID:(NSString *)uuid;


/// Checks gateway online status of the beacon device
/// @param deviceModel The device model.
- (BOOL)gatewayOnlineOfDevice:(ThingSmartDeviceModel *)deviceModel;


/// publish beacon  command data
/// @param requestAction publish request action
/// @param deviceId device id
/// @param requestModel publish data model
- (void)publishChannelRequestWithAction:(ThingBeaconRequestAction)requestAction
                               deviceId:(NSString *)deviceId
                           requestModel:(ThingSmartBeaconRequestModel *)requestModel;


@end

NS_ASSUME_NONNULL_END
