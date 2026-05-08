
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingSmartMatterACLSyncStatus) {
    ThingSmartMatterACLSyncStatusFinished = 1,
    ThingSmartMatterACLSyncStatusSyncing  = 2
};


// https://wiki.thing-inc.com:7799/page/1552199056439144484
@interface ThingSmartMatterACLSyncStatusModel : NSObject

@property (nonatomic, strong) NSString *devId;

@property (nonatomic, assign) ThingSmartMatterACLSyncStatus status;

@property (nonatomic, assign) BOOL isOverLimited;

@end

NS_ASSUME_NONNULL_END
