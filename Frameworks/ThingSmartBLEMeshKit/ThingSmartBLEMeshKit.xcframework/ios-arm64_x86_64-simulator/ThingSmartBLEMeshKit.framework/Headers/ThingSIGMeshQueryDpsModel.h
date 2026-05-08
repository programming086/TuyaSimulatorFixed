
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshQueryDpsModel : NSObject

/// Device's nodeId
@property (nonatomic, strong) NSString *nodeId;

/// The dpId collection to be queried
@property (nonatomic, strong) NSArray *dpIds;

/// Query the delay time for each dpId in milliseconds. Default is 200
@property (nonatomic, assign) NSInteger delayMills;

@end

NS_ASSUME_NONNULL_END
