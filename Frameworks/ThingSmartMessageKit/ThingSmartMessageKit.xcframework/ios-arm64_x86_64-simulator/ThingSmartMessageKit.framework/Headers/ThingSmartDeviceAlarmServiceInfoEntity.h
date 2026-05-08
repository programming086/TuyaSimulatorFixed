
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingSmartDeviceAlarmServiceInfoEntityBizType) {
    ThingSmartDeviceAlarmServiceInfoEntityBizTypeFixedRule = 0, // Fixed rules
    ThingSmartDeviceAlarmServiceInfoEntityBizTypeAIRule = 1, //  AI generated
};

/*
 Device alarm rule
 
 Fixed rules:
 {
   "bizType" : 0,
   "isSelected" : false,
   "name" : "Device offline for 30 minutes",
   "productId" : "xxx"
   
   "ruleId" : "xxx",
 }
 
 AI generated rules:
 {
   "bizType" : 1,
   "isSelected" : false,
   "name" : "Methane overrun phone alert"
   "productId" : "xxx",
 
   "ruleId" : "",
   "deviceId" : "xxx",
   "templateId" : "1",
 },
 
 */
@interface ThingSmartDeviceAlarmServiceInfoEntity : NSObject

/// The id of device alarm configuration
@property (nonatomic, copy) NSString *configId;

/// Template ID
@property (nonatomic, copy, nullable) NSString *templateId;

/// Product ID
@property (nonatomic, copy) NSString *productId;

/// The name of device alarm configuration
@property (nonatomic, copy) NSString *configName;

/// Configuration is selected or not
@property (nonatomic, assign) BOOL selected;

/// Business type
@property (nonatomic, assign) ThingSmartDeviceAlarmServiceInfoEntityBizType bizType;

@end

NS_ASSUME_NONNULL_END
