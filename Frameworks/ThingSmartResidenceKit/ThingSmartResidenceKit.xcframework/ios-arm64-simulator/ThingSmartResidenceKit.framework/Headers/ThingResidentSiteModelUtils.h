//
//  ThingResidentSiteModelUtils.h
//  ThingSmartResidenceKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#ifndef ThingResidentSiteModelUtils_h
#define ThingResidentSiteModelUtils_h

typedef NS_ENUM(NSInteger, ThingSiteRoleType) {
    ThingSiteRoleType_Unknown = -999,  /**< The invalid role. */
    ThingSiteRoleType_Custom  = -1,  /**< The customized role. */
    ThingSiteRoleType_Member  = 0,   /**< The general site member. */
    ThingSiteRoleType_Admin,         /**< The Site administrator who is not authorized to add or delete other administrators. */
    ThingSiteRoleType_Owner,         /**< The Site super administrator and the site owner. */
};

typedef NS_ENUM(NSUInteger, ThingSiteStatus) {
    ThingSiteStatusPending = 1,      /**< Invitees have not decided whether to join the specified site. */
    ThingSiteStatusAccept,           /**< Invitees have agreed to join the specified site. */
    ThingSiteStatusReject            /**< Invitees have declined to join the specified site. */
};

#endif /* ThingResidentSiteModelUtils_h */
