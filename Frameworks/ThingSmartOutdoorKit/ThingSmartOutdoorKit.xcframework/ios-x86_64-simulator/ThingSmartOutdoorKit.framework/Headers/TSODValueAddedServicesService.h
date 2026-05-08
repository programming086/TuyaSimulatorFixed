//
//  TSODValueAddedServicesService.h
//  ThingSmartOutdoorKit
//
//  Created by Hemin Won on 2024/1/26.
//

#import <Foundation/Foundation.h>
#import <ThingSmartNetworkKit/ThingSmartNetworkKit.h>
#import "TSODValueAddedServicesModel.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ValueAddedServicesService)
@interface TSODValueAddedServicesService : ThingSmartRequest

/// fetch Value-added services
/// - Parameters:
///   - devID: device ID
///   - success: success callback
///   - failure: failure callback
+ (void)fetchValueAddedServicesWithDevID:(NSString *)devID success:(void(^)(TSODValueAddedServicesModel *valueAddedServicesModel))success failure:(ThingFailureError)failure;

/// set Value-added services VASAbilityModel - hadPopup
/// - Parameters:
///   - devID: device ID
///   - hadPopup: ture or false, only AbilityDataCloudStore can set this field.
///   - success: success callback
///   - failure: failure callback
+ (void)setValueAddedServicesPopWithDevID:(NSString *)devID hadPopup:(BOOL)hadPopup success:(ThingSuccessBOOL)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
