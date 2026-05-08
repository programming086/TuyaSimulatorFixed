//
//  TuyaSmartLogTrackConfiguration.h
//  TuyaSmartPairingCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TuyaSmartLogTrackHandleDelegate <NSObject>

@required
- (void)logTrackStartWithAttribute:(NSDictionary *)attribute;

- (void)logTrackFullLinkWithAttribute:(NSDictionary *)attribute infos:(NSDictionary *)infos trackType:(NSString *)trackType;

- (void)logTrackDeviceWithAttribute:(NSDictionary *)attribute;
@end

@protocol TuyaSmartLogTrackConfiguration <NSObject>

@required
@property (nonatomic, strong) NSString   *type;

@property (nonatomic, weak, nullable) id<TuyaSmartLogTrackHandleDelegate> delegate;

@end

@interface TuyaSmartLogTrackConfiguration : NSObject<TuyaSmartLogTrackConfiguration>

@end

NS_ASSUME_NONNULL_END
