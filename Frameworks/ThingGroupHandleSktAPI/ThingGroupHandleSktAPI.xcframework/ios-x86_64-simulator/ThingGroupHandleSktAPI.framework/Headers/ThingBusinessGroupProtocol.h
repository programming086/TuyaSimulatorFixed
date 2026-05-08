
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingBusinessGroupProtocol <NSObject>

@required

#pragma mark - Home Related Information

- (long long)getCurrentSpaceId;

- (NSArray<ThingSmartDeviceModel*> *)deviceListForCurrentSpace;

- (NSArray<ThingSmartGroupModel *> *)groupListForCurrentSpace;

- (NSString *)getsubSpaceNameWithDevice:(ThingSmartDevice *)device;

#pragma mark - deviceKit Implementation

// Retrieve device list based on product ID and space ID for ordinary WiFi groups.
- (void)getDevListWithProductId:(NSString *)productId
                        spaceId:(long long)spaceId
                        success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                        failure:(nullable ThingFailureError)failure;

// Retrieve device list when editing an ordinary WiFi or Zigbee group.
- (void)getDevListWithGroup:(ThingSmartGroup *)group
                  productId:(NSString *_Nullable)productId
                    success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                    failure:(nullable ThingFailureError)failure;

// Create an ordinary WiFi group.
- (void)createGroupWithName:(NSString *)name
                  productId:(NSString *)productId
                    spaceId:(long long)spaceId
                  devIdList:(NSArray<NSString *> *)devIdList
                    success:(nullable void (^)(ThingSmartGroup *group))success
                    failure:(nullable ThingFailureError)failure;

// Update an ordinary WiFi group.
- (void)updateGroupRelationsWithGroup:(ThingSmartGroup *)group
                              devList:(NSArray <NSString *>*)devList
                              success:(nullable ThingSuccessHandler)success
                              failure:(nullable ThingFailureError)failure;

// Retrieve device list for standard WiFi group creation based on space ID and product ID.
- (void)getDpCodeDevListWithSpaceId:(long long)spaceId
                          productId:(NSString *)productId
                            success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                            failure:(nullable ThingFailureError)failure;

// Retrieve device list when editing a standard WiFi group.
- (void)getDpCodeDevListWithGroup:(ThingSmartGroup *)group
                          success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                          failure:(nullable ThingFailureError)failure;

// Create a standard WiFi group.
- (void)createDpCodeGroupWithName:(NSString *)name
                          spaceId:(long long)spaceId
                        productId:(NSString *)productId
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(ThingSmartGroup *group))success
                          failure:(nullable ThingFailureError)failure;

// Edit a standard WiFi group.
- (void)updateDpCodeGroupRelationsWithGroup:(ThingSmartGroup *)group
                                    devList:(NSArray <NSString *>*)devList
                                    success:(nullable ThingSuccessHandler)success
                                    failure:(nullable ThingFailureError)failure;

// Retrieve device list for creation of ordinary Zigbee group using product ID and gateway ID.
- (void)getDevListWithProductId:(NSString *)productId
                           gwId:(NSString *)gwId
                        spaceId:(long long)spaceId
                        success:(nullable void (^)(NSArray<ThingSmartGroupDevListModel *> *))success
                        failure:(nullable ThingFailureError)failure;

// Create an ordinary Zigbee group.
- (void)createGroupWithName:(NSString *)name
                    spaceId:(long long)spaceId
                       gwId:(NSString *)gwId
                  productId:(NSString *)productId
                    success:(nullable void (^)(ThingSmartGroup *))success
                    failure:(nullable ThingFailureError)failure;

// Remove a device from an ordinary Zigbee or standard Zigbee group.
- (void)removeZigbeeDeviceWithGroup:(ThingSmartGroup *)group
                           nodeList:(NSArray <NSString *>*)nodeList
                            success:(nullable ThingSuccessHandler)success
                            failure:(nullable ThingFailureError)failure;

// Add devices to an ordinary Zigbee or standard Zigbee group.
- (void)addZigbeeDeviceWithGroup:(ThingSmartGroup *)group
                        nodeList:(NSArray <NSString *>*)nodeList
                         success:(nullable ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

// Create a standard Zigbee group with a mesh ID.
- (void)createDpCodeGroupWithName:(NSString *)name
                          spaceId:(long long)spaceId
                        productId:(NSString *)productId
                           devIds:(NSArray<NSString *> *)devIds
                           meshId:(NSString *)meshId
                          success:(nullable void (^)(ThingSmartGroup *group))success
                          failure:(nullable ThingFailureError)failure;

// Retrieve device list for thread group creation.
- (void)getThreadDevListWithProductId:(NSString *)productId
                           gwId:(NSString *)gwId
                        spaceId:(long long)spaceId
                        success:(nullable void (^)(NSArray<ThingSmartGroupDevListModel *> *))success
                              failure:(nullable ThingFailureError)failure;

// Create a thread group.
- (void)createThreadGroupWithName:(NSString *)name
                          spaceId:(long long)spaceId
                             gwId:(NSString *)gwId
                        productId:(NSString *)productId
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(ThingSmartGroup *))success
                          failure:(nullable ThingFailureError)failure;

// Update group room association.
- (void)updateGroupBelong:(ThingSmartGroup *)group
                   roomId:(long long)roomId
                  success:(nullable ThingSuccessHandler)success
                  failure:(nullable ThingFailureHandler)failure;

// Update a BLE mesh v2 group with a progress callback.
- (void)updateGroupRelationsWithGroup:(ThingSmartGroup *)group
                              devList:(NSArray <NSString *>*)devList
                              process:(void(^) (NSDictionary<NSString *,NSNumber *> *))process
                              success:(nullable ThingSuccessHandler)success
                              failure:(nullable ThingFailureError)failure;
@end

NS_ASSUME_NONNULL_END
