
#import <Foundation/Foundation.h>

#import "ThingSmartCallBaseProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCallEventMessage <ThingSmartCallBaseProtocol>

///call type
@property (nonatomic, assign) ThingSmartCallType callType;

///event name
@property (nonatomic, copy) ThingSmartCallEventName eventName;
///event
@property (nonatomic, assign, readonly) ThingSmartCallEvent callEvent;

@property (nonatomic, copy) NSString *event __deprecated_msg("Use eventName instead");

@end

NS_ASSUME_NONNULL_END
