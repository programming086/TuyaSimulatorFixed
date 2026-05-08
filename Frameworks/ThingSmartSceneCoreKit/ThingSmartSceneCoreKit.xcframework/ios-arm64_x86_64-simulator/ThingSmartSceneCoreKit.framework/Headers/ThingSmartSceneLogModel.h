//
//  ThingSmartSceneLogModel.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartSceneLogData;

/// @brief ThingSmartSceneLogModel provides more attributes for developers to create log list model for scene.
@interface ThingSmartSceneLogModel : NSObject

/// The scene log data list.
@property (nonatomic, strong) NSArray<ThingSmartSceneLogData *> * datas;

/// The number of scene logs.
@property (nonatomic, assign) NSInteger totalCount;

@end

/// The log execute result type.
typedef NS_ENUM(NSInteger, TSceneLogExecResultType) {
    /// The scene is executed fail.
    TSceneLogExecType_Fail = 0,
    /// The scene all actions is executed succeddfully.
    TSceneLogExecType_Success = 1,
    /// The scene part actions is executed successfully.
    TSceneLogExecType_Part_Success = 2,
    /// The scene is executing.
    TSceneLogExecType_Doing = 3
};

/// The log execute result type.
typedef NS_ENUM(NSInteger, TSceneLogActionStatus) {
    /// 待执行
    TSceneLogActionStatus_Default = -1,
    /// 执行失败
    TSceneLogActionStatus_Fail = 0,
    /// 执行成功
    TSceneLogActionStatus_Success = 1,
    /// 执行中
    TSceneLogActionStatus_Doing = 2,
    /// 不需要执行
    TSceneLogActionStatus_UnNeed = 3
};

@interface ThingSmartLogActionData : NSObject
@property (nonatomic, copy) NSString *actionDisplay;
@property (nonatomic, assign) TSceneLogActionStatus execStatus;
@end

/// The scene log run model is local. Description the scene is executed in the gateway device.
extern NSString * const TSceneLogExecRunModelLocal;
/// The scene log run model is cloud. Description the scene is executed in the cloud.
extern NSString * const TSceneLogExecRunModelCloud;

/// @brief ThingSmartSceneLogData provides more attributes for developers to create log data.
@interface ThingSmartSceneLogData : NSObject

/// The log event id.
@property (nonatomic, strong) NSString *eventId;

/// The result of scene execution. 1 and 3 is success.
@property (nonatomic, assign) TSceneLogExecResultType execResult;

/// The result message of scene execution.
@property (nonatomic, strong) NSString *execResultMsg;

/// The time of scene execution.
@property (nonatomic, strong) NSString *execTime;

/// The error information of scene execution.
@property (nonatomic, strong) NSString *failureCause;

/// The error code.
@property (nonatomic, assign) NSInteger failureCode;

/// The owner id of scene log.
@property (nonatomic, strong) NSString *ownerId;

/// The rule id of the scene.
@property (nonatomic, strong) NSString *ruleId;

/// The rule name.
@property (nonatomic, strong) NSString *ruleName;

/// The rule run mode, `local` means local interaction, `cloud` means cloud interaction
@property (nonatomic, strong) NSString *runMode;

/// The scene type, 1 means tap-to-run scene, 2 means automation scene.
@property (nonatomic, assign) NSInteger sceneType;

/// The user id.
@property (nonatomic, strong) NSString *uid;

/// This data is not from service, you can set this property just for display.
@property (nonatomic, strong) NSString *detailTime;

/// This data is not from service, you can set this property to assist sort the list into category use this property just for display. 0 first , 1 middle, 2 last, -1 needless(just one item)
@property (nonatomic, assign) NSInteger indexType;

@property (nonatomic, strong) NSArray<ThingSmartLogActionData *> *actions;

@end

NS_ASSUME_NONNULL_END
