
#import "ThingSmartBeaconManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface DpsUpdateModel : NSObject

//dps
@property (nonatomic, strong) NSMutableDictionary *dps;

//should update local dps.
@property (nonatomic, assign) BOOL updateLocal;

//should update cloud dps
@property (nonatomic, assign) BOOL updateCloud;

//dps time.if nil,will use current time
@property (nonatomic, strong) NSString *dpsTime;

//default is 0
@property (nonatomic, assign) NSInteger reportType;

@end


@interface ThingSmartBeaconManager (DpsReport)

//Update Device DPS. DO NOT Call this method unless necessary
- (void)reportDps:(NSString *)devId update:(DpsUpdateModel *)dpsUpdate success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
