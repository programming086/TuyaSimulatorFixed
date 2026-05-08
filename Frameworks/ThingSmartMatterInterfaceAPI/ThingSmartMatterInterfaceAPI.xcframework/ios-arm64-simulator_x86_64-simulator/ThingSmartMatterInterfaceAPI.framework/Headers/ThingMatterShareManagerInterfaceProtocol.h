
#import <Foundation/Foundation.h>
#import "ThingSmartMatterNodeModel.h"
#import "ThingSmartMatterACLSyncStatusModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMatterShareManagerInterfaceProtocol <NSObject>

/// writeAccessControlList 
///
/// @param devId           devId
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)writeAccessControlListWithDevId:(NSString *)devId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


- (void)writeAccessControlListWithDevIds:(nonnull NSArray<NSString *> *)devIds callback:(void(^)(void))callback;


///
/// @param devId           devId
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)notifyAccessControlListWithDevId:(NSString *)devId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

- (NSArray<ThingSmartMatterACLSyncStatusModel *> *)getMatterDeviceCachedACLSyncStatus;

- (void)getMatterDeviceACLSyncStatusWithDevIds:(NSArray <NSString *>*)devIds success:(void(^)(NSArray <ThingSmartMatterACLSyncStatusModel *>*result))success failure:(ThingFailureError)failure;


- (NSArray<NSString *> *)getMatterNodesCachedDeviceIds;

- (void)setMatterNodesCachedDevceIds:(NSArray<NSString *> *)devIDs;

- (NSArray<ThingSmartMatterNodeModel *> *)getDevicesLocalCacheFabricNodesWithdevIds:(NSArray <NSString *>*)devIds;

- (void)getDevicesFabricNodesWithdevIds:(NSArray <NSString *>*)devIds
                               callback:(void(^)(NSArray <ThingSmartMatterNodeModel *>*result))callback;

- (void)getDevicesFabricNodesWithdevIds:(NSArray <NSString *>*)devIds
                                spaceId:(long long)spaceId
                               callback:(void(^)(NSArray <ThingSmartMatterNodeModel *>*result))callback;

- (void)setMatterNodes:(NSArray <ThingSmartMatterNodeModel *>*)nodeModelList;


- (void)resetMatterNodes;

@end

NS_ASSUME_NONNULL_END
