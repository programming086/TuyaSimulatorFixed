
#ifndef ThingDeviceDetailPlugAPI_h
#define ThingDeviceDetailPlugAPI_h

@class ThingSmartDeviceModel;
@class ThingSmartGroupModel;
@protocol ThingDeviceDetailCustomMenuModel;

//@param type The type you added in configList.json.
//@param device The device model.
//@param group Group model. Determines whether a device is a group based on whether group is nil or not
//@return An object that adheres to the ThingDeviceDetailCustomMenuModel protocol. If nil is returned, the item of this type will not be displayed.
typedef id<ThingDeviceDetailCustomMenuModel> _Nullable (^InsertDevMenuItemBlock)(NSString*  _Nonnull type,
                                                                           ThingSmartDeviceModel* _Nullable device,
                                                                           ThingSmartGroupModel* _Nullable group);

// Callback data to device details
typedef void (^InsertDevMenuItemComplete)(id<ThingDeviceDetailCustomMenuModel> _Nullable menuItem);

// Asynchronously process item insertion, when the asynchronous operation is finished, call complete(), callback data to device details, and refresh the list. According to whether group is nil, to determine whether the device is a group.
typedef void (^InsertDevMenuItemAsyncBlock)(NSString* _Nonnull type,
                                            ThingSmartDeviceModel* _Nullable device,
                                            ThingSmartGroupModel* _Nullable group,
                                            InsertDevMenuItemComplete _Nonnull complete);

// Insert the callback when the item is clicked. Determine if device or group is nil based on whether group is nil or not
typedef void (^ClickMenuItemBlock)(NSString* _Nonnull type,
                                   ThingSmartDeviceModel* _Nullable device
                                   ,ThingSmartGroupModel* _Nullable group);


@protocol ThingDeviceDetailProtocol <NSObject>

- (void)handleDeviceDetail:(NSDictionary *)query;

/**
 Jump to device information page, push method
 
 @param devId device
 @param isCamera Whether the device is a camera or not.
 */
- (void)gotoDeviceInfoViewControllerWithDeviceId:(NSString *)devId isCamera:(BOOL)isCamera;

/**
 Jump to network detection page
 
 @param devId device id
 */
- (void)gotoDeviceDetailNetworkViewControllerWithDeviceId:(NSString *)devId;

/**
 Jump to the device details page as push

 @param device
 @param group group, pass it if there is one.
 */
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(ThingSmartDeviceModel *)device group:(ThingSmartGroupModel *)group;

/**
 Jump to the device details page as push

 @param device
 @param group Group, if there is one, pass it.
 @param businessParams businessParams, passthrough only.
 */
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(ThingSmartDeviceModel *)device group:(ThingSmartGroupModel *)group businessParams:(NSDictionary *)businessParams;

/**
 Jump to the device details page as push

 @param deviceId device id
 @param businessParams Business parameters, passthrough only.
 */
- (void)gotoDeviceDetailDetailViewControllerWithDeviceId:(NSString *)deviceId businessParams:(NSDictionary *)businessParams;

/**
 Jump to the device details page, push method.

 @param groupId groupId
 @param businessParams Business parameters, only for passthrough.
 */
- (void)gotoDeviceDetailDetailViewControllerWithGroupId:(NSString *)groupId businessParams:(NSDictionary *)businessParams;

/**
 Jump to device detail page applet

 @param device device
 @param group Group, pass if there is one.
 @param businessParams businessParams, passthrough only
 */
- (BOOL)openDeviceDetailMiniProgramWithDevice:(ThingSmartDeviceModel *)device group:(nullable ThingSmartGroupModel *)group businessParams:(nullable NSDictionary *)businessParams;

/**
 Jump to virtual experience device detail page applet

 @param device device
 @param businessParams business parameters, passthrough only
 */
- (BOOL)openDeviceVirtualExperienceMiniProgramWithDevice:(ThingSmartDeviceModel *)device businessParams:(nullable NSDictionary *)businessParams;

/**
 Jump to the device details page of a device in the group as push

 @param device device
 @param isDevInGroup whether the device is in a group.
 */
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(ThingSmartDeviceModel *)device isDevInGroup:(BOOL)isDevInGroup;

/**
 Jump to the remote reboot screen as a push

 @param deviceId device id
 */
- (void)gotoDeviceRemoteRebootViewControllerWithDeviceId:(NSString *)deviceId;

/// Get whether the red dot has been clicked
/// @param pid the product id of the current user action
- (BOOL)getRedPointRecordExistForProduct:(NSString *)pid;

/// Queries if the ‘Recommended Products’ portal is displayed under this product id.
/// @param pid product id
/// @param success
/// @param failure
- (void)requestEnableAccessTMWithProductID:(NSString *)pid
                                   success:(void(^)(BOOL))success
                                   failure:(void(^)(void))failure;

/// Queries if the ‘Recommended Products’ portal is displayed under this product id. Returns all the data of the interface
/// @param pid product id
/// @param success
/// @param failure
- (void)requestIfOpenTMWithProductID:(NSString *)pid
                                   success:(void(^)(NSDictionary *))success
                                   failure:(void(^)(void))failure;

/// Jump to Thing Store
/// @param device device model
/// @param tmUrlStr mallURL
- (void)gotoTMWithProductId:(ThingSmartDeviceModel *)device tmUrlStr:(NSString *)tmUrlStr;

/// Get whether the infrared sub-device is displaying or not
/// @param devId device id, passing in a non-infrared gateway or sub-device will return **YES**.
/// @param spaceId spaceid
/// @return YES, show; NO, don't show.
- (BOOL)getInfraredDisplayStatusWithDevId:(nullable NSString *)devId spaceId:(long long)spaceId;

/// Determine if the device is enabled to display infrared sub-devices
/// @param devId infrared gateway id
/// @param spaceId space id
/// @return YES, display; NO, do not display
- (BOOL)cacheOfInfraredDisplayStatusWithDevId:(nullable NSString *)devId spaceId:(long long)spaceId;

/// Sets whether the infrared sub-device is displayed
/// @param devId deviceId
/// @param spaceId space id
/// @param subDeviceDisplay subdevice display, yes/no
- (void)updateCacheOfInfraredDisplayStatusWithDevId:(nullable NSString *)devId spaceId:(long long)spaceId subDeviceDisplay:(BOOL)subDeviceDisplay;

/// Whether or not the device is enabled to display infrared sub-device status change notification name
- (nullable NSNotificationName)subDeviceDisplayStatusChangeNotificationName;

//// Empty the set custom item
- (void)clearInsertItem;

/// Synchronise item insertion callbacks
/// @param insertDevMenuItemBlock Synchronising the item insertion callbacks
-(void)insertDevMenuItem:(InsertDevMenuItemBlock) insertDevMenuItemBlock customType:(NSString *)type;

/// Asynchronous callback for item insertion.
/// @param insertDevMenuItemAsyncBlock Asynchronous callback to handle item insertion
-(void)insertDevMenuItemAsync:(InsertDevMenuItemAsyncBlock) insertDevMenuItemAsyncBlock customType:(NSString *)type;

/// Callback when an item is clicked.
/// @param clickMenuItemBlock clickMenuItemBlock
-(void)clickMenuItem:(ClickMenuItemBlock) clickMenuItemBlock;

@end

/// Protocols that must be adhered to for data in the device details custom item
@protocol ThingDeviceDetailCustomMenuModel <NSObject>
/// title
@property (nonatomic,copy) NSString *title;

///subtitle
@property (nonatomic,copy) NSString *detail;

@end

#endif /* ThingDeviceDetailPlugAPI_h */
