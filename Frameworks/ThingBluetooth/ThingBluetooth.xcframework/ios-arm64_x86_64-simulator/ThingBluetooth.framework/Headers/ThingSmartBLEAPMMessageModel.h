
#import <Foundation/Foundation.h>
#import "ThingSmartBLEAPMEnum.h"

@interface ThingSmartBLEAPMMessageModel : NSObject <NSCopying>

@property (nonatomic, strong) NSString *devId;
@property (nonatomic, assign) ThingSmartBLEAPMType type;
@property (nonatomic, strong) NSDictionary *dps;
@property (nonatomic, assign) NSTimeInterval time; /**< The time when data is reported.  */
@property (nonatomic, strong) NSString *des; /**< The description.  */
@property (nonatomic, strong) NSDictionary *extInfo; /**< Reserved.  */


- (NSDictionary *)attributes;

@end
