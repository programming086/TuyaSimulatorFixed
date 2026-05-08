//
//  ThingLightingRepairOrderModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingRepairOrderModel : NSObject

/// The number of repair work order
@property (nonatomic, copy) NSString *ticketNo;

/// The status description of repair work order
@property (nonatomic, copy) NSString *ticketStatus;

/// The status of repair work order
@property (nonatomic, copy) NSString *state;

/// Start time
@property (nonatomic, assign) long startTime;

/// End time
@property (nonatomic, assign) long endTime;

/// Finish time
@property (nonatomic, assign) long finishTime;

/// The type of repair work order. 1.manual 2.exception 3.alarm
@property (nonatomic, assign) NSInteger ticketType;

/// The description of repair work order type. (Same as above)
@property (nonatomic, copy) NSString *ticketTypeDesc;

/// The content of repair work order
@property (nonatomic, copy) NSString *ticketContent;

/// The classification of question
@property (nonatomic, copy) NSString *problemClassification;

/// Device name
@property (nonatomic, copy) NSString *deviceName;

@end

NS_ASSUME_NONNULL_END
