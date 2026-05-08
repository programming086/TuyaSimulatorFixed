//
//  IndustrySpaceModelCollection.h
//  Pods
//
//  Copyright (c) 2014-2023 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
@import IndustrySpaceKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustrySpaceModel : NSObject <ISpace>

@property (nonatomic, copy) NSString *spaceId;
@property (nonatomic, copy) NSString *spaceName;
@property (nonatomic, copy, nullable) NSString *parentSpaceId;
@property (nonatomic, copy) NSString *permission;
@property (nonatomic, assign) NSInteger currentSubSpaceNum;
@property (nonatomic, assign) NSInteger currentSpaceDeviceNum;
@property (nonatomic, copy) NSString *userDefinedPath;

@end

@interface IndustrySpaceDeviceStatistics : NSObject<ISpaceDeviceStatistics>

@property (nonatomic, copy) NSString *typeValue;
@property (nonatomic, copy) NSString *statisticType;
@property (nonatomic, assign) NSInteger total;

@end


@interface IndustrySpaceDevice : NSObject <ISpaceDevice>

@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, assign) BOOL online;
@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *absoluteIconUrl;
@property (nonatomic, copy) NSString *homeId;
@property (nonatomic, copy) NSString *permission;

@end


@interface IndustrySpaceDeviceListResult : NSObject <ISpaceDeviceListResult>

@property (nonatomic, copy) NSArray<id<ISpaceDevice>> *devices;
@property (nonatomic, assign) BOOL hasMore;
@property (nonatomic, copy) NSString *lastRowKey;

@end


@interface IndustrySpaceModelCollection : NSObject

@end

NS_ASSUME_NONNULL_END
