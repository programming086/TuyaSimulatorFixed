
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSweeperRecordList : NSObject

@property (copy, nonatomic) NSString *recordId;
@property (assign, nonatomic) NSInteger gid;
@property (assign, nonatomic) NSInteger dpId;
@property (assign, nonatomic) long long gmtCreate;
@property (copy, nonatomic) NSString *value;
@property (copy, nonatomic) NSString *uuid;

/**
 * By parsing the value data of the historical record list, calculate the subRecordId
 * Value map information, parse subRecordId
 */
+ (NSString *)subRecordIdObtainFromValue:(NSString *)value;

@end

NS_ASSUME_NONNULL_END
