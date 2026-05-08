
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingSmartSweeperMQTTMessageType) {
    ThingSmartSweeperMQTTMessageMap = 0,
    ThingSmartSweeperMQTTMessageRoute,
};

@interface ThingSmartSweeperMQTTMessage : NSObject

/**
 * Sweeper map file id
 */
@property (copy, nonatomic) NSString *mapId;
/**
 * Sweeper map file. 0: map; 1:route
 */
@property (assign, nonatomic) ThingSmartSweeperMQTTMessageType mapType;
/**
 * Sweeper map file path
 */
@property (copy, nonatomic) NSString *mapPath;

@property (strong, nonatomic) NSDictionary *originJson;

@end

NS_ASSUME_NONNULL_END
