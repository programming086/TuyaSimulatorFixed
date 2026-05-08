//
//  ThingLampCapacityModel.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ThingLampCapacityAction) {
    ThingLampCapacityAction_None = 0,               // No processing done
    ThingLampCapacityAction_CommonAllowClose = 1,   // Normal popup (closable)
    
    ThingLampCapacityAction_DeviceAllowClose,      // Device Excess Popup (Closable)
    ThingLampCapacityAction_DeviceForbidClose,      // Device Excess Popup (No Close Button)
    ThingLampCapacityAction_DeviceCancelDelete,    // Device Excess Popup Cancel & Delete
    ThingLampCapacityAction_DeviceForceDelete,     //  Device Excess Popup Force Delete
    
    ThingLampCapacityAction_ProjectAllowClose,     // Project Excess Popup (Closable)
    ThingLampCapacityAction_ProjectForbidClose,     // Project Excess Popup (No Close Button)
    ThingLampCapacityAction_ProjectCancelDelete,   // Project Excess Popup Cancel & Delete
    ThingLampCapacityAction_ProjectForceDelete,    // Project Excess Popup Force Delete
};

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Home Page BAR
@interface ThingLampCapacityBarModel : NSObject
@property (nonatomic, strong) NSString *message;
@end

#pragma mark - Popup Action
@interface ThingLampCapacityDialogActionModel : NSObject
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *code;
@end

#pragma mark - Popup Object
@interface ThingLampCapacityDialogModel : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSArray<ThingLampCapacityDialogActionModel *> *actions;
@end


#pragma mark - Validation Object
static NSString *const kLampCapacityType_DevicePoint = @"devicePoint";
static NSString *const kLampCapacityType_ProjectPoint = @"projectPoint";
static NSString *const kLampCapacityType_Common = @"commonPoint";

@interface ThingLampCapacityModel : NSObject
@property (nonatomic, assign,readonly) ThingLampCapacityAction action;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) ThingLampCapacityDialogModel *dialog;
@property (nonatomic, strong) ThingLampCapacityBarModel *bar;
@end

NS_ASSUME_NONNULL_END
