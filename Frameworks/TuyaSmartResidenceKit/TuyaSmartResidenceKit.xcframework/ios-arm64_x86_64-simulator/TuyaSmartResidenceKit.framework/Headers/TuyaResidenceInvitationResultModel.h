//
//  TuyaResidenceInvitationResultModel.h
//  TuyaSmartResidenceKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
#import "TuyaResidentSiteModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaResidenceAddMemberRequestModel : NSObject

@property (nonatomic, copy) NSString *name;

/// The invited accounts.
@property (nonatomic, copy) NSString *account;

/// The invitee account for the specified country code.
@property (nonatomic, copy) NSString *countryCode;

/// The member role. Set the required role type.
@property (nonatomic, assign) TYSiteRoleType role;

/// The avatar for the invitee. If the value is set to nil, the invitee's personal avatar is used.
@property (nonatomic, strong) UIImage *headPic;

/// Specifies whether the invitee must accept the invitation. Valid values: `YES`: The invited account automatically accepts the home invitation without the invitee's confirmation. `NO`: The invitee's consent is required to join the home.
@property (nonatomic, assign) BOOL autoAccept;

@end

@interface TuyaResidenceInvitationCreateRequestModel : NSObject

/// The site ID.
@property (nonatomic, assign) long long siteId;

/// A Boolean value that specifies whether an invitation message is required.
@property (nonatomic, assign) BOOL needMsgContent;

@end

@interface TuyaResidenceInvitationReinviteRequestModel : NSObject

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationId;

/// A Boolean value that specifies whether an invitation message is required.
@property (nonatomic, assign) BOOL needMsgContent;

@end

@interface TuyaResidenceInvitationInfoRequestModel : NSObject

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationId;

/// The name in the invitation remarks.
@property (nonatomic, copy) NSString *name;

@end

@interface TuyaResidenceInvitationResultModel : NSObject

/// The invitation message.
@property (nonatomic, copy) NSString *invitationMsgContent;

/// The invitation code.
@property (nonatomic, copy) NSString *invitationCode;

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationId;

@end


@interface TuyaResidenceInvitationRecordModel : NSObject;

/// The validity period of the invitation code. Unit: hours.
@property (nonatomic, assign) NSInteger validTime;

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationId;

/// The invitation code.
@property (nonatomic, copy) NSString *invitationCode;

/// The name in the invitation remarks.
@property (nonatomic, copy) NSString *name;

@end

NS_ASSUME_NONNULL_END
