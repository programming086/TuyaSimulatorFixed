
#import <Foundation/Foundation.h>
#import "ThingSmartLockRelationModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingLockMemberUserType) {
    ThingLockMemberUserTypeHomeMember = 1, // Family Member
    ThingLockMemberUserTypeNomal      = 2, // Non-Family Member
};

@interface ThingSmartLockMemberModel : NSObject

@property (nonatomic, strong) NSString *userId; // Member ID
@property (nonatomic, strong) NSString *userName; // User Nickname
@property (nonatomic, strong) NSString *avatarUrl; // Avatar URL
@property (nonatomic, strong) NSString *contact; // Contact Information
@property (nonatomic, strong) NSArray<ThingSmartLockRelationModel *> *unlockRelations; // Unlocking Relation IDs
@property (nonatomic, strong) NSString *devId; // Lock Device ID
@property (nonatomic, strong) NSString *ownerId; // Owner ID

@property (nonatomic, strong) NSDictionary *originJson; // Original JSON

// Lock Member Type, Family Member or Non-Family Member
// Family Members can only be created through `ThingSmartHomeMember`, and users created by the lock device are Non-Family Members
@property (nonatomic, assign) ThingLockMemberUserType userType; // Lock Member Type

@end


NS_ASSUME_NONNULL_END
