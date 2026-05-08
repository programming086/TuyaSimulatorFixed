//
//  ThingLightingDevLocationModel.h
//  AFNetworking
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingDevLocationModel : NSObject


/// The device ID.
@property (nonatomic, copy) NSString *deviceId;

/// Latitude
@property (nonatomic, copy) NSString *x;/// UID

/// Longitude
@property (nonatomic, copy) NSString *y;

/// The address by device
@property (nonatomic, copy) NSString *address;



@end

NS_ASSUME_NONNULL_END
