
#import <Foundation/Foundation.h>

#import <ThingSmartCameraBase/ThingSmartCameraErrorCode.h>


@class ThingSmartDeviceModel;

@interface ThingSmartDoorBellCallModel : NSObject

/// call type, "doorbell" or "ac_doorbell", or custom type
@property (nonatomic, strong) NSString *type;
/// the device id of doorbell call
@property (nonatomic, strong) NSString *devId;
/// the sub device's node id which calling
@property (nonatomic, strong) NSString *nodeId;
/// the call event identifier
@property (nonatomic, strong) NSString *messageId;
/// the time of doorbell call be triggered
@property (nonatomic, assign) NSInteger time;
/// the ext info
@property (nonatomic, strong) NSString *ext;
/// did answered
@property (nonatomic, assign, readonly, getter=isAnsweredBySelf) BOOL answeredBySelf;
/// is answered by other user
@property (nonatomic, assign, readonly, getter=isAnsweredByOther) BOOL answeredByOther;
/// is device canceled this call event
@property (nonatomic, assign, readonly, getter=isCanceled) BOOL canceled;

/// is a NVR sub device
@property (nonatomic, assign, readonly) BOOL isSubDevice;

- (NSDictionary *)map;

@end

@protocol ThingSmartDoorBellConfigDataSource <NSObject>

@optional

/// set the time out of call, if not answer when time out, the call will be canceled
/// @param defaultRingTimeOut default timeout
/// @param devId the device id of doorbell call
/// @return the time out of call
- (NSInteger)doorbellRingTimeOut:(NSInteger)defaultRingTimeOut
                       withDevId:(NSString *)devId;

@end

@protocol ThingSmartDoorBellObserver <NSObject>

@optional

/// did received a call from the device
- (void)doorBellCall:(ThingSmartDoorBellCallModel *)callModel didReceivedFromDevice:(ThingSmartDeviceModel *)deviceModel;

/// the call was refused
- (void)doorBellCallDidRefuse:(ThingSmartDoorBellCallModel *)callModel;

/// the call was answered
- (void)doorBellCallDidAnswered:(ThingSmartDoorBellCallModel *)callModel;

/// the call was hang up
- (void)doorBellCallDidHangUp:(ThingSmartDoorBellCallModel *)callModel;
/// the call was answered by other one
- (void)doorBellCallDidAnsweredByOther:(ThingSmartDoorBellCallModel *)callModel;
/// the device was canceled this call
- (void)doorBellCallDidCanceled:(ThingSmartDoorBellCallModel *)callModel timeOut:(BOOL)isTimeOut;
/// the camera  preview successful
- (void)doorBellCallDidonPreviewSuccess:(ThingSmartDoorBellCallModel *)callModel;

- (void)imageDoorLockDidHangUp:(ThingSmartDoorBellCallModel *)callModel;
@end

@interface ThingSmartDoorBellManager : NSObject

/// get all observers
@property (nonatomic, strong, readonly) NSArray<id<ThingSmartDoorBellObserver>> *allObservers;

@property (nonatomic, weak) id<ThingSmartDoorBellConfigDataSource> doorBellConfigDataSource;

/// If a device is already in a call, subsequent calls to this device will be automatically ignored when set it YES
@property (nonatomic, assign) BOOL ignoreWhenCalling;

/// set the time out of call, if not answer when time out, the call will be canceled
@property (nonatomic, assign) NSInteger doorbellRingTimeOut __deprecated_msg("Use -[doorBellConfigDataSource doorbellRingTimeOut:withDevId:] instead");;

+ (instancetype)sharedInstance;

/// Add observer for doorbell call
- (void)addObserver:(id<ThingSmartDoorBellObserver>)observer;

/// answer the doorbell call of specified message id
- (ThingDoorBellError)answerDoorBellCall:(NSString *)messageId;

/// refuse the doorbell call of specified message id
- (ThingDoorBellError)refuseDoorBellCall:(NSString *)messageId;

/// hangup the doorbell call of specified message id
- (ThingDoorBellError)hangupDoorBellCall:(NSString *)messageId;

/// the camera  preview successful
- (void)onPreviewSuccess:(NSString *)messageId;

/// generate a doorbell call with call message data
- (void)generateCall:(NSDictionary *)params;

/// get the call model for the specified message id, if no validate call model, return nil
- (ThingSmartDoorBellCallModel *)callModelWithMessageId:(NSString *)messageId;

/// remove the specified observer for doorbell call
- (void)removeObserver:(id<ThingSmartDoorBellObserver>)observer;

/// remove all observer
- (void)removeAllObservers;

- (void)didReceiveVoipDatas:(ThingSmartDoorBellCallModel *)callModel;

@end
