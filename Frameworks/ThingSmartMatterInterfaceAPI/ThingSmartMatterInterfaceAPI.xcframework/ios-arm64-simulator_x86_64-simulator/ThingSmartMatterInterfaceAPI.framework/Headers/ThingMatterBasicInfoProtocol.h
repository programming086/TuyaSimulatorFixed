

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingMatterAttributeBasicInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMatterBasicInfoProtocol <NSObject>

/// Query matter basic infomation.
/// @param success success.
/// @param failure failure.
- (void)queryAttributeBasicInfoWithDevId:(NSString *)devId basicInfo:(void(^)(ThingMatterAttributeBasicInfo *info))success
                        failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
