
#import <Foundation/Foundation.h>
#import "ThingGroupServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupServiceMaker : NSObject
/// Create an instance of a non-remote control group service
+ (id<ThingGroupServiceProtocol>)groupServiceMakerWithBuildQuery:(NSDictionary *)params;

/// Create an instance of a remote control group service
+ (id<ThingGroupServiceProtocol>)remoteControlGroupServiceMakerWithBuildQuery:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
