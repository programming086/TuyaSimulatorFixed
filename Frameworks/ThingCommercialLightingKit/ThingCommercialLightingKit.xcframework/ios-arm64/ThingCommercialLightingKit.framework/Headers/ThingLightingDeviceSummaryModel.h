//
// ThingLightingDeviceSummaryModel.h
// ThingSmartCommercialLightingSdk
//
// Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief Device summary model
@interface ThingLightingDeviceSummaryModel : NSObject

/// Device summary id
@property (nonatomic, copy) NSString *summaryId;

/// Device summary code
@property (nonatomic, copy) NSString *code;

/// Device summary name
@property (nonatomic, copy) NSString *name;

/// Device count
@property (nonatomic, assign) long deviceCount;

/// Sub summary list
@property (nonatomic, copy) NSArray<ThingLightingDeviceSummaryModel *> *list;

@end

NS_ASSUME_NONNULL_END
