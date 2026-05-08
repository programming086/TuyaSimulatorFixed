//
//  TYDeviceDetailPlugAPI.h
//  Pods
//
//  Created by 萧然 on 2022/4/6.
//

#ifndef TYDeviceDetailPlugAPI_h
#define TYDeviceDetailPlugAPI_h

@class TuyaSmartDeviceModel;
@class TuyaSmartGroupModel;
@protocol TYDeviceDetailCustomMenuModel;

//@param type configList.json里自己添加的type
//@param device  设备模型
//@param group   群组模型。 根据group是否为nil，来判断设备还是群组
//@return 遵守TYDeviceDetailCustomMenuModel协议的对象。返回nil，该type的item则不会显示
typedef id<TYDeviceDetailCustomMenuModel> _Nullable (^InsertDevMenuItemBlock)(NSString*  _Nonnull type,
                                                                           TuyaSmartDeviceModel* _Nullable device,
                                                                           TuyaSmartGroupModel* _Nullable group);

//回调数据给设备详情
typedef void (^InsertDevMenuItemComplete)(id<TYDeviceDetailCustomMenuModel> _Nullable menuItem);

//异步处理item插入，当异步操作结束以后，调用complete(),回调数据给设备详情，并进行刷新列表。根据group是否为nil，来判断设备还是群组
typedef void (^InsertDevMenuItemAsyncBlock)(NSString* _Nonnull type,
                                            TuyaSmartDeviceModel* _Nullable device,
                                            TuyaSmartGroupModel* _Nullable group,
                                            InsertDevMenuItemComplete _Nonnull complete);

//插入item被点击时候回调。根据group是否为nil，来判断设备还是群组
typedef void (^ClickMenuItemBlock)(NSString* _Nonnull type,
                                   TuyaSmartDeviceModel* _Nullable device
                                   ,TuyaSmartGroupModel* _Nullable group);


@protocol TYDeviceDetailProtocol <NSObject>

- (void)handleDeviceDetail:(NSDictionary *)query;

/**
 跳转到设备信息页, push 方式
 
 @param devId 设备
 @param isCamera 是否为摄像头
 */
- (void)gotoDeviceInfoViewControllerWithDeviceId:(NSString *)devId isCamera:(BOOL)isCamera;

/**
 跳转到网络检测页
 
 @param devId 设备 id
 */
- (void)gotoDeviceDetailNetworkViewControllerWithDeviceId:(NSString *)devId;

/**
 跳转到设备详情页，以 push 方式

 @param device 设备
 @param group 群组，若有就传
 */
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(TuyaSmartDeviceModel *)device group:(TuyaSmartGroupModel *)group;

/**
 跳转到设备详情页，以 push 方式

 @param device 设备
 @param group 群组，若有就传
 @param businessParams 业务参数，只做透传
 */
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(TuyaSmartDeviceModel *)device group:(TuyaSmartGroupModel *)group businessParams:(NSDictionary *)businessParams;

/**
 跳转到设备详情页，以 push 方式

 @param deviceId 设备id
 @param businessParams 业务参数，只做透传
 */
- (void)gotoDeviceDetailDetailViewControllerWithDeviceId:(NSString *)deviceId businessParams:(NSDictionary *)businessParams;

/**
 跳转到设备详情页，以 push 方式

 @param groupId 群组id
 @param businessParams 业务参数，只做透传
 */
- (void)gotoDeviceDetailDetailViewControllerWithGroupId:(NSString *)groupId businessParams:(NSDictionary *)businessParams;


/**
 跳转到群组中设备的设备详情页，以 push 方式

 @param device 设备
 @param isDevInGroup 是否是群组下的设备
 */
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(TuyaSmartDeviceModel *)device isDevInGroup:(BOOL)isDevInGroup;


/// 获取红点是否点击过
/// @param pid 当前用户操作的产品 id
- (BOOL)getRedPointRecordExistForProduct:(NSString *)pid;

/// 查询此产品 id 下，是否展示“推荐商品”入口
/// @param pid product id
/// @param success 成功
/// @param failure 失败
- (void)requestEnableAccessTMWithProductID:(NSString *)pid
                                   success:(void(^)(BOOL))success
                                   failure:(void(^)(void))failure;

/// 查询此产品 id 下，是否展示“推荐商品”入口。返回接口的全部数据
/// @param pid product id
/// @param success 成功
/// @param failure 失败
- (void)requestIfOpenTMWithProductID:(NSString *)pid
                                   success:(void(^)(NSDictionary *))success
                                   failure:(void(^)(void))failure;

/// 跳转到涂鸦商城
/// @param device 设备模型
/// @param tmUrlStr 商城URL
- (void)gotoTMWithProductId:(TuyaSmartDeviceModel *)device tmUrlStr:(NSString *)tmUrlStr;

/// 获取红外子设备是否显示
/// @param devId 设备id，传入非红外线网关或者子设备将返回 **YES**
/// @param spaceId 空间id
/// @return YES，展示；NO，不展示
- (BOOL)getInfraredDisplayStatusWithDevId:(nullable NSString *)devId spaceId:(long long)spaceId;

/// 判断设备是否开启了显示红外子设备
/// @param devId 红外网关id
/// @param spaceId 空间id
/// @return YES，展示；NO，不展示
- (BOOL)cacheOfInfraredDisplayStatusWithDevId:(nullable NSString *)devId spaceId:(long long)spaceId;


/// 设备是否开启了显示红外子设备 状态变化通知名称
- (nullable NSNotificationName)subDeviceDisplayStatusChangeNotificationName;

///清空设置的自定义item
- (void)clearInsertItem;

/// 设置-》同步处理item插入的回调
/// @param insertDevMenuItemBlock 同步处理item插入回调
-(void)insertDevMenuItem:(InsertDevMenuItemBlock) insertDevMenuItemBlock customType:(NSString *)type;
 
/// 设置-》异步处理item插入的回调
/// @param insertDevMenuItemAsyncBlock  异步处理item插入的回调
-(void)insertDevMenuItemAsync:(InsertDevMenuItemAsyncBlock) insertDevMenuItemAsyncBlock customType:(NSString *)type;
 
/// 设置-》插入item被点击时候回调
/// @param clickMenuItemBlock  clickMenuItemBlock
-(void)clickMenuItem:(ClickMenuItemBlock) clickMenuItemBlock;

@end

/// 设备详情自定义item的数据必须遵守的协议
@protocol TYDeviceDetailCustomMenuModel <NSObject>
///标题
@property (nonatomic,copy) NSString *title;

///子标题
@property (nonatomic,copy) NSString *detail;

@end

#endif /* TYDeviceDetailPlugAPI_h */
