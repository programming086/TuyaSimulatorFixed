
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityAlarmMessageModel.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityAlarmOperationModel.h>

NS_ASSUME_NONNULL_BEGIN

/// Alarm detail
@interface ThingSecurityAlarmDetailModel : NSObject

/// alarm description
@property (nonatomic, copy) NSString *stateDescription;

/// Whether the alarm system is on or off
@property (nonatomic, assign) BOOL isEnableVoice;

/// alarm operations
@property (nonatomic, strong) NSArray<ThingSecurityAlarmOperationModel *>*operations;

/// alarm messages
@property (nonatomic, strong) NSArray<ThingSecurityAlarmMessageModel *>*alarmMessages;


@end

NS_ASSUME_NONNULL_END

