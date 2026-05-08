//
//  ThingSmartMultiControlDeviceModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMultiControlDeviceModel : NSObject

@property (copy, nonatomic) NSString *devId;///< The device ID.
@property (copy, nonatomic) NSString *productId;///< The product ID.
@property (copy, nonatomic) NSString *name;///< The device name.
@property (copy, nonatomic) NSString *iconUrl;///< The URL of the device icon.
@property (copy, nonatomic) NSString *roomName;///< The room name.
@property (assign, nonatomic) BOOL inRule;///< A Boolean value that indicates whether the device is in an automated condition.
@property (strong, nonatomic) NSArray<ThingSmartMultiControlDatapointModel *> *datapoints;
@property (strong, nonatomic) NSArray<NSString *> *multiControlIds;///< The arrays of the multi-control group IDs with which the device has been associated.


@end

NS_ASSUME_NONNULL_END
