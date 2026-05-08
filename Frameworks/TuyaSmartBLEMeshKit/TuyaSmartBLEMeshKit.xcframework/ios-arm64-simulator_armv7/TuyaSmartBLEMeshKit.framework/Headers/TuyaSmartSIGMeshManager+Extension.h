//
//  TuyaSmartSIGMeshManager+extension.h
//  TuyaSmartBLEMeshKit
//
//  Created by 宇 on 2022/6/13.
//

#import "TuyaSmartSIGMeshManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartSIGMeshManager ()

//是否收到设置广播包的消息
@property (nonatomic, assign) BOOL receiveNodeIdentifySetMsg;

@property (nonatomic, assign) BOOL isConnecting;
@property (nonatomic, assign) BOOL isActiving;//正在激活配网
@property (nonatomic, assign) BOOL isLogin;

@property (nonatomic, copy) void (^customVendorSuccBlock)(BOOL succ, NSInteger errorCode);
@property (nonatomic, strong, nullable) NSArray *sceneNodeIds;//要删除(执行)场景的所有设备nodeId集合
@property (nonatomic, strong) NSMutableArray *succSceneNodeIds;//成功删除(执行)场景的设备nodeId集合
@property (nonatomic, strong) NSMutableArray *failSceneNodeIds;//删除（执行）场景失败的设备nodeId集合

@property (nonatomic, copy, nullable) NSString *lowPowerNodeId;
@property (nonatomic, strong, nullable) ProvisionedMeshNode *lowPowerProxyNode;
@property (nonatomic, assign) BOOL isLowPowerOTA;//是否执行低功耗设备OTA流程

@property (nonatomic, strong) NSMutableDictionary *activeDeviceList;//待激活设备集合


- (NSMutableArray <TuyaSmartDeviceModel *> *)getCurrentSigMeshDeviceList;

- (void)peripheralDisconnected;

@end

NS_ASSUME_NONNULL_END
