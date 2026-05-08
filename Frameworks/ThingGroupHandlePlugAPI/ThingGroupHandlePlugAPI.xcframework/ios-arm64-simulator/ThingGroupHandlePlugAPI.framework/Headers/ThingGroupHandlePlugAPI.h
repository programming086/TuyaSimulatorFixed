
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
  ThingGroupHandleTypeSupport,
  ThingGroupHandleTypeNotSupport,
  ThingGroupHandleTypeInvalid,
} ThingGroupHandleType;

@class ThingSmartGroupDevListModel;

/**
 Describes various ways to jump to a group page
 */
@protocol ThingGroupHandleProtocol <NSObject>

/**
 Page jump to mesh group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller
 
 @param query  init data
 @param isNav  if present by navigator
 */
- (void)presentMeshGroupWithQueryData:(NSDictionary *_Nullable)query
                                isNav:(BOOL)isNav;


- (void)presentBeaconGroupWithQueryData:(NSDictionary *_Nullable)query isNav:(BOOL)isNav;

/**
 Page jump to common group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller

 @param query  init data
 @param isNav  if present by navigator
 */
- (void)presentGroupWithQueryData:(NSDictionary *_Nullable)query
                            isNav:(BOOL)isNav;
/**
 Page jump to zigbee group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller
 
 @param query  init data
 @param isNav  if present by navigator
 */
- (void)presentZigbeeGroupWithQueryData:(NSDictionary *_Nullable)query
                                  isNav:(BOOL)isNav;
/**
 Page jump to Bluetooth group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller

 
 @param query  init data
 @param isNav  if present by navigator
 */
- (void)presentMeshLocalGroupWithQueryData:(NSDictionary *_Nullable)query
                                     isNav:(BOOL)isNav ;

/**
 Page jump to Bluetooth group
 
 param  isNav: `YES` the vc will be presented inside a naviagtorVC, `NO` present a normal view controller
 
 
 @param query  init data
 @param isNav  if present by navigator
 */
- (void)presentSIGMeshGroupWithQueryData:(NSDictionary *_Nullable)query isNav:(BOOL)isNav;

/**
 Create wifi standard or common group
 
 @param deviceId  device ID
 @param completion  call back
 */
- (void)createWifiGroupWithDeviceId:(NSString *_Nonnull)deviceId completion:(void (^ _Nullable)(ThingGroupHandleType type))completion
__deprecated_msg("Use createGroup:completion: instead");

/**
 Edit wifi standard or common group
 
 @param groupId  group ID
 @param completion  call back
 */
- (void)editWifiGroupWithGroupId:(NSString *_Nonnull)groupId completion:(void (^ _Nullable)(ThingGroupHandleType type))completion
__deprecated_msg("Use editGroup:completion: instead");

/**
 Create wifi standard or common group

 @param deviceId  device ID
 @param completion  call back
 */
- (void)createGroup:(NSString *_Nonnull)deviceId completion:(void (^ _Nullable)(ThingGroupHandleType type))completion;

/**
 Edit wifi standard or common group

 @param groupId  group ID
 @param completion  call back
 */
- (void)editGroup:(NSString *_Nonnull)groupId completion:(void (^ _Nullable)(ThingGroupHandleType type))completion;


#pragma mark -Group service

/**
 Init group service
 
 @param params  group params
 @param isRemoteControl  is remote control
 */
- (id _Nullable )makeServiceWithParams:(NSDictionary *_Nonnull)params isRemoteControl:(BOOL)isRemoteControl;

/**
 Get group devices
 
 @param groupService  group service object
 @param result   sucess block
 @param failure  failure block
 */
- (void)fetchGroupDeviceListWithGroupService:(id _Nonnull )groupService
                                     success:(void(^_Nullable)(NSArray<ThingSmartGroupDevListModel *> * _Nullable list))result
                                     failure:(void(^_Nullable)(NSError * _Nullable error))failure;

/**

 Create group devices
 
 @param groupService  group service object
 @param name  group name
 @param deviceList   selectd device list
 @param process process
 @param result  sucess block
 @param failure failure block
 
 */
- (void)createGroupWithGroupService:(id _Nonnull )groupService
                          groupName:(NSString *_Nullable)name
                         deviceList:(NSArray <NSString *> *_Nullable)deviceList
                            process:(void (^_Nullable)(NSDictionary<NSString *,NSNumber *> * _Nullable process))process
                            success:(void (^_Nullable)(NSString * _Nullable groupId))result
                            failure:(void (^_Nullable)(NSDictionary <NSString *, id> * _Nullable errorInfo))failure;

/**
 Update group devices
 
 @param groupService group service object
 @param deviceList  selectd device list
 @param process  process
 @param result   sucess block
 @param failure  failure block
 */
- (void)updateSigmeshGroupWithGroupService:(id _Nonnull )groupService
                                deviceList:(NSArray <NSString *> *_Nullable)deviceList
                                   process:(void (^_Nullable)(NSDictionary<NSString *,NSNumber *> * _Nullable process))process
                                   success:(void (^_Nullable)(NSString * _Nullable groupId))result
                                   failure:(void (^_Nullable)(NSDictionary <NSString *, id> * _Nullable errorInfo))failure;
__deprecated_msg("Use updateGroupWithGroupService:deviceList:process:success:failure: instead");

/**
 Update group devices
 
 @param groupService  group service object
 @param deviceList  selectd device list
 @param process  process
 @param result   sucess block
 @param failure  failure block
 */
- (void)updateGroupWithGroupService:(id _Nonnull )groupService
                         deviceList:(NSArray <NSString *> *_Nullable)deviceList
                            process:(void (^_Nullable)(NSDictionary<NSString *,NSNumber *> * _Nullable process))process
                            success:(void (^_Nullable)(NSString * _Nullable groupId))result
                            failure:(void (^_Nullable)(NSDictionary <NSString *, id> * _Nullable errorInfo))failure;

/**
 Device supports group service
 
 @param devId device id
 */
- (BOOL)isDeviceSupportGroupWithDevId:(nonnull NSString *)devId;


@end


NS_ASSUME_NONNULL_END
