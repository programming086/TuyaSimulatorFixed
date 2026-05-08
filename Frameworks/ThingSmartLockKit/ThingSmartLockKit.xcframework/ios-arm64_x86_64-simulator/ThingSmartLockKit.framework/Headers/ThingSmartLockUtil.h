
#import <Foundation/Foundation.h>
#import "ThingSmartBLELockScheduleModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartLockUtil : NSObject

+ (NSString *)getScheduleTime:(int )time;

+ (NSString *)getHexByDecimal:(NSInteger)decimal;

+ (NSString *)getBinaryByDecimal:(NSInteger)decimal;

+ (NSArray *)getOpenDoorDpCodes;

+ (NSString *)getProUnlockDpValue:(NSString *)lockUserId;

+ (NSString *)getProUnlockDpValue:(NSString *)devUnlockId ins:(NSString *)ins lockUserId:(NSString *)lockUserId;

+ (NSString *)getScheduleListHexValue:(NSArray<ThingSmartBLELockScheduleModel *> *)scheduleList;

+ (NSString *)getCancelUnlockOpmodeDpValue:(BOOL)isAdmin lockUserId:(int)lockUserId;

+ (NSString *)getDeleteMemberDpValue:(BOOL)isAdmin lockUserId:(int)lockUserId;

@end

NS_ASSUME_NONNULL_END
