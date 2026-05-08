//
//  ThingSmartFamilyError.h
//  Pods
//
//  Created by 柒松 on 2023/10/17.
//

#ifndef ThingSmartFamilyError_h
#define ThingSmartFamilyError_h

typedef NS_ENUM(NSUInteger, ThingSmartFamilyError) {
    ThingSmartFamilyError_InvalidParams = 2200,
    
    ThingSmartFamilyError_FamilyNotExist = 2201,
    
    ThingSmartFamilyError_FamilyAlreadyExist = 2202,
    
    ThingSmartFamilyError_CannotOperateFamilyWhenLocked = 2203,
    
    ThingSmartFamilyError_FamilyHaveService = 2204,
    
    ThingSmartFamilyError_RoomNameOutLength = 2205,
    
    ThingSmartFamilyError_RoomCountOverLimit = 2206,
    
    ThingSmartFamilyError_MemberNotExist = 2207,
    
    ThingSmartFamilyError_AlreadyFamilyOwner = 2208,
    
    ThingSmartFamilyError_UserNotAccept = 2209,
    
    ThingSmartFamilyError_RemoveAllBeforeDeleteFamily = 2210,
    
    ThingSmartFamilyError_AccountIsEmpty = 2211,
    
    ThingSmartFamilyError_CannotAddLowVersionUser = 2212,
    
    ThingSmartFamilyError_AlreadyInFamily = 2213,
    
    ThingSmartFamilyError_UserNotExist = 2214,
    
    ThingSmartFamilyError_InvitationCountOverLimit = 2215,
    
    ThingSmartFamilyError_AcceptInvitationOverLimit = 2216,
    
    ThingSmartFamilyError_InvitaionCodeInvalid = 2217,
    
    ThingSmartFamilyError_InvalidInput = 2218,
};

#endif /* ThingSmartFamilyError_h */
