
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBLELockMemberModel : NSObject

@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *userContact;
@property (nonatomic, strong) NSString *avatarUrl;
@property (nonatomic, strong) NSString *nickName;
@property (nonatomic, strong) NSString *userTimeSet;
@property (nonatomic, assign) NSUInteger phase;
@property (nonatomic, assign) NSUInteger status;
@property (nonatomic, assign) int lockUserId;
@property (nonatomic, assign) NSUInteger userType;
@property (nonatomic, strong) NSArray *supportOpenType;
@property (nonatomic, strong) NSString *shareUser;
@property (nonatomic, assign) NSUInteger productAttribute;

@end

NS_ASSUME_NONNULL_END
