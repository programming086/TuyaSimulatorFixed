
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityArmAbilityEnum.h>

@class ThingSmartSecurityAlarmPlatformModel,ThingSecurityAlarmOperationModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityAlarmConfigModel : NSObject

/// Alarm service platform infomation
@property (nonatomic, strong) ThingSmartSecurityAlarmPlatformModel *info;

/// Alarm operations
@property (nonatomic, strong) NSArray<ThingSecurityAlarmOperationModel *> *actions;

@end

@interface ThingSmartSecurityAlarmPlatformModel : NSObject

/// Alarm count down dead time line
@property (nonatomic, assign) NSTimeInterval deadline;

/// Alarm count down current time line
@property (nonatomic, assign) long long currentMillis;

/// Current time interval
@property (nonatomic, assign) NSTimeInterval ct;

/// Alarm service platform description
@property (nonatomic, copy) NSString *desc;

/// Alarm service platform name
@property (nonatomic, copy) NSString *mcName;

/// Alarm id
@property (nonatomic, copy) NSString *alarmId;

/// Alarm service platform type
@property (nonatomic, assign) ThingSecurityLocationMonitorState mcState;

/// Whether the alarm has been sent to the alarm receiving center
@property (nonatomic, assign) BOOL dispatched;

/// Alarm voice state
@property (nonatomic, assign) BOOL voice;


@end

NS_ASSUME_NONNULL_END
