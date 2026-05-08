//
//  TuyaSmartThingModel.h
//  TuyaSmartDeviceCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartSchemaPropertyModel.h"

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartThingServiceModel;
@class TuyaSmartThingProperty;
@class TuyaSmartThingAction;
@class TuyaSmartThingEvent;

@interface TuyaSmartThingModel : NSObject
/// The thing model's id.
@property (nonatomic, strong) NSString *modelId;
/// The thing model's product id.
@property (nonatomic, strong) NSString *productId;
/// The thing model's product version.
@property (nonatomic, strong) NSString *productVersion;
/// The thing model's services.
@property (nonatomic, strong) NSArray<TuyaSmartThingServiceModel *> *services;
/// The thing model's extensions.
@property (nonatomic, strong) NSDictionary *extensions;

/// Transfer properties to dps formate
///
/// Example:
/// Input:
/// {
///   "code_name": {
///     "value": "xxx",
///     "time": 1234567890
///   }
/// }
/// The property's code="code_name", abilityId="101".
/// Output:
/// {
///   "dps": {
///     "101": "xxx"
///   },
///   "dpsTime": {
///     "101": 1234567890
///   }
/// }
///
/// @param properties properties
- (NSDictionary *)dpsFromProperties:(NSDictionary *)properties;

@end

@interface TuyaSmartThingServiceModel : NSObject
/// The list of properties.
@property (nonatomic, strong) NSArray<TuyaSmartThingProperty *> *properties;
/// The list of acrtions.
@property (nonatomic, strong) NSArray<TuyaSmartThingAction *> *actions;
/// The list of events.
@property (nonatomic, strong) NSArray<TuyaSmartThingEvent *> *events;
@end

@interface TuyaSmartThingProperty : NSObject
/// The property id.
@property (nonatomic, assign) NSInteger abilityId;
/// The property code.
@property (nonatomic, strong) NSString *code;
/// The access mode.
///   - rw: send and report
///   - ro: only report
///   - wr: only send.
@property (nonatomic, strong) NSString *accessMode;
/// The type spec.
@property (nonatomic, strong) NSDictionary *typeSpec;
/// The default value.
@property (nonatomic, strong) id defaultValue;
@end
  
@interface TuyaSmartThingAction : NSObject
/// The action id.
@property (nonatomic, assign) NSInteger abilityId;
/// The action code.
@property (nonatomic, strong) NSString *code;
/// The input params of action.
@property (nonatomic, strong) NSArray *inputParams;
/// The output params of action.
@property (nonatomic, strong) NSArray *outputParams;
@end

@interface TuyaSmartThingEvent : NSObject
/// The event id.
@property (nonatomic, assign) NSInteger abilityId;
/// The event code.
@property (nonatomic, strong) NSString *code;
/// The output params of event.
@property (nonatomic, strong) NSArray *outputParams;

@end

NS_ASSUME_NONNULL_END
