
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBLELockOpmodeModel : NSObject

@property (nonatomic, strong) NSString *opmode;
@property (nonatomic, strong) NSString *phase;
@property (nonatomic, assign) NSUInteger sourceAttribute;
@property (nonatomic, strong) NSString *unlockName;
@property (nonatomic, strong) NSString *userName;
@property (nonatomic, assign) long long lockUserId;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *opmodeValue;
@property (nonatomic, assign) NSUInteger unlockAttr;
@property (nonatomic, strong) NSString *opmodeId;
@property (nonatomic, assign) NSUInteger userType;

@end

NS_ASSUME_NONNULL_END
