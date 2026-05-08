//
//  TYActivatorProtocol.h
//  TYModuleServices
//
//  Created by TuyaInc on 2018/4/13.
//

#ifndef TYActivatorProtocol_h
#define TYActivatorProtocol_h

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TYActivatorCompletionNode) {
    TYActivatorCompletionNodeNormal
};

@class TuyaSmartHome;
@class TuyaSmartDeviceModel;
@class TuyaSmartDeviceCategoryModel;

/// 对一个配网流程的监听实例
@protocol TYActivatorCustomObservationProtocol <NSObject>

@required
/// 移除监听
- (void)dispose;

@end

@protocol TYActivatorProtocol <NSObject>

/**
 * Start config
 */
- (void)gotoCategoryViewController;

/// 从配网首页进入的配网流程
/// @param completion 配网完成的回调
///     - userInfo  可传字段
///         - 设备数组：deviceArray: [TYActivatorResultModel]
///         - 设备添加失败的数量：failureDeviceCount: NSNumber
///         - 设备添加失败的错误提示：failureList: [TYSmartActivatorModel]
///         - 设备ID数组：devIDList: [NSString]
///     - rootViewController 配网首页
///     - finishViewController 配网完成页面
///
/// @note 优先级高于 `[TYActivatorExternalExtensionTool gotoCustomVC:]`
- (void)gotoCategoryViewControllerWithCustomBackAction:(BOOL(^)(NSDictionary *userInfo, __kindof UIViewController *rootViewController,  __kindof UIViewController *finishViewController))completion;

/// RN/路由等进入口进入的配网流程 。提前注册，配网完成后回调
///
/// @note
///   如果通过 `gotoCategoryViewControllerWithCustomBackAction:` 进入的配网流程尚未结束（页面的生命周期还在），会优先处理它的回调，忽略本方法回调
///
///   优先级高于 `[TYActivatorExternalExtensionTool gotoCustomVC:]`
///
///   只会保留一份监听者 `id<TYActivatorCustomObservationProtocol>`，重复调用会覆盖之前的监听者
///
/// @param completion 配网完成回调，返回 YES 自定义处理，返回 NO 默认逻辑。 `id<TYActivatorCustomObservationProtocol>` 会强引用 `completinon`，所以 `completion` 不能强引用 `id<TYActivatorCustomObservationProtocol>`，会造成循环引用
///         - observation 注册后的监听者，调用 `-[observation dispose]` 会移除监听，否则一直会有回调
///         - rootViewController 配网根页面，如果找不到，可能为空
///         - finishViewController 配网完成页面
///         - userInfo 参考 `gotoCategoryViewControllerWithCustomBackAction:`
///  @return id<TYActivatorCustomObservationProtocol> 监听者
- (id<TYActivatorCustomObservationProtocol>)registerActivatorProcessWithCompletionBlock:(BOOL(^)(NSDictionary *userInfo,
                                                                                                 __kindof UIViewController * _Nullable rootViewController,
                                                                                                 __kindof UIViewController *finishViewController))completion;

/**
 *  Obtain device information after each device connection
 *  @param node completion node, default TYActivatorCompletionNodeNormal
 *  @param customJump default false, set true for process not need to jump to de device panel
 */
- (void)activatorCompletion:(TYActivatorCompletionNode)node customJump:(BOOL)customJump completionBlock:(void (^)(NSArray * _Nullable deviceList))callback;



/**
 ZigBee网关详情页添加子设备
 跳转到 - 添加子设备详情页
 
 @param devId Zigbee网关 设备Id
 */
- (void)gotoZigbeeCategoryViewControllerWithGatewayId:(NSString * _Nullable)devId;

/**
 跳转到 - 自定义配网设备选择页面
 
 @param customCategoryName customCategoryName 自定义类名
 */
- (void)gotoCustomCategoryViewController:(NSString * _Nullable)customCategoryName;

/// IPC 基站添加子设备 跳转到 - 添加子设备详情页
/// @param gatewayId IPC基站Id
/// @param subProductId subProductId
- (void)subDevicePrepareViewWithGatewayId:(NSString *)gatewayId subProductId:(NSString *)subProductId;

/// 设备配网列表页
/// @param parentId parentId
- (UIViewController *)manualActivatorViewController:(NSString *)parentId;


/// 开启快捷配网扫描
/// @param vc 支持扫描的页面
/// @param completion 搜索到弹出框回调
- (void)startScanInVC:(__kindof UIViewController *)vc completion:(nullable dispatch_block_t)completion;
- (void)stopScan;

/**
配网添加设备引导
 
 */
- (void)showUserGuideInVC:(NSString *)VC completion:(void (^)(void))completion;

///快捷扫描弹窗是否显示
/// @param vc 当前页面
- (BOOL)dialogInVcWhetherIsShowing:(__kindof UIViewController *)vc;

/**
 跳转到 - 设备配网页面（包含手动和搜索）
 
 */
- (void)goActivatorRootView;
/**
 跳转到 - 设备配网页面（包含手动和搜索）
 
 @param productId 设备ID
 @param section 手动搜索的索引项
 */
- (void)goActivatorRootView:(NSString *)productId selectSection:(NSInteger)section;

/**
 跳转到 - 子设备搜索配网页面
 
 @param gwId 网关ID
 */
- (void)gotoSearchSubDeviceVC:(NSString *)gwId;

/**
 跳转到 - 路由网关配子设备页面
 支持闪电配网与 ZigBee 子设备配网
 
 @param gwid 网关ID
 @param custom 预留字段
 */
- (void)gotoRouteGatewayConfigVC:(NSString *)gwid customData:(NSDictionary * _Nullable)custom;

/**
注册路由网关设备列表变化通知
 
 @param needListen 是否需要监听注册
 @param completion 监听回调
 */
- (void)listenDeviceListChange:(BOOL)needListen completion: (void(^)(void))completion;

/**
返回未激活设备列表
 */
- (NSArray *)deviceNeedWifiChannelConfig;

/**
返回未激活设备
 */
- (BOOL)isDeviceNeedWifiChannelConfigWithDevice:(TuyaSmartDeviceModel *)deviceModel;

/**
 * into WiFi channel page to config device
 * @prama devices         devices need connect wifi
 * @prama completion      result block,  need to update devices when 'finished' value is true, use - deviceNeedWifiChannelConfig
 */
- (void)configDeviceThroughWifiChannel:(NSArray *)devices completion:(void (^)(BOOL cancle,BOOL finished))completion;

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


/// 获取配网列表三级品类详情数据（优先取磁盘缓存中的品类信息）
/// @param PID 产品ID
/// @param category 品类
/// @param success 成功回调
/// @param failure 失败回调
///
/// @note 优先用 pid 获取
- (void)getCategoryDetailWithPID:(NSString * _Nullable)PID
                        category:(NSString * _Nullable)category
                         success:(void(^)(TuyaSmartDeviceCategoryModel * _Nullable model))success
                         failure:(void(^)(NSError *error))failure;

/// 跳转到三级品类对应的手动配网流程
/// @param categoryModel 三级品类
- (void)gotoAcvitavorWithCategoryModel:(TuyaSmartDeviceCategoryModel *)categoryModel;

#pragma mark - deprecated
- (void)startScanVCName:(NSString *)vcName completion: (void(^)(void))completion __deprecated_msg("This method is deprecated, Use [TYActivatorProtocol startScanInVC:completion:]");

@end
NS_ASSUME_NONNULL_END

#endif /* TYActivatorProtocol_h */

