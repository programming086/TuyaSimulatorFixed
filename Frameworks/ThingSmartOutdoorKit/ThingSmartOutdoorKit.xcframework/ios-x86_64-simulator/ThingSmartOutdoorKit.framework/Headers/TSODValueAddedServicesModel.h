//
//  TSODValueAddedServicesModel.h
//  ThingSmartOutdoorKit
//
//  Created by Hemin Won on 2023/10/9.
//
//  VAS:Value-added services

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

typedef NSString TSODVASAbilityKey NS_SWIFT_NAME(AbilityKey);
FOUNDATION_EXTERN TSODVASAbilityKey * const TSODVASAbilityDataCloudStore NS_SWIFT_NAME(AbilityDataCloudStore);
FOUNDATION_EXTERN TSODVASAbilityKey * const TSODVASAbilityTrackRecord NS_SWIFT_NAME(AbilityTrackRecord);
FOUNDATION_EXTERN TSODVASAbilityKey * const TSODVASAbilityTravelMapbox NS_SWIFT_NAME(AbilityTravelMapbox);
FOUNDATION_EXTERN TSODVASAbilityKey * const TSODVASAbilitySIMCenterCard;
FOUNDATION_EXTERN TSODVASAbilityKey * const TSODVASAbilityRidingVoiceBroadcast;

NS_SWIFT_NAME(ExtendInfo)
@interface TSODVASExtendInfo : NSObject
// Total Cellular Data Usage (KB)
@property (nonatomic, assign) long long trafficUsable;
// Used Cellular Data Usage (KB)
@property (nonatomic, assign) long long trafficUsed;
// Effective Date of Plan Service
@property (nonatomic, assign) NSTimeInterval trafficEffectDate;
// Expiry Date of Plan Service
@property (nonatomic, assign) NSTimeInterval trafficExpireDate;
@end


NS_SWIFT_NAME(AbilityModel)
@interface TSODVASAbilityModel : NSObject

// true means possessing advanced capabilities of smart services for travel, false means not having advanced capabilities.
@property (nonatomic, assign) BOOL isPidHadVAS;
// Optional: god or brand
@property (nonatomic, copy, nullable) NSString *serviceProvider;

// Required: true means smart services are in service, false means not in service (smart services have expired or not purchased).
@property (nonatomic, assign) BOOL inService;
// Required: true means a popup has occurred, false means no popup.
@property (nonatomic, assign) BOOL hadPopup;
// Optional: URL for purchasing smart services.
@property (nonatomic, copy, nullable) NSString *commodityUrl;
// Required: Product Binding Tag (Mini Program ID)
@property (nonatomic, copy, nullable) NSString *bindingTag;

@property (nonatomic, strong) TSODVASExtendInfo *extendInfo;

// Required: same AbilityKey
@property (nonatomic, copy) TSODVASAbilityKey *externalCode;
// Required: Value-added services start time
@property (nonatomic, assign) double effectiveStartDate;
// Required: Value-added services end time
@property (nonatomic, assign) double effectiveEndDate;

@end

NS_SWIFT_NAME(ValueAddedServicesModel)
@interface TSODValueAddedServicesModel : NSObject

@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, copy) NSString *devId;

/// key: abilityKey value: abilityModel
@property (nonatomic, copy) NSDictionary<TSODVASAbilityKey *, TSODVASAbilityModel *> *abilityMap;

/// ability from abilityMap
/// - Parameter key: AbilityKey
- (nullable TSODVASAbilityModel *)abilityForKey:(TSODVASAbilityKey *)key NS_SWIFT_NAME(ability(key:));

@end

NS_ASSUME_NONNULL_END
