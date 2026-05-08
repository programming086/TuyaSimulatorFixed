//
//  ThingResidenceSiteNotificationUtils.h
//  ThingSmartResidenceKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#ifndef ThingResidenceSiteNotificationUtils_h
#define ThingResidenceSiteNotificationUtils_h

// device
#define kNotificationGatewayListRefreshed   @"kNotificationGatewayListRefreshed"
#define kNotificationGatewayAdded           @"kNotificationGatewayListAdded"
#define kNotificationGatewayRemoved         @"kNotificationGatewayRemoved"
#define kNotificationGatewayInfoUpdate      @"kNotificationGatewayInfoUpdate"
#define kNotificationGatewayListRefreshedFailed   @"kNotificationGatewayListRefreshedFailed"

#define kNotificationDeviceInfoUpdate       @"kNotificationDeviceInfoUpdate"
#define kNotificationDeviceDpsUpdate        @"kNotificationDeviceDpsUpdate"

//#define kNotificationMeshDeviceDpsUpdate    @"kNotificationMeshDeviceDpsUpdate"
//#define kNotificationMeshDeviceRawData      @"kNotificationMeshDeviceRawData"
//#define kNotificationMeshDeviceBatchDpsData      @"kNotificationMeshDeviceBatchDpsData"


// 固件升级
#define kNotificationFirmwareUpgrade        @"kNotificationFirmwareUpgrade"
//#define kNotificationFirmwareUpgradeProgress @"kNotificationFirmwareUpgradeProgress"

// group
#define kNotificationGroupRemoved           @"kNotificationGroupRemoved"
#define kNotificationGroupUpdate            @"kNotificationGroupUpdate"
#define kNotificationGroupDpsUpdate         @"kNotificationGroupDpsUpdate"
//#define kNotificationGroupDpCodesUpdate     @"kNotificationGroupDpCodesUpdate"
#define KNotificationCreateGroup            @"KNotificationCreateGroup"

// home room
#define kNotificationHomeInfoUpdate         @"kNotificationHomeInfoUpdate"
#define kNotificationHomeAdded              @"kNotificationHomeAdded"
#define kNotificationHomeRemoved            @"kNotificationHomeRemoved"

#define kNotificationRoomRelation           @"kNotificationRoomRelation"
#define kNotificationRoomRename             @"kNotificationRoomRename"
#define kNotificationSharedListUpdate       @"kNotificationSharedListUpdate"

#define kNotificationCheckBLEDevice @"kNotificationCheckBLEDevice" //

// mesh
#define kNotificationMeshDeviceDpsChange      @"kNotificationMeshDeviceDpsChange" //

// 扫地机
//#define kNotificationMQTTDataChannel        @"kNotificationMQTTDataChannel" // 数据通道通知

//登录通知，在登录/注册/sdk初始化后都会发送
#define kNotificationLoginSuccess @"kNotificationLoginSuccess"
//登出通知，在登出/销毁账号/重置密码后都会发送
#define kNotificationLogout       @"kNotificationLogout"


//#define  ThingSmartGwNameUpdate              @"s.m.gw.name.update"
//#define  ThingSmartGwReset                   @"s.m.gw.reset"
//#define  ThingSmartFactoryReset              @"s.m.gw.factory.reset"
//#define  ThingSmartDevDpPublish              @"thing.m.device.dp.publish"
//#define  ThingSmartUpdateGwLocation           @"s.m.gw.location.update"


#define kThingMyMeshList                     @"thing.m.my.group.mesh.list"
#define kThingMyHomeDetail                   @"thing.m.location.get"
//#define kThingMyRoomList                     @"thing.m.room.list"
#define kThingMyGroupList                    @"thing.m.my.group.device.group.list"
#define kThingMyDeviceList                   @"thing.m.my.group.device.list"
#define kThingMyProductInfoList              @"thing.m.device.ref.info.my.list"
#define kThingStandardProductInfoList        @"thing.m.product.standard.config.list"
#define kThingDeviceProductRefInfoList       @"thing.m.device.product.ref.list"
#define kThingMyRelationList                 @"thing.m.my.group.device.relation.list"
#define kThingMySharedDeviceList             @"thing.m.my.shared.device.list"
#define kThingMySharedGroupList              @"thing.m.my.shared.device.group.list"

#define kThingMyRuleDeviceList                @"thing.m.my.rule.device.list"

#define kThingFamilyDevicesSortedQuery       @"thing.m.my.group.device.sort.list"        /** 获取当前家庭已排序的设备列表 */
#define kThingFamilyDevicesSortUpdate        @"thing.m.my.group.device.sort.list.update" /** 更新当前家庭的设备列表顺序 */

#define kThingDeviceRefInfoList              @"thing.m.device.ref.info.list"

#define kThingMeshGateWayRelationList        @"thing.m.mesh.relation.list"

// blue mesh
//#define ThingSmartDeviceBlueMeshCreate        @"thing.m.device.ble.mesh.create"       // mesh组网
//#define ThingSmartDeviceBlueMeshDismiss       @"thing.m.device.ble.mesh.dismiss"      // 移除mesh组
//#define ThingSmartDeviceBlueMeshNameUpdate    @"thing.m.device.ble.mesh.name.update"  // 改名
//#define ThingSmartDeviceBlueMeshJoin          @"thing.m.device.ble.mesh.join"         // 蓝牙设备入网
//#define ThingSmartDeviceBlueMeshSubRename     @"thing.m.device.sub.name.update"       // 子设备改名
//#define ThingSmartDeviceBlueMeshSubRemove     @"thing.m.device.ble.mesh.leave"        // 移除蓝牙子设备
#define ThingSmartDeviceSubList               @"thing.m.device.sub.list"
#define ThingSmartDeviceSubGet                @"thing.m.device.sub.get"
//#define ThingSmartDeviceBleueMeshNodeId       @"thing.m.device.ble.mesh.node.alloc"   // 获取 mesh ID

/// 获取设备升级状态
#define ThingSmartDeviceBizPropList @"thing.m.device.biz.prop.list"

#define kNotificationProductWarning         @"kNotificationProductWarning"

#define kNotificationDidAddIPCAPDevice @"kNotificationDidAddIPCAPDevice"

/// 通行MQTT通知
#define kNotificationUserTypeChange         @"kNotificationUserTypeChange"
/// 创建通行成员MQTT通知
#define kNotificationCreateAccessUser       @"kNotificationCreateAccessUser"
/// 通行成员授权的设备变更MQTT通知
#define kNotificationUpdateAccessDevice     @"kNotificationUpdateAccessDevice"
/// 确认入住MQTT通知
#define kNotificationConfirmCheckIn         @"kNotificationConfirmCheckIn"
#define kNotificationConfirmCheckInAlert    @"kNotificationConfirmCheckInAlert"
/// 删除入住人MQTT通知
#define kNotificationDeleteCheckInCustomer  @"kNotificationDeleteCheckInCustomer"
/// 删除入住单MQTT通知
#define kNotificationDeleteCheckInOrder     @"kNotificationDeleteCheckInOrder"
/// 取消预订MQTT通知
#define kNotificationCancelCheckInOrder     @"kNotificationCancelCheckInOrder"
/// 首页设备列表变更
#define kNotificationAuthDeviceDelete @"kNotificationAuthDeviceDelete"


#endif /* ThingResidenceSiteNotificationUtils_h */
