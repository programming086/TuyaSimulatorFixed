
#import <Foundation/Foundation.h>
#import "ThingSmartCallKitExecuter.h"
#import "ThingSmartCallProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCallInterface;
@protocol ThingCallActionExecuter <NSObject>
@optional
- (void)interface:(id<ThingSmartCallInterface>)interface onRing:(id<ThingSmartCallProtocol>)call;
- (void)interface:(id<ThingSmartCallInterface>)interface onCancel:(id<ThingSmartCallProtocol>)call;
- (void)interface:(id<ThingSmartCallInterface>)interface onHangUp:(id<ThingSmartCallProtocol>)call;
- (void)interface:(id<ThingSmartCallInterface>)interface onReject:(id<ThingSmartCallProtocol>)call;
- (void)interface:(id<ThingSmartCallInterface>)interface onAccept:(id<ThingSmartCallProtocol>)call;
- (void)interface:(id<ThingSmartCallInterface>)interface onConnected:(id<ThingSmartCallProtocol>)call;
- (void)interface:(id<ThingSmartCallInterface>)interface onException:(id<ThingSmartCallProtocol>)call error:(nullable NSError *)error;

@end


@protocol ThingSmartCallInterface <NSObject, ThingSmartCallKitExecuterDelegate>

///send message to the peer by actionExecuter.
@property (nonatomic, weak) id<ThingCallActionExecuter> actionExecuter;


- (instancetype)initWithCall:(id<ThingSmartCallProtocol>)call;

///setup some actions before send/receive call,eg:sync device model.
- (void)setupCompleted:(void(^)(NSError * _Nullable error))completed;

///the peer sent answer or already answered.
- (void)callPeerDidRespond;

- (void)callEndWithError:(nullable NSError *)error;

@optional

- (BOOL)configurateAudioSession;

/// retrun value, dismiss after interval, default 1.5
- (CGFloat)intervalBeforeInterfaceDismission;

- (void)executeHeavyTasksCompleted:(void(^ __nullable)(NSError * _Nullable error))completed;

///implement ThingSmartCallKitExecuter if use callKit.
@property (nonatomic, strong) id<ThingSmartCallKitExecuter> callKit;
//show name on callKit UI if use callKit.
- (NSString *)targetName;

@end

typedef void(^ThingCallInterfaceManagerCompletion)(void);

@protocol ThingCallInterfaceManager <NSObject>

@property (nonatomic, copy) ThingCallInterfaceManagerIdentifier identifier;

- (id<ThingSmartCallInterface>)generateCallInterfaceWithCall:(id<ThingSmartCallProtocol>)call;

- (void)presentInterface:(id<ThingSmartCallInterface>)interface completion:(ThingCallInterfaceManagerCompletion)completion;

- (void)dismissInterface:(id<ThingSmartCallInterface>)interface completion:(ThingCallInterfaceManagerCompletion)completion;

@end


NS_ASSUME_NONNULL_END
