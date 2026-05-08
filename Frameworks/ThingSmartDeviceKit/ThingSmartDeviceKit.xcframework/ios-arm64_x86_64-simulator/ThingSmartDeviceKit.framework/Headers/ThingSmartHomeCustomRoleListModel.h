//
//  ThingSmartHomeCustomRoleListModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

#ifndef ThingSmartHomeCustomRoleListDefine_h
#define ThingSmartHomeCustomRoleListDefine_h

typedef NS_ENUM(NSInteger, ThingHomeRoleResourceType) {
    ThingHomeRoleResourceType_Device = 0,  /**< The device resource. */
    ThingHomeRoleResourceType_OneClick  = 1,   /**< The one click resource. */
    ThingHomeRoleResourceType_Automation  = 2,  /**< The automation resource. */
    
};

typedef NS_ENUM(NSInteger, ThingHomeRoleSaveResult) {
    ThingHomeRoleSaveResult_Success = 1,  /**< The operation succeeded.. */
    ThingHomeRoleSaveResult_HaveSubDeviceList  = 0,  /**< The operation succeeded, but the resources contain subdevices. */
    ThingHomeRoleSaveResult_Failure  = -1   /**< The operation failed. */
};

#endif


@interface ThingSmartHomeSaveResultModel : NSObject

@property (nonatomic, assign) long long roleId;

@property (nonatomic, assign) ThingHomeRoleSaveResult resultCode;

@end

NS_ASSUME_NONNULL_BEGIN


@interface ThingSmartHomeCustomRoleResourceModel : NSObject

/// The resource's type
@property (nonatomic, assign) ThingHomeRoleResourceType resType;
/// The resource's ID
@property (nonatomic, strong) NSString *resId;

@end


@interface ThingSmartHomeCustomRoleModel : NSObject

///The role's ID
@property (nonatomic, assign) long long roleId;
///The role's name
@property (nonatomic, strong) NSString *roleName;

/// The resource's list.
@property (nonatomic, strong) NSArray<ThingSmartHomeCustomRoleResourceModel *> *resourceList;

@end

@interface ThingSmartHomeCustomRoleListModel : NSObject

/// Create an upper limit for the role.
@property (nonatomic, assign) NSInteger roleCreateLimit;
/// The role's list.
@property (nonatomic, strong) NSArray<ThingSmartHomeCustomRoleModel *> *roleList;

@end


@interface ThingSmartHomeResourceModel : NSObject

/// The ID  of resource.
@property (nonatomic, copy) NSString *resourceId;
/// The icon  of resource.
@property (nonatomic, copy) NSString *icon;
/// The icon  of resource.
@property (nonatomic, copy) NSString *name;
/// The background color of resource.
@property (nonatomic, copy) NSString *background;


@end

NS_ASSUME_NONNULL_END
