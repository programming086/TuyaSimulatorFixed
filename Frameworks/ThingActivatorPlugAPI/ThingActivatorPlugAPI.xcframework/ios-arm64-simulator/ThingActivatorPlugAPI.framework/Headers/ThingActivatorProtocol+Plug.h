
#ifndef ThingActivatorProtocol_h
#define ThingActivatorProtocol_h

NS_ASSUME_NONNULL_BEGIN
/*
 *  This protocol has been deprecated
 */

typedef NS_ENUM(NSUInteger, ThingActivatorCompletionNode) {
    ThingActivatorCompletionNodeNormal
};

@class ThingSmartHome;
@class ThingSmartDeviceModel;
@class ThingSmartDeviceCategoryModel;
@class ThingActivatorEntryConfig;

/// An instance to listen to a network configuration process
@protocol ThingActivatorCustomObservationProtocol <NSObject>

@required
/// Remove listener
- (void)dispose;

@end

/// Network configuration module
@protocol ThingActivatorProtocol <NSObject>

/// Navigate to the network configuration homepage
/// @param config Can be null
- (void)goActivatorRootViewWithConfig:(ThingActivatorEntryConfig *)config;

/// Network configuration process accessed from homepage
/// @param completion Callback when configuration is complete
///     - userInfo Possible fields
///         - Device array: deviceArray: [ThingActivatorResultModel]
///         - Number of device addition failures: failureDeviceCount: NSNumber
///         - Error messages from device addition failures: failureList: [ThingSmartActivatorModel]
///         - Device ID array: devIDList: [NSString]
///     - rootViewController Configuration homepage
///     - finishViewController Configuration completion page
///
/// @note Higher priority than `[ThingActivatorExternalExtensionTool gotoCustomVC:]`
- (void)gotoCategoryViewControllerWithCustomBackAction:(BOOL(^)(NSDictionary *userInfo, __kindof UIViewController *rootViewController,  __kindof UIViewController *finishViewController))completion;

/// Configuration process accessed via RN/router entry. Register beforehand, callback after completion
///
/// @note
///   If the configuration process entered via `gotoCategoryViewControllerWithCustomBackAction:` has not ended (lifecycle of the page is still active), its callback will be prioritized, and this method's callback will be ignored
///
///   Higher priority than `[ThingActivatorExternalExtensionTool gotoCustomVC:]`
///
///   Only one listener `id<ThingActivatorCustomObservationProtocol>` will be retained, repeated calls will overwrite previous listeners
///
/// @param completion Callback when configuration is complete, return YES for custom handling, return NO for default logic. `id<ThingActivatorCustomObservationProtocol>` will strongly reference `completion`, so `completion` should not strongly reference `id<ThingActivatorCustomObservationProtocol>` to avoid circular references
///         - observation Registered listener, calling `-[observation dispose]` will remove listener, otherwise there will always be callbacks
///         - rootViewController Configuration root page, may be null if not found
///         - finishViewController Configuration completion page
///         - userInfo Refer to `gotoCategoryViewControllerWithCustomBackAction:`
///  @return id<ThingActivatorCustomObservationProtocol> Listener
- (id<ThingActivatorCustomObservationProtocol>)registerActivatorProcessWithCompletionBlock:(BOOL(^)(NSDictionary *userInfo,
                                                                                                 __kindof UIViewController * _Nullable rootViewController,
                                                                                                 __kindof UIViewController *finishViewController))completion;

/**
 *  Obtain device information after each device connection
 *  @param node completion node, default ThingActivatorCompletionNodeNormal
 *  @param customJump default false, set true for process not need to jump to de device panel
 */
- (void)activatorCompletion:(ThingActivatorCompletionNode)node customJump:(BOOL)customJump completionBlock:(void (^)(NSArray * _Nullable deviceList))callback;



/**
 Add a sub-device from ZigBee gateway details page
 Navigate to - Add sub-device details page
 
 @param devId Zigbee gateway device ID
 */
- (void)gotoZigbeeCategoryViewControllerWithGatewayId:(NSString * _Nullable)devId;

/**
 Navigate to - Custom network configuration device selection page

 @param customCategoryName Custom class name
 */
- (void)gotoCustomCategoryViewController:(NSString * _Nullable)customCategoryName;

/// Add sub-device for IPC base station, Navigate to - Add sub-device details page
/// @param gatewayId IPC base station ID
/// @param subProductId Sub-product ID
- (void)subDevicePrepareViewWithGatewayId:(NSString *)gatewayId subProductId:(NSString *)subProductId;

/// Add sub-device for IPC base station, Navigate to - Add sub-device details page
/// @param gatewayId IPC base station ID
/// @param subProductId Sub-product ID
/// @param userInfo Additional fields
- (void)subDevicePrepareViewWithGatewayId:(NSString *)gatewayId subProductId:(NSString *)subProductId userInfo:(nullable NSDictionary *)userInfo;

/// Device network configuration list page
/// @param parentId Parent ID
- (UIViewController *)manualActivatorViewController:(NSString *)parentId;


