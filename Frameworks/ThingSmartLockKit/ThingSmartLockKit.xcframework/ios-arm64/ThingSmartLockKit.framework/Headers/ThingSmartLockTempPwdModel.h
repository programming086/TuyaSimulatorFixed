
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Password Status
typedef NS_ENUM(NSUInteger, ThingLockTempPwdStatusType) {
    ThingLockTempPwdStatusTypeRemoved     = 0, // Deleted
    ThingLockTempPwdStatusTypeToBeDeleted = 3, // Pending Deletion
    
    ThingLockTempPwdStatusTypeToBePubilsh = 1, // Pending Issuance
    ThingLockTempPwdStatusTypePublished   = 2, // Issued
};

// Password Validity Status
typedef NS_ENUM(NSUInteger, ThingLockTempPwdEffectiveType) {
    ThingLockMemberStatusTypeInvalid     = 1, // Invalid
    ThingLockMemberStatusTypeToBePubilsh = 2, // Pending Issuance
    ThingLockMemberStatusTypeWorking     = 3, // In Use
    ThingLockMemberStatusTypeToBeDeleted = 4, // Pending Deletion
    ThingLockTempPwdEffectiveTypeExpired = 5, // Expired
};

@interface ThingSmartLockTempPwdModel : NSObject

@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *name; // Temporary password name
@property (nonatomic, assign) NSTimeInterval invalidTime; // Expiration time, 10-digit timestamp
@property (nonatomic, assign) NSTimeInterval effectiveTime; // Effective time, 10-digit timestamp
@property (nonatomic, assign) NSTimeInterval createTime;  // Creation time, 13-digit timestamp
@property (nonatomic, assign) ThingLockTempPwdStatusType phase; // Password status
@property (nonatomic, assign) ThingLockTempPwdEffectiveType effective; // Password validity status
@property (nonatomic, assign) NSInteger code; // Unique ID
@property (nonatomic, assign) NSInteger sn; // Password number, associated with an account

@property (nonatomic, strong, readonly) NSDate *invalidDate;    // Expiration date, derived from invalidTime
@property (nonatomic, assign, readonly) NSDate *effectiveDate;  // Effective date, derived from effectiveTime
@property (nonatomic, assign, readonly) NSDate *createDate;  // Creation date, derived from createTime

@end

NS_ASSUME_NONNULL_END
