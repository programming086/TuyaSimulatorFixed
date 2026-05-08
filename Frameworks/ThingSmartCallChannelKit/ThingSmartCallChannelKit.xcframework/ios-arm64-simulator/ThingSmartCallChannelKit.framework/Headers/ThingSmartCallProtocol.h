
#import <Foundation/Foundation.h>

#import "ThingSmartCallBaseProtocol.h"
#import "ThingSmartCallEventMessageExtProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCallProtocol <ThingSmartCallBaseProtocol>

///whether is call out
@property (nonatomic, assign) BOOL outgoing;

///call type
@property (nonatomic, assign) ThingSmartCallType callType;

///whether the call has accepted.
@property (nonatomic, assign) BOOL accepted;

///whether the peer has answered.
@property (nonatomic, assign) BOOL answered;

///whether the connection is connected.
@property (nonatomic, assign) BOOL connected;

///whether the call ended.
@property (nonatomic, assign) BOOL end;

///uuid,if use callKit, set it.
@property (nonatomic, copy, nullable) NSUUID *uuid;

@optional
@property (nonatomic, strong) id <ThingSmartCallEventMessageExt> extraModel;

@end

NS_ASSUME_NONNULL_END
