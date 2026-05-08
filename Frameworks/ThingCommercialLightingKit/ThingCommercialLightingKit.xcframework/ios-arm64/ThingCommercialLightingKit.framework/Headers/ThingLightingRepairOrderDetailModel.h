//
//  ThingLightingRepairOrderDetailModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingTicketDeviceModel,ThingLightingReplaceDeviceModel,ThingLightingAccountVO, ThingLightingTicketResourceModel, ThingLightingFeedBackModel;

@interface ThingLightingRepairOrderDetailModel : NSObject

/// The number of repair work order
@property (nonatomic, copy) NSString *ticketNo;

/// The status of repair work order
@property (nonatomic, copy) NSString *ticketStatus;

/// The description of repair work order state
/// (waitingForDistribute/repairing/hasDelayed/waitingForConfirm/finished)
@property (nonatomic, copy) NSString *state;

/// The type of repair work order. 1.manual 2.exception 3.alarm
@property (nonatomic, assign) NSInteger ticketType;

/// The description of repair work order type. 1.manual 2.exception 3.alarm
@property (nonatomic, copy) NSString *ticketTypeDesc;

/// The source of repair work order
@property (nonatomic, copy) NSString *source;

/// The admin ID of repair work order
@property (nonatomic, copy) NSString *adminId;

/// Room ID
@property (nonatomic, strong) NSString *roomId;

/// Projece ID
@property (nonatomic, copy) NSString *projectId;

/// Device ID
@property (nonatomic, copy) NSString *devId;

/// Current device.
@property (nonatomic, strong) ThingLightingTicketDeviceModel *ticketDevice;

/// Device type
@property (nonatomic, copy) NSString *deviceType;

/// The device ID by replaced
@property (nonatomic, copy) NSString *replaceDevId;

/// The finish time of repair work order
@property (nonatomic, assign) long finishTime;

/// The end time of repair work order
@property (nonatomic, assign) long endTime;

/// The creation time of repair work order
@property (nonatomic, assign) long gmtCreate;

/// The modified time of repair work order
@property (nonatomic, assign) long gmtModified;

/// The classification of question(custom question description)
@property (nonatomic, copy) NSString *problemClassification;

/// The replace device
@property (nonatomic, strong) ThingLightingReplaceDeviceModel *replaceDevice;

/// The status of device(1.online  0.offline)
@property (nonatomic, assign) NSInteger deviceStatus;

/// The content of repair work order
@property (nonatomic, copy) NSString *ticketContent;

/// The resources of repair work order
@property (nonatomic, strong) NSArray <ThingLightingTicketResourceModel *> *ticketResource;

/// Room name
@property (nonatomic, copy) NSString *roomName;

/// The content of feedback
@property (nonatomic, copy) NSString *feedbackContent;

/// The resources of feedback
@property (nonatomic, strong) NSArray <ThingLightingTicketResourceModel *> *feedbackResource;

/// Feedbacks on repair orders.
@property (nonatomic, strong) NSArray<ThingLightingFeedBackModel *> *feedBacks;

@property (nonatomic, strong) ThingLightingAccountVO *accountVO;

/// The remarks of repair work order
@property (nonatomic, copy) NSString *remark;

/// The description of question classified(custom question description)
@property (nonatomic, copy) NSString *problemClassificationDesc;

@end

NS_ASSUME_NONNULL_END
