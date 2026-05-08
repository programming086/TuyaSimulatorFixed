//
//  ThingDeviceDetailProtocol.h
//  ThingDeviceDetailModule
//
//  Created by 黄凯 on 2018/9/5.
//

#ifndef ThingDeviceDetailProtocol_h
#define ThingDeviceDetailProtocol_h

@class ThingSmartDeviceModel;
@class ThingSmartGroupModel;
@protocol ThingDeviceDetailCustomMenuModel;

//@param type configList.json里自己添加的type
//@param device  设备模型
//@param group   群组模型。 根据group是否为nil，来判断设备还是群组
//@return 遵守TYDeviceDetailCustomMenuModel协议的对象。返回nil，该type的item则不会显示
typedef id<ThingDeviceDetailCustomMenuModel> _Nullable (^InsertDevMenuItemBlock)(NSString*  _Nonnull type,
                                                                           ThingSmartDeviceModel* _Nullable device,
                                                                           ThingSmartGroupModel* _Nullable group);

//回调数据给设备详情
typedef void (^InsertDevMenuItemComplete)(id<ThingDeviceDetailCustomMenuModel> _Nullable menuItem);

//异步处理item插入，当异步操作结束以后，调用complete(),回调数据给设备详情，并进行刷新列表。根据group是否为nil，来判断设备还是群组
typedef void (^InsertDevMenuItemAsyncBlock)(NSString* _Nonnull type,
                                            ThingSmartDeviceModel* _Nullable device,
                                            ThingSmartGroupModel* _Nullable group,
                                            InsertDevMenuItemComplete _Nonnull complete);

//插入item被点击时候回调。根据group是否为nil，来判断设备还是群组
typedef void (^ClickMenuItemBlock)(NSString* _Nonnull type,
                                   ThingSmartDeviceModel* _Nullable device
                                   ,ThingSmartGroupModel* _Nullable group);

@protocol ThingDeviceDetailProtocol <NSObject>

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
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(ThingSmartDeviceModel *)device group:(ThingSmartGroupModel *)group;

- (void)insertDevMenuItem:(InsertDevMenuItemBlock) insertDevMenuItemBlock __deprecated_msg("Use insertDevMenuItem:customType: instead");

///清空设置的自定义item
- (void)clearInsertItem;

/// 设置-》同步处理item插入的回调
/// @param insertDevMenuItemBlock 同步处理item插入回调
- (void)insertDevMenuItem:(InsertDevMenuItemBlock) insertDevMenuItemBlock customType:(NSString *)type;

- (void)insertDevMenuItemAsync:(InsertDevMenuItemAsyncBlock) insertDevMenuItemAsyncBlock __deprecated_msg("Use insertDevMenuItemAsync:customType: instead");

/// 设置-》异步处理item插入的回调
/// @param insertDevMenuItemAsyncBlock  异步处理item插入的回调
- (void)insertDevMenuItemAsync:(InsertDevMenuItemAsyncBlock) insertDevMenuItemAsyncBlock customType:(NSString *)type;

/// 设置-》插入item被点击时候回调
/// @param clickMenuItemBlock  clickMenuItemBlock
- (void)clickMenuItem:(ClickMenuItemBlock) clickMenuItemBlock;

@optional
/// 获取红外子设备是否显示
/// @param devId 网关id，传入非红外线网关或者子设备将返回 **YES**
/// @param spaceId 空间id
/// @return YES，展示；NO，不展示
- (BOOL)getInfraredDisplayStatusWithDevId:(nullable NSString *)devId spaceId:(long long)spaceId;

@optional
/// 判断设备是否开启了显示红外子设备
/// @param devId 网关id
/// @param spaceId 空间id
/// @return YES，展示；NO，不展示
- (BOOL)cacheOfInfraredDisplayStatusWithDevId:(nullable NSString *)devId spaceId:(long long)spaceId;

@optional
/// 设备是否开启了显示红外子设备 状态变化通知名称
- (nullable NSNotificationName)subDeviceDisplayStatusChangeNotificationName;

@end

/// 设备详情自定义item的数据必须遵守的协议
@protocol ThingDeviceDetailCustomMenuModel <NSObject>
///标题
@property (nonatomic,copy) NSString *title;

///子标题
@property (nonatomic,copy) NSString *detail;


@end

#endif /* ThingDeviceDetailProtocol_h */
