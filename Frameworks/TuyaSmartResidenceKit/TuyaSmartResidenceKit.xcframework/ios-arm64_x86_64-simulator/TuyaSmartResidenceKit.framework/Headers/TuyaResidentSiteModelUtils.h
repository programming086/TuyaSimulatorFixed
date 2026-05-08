//
//  TuyaResidentSiteModelUtils.h
//  TuyaSmartResidenceKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#ifndef TuyaResidentSiteModelUtils_h
#define TuyaResidentSiteModelUtils_h

typedef NS_ENUM(NSInteger, TYSiteRoleType) {
    TYSiteRoleType_Unknown = -999,  /**< The invalid role. */
    TYSiteRoleType_Custom  = -1,  /**< The customized role. */
    TYSiteRoleType_Member  = 0,   /**< The general site member. */
    TYSiteRoleType_Admin,         /**< The Site administrator who is not authorized to add or delete other administrators. */
    TYSiteRoleType_Owner,         /**< The Site super administrator and the site owner. */
};

typedef NS_ENUM(NSUInteger, TYSiteStatus) {
    TYSiteStatusPending = 1,      /**< Invitees have not decided whether to join the specified site. */
    TYSiteStatusAccept,           /**< Invitees have agreed to join the specified site. */
    TYSiteStatusReject            /**< Invitees have declined to join the specified site. */
};

typedef NS_ENUM(NSInteger, TYSiteAuthStatus) {
    TYSiteAuthStatusToEffect    =   0,    /**< Coming into effect */
    TYSiteAuthStatusInEffect    =   1,    /**< Valid period */
    TYSiteAuthStatusOverdue     =   2,    /**< Expired */
    TYSiteAuthStatusForever     =   3,    /**< Long-term validity */
};

typedef NS_ENUM(NSInteger, TYSmartSiteType) {
    TYSmartSiteType_Home     =   1,    /**< Ordinary home */
    TYSmartSiteType_Access   =   2,    /**< Access home */
    TYSmartSiteType_Bisiness =   3,    /**< B-Side Empowered home */
};

#endif /* TuyaResidentSiteModelUtils_h */
