//
//  IndustryAssetDeviceListResult.h
//  Pods
//
//  Copyright (c) 2014-2022 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
@import IndustryAssetKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryAssetDeviceListResult : NSObject <IAssetDeviceListResult>

@property (nonatomic, copy) NSArray<id<IAssetDevice>> *devices;

@property (nonatomic, assign) BOOL hasMore;

@property (nonatomic, copy) NSString *lastRowKey;

@end

NS_ASSUME_NONNULL_END
