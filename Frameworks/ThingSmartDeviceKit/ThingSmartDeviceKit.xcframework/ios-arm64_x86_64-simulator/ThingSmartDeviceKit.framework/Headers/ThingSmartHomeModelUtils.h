//
//  ThingSmartHomeModelUtils.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#ifndef ThingSmartHomeModelUtils_h
#define ThingSmartHomeModelUtils_h

typedef NS_ENUM(NSInteger, ThingHomeRoleType) {
    ThingHomeRoleType_Unknown = -999,  /**< The invalid role. */
    ThingHomeRoleType_Custom  = -1,  /**< The customized role. */
    ThingHomeRoleType_Member  = 0,   /**< The general home member. */
    ThingHomeRoleType_Admin,         /**< The home administrator who is not authorized to add or delete other administrators. */
    ThingHomeRoleType_Owner,         /**< The home super administrator and the home owner. */
};

typedef NS_ENUM(NSUInteger, ThingHomeStatus) {
    ThingHomeStatusPending = 1,      /**< Invitees have not decided whether to join the specified home. */
    ThingHomeStatusAccept,           /**< Invitees have agreed to join the specified home. */
    ThingHomeStatusReject            /**< Invitees have declined to join the specified home. */
};

#endif /* ThingSmartHomeModelUtils_h */
