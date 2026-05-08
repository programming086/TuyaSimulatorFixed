//
//  ThingSmartSceneActionModel.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)


extern NSString * const ACTION_EXECUTOR_APP_PUSH; /// push message action
extern NSString * const ACTION_EXECUTOR_APP_CALL; /// call action
extern NSString * const ACTION_EXECUTOR_SMS_SEND; /// sms action

extern NSString * const ACTION_EXECUTOR_DP_ISSUE; /// device dp action
extern NSString * const ACTION_EXECUTOR_GROUP_DP_ISSUE; /// device group dp action

extern NSString * const ACTION_EXECUTOR_IR_ISSUE; /// ir device dp action
extern NSString * const ACTION_EXECUTOR_IR_ISSUE_VII; /// ir device dp action(2rd version)

extern NSString * const ACTION_EXECUTOR_RULE_ENABLE; /// enable a automation
extern NSString * const ACTION_EXECUTOR_RULE_DISABLE; /// diable a automation
extern NSString * const ACTION_EXECUTOR_RULE_TRIGGER; /// execute a scene

extern NSString * const ACTION_EXECUTOR_DELAY; /// delay action
extern NSString * const ACTION_EXECUTOR_TOGGLE; /// toggle action
extern NSString * const ACTION_EXECUTOR_STEP; /// step action
extern NSString * const ACTION_EXECUTOR_LIGHT; /// light trigger action
extern NSString * const ACTION_EXECUTOR_ARMEDSTATE; /// security action
extern NSString * const ACTION_EXECUTOR_BATCH_CONTROL_DEVICE; /// batch control device action
extern NSString * const ACTION_EXECUTOR_AI; /// ai action

/// The five types of action status. Provides loading, success, offline, timeout and delay types.
typedef NS_ENUM(NSInteger, ThingSceneActionStatus)
{
    /// The loading action type.
    ThingSceneActionStatusLoading = 0,
    /// The success action type.
    ThingSceneActionStatusSuccess,
    /// The offline action type.
    ThingSceneActionStatusOffline,
    /// The timeout action type.
    ThingSceneActionStatusTimeout,
    /// The delay action type.
    ThingSceneActionStatusDelay,
    /// The failed action type.
    ThingSceneActionStatusFailed
};


/// @brief Data model for Scene Base Action.
@interface ThingSmartSceneActionModel : NSObject<NSCoding>

/// The action id.
@property (nonatomic, copy) NSString *actionId;

/// The entity id. If action is a device, entityId is devId, and groupId for group action, @"delay" for a delay action, sceneId of operated scene for scene action.
@property (nonatomic, copy) NSString *entityId;

/// The entity name, like "lamp", "lamp group".
@property (nonatomic, copy) NSString *entityName;

/// The scene id, can be used to save the scene's Id which this action belonged to.
@property (nonatomic, copy) NSString *scenarioId;

/// Describe what this action will do, like "Switch : Open".
@property (nonatomic, copy) NSString *actionDisplay;

/// Describe what this action will do with origin format like the below example, you can use it to create the description.
/// {
///    1: [
///        "Switch",
///        "Open"
///        ]
/// }
@property (nonatomic, strong) NSDictionary *actionDisplayNew;


/// The action type, can be the followed types:
/// "dpIssue" :execute a device action.
/// "deviceGroupDpIssue": execute a group action.
/// "irIssue": execute an infrared device, like an air conditioner which is controlled by a remote control.
/// "irIssueVii": execute an infrared device, like an air conditioner which is controlled by a remote control.ExecutorProperty is real infrared ray remotes control code.
/// "ruleTrigger": execute a scene.
/// "ruleEnable":  Enable an automation.
/// "ruleDisable": Disable an automation.
/// "delay": Delay for a while.
@property (nonatomic, copy) NSString *actionExecutor;

/// Execute property, like {"1":true, ...}, "1" is dpId, a data point's Id, value is the value you want this datapoint to set. Delay action should be like "executorProperty":{"seconds":"5","minutes":"0"}.
@property (nonatomic, strong) NSDictionary *executorProperty;

/// Local property of scene , save gId and gwId.
@property (nonatomic, strong) NSDictionary *extraProperty;

/// If this action is a device type action and this device has been removed from the current account, this flag is YES.
@property (nonatomic, assign) BOOL devDelMark;

/// If this action is a device type action, and this device has been removed from the current account, then provide this icon url to display the device icon.
@property (nonatomic, copy) NSString *deleteDevIcon;

/// Execute action status, you can use this property to store the execute status when executing.
@property (nonatomic, assign) ThingSceneActionStatus status;

/// Batch control device information.
@property (nonatomic, strong) NSDictionary *relationGroup;

#pragma mark - Panel info

/// The panel id, this value will be assigned by cloud server when this action should be oprate by a React Native panel.
@property (nonatomic, copy) NSString *uiid;

/// The panel info, this value will be assigned by cloud server when this action should be oprate by a React Native panel.
@property (nonatomic, strong) NSDictionary *uiInfo;

/// The panel info, this value will be assigned by cloud server when this action should be oprate by a React Native panel.
@property (nonatomic, assign) long i18nTime;

/// The panel relate device's pid, this value will be assigned by cloud server when this action should be oprate by a React Native panel.
@property (nonatomic, copy) NSString *pid;


#pragma mark - Recommend info

/// The recommend product id.
@property (nonatomic, copy) NSString *productId;

/// The recommend product icon.
@property (nonatomic, copy) NSString *productPic;

/// The recommend product local default icon.
@property (nonatomic, copy) NSString *defaultIconUrl;

// MARK: - Category

/**
 Determine whether is recommend type.
 */
- (BOOL)isRecommend;

/**
 Determine whether is device type. It includes normal device type and infrared device type.
 */
- (BOOL)isDevice;

/**
 Determine whether is group type.
 */
- (BOOL)isGroup;

/**
 Determine whether is normal device type. It includes ACTION_EXECUTOR_DP_ISSUE, ACTION_EXECUTOR_TOGGLE,  ACTION_EXECUTOR_STEP.
 */
- (BOOL)isNormalDevice;

/**
 Determine whether is infrared device type. It includes ACTION_EXECUTOR_IR_ISSUE, ACTION_EXECUTOR_IR_ISSUE_VII.
 */
- (BOOL)isIRDevice;

/**
 Determine whether is message type. It includes ACTION_EXECUTOR_APP_PUSH, ACTION_EXECUTOR_APP_CALL, ACTION_EXECUTOR_SMS_SEND.
 */
- (BOOL)isMessage;

/**
 Determine whether is rule handle type. It includes ACTION_EXECUTOR_RULE_ENABLE, ACTION_EXECUTOR_RULE_DISABLE, ACTION_EXECUTOR_RULE_TRIGGER, ACTION_EXECUTOR_LIGHT.
 */
- (BOOL)isRuleHandle;

/**
 Determine whether is batch control device type.
 */
- (BOOL)isBatchControl;

/**
 Determine whether is security type.
 */
- (BOOL)isSecurity;

/**
 Check whether is delay type.
 */
- (BOOL)isDelay;

/**
 Detemine whether the action is valid. When the action is non-device type, action is valid. When the action is device type, the action is valid if device is not removed and online.
 */
- (BOOL)isValid;

@end
