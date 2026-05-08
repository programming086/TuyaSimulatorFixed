//
//  TuyaSmartBeaconResponseModel.h
//  TuyaSmartBeaconKit
//
//  Created by Christina Ma on 2021/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBeaconResponseModel : NSObject

@property (nonatomic) NSUInteger groupId;
@property (nonatomic, strong) NSString *authDeviceMac;
@property (nonatomic, strong) NSString *authDeviceS1;

@end

NS_ASSUME_NONNULL_END
