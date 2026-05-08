//
//  ThingLightingProject.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import <ThingSmartBLEMeshKit/ThingSmartBLEMeshKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingAreaModel;
@class ThingSmartPackedGroupModel;

@class ThingLightingProject;
@class ThingLightingProjectModel;
@class ThingSmartDeviceModel;
@class ThingSmartDeviceOTAModel;
@class ThingSmartGroupModel;
@class ThingSmartFirmwareUpgradeStatusModel;
@class ThingSmartBleMeshModel;
@class ThingSmartDeviceGroupOTAModel;
@class ThingLightingMenuItemModel;

@protocol ThingLightingProjectDelegate <NSObject>

@optional


/// The delegate of project update information, such as the name, online.
/// @param project The project instance
- (void)projectDidUpdateInfo:(ThingLightingProject *)project;


/// The delegate of shared device list update.
/// @param project The project instance
- (void)projectDidUpdateSharedInfo:(ThingLightingProject *)project;


/// The delegate when a new area is added.
/// @param project The project instance
/// @param areaId AreaId
- (void)project:(ThingLightingProject *)project didAddArea:(long long)areaId;


/// The delegate when an existing area is removed.
/// @param project The project instance
/// @param areaId AreaId
- (void)project:(ThingLightingProject *)project didRemoveArea:(long long)areaId;


/// The delegate of area update information, such as the name.
/// @param project The project instance
/// @param areaId AreaId
- (void)project:(ThingLightingProject *)project areaId:(long long)areaId infoUpdate:(NSDictionary *)info;


/// The delegate of area dps update.
/// @param project The project instance
/// @param areaId AreaId
/// @param dps Dps
- (void)project:(ThingLightingProject *)project areaId:(long long)areaId dpsUpdate:(NSDictionary *)dps;


/// The delegate when a new device is added.
/// @param project The project instance
/// @param device Device model
- (void)project:(ThingLightingProject *)project didAddDevice:(ThingSmartDeviceModel *)device;


/// The delegate when an existing device is removed.
/// @param project The project instance
/// @param devId Device ID
- (void)project:(ThingLightingProject *)project didRemoveDevice:(NSString *)devId;


/// The delegate when an existing device is moved.
/// @param project The project instance
/// @param areaId AreaId
/// @param successDevIds Success device ID array
/// @param failedDevIds Failed device ID array
- (void)project:(ThingLightingProject *)project areaId:(long long)areaId didMoveDevice:(NSArray<NSString *> *)successDevIds failedDevIds:(NSArray<NSString *> *)failedDevIds;


/// The delegate of device update information, such as the name.
/// @param project The project instance
/// @param device Device model
- (void)project:(ThingLightingProject *)project deviceInfoUpdate:(ThingSmartDeviceModel *)device;


/// The delegate of device dps update.
/// @param project The project instance
/// @param device Device model
/// @param dps Dps
- (void)project:(ThingLightingProject *)project device:(ThingSmartDeviceModel *)device dpsUpdate:(NSDictionary *)dps;


/// The delegate of warning information update.
/// @param project The project instance
/// @param device Device model
/// @param warningInfo Warning Info
- (void)project:(ThingLightingProject *)project device:(ThingSmartDeviceModel *)device warningInfoUpdate:(NSDictionary *)warningInfo;


