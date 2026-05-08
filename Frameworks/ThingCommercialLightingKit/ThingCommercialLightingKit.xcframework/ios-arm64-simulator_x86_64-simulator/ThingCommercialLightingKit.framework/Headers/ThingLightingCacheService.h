//
//  ThingLightingProjectCacheService.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    Thing_BIZTYPE_LOCATION = 2,
    Thing_BIZTYPE_MESH,
    Thing_BIZTYPE_ROOM,
    Thing_BIZTYPE_GROUP,
    Thing_BIZTYPE_DEVICE,
} Thing_BIZTYPE_Model;

@class ThingCoreCacheService;
@class ThingLightingProjectConfigModel;
@class ThingLightingProjectModel;
@class ThingLightingAreaModel;
@class ThingSmartGroupModel;
@class ThingSmartDeviceModel;
@class ThingSmartDeviceOTAModel;
@class ThingSmartPackedGroupModel;
@class ThingSmartBleMeshModel;
@class ThingSmartSchemaModel;
@class ThingLightingMenuItemModel;

@interface ThingLightingCacheService : NSObject

ThingSDK_SINGLETON;

@property (nonatomic, strong) NSDictionary<NSString *, NSArray *> *dpRuleList;

@property (nonatomic, strong) NSArray<ThingSmartSchemaModel *> *areaCommonSchemaArray;

- (ThingCoreCacheService *)coreCacheService;

- (void)reset;

#pragma mark - project config

/// Bulk update project configuration information
/// @param configList Collection of configuration items
- (void)updateConfigList:(NSArray<ThingLightingProjectConfigModel *> *)configList;

/// Get all project configuration information
- (NSArray<ThingLightingProjectConfigModel *> *)getConfigList;

/// Update individual project configuration information
/// @param configModel Configuration item model
/// @param projectType Project type
- (void)updateConfigModel:(ThingLightingProjectConfigModel *)configModel projectType:(NSInteger)projectType;

/// Get individual project configuration information
/// @param projectType Project type
- (ThingLightingProjectConfigModel *)getConfigModelWithProjectType:(NSInteger)projectType;

#pragma mark - project

/// Update project list information
/// @param projectList Project list information
- (void)updateProjectList:(NSArray<NSDictionary *> *)projectList;

/// Get project list information
- (NSArray<ThingLightingProjectModel *> *)getProjectList;

/// Add individual project information
/// @param projectModel Project model
- (void)addProjectModel:(ThingLightingProjectModel *)projectModel;

/// Update individual project information
/// @param projectModel Project model
- (void)updateProjectModel:(ThingLightingProjectModel *)projectModel;

/// Remove individual project information
/// @param projectId Project model
- (void)removeProjectModel:(long long)projectId;

/// Get individual project information
/// @param projectId Project ID
- (ThingLightingProjectModel *)getProjectWithProjectId:(long long)projectId;

#pragma mark - area

/// Update information for a specific sub-area under the specified area
/// @param areaModel Area model
/// @param parentAreaId Parent area ID
/// @param projectId Project ID
- (void)updateAreaModel:(ThingLightingAreaModel *)areaModel parentAreaId:(long long)parentAreaId projectId:(long long)projectId;


- (void)updateAreaModelWithDic:(NSDictionary *)areaDic parentAreaId:(long long)parentAreaId projectId:(long long)projectId;

/// Update the list of areas. for example, if level 1 spaces have A, B, C, D, E, and now it returns only A, B, C, the cache will only have A, B, C. However, it won't affect other levels of spaces.
/// @param areaList List of areas at the same level
/// @param parentAreaId Parent area ID
/// @param projectId Project ID
- (void)updateSingleAreaList:(NSArray<ThingLightingAreaModel *> *)areaList parentAreaId:(long long)parentAreaId projectId:(long long)projectId;


/// Update the list of areas by providing the original data. This is useful for handling situations where some API responses have only a few fields, and other fields are not processed.
/// @param areaList Original data for a list of areas at the same level
/// @param parentAreaId Parent area ID
/// @param projectId Project ID
- (void)updateSingleAreaDicList:(NSArray<NSDictionary *> *)areaList parentAreaId:(long long)parentAreaId projectId:(long long)projectId;

/// Update favorite area information
/// @param areaList Area list information
/// @param projectId Project ID
- (void)updateCollectionAreaList:(NSArray<ThingLightingAreaModel *> *)areaList projectId:(long long)projectId;

/// Refresh all area information in the cache
/// @param areaList All area information (with hierarchy)
/// @param projectId Project ID
- (void)resetAllAreaList:(NSArray<ThingLightingAreaModel *> *)areaList projectId:(long long)projectId;

/// Remove specific area information from the cache
/// @param areaId Area iD
/// @param projectId Project ID
- (void)removeAreaModelWithAreaId:(long long)areaId projectId:(long long)projectId;

/// Get specific area information from the cache
/// @param areaId Area iD
/// @param projectId Project ID
- (ThingLightingAreaModel *)getAreaModelWithAreaId:(long long)areaId projectId:(long long)projectId;

/// Get specific array of area information from the cache
/// @param areaIdArray Area ID list
/// @param projectId Project ID
- (NSArray<ThingLightingAreaModel *> *)getAreaModelWithAreaIdArray:(NSArray<NSNumber *> *)areaIdArray projectId:(long long)projectId;

/// Get all top-level area information
/// @param projectId Project ID
- (NSArray<ThingLightingAreaModel *> *)getAreaModelListWithProjectId:(long long)projectId;

/// Get the list of sub-areas under the specified area
/// @param areaId Designated Area ID
/// @param projectId Project ID
- (NSArray<ThingLightingAreaModel *> *)getSubAreaModelWithAreaId:(long long)areaId projectId:(long long)projectId;

