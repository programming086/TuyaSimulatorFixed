//
//  IndustryAssetDevice.h
//  IndustryAssetImpl
//
//  Created by 后主 on 2022/7/25.
//

#import <Foundation/Foundation.h>
@import IndustryAssetKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryAssetDeviceStatistics : NSObject<IAssetDeviceStatistics>

@property (nonatomic, copy) NSString *typeValue;
@property (nonatomic, copy) NSString *statisticType;
@property (nonatomic, assign) NSInteger total;

@end


@interface IndustryAssetDevice : NSObject <IAssetDevice>

@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, assign) BOOL online;
@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *absoluteIconUrl;
@property (nonatomic, copy) NSString *homeId;
@property (nonatomic, copy) NSString *permission;

@end

NS_ASSUME_NONNULL_END