/// The delegate of device firmware upgrade status update.
/// @param project The project instance
/// @param device Device model
/// @param upgradeStatusModel UpgradeStatusModel
- (void)project:(ThingLightingProject *)project device:(ThingSmartDeviceModel *)device firmwareUpgradeStatusModel:(ThingSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;


/// The delegate when project/shared devices ota status are updated.
/// @param project The project instance
/// @param otaModelList OTA model list
- (void)project:(ThingLightingProject *)project didUpdateOTAModelList:(NSArray<ThingSmartDeviceOTAModel *> *)otaModelList;


/// The delegate when a new group is added.
/// @param project The project instance
///  @param group Group model
- (void)project:(ThingLightingProject *)project didAddGroup:(ThingSmartGroupModel *)group;


/// The delegate of group dps update.
/// @param project The project instance
/// @param group Group model
/// @param dps Dps
- (void)project:(ThingLightingProject *)project group:(ThingSmartGroupModel *)group dpsUpdate:(NSDictionary *)dps;


/// The delegate when an existing group is removed.
/// @param project The project instance
/// @param groupId  Group ID
- (void)project:(ThingLightingProject *)project didRemoveGroup:(NSString *)groupId;


/// The delegate of group update information, such as the name.
/// @param project The project instance
/// @param group Group model
- (void)project:(ThingLightingProject *)project groupInfoUpdate:(ThingSmartGroupModel *)group;



/// The delegate when an existing packed group is removed.
/// @param project The project instance
/// @param packedGroupId The packed group ID
- (void)project:(ThingLightingProject *)project didRemovePackedGroup:(NSString *)packedGroupId;


/// The delegate when a new packed group is added.
/// @param project The project instance.
/// @param packedGroup The packed group instance.
- (void)project:(ThingLightingProject *)project didAddPackedGroup:(ThingSmartPackedGroupModel *)packedGroup;


/// The delegate of packed group update information, such as the name.
/// @param project The project instance
/// @param group Packed Group model
- (void)project:(ThingLightingProject *)project packedGroupInfoUpdate:(ThingSmartPackedGroupModel *)group;


/// The delegate when background did updated
/// @param project The project instance
- (void)projectBackgroundImageDidUpdate:(ThingLightingProject *)project;

/// The delegate when menu tree did updated
/// @param project The project instance
- (void)projectMenuTreeDidUpdate:(ThingLightingProject *)project;

@end

/// @brief ThingLightingProject provides methds for developers to manage single project.
///
/// ThingLightingProject is a core class of the SDK, which provides interfaces for querying and updating project information, deleting projects, etc.
@interface ThingLightingProject : NSObject

@property (nonatomic, weak) id<ThingLightingProjectDelegate> delegate;

/// Project model read from cache, which need to use  getProjectDetailWithSuccess:failure: method.
@property (nonatomic, strong, readonly, nullable) ThingLightingProjectModel *model;

/// Current Area Model.
@property (nonatomic, copy, readonly) ThingLightingAreaModel * currentArea;

/// First level area model list of current project
@property (nonatomic, copy, readonly) NSArray<ThingLightingAreaModel *> *firstLevelAreas;

/// Collection area model list of current project
@property (nonatomic, copy, readonly) NSArray<ThingLightingAreaModel *> *collectionAreas;

/// Not assign area model of current project
@property (nonatomic, strong, readonly) ThingLightingAreaModel *notAssignAreaModel;

/// Device model list of current project
@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceModel *> *deviceList;

/// Group model list of current project
@property (nonatomic, copy, readonly) NSArray <ThingSmartGroupModel *> *groupList;

/// packedGroup model list of current project
@property (nonatomic, copy, readonly) NSArray <ThingSmartPackedGroupModel *> *packedGroupList;

/// Shared device model list of current project
@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceModel *> *sharedDeviceList;

/// Shared group model list of current project
@property (nonatomic, copy, readonly) NSArray <ThingSmartGroupModel *>  *sharedGroupList;

/// Device ota list of current project
@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceOTAModel *> *deviceOtaList;

/// Private mesh model of current project.
@property (nonatomic, strong, readonly) ThingSmartBleMeshModel *meshModel;

/// SIG mesh model of current project.
@property (nonatomic, strong, readonly) ThingSmartBleMeshModel *sigMeshModel;

/// Return the SigMesh manager object for current area.
@property (nonatomic, strong, readonly) ThingSmartSIGMeshManager * currentSigMeshManager;

/// Menu tree list
@property (nonatomic, strong, readonly) NSArray<ThingLightingMenuItemModel *> *menuTreeList;

- (instancetype)init NS_UNAVAILABLE;


/// Get ThingLightingProject instance.
/// @param projectId The project ID.
+ (instancetype)projectWithProjectId:(NSInteger)projectId;


/// Get ThingLightingProject instance.
/// @param projectId The project ID.
/// @param areaId area ID.
+ (instancetype)projectWithProjectId:(NSInteger)projectId areaId:(NSInteger)areaId;

/// Get ThingLightingProject instance.
/// @param projectId The project ID.
- (instancetype)initWithProjectId:(NSInteger)projectId;


/// Get ThingLightingProject instance.
/// @param projectId The project ID.
/// @param areaId Current area ID.
- (instancetype)initWithProjectId:(NSInteger)projectId areaId:(NSInteger)areaId;


/// Get project model from remote.
/// @param success Called when the task finishes successfully.
///// @param failure If error occurred while adding the task, this block will be called.
- (void)getProjectInfoWithSuccess:(nullable void(^)(id result))success
                          failure:(nullable void(^)(NSError *error))failure;



///// Get project details, including mesh list, gateway list, area list, group list, Bluetooth direct connection device list.
///// @param success Called when the task finishes successfully.
///// @param failure If error occurred while adding the task, this block will be called.
- (void)getProjectDetailWithSuccess:(nullable void(^)(void))success
                            failure:(nullable void(^)(NSError *error))failure;


- (void)getNeedBlePermissionsWithSuccess:(ThingSuccessBOOL)success
                                 failure:(nullable void(^)(NSError *error))failure;


/// Update project info.
/// @param projectName project name
/// @param leaderName project leader name
/// @param leaderMobile project leader mobile
/// @param detailAddress project detail address
/// @param regionLocationId region location id that is made up of a combination of country code and first-level administrative area code,  which separated by English commas；it can be obtained through ThingLightingRegionManager.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateProjectInfoWithProjectName:(nonnull NSString *)projectName
                              leaderName:(nonnull NSString *)leaderName
                            leaderMobile:(nonnull NSString *)leaderMobile
                           detailAddress:(nonnull NSString *)detailAddress
                        regionLocationId:(nullable NSString *)regionLocationId
                                 success:(nullable void(^)(id result))success
                                 failure:(nullable void(^)(NSError *error))failure;


/// Delete project.
/// @param password user password
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)deleteProjectWithPassword:(nonnull NSString *)password
                          success:(nullable void(^)(void))success
                          failure:(nullable void(^)(NSError *error))failure;

- (void)getAllDisributedDeviceWithSuccess:(nullable void(^)(NSArray<NSString *> *deviceList))success
                                    failure:(nullable ThingFailureError)failure;


- (void)getBackgroundImageWithSuccess:(nullable ThingSuccessDict)success failure:(nullable ThingFailureError)failure;


- (void)getMenuTreeWithSuccess:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;


/// Disconnect all mesh connections
- (void)disconnectAllMesh;

@end




NS_ASSUME_NONNULL_END
