//
//  ThingSmartSceneModel.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <Foundation/Foundation.h>

#import "ThingSmartSceneActionModel.h"
#import "ThingSmartSceneConditionModel.h"
#import "ThingSmartScenePreConditionModel.h"
#import "TSmartSceneModelTypes.h"

/// The two types of condition match. Provides any and all types.
typedef NS_ENUM(NSUInteger, ThingSmartConditionMatchType) {
    /// The condition match any type, it means any one condition in the scene is be matched, it will be executed.
    ThingSmartConditionMatchAny = 1,
    /// The condition match all type, it means all conditions in the scene is be matched, it will be executed.
    ThingSmartConditionMatchAll
};

/// The two types of condition match. Provides any and all types.
typedef NS_ENUM(NSUInteger, ThingSmartConditionSubMatchType) {
    /// The condition match any type, it means any one condition in the scene is be matched, it will be executed.
    ThingSmartConditionSubMatchAny = 1,
    /// The condition match all type, it means all conditions in the scene is be matched, it will be executed.
    ThingSmartConditionSubMatchAll
};

/// The three types of recommend scene. Provides none, scene and automation types.
typedef NS_ENUM(NSUInteger, ThingSmartSceneRecommendType) {
    /// The none recommend type, indicates it is neither tap-to-run nor automation scene.
    ThingSmartSceneRecommendTypeNone,
    /// The tap-to-run recommend scene type.
    ThingSmartSceneRecommendTypeScene,
    /// The automation recommend scene type.
    ThingSmartSceneRecommendTypeAutomation
};

/// The three types of collection scene. Provides none, scene and automation types.
typedef NS_ENUM(NSUInteger, ThingSmartSceneCollectionType) {
    /// The none collection type, indicates it is neither tap-to-run nor automation scene.
    ThingSmartSceneCollectionTypeNone,
    /// The tap-to-run collection scene type.
    ThingSmartSceneCollectionTypeScene,
    /// The automation collection scene type.
    ThingSmartSceneCollectionTypeAutomation
};

/// The two types of device list on the panel when creating scene.
typedef NS_ENUM(NSInteger, ThingSmartScenePanelType) {
    /// The non all device panel type, indicates you can only add zigbee device in the scene action.
    ThingSmartScenePanelTypeNonAllDevevice = 0,
    /// The all device panel type, indicates you can add zigbee device and wifi device in the scene action.
    ThingSmartScenePanelTypeAllDevices
};

/// Describes whether the scene works properly
typedef NS_ENUM(NSUInteger, ThingSmartSceneWorkingStatus) {
    /// Normal state
    ThingSmartSceneWorkingStatusFine = 0,
    /// Invalid status, scenario cannot be executed successfully
    ThingSmartSceneWorkingStatusInvalid,
    /// An abnormal state indicates that a device is offline, but the scenario can still be executed
    ThingSmartSceneWorkingStatusException,
};

/// Describes the linkage types
typedef NS_ENUM(NSInteger, ThingLocalLinkageType) {
    /// The unknow linkage type.
    ThingLinkageTypeUnknow = 0,
    /// The local linkage type, indicates only one gateway.
    ThingLinkageTypeLocal,
    /// The lan linkage type, allows devices to be controlled across multiple gateways without a network or router.
    ThingLinkageTypeLan
};

/// @brief ThingSmartSceneModel provides more data attributes for developers to implement business logic of the scene.
@interface ThingSmartSceneModel : NSObject<NSCoding, NSCopying>

/// The scene id, it's unique. But only custom scene has this property.
@property (nonatomic, strong) NSString *sceneId;

/// The scene code, only default scene has this property.
@property (nonatomic, strong) NSString *code;

/// The scene name, it describes what the scene is used to.
@property (nonatomic, strong) NSString *name;

/// Whether the scene enabled, this status is used to automation scene and default enabled in tap-to-run scene.
@property (nonatomic, assign) BOOL enabled;

/// Whether show scene in first page, the status only can be switched when editing scene.
@property (nonatomic, assign) BOOL stickyOnTop;

/// The pre condition object model list is used to set the valid time period for automation scene. More information about ThingSmartScenePreConditionModel, you can see ThingSmartScenePreConditionModel class.
@property (nonatomic, strong) NSArray<ThingSmartScenePreConditionModel *> *preConditions;

/// The condition model list,
@property (nonatomic, strong) NSArray<ThingSmartSceneConditionModel *> *conditions;

/// The action model list,
@property (nonatomic, strong) NSArray<ThingSmartSceneActionModel *> *actions;

/// The status condition model list.
@property (nonatomic, strong) NSArray<ThingSmartSceneConditionModel *> *statusConditions;

/// The device list,
@property (nonatomic, strong) NSArray *devList;

/// The scene background icon URL
@property (nonatomic, copy) NSString *coverIcon;

