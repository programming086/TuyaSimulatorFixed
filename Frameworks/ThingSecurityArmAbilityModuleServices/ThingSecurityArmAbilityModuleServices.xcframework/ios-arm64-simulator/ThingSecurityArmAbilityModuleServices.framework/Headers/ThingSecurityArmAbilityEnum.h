
#ifndef ThingSecurityArmAbilityEnum_h
#define ThingSecurityArmAbilityEnum_h

//gateway state
typedef NS_ENUM(NSUInteger, ThingSecurityGatewayStatusType) {
    ThingSecurityGatewayStatusType_Disarm = 0,
    ThingSecurityGatewayStatusType_Stay,
    ThingSecurityGatewayStatusType_Leaving,
    ThingSecurityGatewayStatusType_Offline,
    ThingSecurityGatewayStatusType_No_Gateway,
    ThingSecurityGatewayStatusType_Error,
};

//gateway device arm result
typedef NS_ENUM(NSUInteger, ThingSecurityGatewayDeviceArmResultType) {
    ThingSecurityGatewayDeviceArmResultSuccess = 1,//arm success
    ThingSecurityGatewayDeviceArmResultFailed      //arm failure
};

//alarm service platform type
typedef NS_ENUM(NSUInteger, ThingSecurityLocationMonitorState) {
    ThingSecurityLocationMonitorNotSet = 0,//not set
    ThingSecurityLocationMonitorSelfMonitoring,//set monitoring
    ThingSecurityLocationMonitoroMonitoring//major monitoring
};

// update home state
typedef NS_ENUM(NSUInteger, ThingHSGatewayStateUpdateType) {
    ThingHSGatewayStateCancelAlarm = 0,//cancel alarm
    ThingHSGatewayStateCancelAlarmAndDisarm = 1,//disarm
    ThingHSGatewayStateSoundOpen = 10,//open alarm voice
    ThingHSGatewayStateSoundOff = 11,//close alarm voice
};

//sos alarm type
typedef NS_ENUM(NSUInteger, ThingHSGatewaySOSType) {
    ThingHSGatewaySOSFire = 5,//fire alarm
    ThingHSGatewaySOSPanic = 8,//panic alarm
    ThingHSGatewaySOSEmergency = 9//emergency alarm
};

//alarm message state
typedef NS_ENUM(NSInteger,AlarmMessageState){
    AlarmMessageStateOpen = 1,// open
    AlarmMessageStateCancel = 2,// cancel
    AlarmMessageStateDone = 3,// done
    AlarmMessageStateMC = 4,//sent to alarm service platform
    AlarmMessageStateDealed = 5//dealed
};

//alrm type
typedef NS_ENUM(NSUInteger, ThingSecurityAlarmType) {
    ThingSecurityAlarmType_FireSmoke,//fire smoke
    ThingSecurityAlarmType_FireCO,// co
    ThingSecurityAlarmType_WaterLeak,// water leak
    ThingSecurityAlarmType_SOS,//sos
    ThingSecurityAlarmType_Default,// default type
    ThingSecurityAlarmType_Gas,// gas
    ThingSecurityAlarmType_Undefine,//undefine
};

//camera ability
typedef NS_ENUM(NSUInteger, ThingSecurityCameraAbility) {
    ThingSecurityCameraAbilityP2P,//p2p
    ThingSecurityCameraAbilityAISmart,//AI
    ThingSecurityCameraAbilityCloudStorage//cloud storage
};

//security init type
typedef NS_ENUM(NSInteger, ThingSecurityHomeInitType){
    ThingSecurityHomeInitTypeThingSmartSecurity = 2,//Thing Smart
    ThingSecurityHomeInitTypeApartmentSecurity = 3//Thing Apartment
};

//arm mode
typedef NS_ENUM(NSInteger, ThingSecurityArmMode){
    ThingSecurityArmModeDisarmed = 0,// disarmed
    ThingSecurityArmModeStaying = 1,// stay
    ThingSecurityArmModeLeaving = 2,//away
    ThingSecurityArmModeAllHours = 4,//24 hours
    ThingSecurityArmModeUndefine = 100//undefine
};

//location online type
typedef NS_ENUM(NSUInteger, ThingSecurityLocationLineState) {    
    ThingSecurityLocationLineStateInit = 0,//init state(offline)
    ThingSecurityLocationLineStateAllGatewayOnline = 1,//all gateway device online
    ThingSecurityLocationLineStateAllGatewayOffline = 2,//some gateway device online
    ThingSecurityLocationLineStateSomeGatewayOffline = 3,//some gateway device offline
//    ThingSecurityLocationLineStateAllGatewayOffline = 5,
    ThingSecurityLocationLineStateNOGatewayDevice = 6,//has no gateway device
    ThingSecurityLocationLineStateGatewayDeviceArmBypass = 7,//gateway device has irregular sub device when armed
    ThingSecurityLocationLineStateGatewayNoDevice = 8, //location has no deivce
    ThingSecurityLocationLineStateGatewayStayingArmNoDevice = 9,//has no rule device on stay mode
    ThingSecurityLocationLineStateGatewayLeavingArmNoDevice = 10//has no rule device on away mode
};

typedef NS_ENUM(NSUInteger, ThingSecurityGatewayDeviceOnlineType) {
    ThingSecurityGatewayDeviceOnlineTypeOnline = 1,//gateway device online
    ThingSecurityGatewayDeviceOnlineTypeOffine = 2,//gateway device offline
    ThingSecurityGatewayDeviceOnlineNoGateway = 3//no gateway device
};

//weather type
typedef NS_ENUM(NSUInteger, ThingSecurityWeatherViewShowType) {
    ThingSecurityWeatherViewShowError = 1,//load datas failure
    ThingSecurityWeatherViewShowNoLocation = 2,//no address
    ThingSecurityWeatherViewShowSuccess = 3//load datas success
};


/// Security error code
typedef enum {
    /// query home information error
    ThingSecurityArmAbilityErrorCodeQueryHomeInfo = 900002,
    /// query home mode error
    ThingSecurityArmAbilityErrorCodeQueryMode = 900003,
    /// save devices error
    ThingSecurityArmAbilityErrorCodeSaveDeviceList = 900007,
    /// Invalid id
    ThingSecurityArmAbilityErrorCodeInvalidId = 900008,
    /// Update home mode error.
    ThingSecurityArmAbilityErrorCodeUpdateHomeMode = 900009,
    /// Get irregular device error.
    ThingSecurityArmAbilityErrorCodeQueryIrregularDevice = 900010,
} ThingSecurityArmAbilityErrorCode;


#endif /* ThingSecurityArmAbilityEnum_h */
