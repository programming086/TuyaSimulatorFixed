//
//  TYGroupHandlePlugAPI.h
//  Pods
//
//  Created by yuheng on 2022/5/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
  TYGroupHandleTypeSupport,
  TYGroupHandleTypeNotSupport,
  TYGroupHandleTypeInvalid,
} TYGroupHandleType;

@class TuyaSmartGroupDevListModel;

/**
 zh^
 描述了各种方式进行群组页面的跳转
 zh$
 
 en^
 Describes various ways to jump to a group page
 en$
 */
@protocol TYGroupHandleProtocol <NSObject>

/**
 
 zh^
 跳转到 mesh 群组入口
 
 参数 isNav : `YES` 将会把 vc 装到 naviagtorVC 再进行 present, `NO` 直接present
 
 zh$
 
 en^
 Page jump to mesh group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller

 en$
 
 @param query zh^ 初始数据 zh$ en^ init data en$
 @param isNav zh^ 是否以 navigator 的方式进行present zh$ en^ if present by navigator en$ ，
 */
- (void)presentMeshGroupWithQueryData:(NSDictionary *_Nullable)query
                                isNav:(BOOL)isNav;


- (void)presentBeaconGroupWithQueryData:(NSDictionary *_Nullable)query isNav:(BOOL)isNav;

/**
 
 zh^
 跳转到一般群组入口
 
 参数 isNav : `YES` 将会把 vc 装到 naviagtorVC 再进行 present, `NO` 直接present

 zh$
 
 en^
 
 Page jump to common group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller


 en$

 @param query zh^ 初始数据 zh$ en^ init data en$
 @param isNav zh^ 是否以 navigator 的方式进行present zh$ en^ if present by navigator en$ ，
 */
- (void)presentGroupWithQueryData:(NSDictionary *_Nullable)query
                            isNav:(BOOL)isNav;
/**
 
 zh^
 跳转到zigbee群组入口
 
 参数 isNav : `YES` 将会把 vc 装到 naviagtorVC 再进行 present, `NO` 直接present

 zh$
 
 en^
 Page jump to zigbee group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller

 en$
 
 @param query zh^ 初始数据 zh$ en^ init data en$
 @param isNav zh^ 是否以 navigator 的方式进行present zh$ en^ if present by navigator en$ ，
 */
- (void)presentZigbeeGroupWithQueryData:(NSDictionary *_Nullable)query
                                  isNav:(BOOL)isNav;
/**
 
 zh^
 跳转到蓝牙本地群组入口

 参数 isNav : `YES` 将会把 vc 装到 naviagtorVC 再进行 present, `NO` 直接present

 zh$
 
 en^
 Page jump to Bluetooth group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller

 en$
 
 @param query zh^ 初始数据 zh$ en^ init data en$
 @param isNav zh^ 是否以 navigator 的方式进行present zh$ en^ if present by navigator en$ ，
 */
- (void)presentMeshLocalGroupWithQueryData:(NSDictionary *_Nullable)query
                                     isNav:(BOOL)isNav ;

/**
 
 zh^
 跳转到 sig mesh 本地群组入口
 
 参数 isNav : `YES` 将会把 vc 装到 naviagtorVC 再进行 present, `NO` 直接present
 
 zh$
 
 en^
 Page jump to Bluetooth group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller
 
 en$
 
 @param query zh^ 初始数据 zh$ en^ init data en$
 @param isNav zh^ 是否以 navigator 的方式进行present zh$ en^ if present by navigator en$ ，
 */
- (void)presentSIGMeshGroupWithQueryData:(NSDictionary *_Nullable)query isNav:(BOOL)isNav;

/**
 
 zh^
 创建wifi标准或普通群组
 zh$
 
 en^
 Create wifi standard or common group
 en$
 
 @param deviceId zh^ 设备ID zh$ en^ device ID en$
 @param completion zh^ 回调 zh$ en^ call back en$
 */
- (void)createWifiGroupWithDeviceId:(NSString *_Nonnull)deviceId completion:(void (^ _Nullable)(TYGroupHandleType type))completion
__deprecated_msg("Use createGroup:completion: instead");

/**
 
 zh^
 编辑WIFI标准或普通群组
 zh$
 
 en^
 Edit wifi standard or common group
 en$
 
 @param groupId zh^ 群组ID zh$ en^ group ID en$
 @param completion zh^ 回调 zh$ en^ call back en$
 */
- (void)editWifiGroupWithGroupId:(NSString *_Nonnull)groupId completion:(void (^ _Nullable)(TYGroupHandleType type))completion
__deprecated_msg("Use editGroup:completion: instead");

/**

 zh^
 创建群组。
 zh$

 en^
 Create wifi standard or common group
 en$

 @param deviceId zh^ 设备ID zh$ en^ device ID en$
 @param completion zh^ 回调 zh$ en^ call back en$
 */
- (void)createGroup:(NSString *_Nonnull)deviceId completion:(void (^ _Nullable)(TYGroupHandleType type))completion;

