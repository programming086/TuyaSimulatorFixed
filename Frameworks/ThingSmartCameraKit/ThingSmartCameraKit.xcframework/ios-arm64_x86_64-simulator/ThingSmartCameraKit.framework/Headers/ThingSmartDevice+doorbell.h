
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

#import <ThingSmartCameraBase/ThingSmartCameraErrorCode.h>

typedef NSString * ThingSmartDoorBellType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXTERN ThingSmartDoorBellType const ThingSmartDoorBell;
FOUNDATION_EXTERN ThingSmartDoorBellType const ThingSmartACDoorBell;
FOUNDATION_EXTERN ThingSmartDoorBellType const ThingSmartDoorLock;

@interface ThingSmartDevice (doorbell)

- (ThingDoorBellError)answerDoorBellCallWithType:(ThingSmartDoorBellType)type messageId:(NSString *)messageId;

- (ThingDoorBellError)hangupDoorBellCallWithType:(ThingSmartDoorBellType)type messageId:(NSString *)messageId;

- (ThingDoorBellError)sendHeartbeatWithType:(ThingSmartDoorBellType)type messageId:(NSString *)messageId;


@end
