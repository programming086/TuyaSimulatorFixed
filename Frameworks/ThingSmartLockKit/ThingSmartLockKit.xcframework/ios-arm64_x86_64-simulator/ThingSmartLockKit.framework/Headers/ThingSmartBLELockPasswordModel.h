
#import <Foundation/Foundation.h>
#import "ThingSmartBLELockScheduleModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingLOCK_TEMPORARY_PASSWORD) {
    ThingLOCK_TEMPORARY_PASSWORD_CREATE = 1,
    ThingLOCK_TEMPORARY_PASSWORD_MODIFY = 2,
    ThingLOCK_TEMPORARY_PASSWORD_DELETE = 3
};

typedef enum : NSInteger {
    ThingLOCK_TEMPORARY_CREATE_SUCCESS = 0x00, // Successfully Added
    ThingLOCK_TEMPORARY_CREATE_FAILURE = 0x01, // Failed to Add
    ThingLOCK_TEMPORARY_CREATE_SN_OVER = 0x02, // Hardware ID Allocation Exhausted
    ThingLOCK_TEMPORARY_CREATE_PASSWORD_REPEAT = 0x03, // Password Duplication
} ThingLOCK_TEMPORARY_CREATE;

typedef enum : NSInteger {
    ThingLOCK_TEMPORARY_MODIFY_SUCCESS = 0x00, // Successfully Modified
    ThingLOCK_TEMPORARY_MODIFY_FAILURE = 0x01, // Failed to Modify
} ThingLOCK_TEMPORARY_MODIFY;

typedef enum : NSInteger {
    ThingLOCK_TEMPORARY_DELETE_SUCCESS = 0x00, // Successfully Deleted
    ThingLOCK_TEMPORARY_DELETE_FAILURE = 0x01, // Failed to Delete
    ThingLOCK_TEMPORARY_DELETE_PASSWORD_NOT_EXIST = 0x02, // Temporary Password Does Not Exist
} ThingLOCK_TEMPORARY_DELETE;

@interface ThingSmartBLELockPasswordModel : NSObject

@property (nonatomic, assign) int firmwareId;
@property (nonatomic, assign) ThingLOCK_TEMPORARY_CREATE createResult;
@property (nonatomic, assign) ThingLOCK_TEMPORARY_MODIFY modifyResult;
@property (nonatomic, assign) ThingLOCK_TEMPORARY_DELETE deleteResult;

@property (nonatomic, copy, readonly) NSString *hexCommand;

- (instancetype)initCreatePasswordModelWithAvailTime:(NSInteger)availTime
                                       effectiveTime:(NSInteger)effectiveTime
                                         invalidTime:(NSInteger)invalidTime
                                            schedule:(ThingSmartBLELockScheduleList *)schedule
                                                type:(ThingLOCK_TEMPORARY_PASSWORD)type
                                            password:(NSString *)password
                                                  sn:(NSInteger)sn;

- (instancetype)initDeletePasswordModelWithSn:(NSInteger)sn;

@end

NS_ASSUME_NONNULL_END
