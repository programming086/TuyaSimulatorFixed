//
//  ThingLightingRemoteDataTransfer.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
@class ThingLightingConstructionResourceDetail;
@class ThingLightingActivateDeviceModel;
@class ThingLightingActivateModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingRemoteDataTransfer : NSObject


/// Send resource data to the remote controller
/// - Parameter spaces: Resource array
+ (NSData *)json2bin:(NSArray<ThingLightingConstructionResourceDetail *> *)spaces;


/// Convert remote controller data into a data model
/// - Parameter binData: Data uploaded from the remote controller
+ (NSArray<ThingLightingActivateDeviceModel *> *)up_bin2json:(NSData *)binData;


@end

NS_ASSUME_NONNULL_END