/// The scene background color hex string.
@property (nonatomic, copy) NSString *displayColor;

/// The scene background URL, when created a new scene, use the URL provided by Thing.
@property (nonatomic, strong) NSString *background;

/// The condition match type, For detail you can see ThingSmartConditionMatchType enumeration value introduction.
@property (nonatomic, assign) ThingSmartConditionMatchType matchType;

/// The status condition match type, For detail you can see ThingSmartConditionMatchType enumeration value introduction.
@property (nonatomic, assign) ThingSmartConditionSubMatchType subMatchType;

/// Whether this scene is bound to a panel. This attribute only supports standard zigbee devices.
@property (nonatomic, assign) BOOL boundForPanel;

/// Whether this scene is bound by a panel with new firmware. The new panel indicates that the scene supports zigbee devices and wifi devices.
@property (nonatomic, assign) BOOL boundForWiFiPanel;

/// Whether the automation scene supports to execute in LAN, If YES indicates the automation scene can be executed when zigbee gateway is offline.
@property (nonatomic, assign) BOOL localLinkage;

/// Whether the tap-to-run scene supports to execute in LAN, If YES indicates you can directly notify the zigbee gateway to execute the scene through TCP or MQTT messages.
@property (nonatomic, assign) BOOL newLocalScene;

/// The bound panel type, For detail you can see ThingSmartScenePanelType enumeration value introduction.
@property (nonatomic, assign) ThingSmartScenePanelType panelType;

/// The recommend scene type, For detail you can see ThingSmartSceneRecommendType enumeration value introduction.
@property (nonatomic, assign) ThingSmartSceneRecommendType recommendType;

/// The collection scene type, For detail you can see ThingSmartSceneCollectionType enumeration value introduction.
@property (nonatomic, assign) ThingSmartSceneCollectionType collectionType;

/// The recommend scene description.
@property (nonatomic, copy) NSString *recomDescription;

/// The recommended coefficient value of recommended scene, the range value is 0-100.
@property (nonatomic, assign) CGFloat recomCoefficient;

/// The timestamp when the automation scene will be automatically closed, The zero means it has not been set.
@property (nonatomic, assign) long long  disableTime;

/// Describe scenario execution status，See enum `ThingSmartSceneWorkingStatus`.
@property (nonatomic, assign) ThingSmartSceneWorkingStatus outOfWork;

/// When is true, this scene not disappear in scene tab view
@property (nonatomic, assign) BOOL notShowInTabList;

/// The linkage type.
@property (nonatomic, assign) ThingLocalLinkageType linkageType;

/// The room id list, eg:"123,234"
@property (nonatomic, copy) NSArray *roomIds;

/// The category id list, eg:"xadacc,cag1af3"
@property (nonatomic, copy) NSArray<NSString *> *categorys;

/// The master gateway id.
@property (nonatomic, copy) NSString *gwId;

#pragma mark - Business field

/// Whether the scene has already obtained details.
@property (nonatomic, assign) BOOL cached;

/// The arrow icon URL.
@property (nonatomic, copy) NSString *arrowIconUrl;

/// The hot value of recommended scene
@property (nonatomic, copy) NSString *hotCount;

/// The type of scene
@property (nonatomic, assign) ThingSmartSceneRuleGenre ruleGenre;

#pragma mark - Deprecated

/// The scene subtitle.
@property (nonatomic, strong) NSString *subTitle __deprecated;

/// The scene edit icon URL.
@property (nonatomic, strong) NSString *editIcon __deprecated;

/// The scene display icon URL.
@property (nonatomic, strong) NSString *displayIcon __deprecated;

// MARK: - Category

/**
 Determine whether is manual scene.
 */
- (BOOL)isManual;

/**
 Determine whether is recommend scene.
 */
- (BOOL)isRecommend;

/**
 Determine whether is collection scene.
 */
- (BOOL)isCollection;

/**
 Return set for offline devices in the scene.
 */
- (NSSet *)offlineDevices;

/**
 Return set of devices did removed in the scene.
 */
- (NSSet *)deletedDevices;

/**
 Determine whether the scene contains exception devices, offline and removed devices are exception devices.
 */
- (BOOL)containExceptionDevice;

/**
 Return the number of valid actions in the scene.
 */
- (NSInteger)effectiveActionCount;

/**
 Determine whether the scene contains devices to be purchased.
 */
- (BOOL)containsUnpurchasedDevice;

@end


/// The recommend business category.
@interface ThingSmartSceneModel (ThingSceneRecom)
/// The recommend source biz type.
@property (nonatomic, assign, readonly) TSceneRecomBizType bizType;
/// The recommend source description.
@property (nonatomic, copy) NSString *recommendSource;
/// The target jump URL.
@property (nonatomic, copy) NSString *jumpUrl;
/// The type of target page.
@property (nonatomic, copy) NSString *jumpType;

@end
