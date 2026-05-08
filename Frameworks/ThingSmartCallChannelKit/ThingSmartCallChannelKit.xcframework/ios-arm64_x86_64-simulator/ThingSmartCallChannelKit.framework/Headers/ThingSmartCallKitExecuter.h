
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSmartCallHandleType) {
    ThingSmartCallHandleTypeGeneric = 1,
    ThingSmartCallHandleTypePhoneNumber = 2,
    ThingSmartCallHandleTypeEmailAddress = 3,
};

@protocol ThingSmartCallKitExecuterDelegate;
@protocol ThingSmartCallKitExecuterDataSource;

@protocol ThingSmartCallKitExecuter <NSObject>

@property (nonatomic, assign, readonly) BOOL isCalling;

- (void)launchOutgoingCallForUUID:(NSUUID *)uuid callValue:(NSString*)callValue CTYHandleType:(ThingSmartCallHandleType)type dataSource:(id<ThingSmartCallKitExecuterDataSource>)dataSource delegate:(id<ThingSmartCallKitExecuterDelegate>)delegate completion:(void(^)(NSError *error))completion;
- (void)reportIncomingCallForUUID:(NSUUID *)uuid callValue:(NSString*)callValue CTYHandleType:(ThingSmartCallHandleType)type dataSource:(id<ThingSmartCallKitExecuterDataSource>)dataSource delegate:(id<ThingSmartCallKitExecuterDelegate>)delegate completion:(void(^)(NSError *error))completion;


/// Report that an outgoing call started connecting. A nil value for `dateStartedConnecting` results in the started connecting date being set to now.
- (void)reportOutgoingCallWithUUID:(NSUUID *)UUID startedConnectingAtDate:(nullable NSDate *)dateStartedConnecting;

/// Report that an outgoing call connected. A nil value for `dateConnected` results in the connected date being set to now.
- (void)reportOutgoingCallWithUUID:(NSUUID *)UUID connectedAtDate:(nullable NSDate *)dateConnected;

- (void)reportCallWithUUID:(NSUUID *)UUID callValue:(NSString*)callValue CTYHandleType:(ThingSmartCallHandleType)type;


- (void)endCall;
- (void)endCallWithFailed;
- (void)endCallWithRemoteEnded;
- (void)endCallWithUnanswered;
- (void)endCallWithAnsweredElsewhere;
- (void)endCallWithDeclinedElsewhere;
- (void)endCallWithCompletion:(nullable void(^)(NSError *error))completion;
- (void)acceptCallWithCompletion:(nullable void(^)(NSError *error))completion;

@end

@protocol ThingSmartCallKitAction <NSObject>

@property (nonatomic, copy) void(^fillHandle)(void);
@property (nonatomic, copy) void(^failHandle)(void);
- (void)fill;
- (void)fail;

@end


@protocol ThingSmartCallKitExecuterDelegate <NSObject>
@optional
- (void)providerDidReset:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerDidBegin:(id<ThingSmartCallKitExecuter>)manager;
- (BOOL)providerExecuteTransaction:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerPerformStartCallAction:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerPerformAnswerCallAction:(id<ThingSmartCallKitExecuter>)manager;
- (void)provider:(id<ThingSmartCallKitExecuter>)manager performAnswerCallAction:(id<ThingSmartCallKitAction>)action;
- (void)providerPerformEndCallAction:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerPerformSetHeldCallAction:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerPerformSetMutedCallAction:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerPerformSetGroupCallAction:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerPerformPlayDTMFCallAction:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerTimedOutPerformingAction:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerDidActivateAudioSession:(id<ThingSmartCallKitExecuter>)manager;
- (void)providerDidDeactivateAudioSession:(id<ThingSmartCallKitExecuter>)manager;
- (void)callManagerWithReportNewIncomingCallError:(NSError *)error;
@end

@protocol ThingSmartCallKitExecuterDataSource <NSObject>
@optional
// Name of resource in app's bundle to play as ringtone for incoming call
- (NSString *)ringtoneSound;
// Image should be a square with side length of 40 points
- (NSData *)iconTemplateImageData;
// Default 1
- (NSUInteger)maximumCallGroups;
// Default 1
- (NSUInteger)maximumCallsPerCallGroup;
/// Whether this provider's calls should be included in the system's Recents list at the end of each call.
/// Default: YES
- (BOOL)includesCallsInRecents API_AVAILABLE(ios(11.0), macCatalyst(13.0), macos(11.0)) API_UNAVAILABLE(watchos);;
// Default YES
- (BOOL)supportsVideo;
// Numbers are of type ThingSmartCallHandleType,default support ThingSmartCallHandleTypePhoneNumber
- (NSSet<NSNumber *> *)supportedHandleTypes;

/*CXCallUpdate*/
/// Override the computed caller name to a provider-defined value.
/// Normally the system will determine the appropriate caller name to display (e.g. using the user's contacts) based on the supplied caller identifier. Set this property to customize.
- (NSString *)localizedCallerName;

/// Whether the call can be held on its own or swapped with another call
- (BOOL)supportsHolding;

/// Whether the call can be grouped (merged) with other calls when it is ungrouped
- (BOOL)supportsGrouping;

/// The call can be ungrouped (taken private) when it is grouped
- (BOOL)supportsUngrouping;

/// The call can send DTMF tones via hard pause digits or in-call keypad entries
- (BOOL)supportsDTMF;

/// The call includes video in addition to audio.
- (BOOL)hasVideo;
@end



NS_ASSUME_NONNULL_END
