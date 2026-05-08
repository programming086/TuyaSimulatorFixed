
#import <Foundation/Foundation.h>
#import "ThingSmartMatterDeviceNodeModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterShareManager : NSObject

/// shareInstance
ThingSDK_SINGLETON

/// Get the device fabric node.
///
/// @param devIds          List of device id.
/// @param callback     Called when the task is finished.
- (void)getDevicesFabricNodesWithdevIds:(NSArray <NSString *>*)devIds callback:(void(^)(NSArray <ThingSmartMatterDeviceNodeModel *>*result))callback;

/// Write  ACL (Access Controller List) to Matter Device.
///
/// @param devId           List of device id.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)writeAccessControlListWithDevId:(NSString *)devId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Notify device write ACL (Access Controller List).
/// Notice: The method used for Thing Matter Device.
///
/// @param devId           List of device id.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)notifyAccessControlListWithDevId:(NSString *)devId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Get the device fabric node models in specified space id.
///
/// @param devIds          List of device id.
/// @param spaceId        The space id. (aka home id)
/// @param callback      Called when the task is finished.
- (void)getDevicesFabricNodesWithdevIds:(NSArray <NSString *>*)devIds spaceId:(long long)spaceId callback:(void(^)(NSArray <ThingSmartMatterDeviceNodeModel *>*result))callback;

/// Fetch the fabric nodes from local cached.
///
/// @param devIds List of device id.
- (NSArray<ThingSmartMatterDeviceNodeModel *> *)getDevicesLocalCacheFabricNodesWithdevIds:(NSArray <NSString *>*)devIds;

/// Set the matter node info.
///
/// @param nodeModelList    List of matter device node model.
- (void)setMatterNodes:(NSArray <ThingSmartMatterDeviceNodeModel *>*)nodeModelList;

@end

NS_ASSUME_NONNULL_END
