
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityArmAbilityEnum.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingAlarmDetailModel;

/// Alarm message
@interface ThingSecurityAlarmMessageModel : NSObject

/// Alarm id
@property (nonatomic, copy) NSString *alarmId;

/// Alarm message id
@property (nonatomic, copy) NSString *msgId;

/// Alarm message content
@property (nonatomic, copy) NSString *msgContent;

/// Alarm message title
@property (nonatomic, copy) NSString *msgTitle;

/// product type
@property (nonatomic, copy) NSString *productType;

/// product id
@property (nonatomic, copy) NSString *productId;

/// A list of devices where the alarm occurred
@property (nonatomic, strong) NSArray<NSString *> *deviceIds;

@property (nonatomic, copy) NSString *monitoringDeadline;

/// Alarm type
@property (nonatomic, copy) NSString *type;

@property (nonatomic, assign) ThingSecurityAlarmType alarmType;

/// Alarm type description
@property (nonatomic, copy) NSString *typeDesc;

@property (nonatomic, copy) NSString *gmtCreate;

/// Alarm message state
@property (nonatomic, assign) AlarmMessageState state;

@property (nonatomic, strong) NSMutableArray<ThingAlarmDetailModel *> *details;

@property (nonatomic, assign) NSInteger alarmLeavel;

@end

@interface ThingAlarmDetailModel : NSObject

/// room name
@property (nonatomic, copy) NSString *roomName;

/// device name
@property (nonatomic, copy) NSString *deviceName;

/// time string
@property (nonatomic, copy) NSString *timeString;

@end

NS_ASSUME_NONNULL_END

