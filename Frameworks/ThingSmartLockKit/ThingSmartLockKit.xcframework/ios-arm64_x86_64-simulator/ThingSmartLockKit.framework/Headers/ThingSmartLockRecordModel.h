
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartLockRecordModel : NSObject

@property (nonatomic, strong) NSString *devId; // Device ID
@property (nonatomic, strong) NSArray<NSDictionary *> *dpsArray; // DPS Data Array
@property (nonatomic, strong) NSString *avatarUrl; // Avatar URL
@property (nonatomic, strong) NSString *userName; // User Name
@property (nonatomic, assign) NSTimeInterval time; // Occurrence Time, 13 digits
@property (nonatomic, strong) NSString *userId; // Member ID
@property (nonatomic, strong) NSString *uuid; // Identifier
@property (nonatomic, strong) NSDictionary *dpData; // DP Data
@property (nonatomic, assign) NSInteger status; // Status Bit
@property (nonatomic, assign) NSInteger tags; // Tag Bit, 0 indicates others, 1 indicates hijack alarm

@end

NS_ASSUME_NONNULL_END