/// Get all sub-area data under the specified area
/// @param areaId Current area ID
/// @param projectId Project ID
- (NSArray<ThingLightingAreaModel *> *)getAllSubAreaModelWithAreaId:(long long)areaId projectId:(long long)projectId;

/// Get all favorited areas
/// @param projectId Project ID
- (NSArray<ThingLightingAreaModel *> *)collectionAreaModelListWithProjectId:(long long)projectId;

/// Get unallocated areas
/// @param projectId Project ID
- (ThingLightingAreaModel *)notAssignAreaModelWithProjectId:(long long)projectId;

#pragma mark - group

/// Update group list information
/// @param groupList Group model list
/// @param projectId Project ID
- (void)updateGroupList:(NSArray<ThingSmartGroupModel *> *)groupList projectId:(long long)projectId;

/// Get group list information
/// @param projectId Project ID
- (NSArray <ThingSmartGroupModel *> *)getGroupListWithProjectId:(long long)projectId;

/// Add or update individual group information
/// @param groupModel Group model
/// @param projectId Project ID
- (void)addOrUpdateGroupModel:(NSDictionary *)groupModel projectId:(long long)projectId;

#pragma mark - packed group

/// Add or update packed groups
/// @param packedGroup Packed group model
/// @param projectId Project ID
- (void)addOrUpdatePackedGroupModel:(NSDictionary *)packedGroup projectId:(long long)projectId;

/// Update the name of a composite group
/// @param groupId Group ID
/// @param projectId Project ID
- (void)renamePackedGroupWithGroupId:(NSString *)groupId projectId:(long long)projectId newName:(NSString *)newName;

/// Delete packed group
/// @param groupId Group ID
/// @param projectId Project ID
- (void)removePackedGroupWithGroupId:(NSString *)groupId projectId:(long long)projectId;

/// Get an array of packed groups
/// @param projectId Project ID
- (NSArray <ThingSmartPackedGroupModel *> *)getPackedGroupListWithProjectId:(long long)projectId;

/// Get packed groups
/// @param groupId Group ID
/// @param projectId Project ID
- (ThingSmartPackedGroupModel * __nullable)packedGroupModelWithGroupId:(NSString *)groupId projectId:(long long)projectId;

/// Get a specific array of packed groups
/// @param groupIds Group ID
/// @param projectId Project ID
- (NSArray<ThingSmartPackedGroupModel *> * __nullable)packedGroupListWithGroupIds:(NSArray<NSString *> *)groupIds projectId:(long long)projectId;

/// Update the number of packed groups (since there is pagination, you can't get all the results at once)
/// @param count Group count
/// @param projectId Project ID
- (void)updatePackedGroupCount:(NSInteger)count projectId:(long long)projectId;

/// Get the number of packed groups
/// @param projectId Project ID
- (NSInteger)packedGroupCountWithProjectId:(long long)projectId;

#pragma mark - device

/// Get an array of devices
/// @param projectId Project ID
- (NSArray <ThingSmartDeviceModel *> *)getDeviceModelListByDevIds:(NSArray<NSString *> *)devIds projectId:(long long)projectId;

/// Add a list of devices
/// @param deviceList Device dictionary list
/// @param projectId Project ID
- (void)addDeviceListByOriginData:(NSArray<NSDictionary *> *)deviceList projectId:(long long)projectId;


/// Update the list of devices
/// @param deviceList Device model list
/// @param projectId Project ID
- (void)updateDeviceList:(NSArray <ThingSmartDeviceModel *> *)deviceList projectId:(long long)projectId;

/// Add an individual device
/// @param deviceModel Device model
- (void)addDeviceModel:(ThingSmartDeviceModel *)deviceModel;


/// Add a list of devices, please note: this method will not trigger device addition callbacks
/// @param deviceList Device model list
- (void)addDeviceModelList:(NSArray<ThingSmartDeviceModel *> *)deviceList;

#pragma mark - ota

/// Update device OTA information
/// @param projectId Project ID
/// @param otaList OTA model list
- (void)updateProjectDeviceOTARelationWithProjectId:(long long)projectId otaList:(NSArray<ThingSmartDeviceOTAModel *> *)otaList;

/// Get device OTA information
/// @param projectId Project ID
- (NSArray<ThingSmartDeviceOTAModel *> *)getProjectDeviceOTARelationWithProjectId:(long long)projectId;

#pragma mark - mesh

/// Get information for a single BleMesh device
/// @param projectId Project ID
/// @param isSigMesh Whether it is SigMesh device information
- (ThingSmartBleMeshModel *)getMeshModelWithProjectId:(long long)projectId isSigMesh:(BOOL)isSigMesh;

/// Get information for a single BleMesh device
/// @param meshId Mesh ID
- (ThingSmartBleMeshModel *)getMeshModelWithId:(NSString *)meshId;

#pragma mark - relation

- (void)updateRelations:(NSDictionary *)relations projectId:(long long)projectId;

/// Update the display order of devices or groups
/// @param orderList Device or group list
/// @param projectId Project ID
- (void)updateDeviceOrGroupOrder:(NSArray *)orderList projectId:(long long)projectId;

#pragma mark - menu

- (void)updateMenuTreeList:(NSArray<ThingLightingMenuItemModel *> *)treeList projectId:(long long)projectId;

- (NSArray<ThingLightingMenuItemModel *> *)getMenuTreeListWithProjectId:(long long)projectId;

#pragma mark - subsribe

#if TARGET_OS_IOS

- (void)subscribeAllTopic;

- (void)subscribeTopicWithProjectId:(long long)projectId;

#endif

@end

NS_ASSUME_NONNULL_END
