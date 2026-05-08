//
//  TuyaSecurityBypassDeviceModel.h
//  TYSecurityArmAbilityBizKit
//
//  Created by Tuya.Inc on 2021/4/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityBypassDeviceModel : NSObject

@property (copy, nonatomic) NSString *titleString;
@property (nonatomic, copy) NSString *subTitleString;
@property (nonatomic, copy) NSString *iconUrl;
@property(nonatomic, assign) BOOL isOfflineDevice;
@property(nonatomic, copy) NSString *areaCode;
@property(nonatomic, copy) NSString *deviceId;


@end

NS_ASSUME_NONNULL_END
