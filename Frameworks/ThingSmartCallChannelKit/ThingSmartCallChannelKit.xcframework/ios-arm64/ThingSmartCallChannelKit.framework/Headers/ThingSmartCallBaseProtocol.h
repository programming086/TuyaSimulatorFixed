
#import <Foundation/Foundation.h>

#import "ThingSmartCallChannelConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCallBaseProtocol <NSObject>

///app unique id
@property (nonatomic, copy) NSString *appDeviceId;

///current id
@property (nonatomic, copy) NSString *curId;

///target id
@property (nonatomic, copy) NSString *targetId;

///session id
@property (nonatomic, copy) NSString *sessionId;

///call timeout interval, unit is millisecond.
@property (nonatomic, assign) long long timeout;

///extra data, eg: {channelType:1, category:xxx}, if see more, please review developer document.
@property (nonatomic, copy) NSDictionary *extra;

///reason.
@property (nonatomic, copy) NSString *reason;

@end

NS_ASSUME_NONNULL_END
