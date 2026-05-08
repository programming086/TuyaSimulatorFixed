
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ThingSmartCallSuccess)(void);
typedef void(^ThingSmartCallFailure)(NSError * _Nullable error);
typedef void(^ThingSmartCallFetchCompletion)(BOOL result,  NSError * _Nullable error);
typedef void(^ThingSmartCallFetchSuccess)(BOOL result);
typedef void(^ThingSmartCallFetchFailure)(NSError * _Nullable error);

///call type
typedef NS_ENUM(NSUInteger, ThingSmartCallType) {
    ThingSmartCallTypeOneToOne = 1, //one to one
    ThingSmartCallTypeOneToMore = 2, //one to more,if one reject, the call stops.
    ThingSmartCallTypeOneToMoreSpecial = 3, //one to more, if one reject, the call has no effect.
};

typedef NS_ENUM(NSUInteger, ThingSmartCallMode) {
    ThingSmartCallModeAudio = 0, //audio
    ThingSmartCallModeVideo = 1, //video
    ThingSmartCallModeBoth = 2, //audio and video
};

FOUNDATION_EXTERN NSErrorDomain const ThingSmartCallErrorDomain;

typedef NS_ENUM(NSInteger, ThingSmartCallError) {
    
    ThingSmartCallErrorInvalidParams = -2500,
    ThingSmartCallErrorRequestFailed = -2501,
    ThingSmartCallErrorInvalidResponse = -2502,
    ThingSmartCallErrorInvalidData = -2503,
    ThingSmartCallErrorInterfaceManagerNotFound = -2504,//did not register call interface manager

    ThingSmartCallErrorUndefinedSessionId = -2508,

    //sender
    ThingSmartCallErrorRejected = -2510, //reject
    ThingSmartCallErrorPeerBusy = -2511, //busy
    ThingSmartCallErrorNotAnswer = -2512, //not answer
    ThingSmartCallErrorPeerHangUp = -2513, //hang up

    //receiver
    ThingSmartCallErrorOnCalling = -2520, //on calling
    ThingSmartCallErrorRejectedByOthers = -2521, //rejected by others
    ThingSmartCallErrorAnsweredByOthers = -2522, //answered by others
    ThingSmartCallErrorCancel = -2523, //sender cancel

    //sender & receiver
    ThingSmartCallErrorTimeout = -2530, //timeout
    ThingSmartCallErrorConnectFail = -2531, //connect failed
    ThingSmartCallErrorDisconnect = -2532, //disconnect
    ThingSmartCallErrorStop = -2533, //remote stop
    
    //CallKit
    ThingSmartCallErrorCallKitUnknownException = -2560,
    ThingSmartCallErrorCallKitInvalidParams = -2561,
    ThingSmartCallErrorCallKitBusy = -2562, //has a call

    //others
    ThingSmartCallErrorNetworkChanged = -2570,//network changed
    ThingSmartCallErrorEnterBackground = -2571, //enter background
    ThingSmartCallErrorCallProcessing = -2575 //call processing
};


typedef NSString * ThingSmartCallEventName NS_STRING_ENUM;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallTriggerEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallCancelEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallHangUpEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallRingEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallAnswerEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallRejectEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallNotAnsweredEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallBusyEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallAlreadyAnsweredEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallAlreadyRejectedEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallHeartbeatEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallStopEventName;
FOUNDATION_EXTERN ThingSmartCallEventName const ThingSmartCallTimeoutEventName;

typedef NSString * ThingCallInterfaceManagerIdentifier NS_STRING_ENUM;
///screen ipc
FOUNDATION_EXTERN ThingCallInterfaceManagerIdentifier const ThingCallInterfaceManagerScreenIPCIdentifier;

typedef NSString * ThingSmartCallExtBizType NS_STRING_ENUM;
FOUNDATION_EXTERN ThingSmartCallExtBizType const ThingSmartCallExtScreenIPCBizType;


/** call event */
typedef NS_ENUM(NSUInteger, ThingSmartCallEvent) {
    ThingSmartCallEventUnknown = 0, //unknown
    ThingSmartCallEventCall = 1, //call
    ThingSmartCallEventCancel = 2, //cancel
    ThingSmartCallEventHangUp = 3, //hang up
    ThingSmartCallEventRing = 4, //ring
    ThingSmartCallEventAnswer = 5, //answer
    ThingSmartCallEventReject = 6, //reject
    ThingSmartCallEventNotAnswered = 7, //not answered
    ThingSmartCallEventBusy = 8, //busy
    ThingSmartCallEventAlreadyAnswered = 9, //already answered
    ThingSmartCallEventAlreadyRejected = 10, //already rejected
    ThingSmartCallEventHeartbeat = 11, //heartbeat
    ThingSmartCallEventStop = 12, //stop
    ThingSmartCallEventTimeOut = 13, //timeout
};

NS_ASSUME_NONNULL_END
