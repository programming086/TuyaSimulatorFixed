
#import <Foundation/Foundation.h>
#import "ThingSmartCameraVASModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartCameraVAS : NSObject

- (void)fetchValueAddedServiceUrlWithParams:(ThingSmartCameraVASParams *)params success:(nullable ThingSmartCameraVASSuccess)success failure:(nullable ThingSmartCameraVASFailure)failure;

- (void)fetchInspectionDetailUrlWithParams:(ThingSmartCameraVASInspectionParams *)params success:(nullable ThingSmartCameraVASSuccess)success failure:(nullable ThingSmartCameraVASFailure)failure;

@end

NS_ASSUME_NONNULL_END
