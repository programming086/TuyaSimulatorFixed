
#import <Foundation/Foundation.h>
@class ThingSIGMeshDCSConditionModel;
@class ThingSIGMeshDCSActionModel;

typedef NS_ENUM (NSInteger, ThingSIGMeshDCSLinkageAutoProperty){
    ThingSIGMeshDCSLinkageAutoPropertyDisable = 0,
    ThingSIGMeshDCSLinkageAutoPropertyEnable = 0x80,
};

typedef NS_ENUM (NSInteger, ThingSIGMeshDCSConditionOperatorType){
    ThingSIGMeshDCSConditionOperatorTypeEqual,//==a
    ThingSIGMeshDCSConditionOperatorTypeUnEqual,//!=a
    ThingSIGMeshDCSConditionOperatorTypeGreater,//>a
    ThingSIGMeshDCSConditionOperatorTypeLess,///<a
    ThingSIGMeshDCSConditionOperatorTypeGreaterOrEqual,//>=a
    ThingSIGMeshDCSConditionOperatorTypeLessOrEqual,///<=a
    ThingSIGMeshDCSConditionOperatorTypeOpenInterval,//(a,b)
    ThingSIGMeshDCSConditionOperatorTypeClosedInterval,//[a,b]
    ThingSIGMeshDCSConditionOperatorTypeNotOpenInterval,//!(a,b)
    ThingSIGMeshDCSConditionOperatorTypeNotClosedInterval//![a,b]
};

typedef NS_ENUM(NSInteger, ThingSIGMeshDCSConditionWeekTimerType) {
    ThingSIGMeshDCSConditionWeekTimerTypeNormal = 0,
    ThingSIGMeshDCSConditionWeekTimerTypeBeforeSunrise,
    ThingSIGMeshDCSConditionWeekTimerTypeAfterSunrise,
    ThingSIGMeshDCSConditionWeekTimerTypeBeforeSunset,
    ThingSIGMeshDCSConditionWeekTimerTypeAfterSunset
};

typedef NS_OPTIONS(NSInteger, ThingSIGMeshDCSConditionWeek) {
    ThingSIGMeshDCSConditionWeekSunday = 1ULL << 0,
    ThingSIGMeshDCSConditionWeekMonday = 1ULL << 1,
    ThingSIGMeshDCSConditionWeekTuesday = 1ULL << 2,
    ThingSIGMeshDCSConditionWeekWednesday = 1ULL << 3,
    ThingSIGMeshDCSConditionWeekThursay = 1ULL << 4,
    ThingSIGMeshDCSConditionWeekFirday = 1ULL << 5,
    ThingSIGMeshDCSConditionWeekSaturday = 1ULL << 6
};

typedef NS_ENUM (NSInteger, ThingSIGMeshDCSActionType){
    ThingSIGMeshDCSActionTypeDP,
    ThingSIGMeshDCSActionTypeDelay,
    ThingSIGMeshDCSActionTypeAuto,
};

typedef NS_ENUM (NSInteger, ThingSIGMeshDCSAutomationType){
    ThingSIGMeshDCSAutomationTypeDisable,
    ThingSIGMeshDCSAutomationTypeEnable,
    ThingSIGMeshDCSAutomationTypeExe,
};

typedef NS_ENUM (NSInteger, ThingSIGMeshDCSActionOperatorType){
    ThingSIGMeshDCSActionOperatorTypeInverse = 0,//!=a
    ThingSIGMeshDCSActionOperatorTypeAssignment,//=a
    ThingSIGMeshDCSActionOperatorTypeIncrement,//+=a
    ThingSIGMeshDCSActionOperatorTypeMinus,//-=a
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshDCSLinkageModel : NSObject

/// The automation ID
@property (nonatomic, assign) int automationId;

/// The property of automation
@property (nonatomic, assign) ThingSIGMeshDCSLinkageAutoProperty autoProperty;

/// The Edge flag of the condition attribute
@property (nonatomic, assign) BOOL isEdgeFlag;

/// The ALL flag of the condition attribute
@property (nonatomic, assign) BOOL isAllFlag;

/// The list of condition attributes
@property (nonatomic, strong) NSArray<ThingSIGMeshDCSConditionModel *> *conditionList;

/// The list of action attributes
@property (nonatomic, strong) NSArray<ThingSIGMeshDCSActionModel *> *actionList;
@end

@interface ThingSIGMeshDCSConditionModel : NSObject

/// The devId
@property (nonatomic, strong) NSString *devId;

/// The pub_address
@property (nonatomic, assign) int pubAddress;

@end

@interface ThingSIGMeshDCSConditionDPModel : ThingSIGMeshDCSConditionModel

/// The DP Id
@property (nonatomic, strong) NSString *dpId;

/// The Edge flag of the invoke rule
@property (nonatomic, assign) BOOL isEdgeFlag;

/// The logical operator type
@property (nonatomic, assign) ThingSIGMeshDCSConditionOperatorType operatorType;

/// The params list for the  logical operator
@property (nonatomic, strong) NSArray *paramsList;
@end


@interface ThingSIGMeshDCSConditionDateTimerModel : ThingSIGMeshDCSConditionModel

/// Start time of a scheduled task. The value is accurate to minute.  Max:1440, Min:0
@property (nonatomic, assign) NSInteger minutes;

@end


@interface ThingSIGMeshDCSConditionWeekTimerModel : ThingSIGMeshDCSConditionModel

/// Whether to repeat. Default NO.
@property (nonatomic, assign) BOOL repeat;

/// Timer type
@property (nonatomic, assign) ThingSIGMeshDCSConditionWeekTimerType type;

/// Week The scheduled task is enabled. eg: ThingSIGMeshDCSConditionWeekSunday | ThingSIGMeshDCSConditionWeekMonday
@property (nonatomic, assign) ThingSIGMeshDCSConditionWeek weeks;

/// Start time of a scheduled task. The value is accurate to minute.  Max:1440, Min:0
@property (nonatomic, assign) NSInteger minutes;

@end


@interface ThingSIGMeshDCSActionModel : NSObject

/// The action type for the action sequence
@property (nonatomic, assign) ThingSIGMeshDCSActionType actionType;

/// For DP
/// The DP Id
@property (nonatomic, strong) NSString *dpId;

/// The operator type
@property (nonatomic, assign) ThingSIGMeshDCSActionOperatorType operatorType;

/// The params list for the  operator
@property (nonatomic, strong) NSArray *paramsList;

///For delay
///The delay time interval.The unit is seconds（S）
@property (nonatomic, assign) int delayInterval;

///For automation
/// The automation ID
@property (nonatomic, assign) int autoId;

/// The automation type
@property (nonatomic, assign) ThingSIGMeshDCSAutomationType automationType;

@end

@interface ThingSIGMeshDCSHashModel : NSObject

///automation Id
@property (nonatomic, strong) NSData *automationId;

///The data of head hash
@property (nonatomic, strong) NSData *headHashData;

///The data of body hash
@property (nonatomic, strong) NSData *bodyHashData;

/// The linkage is open or not
@property (nonatomic, assign) BOOL isLinkageOpen;

- (NSData *)getHashData;
@end


NS_ASSUME_NONNULL_END