/// Start quick network configuration scan
/// @param vc Page supporting scan
/// @param completion Callback when a popup is found
- (void)startScanInVC:(__kindof UIViewController *)vc completion:(nullable dispatch_block_t)completion;
- (void)stopScan;

/// Whether the quick scan dialog is showing
/// @param vc Current page
- (BOOL)dialogInVcWhetherIsShowing:(__kindof UIViewController *)vc;

/**
 Navigate to - Device network configuration page (includes manual and search)
 
 */
- (void)goActivatorRootView;
/**
 Navigate to - Device network configuration page (includes manual and search)
 
 @param productId Device ID
 @param section Manual search index
 */
- (void)goActivatorRootView:(NSString *)productId selectSection:(NSInteger)section;

/**
 Navigate to - Sub-device search network configuration page
 
 @param gwId Gateway ID
 */
- (void)gotoSearchSubDeviceVC:(NSString *)gwId;

/**
 Navigate to - Route gateway configure sub-device page
 Supports Lightning Network Configuration and ZigBee sub-device configuration
 
 @param gwid Gateway ID
 @param custom Reserved field
 */
- (void)gotoRouteGatewayConfigVC:(NSString *)gwid customData:(NSDictionary * _Nullable)custom;

/**
 Register notification for changes in route gateway device list

 @param needListen Whether to listen for registration
 @param completion Callback for listening
 */
- (void)listenDeviceListChange:(BOOL)needListen completion: (void(^)(void))completion;

/**
 Return list of devices needing WiFi channel configuration
 */
- (NSArray *)deviceNeedWifiChannelConfig;

/**
 Check if a device needs WiFi channel configuration
 */
- (BOOL)isDeviceNeedWifiChannelConfigWithDevice:(ThingSmartDeviceModel *)deviceModel;

/**
 * into WiFi channel page to config device
 * @prama devices         devices need connect wifi
 * @prama completion      result block,  need to update devices when 'finished' value is true, use - deviceNeedWifiChannelConfig
 */
- (void)configDeviceThroughWifiChannel:(NSArray *)devices completion:(void (^)(BOOL cancle,BOOL finished))completion;

/**
 * into WiFi channel page to config device
 * @prama devices  devices need connect wifi
 * @prama config  entry config
 * @prama completion result block,  need to update devices when 'finished' value is true, use - deviceNeedWifiChannelConfig
 */
- (void)configDeviceThroughWifiChannel:(NSArray *)devices
                                config:(nullable ThingActivatorEntryConfig *)config
                            completion:(void (^)(BOOL cancle, BOOL finished))completion;

/**
 *  WiFi channel to config single device
 * @prama deviceId       device need connect wifi
 * @prama completion     result block
 */
- (void)configSingleDeviceThroughWifiChannel:(NSString *)deviceId completion:(void(^)(BOOL success))completion;


/**
 *  WiFi channel to config single device
 * @prama deviceId       device need connect wifi
 * @prama startCallBack  start callback block
 * @prama completion     result block
 */
- (void)configSingleDeviceThroughWifiChannel:(NSString *)deviceId startCallBack:(void(^)(BOOL start))startCallBack completion:(void(^)(BOOL success))completion;


/// Retrieve the third-level category detail data from the network configuration list (preferentially fetch category information from disk cache)
/// @param PID Product ID
/// @param category Category
/// @param success Success callback
/// @param failure Failure callback
///
/// @note Preferentially use PID for retrieval
- (void)getCategoryDetailWithPID:(NSString * _Nullable)PID
                        category:(NSString * _Nullable)category
                         success:(void(^)(ThingSmartDeviceCategoryModel * _Nullable model))success
                         failure:(void(^)(NSError *error))failure;

/// Navigate to the manual network configuration process for the corresponding third-level category
/// @param categoryModel Third-level category
- (void)gotoAcvitavorWithCategoryModel:(ThingSmartDeviceCategoryModel *)categoryModel;

/// Navigate to the manual network configuration process for the corresponding third-level category
/// @param categoryModel Third-level category
/// @param userInfo Additional fields
///    - userInfo Possible fields
///         - Gateway ID, used when configuring ZigBee sub-devices: gwid: gatewayModel.id
- (void)gotoAcvitavorWithCategoryModel:(ThingSmartDeviceCategoryModel *)categoryModel userInfo:(NSDictionary *)userInfo;

/// Open the QR code scanning page
/// @param userInfo reserved field
- (void)gotoQRCodeViewControllerWithUserInfo:(nullable NSDictionary *)userInfo;

#pragma mark - deprecated
@optional
- (void)startScanVCName:(NSString *)vcName completion: (void(^)(void))completion __deprecated_msg("This method is deprecated, Use [ThingActivatorProtocol startScanInVC:completion:]");

/**
 * Jump to pairing network home page
 */
- (void)gotoCategoryViewController __deprecated_msg("-goActivatorRootViewWithConfig:");

@end
NS_ASSUME_NONNULL_END

#endif /* ThingActivatorProtocol_h */

