
#import <Foundation/Foundation.h>
#import "ThingSmartSweeperP2PIndexItemModel.h"
NS_ASSUME_NONNULL_BEGIN
/**
 {
     count = 38;
     items =     (
                 {
             channel = 1;
             createTime = 1618043159;
             dir = 0;
             duration = 15;
             filename = "1618043159_ch1.mp4";
             idx = 1;
             type = 2;
         },
     );
 }
 */
@interface ThingSmartSweeperP2PIndexModel : NSObject

@property (nonatomic, assign) NSInteger count;

@property (nonatomic, strong) NSArray<ThingSmartSweeperP2PIndexItemModel *> *items;
@end

NS_ASSUME_NONNULL_END
