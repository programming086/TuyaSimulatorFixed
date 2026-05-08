
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartCameraBase.h>

@class ThingSmartDeviceModel;

@interface ThingSmartCameraAbility : ThingSmartCameraConfig

/// how many video channel did device support, if videoNum == 1 means that device just support HD or SD.
@property (nonatomic, assign, readonly) NSInteger videoNum;

/// device is support speaker
@property (nonatomic, assign, readonly) BOOL isSupportSpeaker;

/// device si support sound pckup
@property (nonatomic, assign, readonly) BOOL isSupportPickup;

/// default talkback mode, configured in Thing backend.
@property (nonatomic, assign, readonly) ThingSmartCameraTalkbackMode defaultTalkbackMode;

/// if device support both speaker and sound pickup, device support both one-way talk and two-way talk, so it could change the talkback mode.
@property (nonatomic, assign, readonly) BOOL couldChangeTalkbackMode;

/// default definition of live video, configured in Thing backend.
@property (nonatomic, assign, readonly) ThingSmartCameraDefinition defaultDefinition;

/// original config data
//@property (nonatomic, strong, readonly) NSDictionary *rowData;

+ (instancetype)cameraAbilityWithDeviceModel:(ThingSmartDeviceModel *)deviceModel;

+ (instancetype)cameraAbilityWithConfigData:(NSDictionary *)configData;

@end

