//
//  ThingResidenceAccessRecordModel.h
//  ThingSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceAccessRecordModel : NSObject
/// The ID of device
@property (nonatomic, copy) NSString *deviceId;

@property (nonatomic, copy) NSString *unlockName;

/// Creation time
@property (nonatomic, strong) NSNumber *createTime;

/// The name of device
@property (nonatomic, copy) NSString *deviceName;

@property (nonatomic, copy) NSString *dp;
@end

NS_ASSUME_NONNULL_END
