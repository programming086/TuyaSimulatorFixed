
@class ThingSmartDeviceModel;
@class ThingSmartGroupModel;

@protocol ThingDeviceDetailExternalProtocol <NSObject>

@optional

/// @brief Customise which page to fall back to after removing a device
/// @return YES custom processing, NO default logic
- (BOOL)customExitWhenDeleted;


/// Custom interception of sub-function click events provided by the applet device details plugin
/// @param type Subfunction type
/// device_edit View modified device icon, name, location
/// device_info Show device information
/// net_setting Show device alternate networks
/// scene_and_automation Scene and one-click execution
/// device_from Device source
/// panel_share_device/panel_share_group device/group share
/// add_icon_to_home_screen Add to home screen
/// device_remove remove device/dismiss group/remove share
/// group_edit_devices Group Device Management
/// group_create Create a group
/// help_and_feedback FAQs and Feedback
/// check_firmware_update Check device firmware update
/// check_device_network Check device network
/// @param data business data {‘deviceId’: ‘xxx’, ‘groupId’: ‘xxx’}
/// @return YES custom processing, NO default logic
- (BOOL)customSubFunctionHandleWithType:(NSString *)type data:(NSDictionary *)data;


/// For applet device details plugin custom data
- (void)customSubFunctionData:(NSString *)type data:(NSDictionary *)data completeHandle:(void(^)(BOOL custom, NSString *type, NSDictionary* data, NSError *error))completeHandle;

/// Disable the mini program functional page
- (BOOL)disableDeviceDetailMiniProgramFuntionalPage;

/// Custom device detail page
- (BOOL)customDeviceDetailPageWithDevice:(ThingSmartDeviceModel *)device group:(ThingSmartGroupModel *)group businessParams:(NSDictionary *)businessParams;

@end
