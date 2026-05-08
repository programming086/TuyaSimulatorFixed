
#import <Foundation/Foundation.h>
#import <ThingSmartBLECoreKit/ThingSmartBLECoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBeaconActiveParamsModel : NSObject

@property (nonatomic, assign) long long homeId;
@property (nonatomic, assign) long timeout;
@property (nonatomic, strong) NSArray<ThingBLEAdvModel *> *advModelList;
@property (nonatomic, strong) NSDictionary *extraParams;


@end

NS_ASSUME_NONNULL_END