/**

 zh^
 编辑群组
 zh$

 en^
 Edit wifi standard or common group
 en$

 @param groupId zh^ 群组ID zh$ en^ group ID en$
 @param completion zh^ 回调 zh$ en^ call back en$
 */
- (void)editGroup:(NSString *_Nonnull)groupId completion:(void (^ _Nullable)(TYGroupHandleType type))completion;


#pragma mark -Group service

/**
 
 zh^
 初始化群组服务
 zh$
 
 en^
 Init group service
 en$
 
 @param params zh^ 构造参数 zh$ en^ group params en$
 @param isRemoteControl zh^ 是否遥控器群组 zh$ en^ is remote control en$
 */
- (id _Nullable )makeServiceWithParams:(NSDictionary *_Nonnull)params isRemoteControl:(BOOL)isRemoteControl;

/**
 
 zh^
 获取群组下符合条件的设备列表
 zh$
 
 en^
 get group devices
 en$
 
 @param groupService zh^ 服务实例对象 zh$ en^ group service object en$
 @param result zh^ 成功回调,void(^)(NSDictionary<NSString*, id> *errorInfo) zh$ en^ sucess block en$
 @param failure zh^ 失败回调 zh$ en^ failure block en$
 */
- (void)fetchGroupDeviceListWithGroupService:(id _Nonnull )groupService
                                     success:(void(^_Nullable)(NSArray<TuyaSmartGroupDevListModel *> * _Nullable list))result
                                     failure:(void(^_Nullable)(NSError * _Nullable error))failure;

/**
 zh^
 创建群组
 zh$
 
 en^
 create group devices
 en$
 
 @param groupService zh^ 服务实例对象 zh$ en^ group service object en$
 @param name zh^ 群组名字  zh$  en^ group name en$
 @param deviceList  zh^ 选中的设备列表 zh$ en^ selectd device list  en$
 @param process zh^ 进度信息 {"total":5,"current":1} zh$  en^ process en$
 @param result zh^ 成功回调 {"groupId":"xxx"} zh$  en^ sucess block en$
 @param failure zh^ 失败回调  {"groupId":"xxxx","failureList":[{"devId":"xxx","errorCode":1},{"devId":"xxx","errorCode":1}],"error":{"errorCode":1,"errorMsg":"xxx"}}  zh$ en^ failure block en$
 
 */
- (void)createGroupWithGroupService:(id _Nonnull )groupService
                          groupName:(NSString *_Nullable)name
                         deviceList:(NSArray <NSString *> *_Nullable)deviceList
                            process:(void (^_Nullable)(NSDictionary<NSString *,NSNumber *> * _Nullable process))process
                            success:(void (^_Nullable)(NSString * _Nullable groupId))result
                            failure:(void (^_Nullable)(NSDictionary <NSString *, id> * _Nullable errorInfo))failure;

/**
 
 zh^
 更新群组列表
 zh$
 
 en^
 update group devices
 en$
 
 @param groupService zh^ 服务实例对象 zh$ en^ group service object en$
 @param deviceList zh^ 选中的设备列表 zh$ en^ selectd device list  en$
 @param process zh^ 进度信息 zh$ en^ process en$
 @param result zh^ 成功回调 {"groupId":"xxx"} zh$ en^ sucess block en$
 @param failure zh^ 失败回调 zh$ en^ failure block en$
 */
- (void)updateSigmeshGroupWithGroupService:(id _Nonnull )groupService
                                deviceList:(NSArray <NSString *> *_Nullable)deviceList
                                   process:(void (^_Nullable)(NSDictionary<NSString *,NSNumber *> * _Nullable process))process
                                   success:(void (^_Nullable)(NSString * _Nullable groupId))result
                                   failure:(void (^_Nullable)(NSDictionary <NSString *, id> * _Nullable errorInfo))failure;
__deprecated_msg("Use updateGroupWithGroupService:deviceList:process:success:failure: instead");

/**
 
 zh^
 更新群组列表
 zh$
 
 en^
 update group devices
 en$
 
 @param groupService zh^ 服务实例对象 zh$ en^ group service object en$
 @param deviceList zh^ 选中的设备列表 zh$ en^ selectd device list  en$
 @param process zh^ 进度信息 zh$ en^ process en$
 @param result zh^ 成功回调 {"groupId":"xxx"} zh$ en^ sucess block en$
 @param failure zh^ 失败回调 zh$ en^ failure block en$
 */
- (void)updateGroupWithGroupService:(id _Nonnull )groupService
                         deviceList:(NSArray <NSString *> *_Nullable)deviceList
                            process:(void (^_Nullable)(NSDictionary<NSString *,NSNumber *> * _Nullable process))process
                            success:(void (^_Nullable)(NSString * _Nullable groupId))result
                            failure:(void (^_Nullable)(NSDictionary <NSString *, id> * _Nullable errorInfo))failure;

/**
 zh^
 设备是否支持群组功能
 zh$
 
 en^
 device supports group service
 en$
 
 @param devId zh^  设备id zh$ en^ device id en$
 */
- (BOOL)isDeviceSupportGroupWithDevId:(nonnull NSString *)devId;


@end


NS_ASSUME_NONNULL_END
