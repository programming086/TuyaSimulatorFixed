//
//  IndustryDevice.h
//  TuyaIoTAppSDK
//
//  Created by 后主 on 2022/6/14.
//

#import <Foundation/Foundation.h>

@import IndustryDeviceKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryDevice : NSObject <IDevice>

- (instancetype)initWithDeviceId:(NSString *)deviceId;

@property (nonatomic, weak) id<IDeviceDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
