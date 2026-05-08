//
//  TSmartScenePreconditionParam.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/6/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The types indicate the types of events within the valid period.
typedef NS_ENUM(NSInteger, TSmartScenePreconditionType) {
    /// The unknown type.
    TSmartScenePreconditionTypeUnknow = -1,
    /// The allday type.
    TSmartScenePreconditionTypeAllDay = 0,
    /// The daytime type.
    TSmartScenePreconditionTypeDaytime,
    /// The night type.
    TSmartScenePreconditionTypeNight,
    /// The custom type.
    TSmartScenePreconditionTypeCustom,
};

@interface TSmartScenePreconditionParam : NSObject

/// The scene id. You can pass nil when create an automation scene.
@property (nonatomic, strong, nullable) NSString *sceneID;

/// The current condition id. You need to pass the original condition id when editing scene for automation scene.
@property (nonatomic, strong, nullable) NSString *conditionID;

/// The precondition type, detail see `TSmartScenePreconditionType`.
@property (nonatomic, assign) TSmartScenePreconditionType preconditionType;

/// The begin date. eg:"00:59". When the preconditionType is `TSmartScenePreconditionTypeCustom`, the beginDate must be passed.
@property (nonatomic, strong) NSString *beginDate;

/// The end date. eg:"18:30". When the preconditionType is `TSmartScenePreconditionTypeCustom`, the endDate must be passed.
@property (nonatomic, strong) NSString *endDate;

/// The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
@property (nonatomic, strong) NSString *loops;

/// The current city id. When the preconditionType is `TSmartScenePreconditionTypeAllDay`, you don't have to pass cityId.
@property (nonatomic, strong, nullable) NSString *cityId;

/// The current city name. When the preconditionType is `TSmartScenePreconditionTypeAllDay`, you don't have to pass cityName.
@property (nonatomic, strong, nullable) NSString *cityName;

/// The timezone id, default is "Asia/Shanghai".
@property (nonatomic, strong, nullable) NSString *timeZoneId;

/// Returns a description string based on the preconditionType. It includes allday, daytime, night, custom.
- (NSString *)stringFromPreconditionType;

@end

NS_ASSUME_NONNULL_END
