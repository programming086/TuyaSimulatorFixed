//
//  TuyaSmartBeaconRequestModel.h
//  TuyaSmartBeaconKit
//
//  Created by Christina Ma on 2021/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBeaconRequestModel : NSObject

@property (nonatomic) NSUInteger groupId;
@property (nonatomic, strong) NSString *authDeviceMac;
@property (nonatomic) BOOL authResult;
@property (nonatomic) BOOL checkResult;

@end

NS_ASSUME_NONNULL_END
