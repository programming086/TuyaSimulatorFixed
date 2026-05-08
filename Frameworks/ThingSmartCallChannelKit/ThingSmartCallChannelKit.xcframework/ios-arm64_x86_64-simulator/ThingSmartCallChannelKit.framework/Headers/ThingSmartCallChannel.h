
#import <Foundation/Foundation.h>

#import "ThingSmartCallEventMessageProtocol.h"
#import "ThingSmartCallInterface.h"
#import "ThingSmartCallProtocol.h"
#import "ThingSmartCallKitExecuter.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartCallChannel;

@protocol ThingSmartCallChannelDelegate <NSObject>
@optional

//receive a MQTT call, but it is an invalid call
- (void)callChannel:(ThingSmartCallChannel *)callChannel didReceiveInvalidCall:(id<ThingSmartCallProtocol>)call error:(NSError *)error;

//receive a push call, but it is an invalid call, eg: go to device panel or an error page.
- (void)callChannel:(ThingSmartCallChannel *)callChannel didReceiveInvalidPushCall:(id<ThingSmartCallProtocol>)call error:(NSError *)error;

@optional
//wrap all event messages, unrecommended.
- (void)callChannel:(ThingSmartCallChannel *)callChannel didReceiveCallEventsMessage:(id<ThingSmartCallEventMessage>)message;

@end

@protocol ThingSmartCallChannelDataSource <NSObject>

@optional
- (nullable id<ThingSmartCallKitExecuter>)callKitExecuter;

//custom the specified call executer.
- (nullable id<ThingSmartCallKitExecuter>)callKitExecuterOfCall:(id<ThingSmartCallProtocol>)call;

//if return YES, will ignore the call, can not presnet call UI.
- (BOOL)isIgnoredCall:(id<ThingSmartCallProtocol>)call;

@end

@interface ThingSmartCallChannel : NSObject

@property (class, nonatomic, strong, readonly) ThingSmartCallChannel *sharedInstance;

@property (nonatomic, weak) id <ThingSmartCallChannelDataSource> dataSource;

@property (nonatomic, assign) BOOL debugMode;

///launch services, call firstly.
- (void)launch;

///register call interface manager, interface manager generate/present/dismiss call interface,
///if call interface manager or identifier is invalid, return false, weak reference.
- (BOOL)registerCallInterfaceManager:(id<ThingCallInterfaceManager>)callInterfaceManager;
- (BOOL)unregisterCallInterfaceManager:(id<ThingCallInterfaceManager>)callInterfaceManager;
@property (nullable, nonatomic, copy, readonly) NSArray<id<ThingCallInterfaceManager>> *callInterfaceManagers;

///if subscribe failed, can call it.
- (void)resubscribeMQTTUserTopic;

///fetch device call ability from cloud, which is dependent on device's ability and product's advanced ability.
- (void)fetchDeviceCallAbilityByDevId:(NSString *)devId completion:(ThingSmartCallFetchCompletion)completion;

/// whether app is on calling
- (BOOL)isOnCalling;

/// whether app can start call
- (BOOL)canStartCall;

/// start call
- (void)startCallWithTargetId:(NSString *)targetId timeout:(NSInteger)timeout extra:(NSDictionary *)extra success:(nullable ThingSmartCallSuccess)success failure:(nullable ThingSmartCallFailure)failure;


///add delegate
- (BOOL)addDelegate:(id<ThingSmartCallChannelDelegate>)delegate;

///remove delegate
- (BOOL)removeDelegate:(id<ThingSmartCallChannelDelegate>)delegate;


/// deal with push/VoIP message
- (void)handlePushMessage:(NSDictionary *)message;

@end

NS_ASSUME_NONNULL_END
