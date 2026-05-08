
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshDpActionModel : NSObject

@property (nonatomic, strong) ThingSmartDeviceModel *deviceModel;
@property (nonatomic, strong) NSDictionary *dp;

/// Default is 200
@property (nonatomic, assign) NSInteger delayMills;
@property (nonatomic, copy) ThingSuccessHandler success;
@property (nonatomic, copy) ThingFailureError failure;

@end

NS_ASSUME_NONNULL_END
