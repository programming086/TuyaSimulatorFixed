//
//  ThingLightDpPropertyModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Dp property model
@interface ThingLightDpPropertyModel : NSObject

/// Type: enum - enumerated | bool - boolean | string - string | value - numeric | bitmap - fault
@property (nonatomic, strong) NSString *type;

/// Unit For example, ℃
@property (nonatomic, strong) NSString *unit;

/// Minimum value of numeric type
@property (nonatomic, assign) double min;

/// Max when type is value
@property (nonatomic, assign) double max;

/// Numerical step
@property (nonatomic, assign) double step;

/// The exponent of 10 in the numeric type, multiplied by the corresponding transmission value, is equal to the actual value and is used to avoid fractional transmission
@property (nonatomic, assign) NSInteger scale;

/// The maximum number of bits of the fault type
@property (nonatomic, assign) NSInteger maxlen;

/// Detailed description of the fault type
@property (nonatomic, strong) NSArray *label;

/// Scope of the enumeration type
@property (nonatomic, strong) NSArray *range;

/// Value of the user to select
@property (nonatomic, assign) NSInteger selectedValue;


@end

NS_ASSUME_NONNULL_END

