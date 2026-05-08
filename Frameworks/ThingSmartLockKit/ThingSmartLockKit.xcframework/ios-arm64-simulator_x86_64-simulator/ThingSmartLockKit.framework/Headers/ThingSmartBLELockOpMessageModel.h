
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Unlocking Methods
typedef enum : NSInteger {
    ThingUnlockOpTypeMember   = 0, // Member
    ThingUnlockOpTypePassword = 1, // Password
    ThingUnlockOpTypeCard     = 2, // Card
    ThingUnlockOpTypeFinger   = 3, // Fingerprint
    ThingUnlockOpTypeFace     = 4, // Facial Recognition
    ThingUnlockOpTypePalmLines     = 5, // Palm Lines
    ThingUnlockOpTypeVeinRecognition    = 6, // Vein Recognition
    
    ThingUnlockOpTypeTimeliness = 20, // Password Timeliness
    
} ThingUnlockOpType;

typedef enum : NSInteger {
    ThingUnlockOpErrorCodeTimeout = 0x00, // Timeout
    ThingUnlockOpErrorCodeWriteError = 0x01, // Write Failure
    ThingUnlockOpErrorCodeRepeatWrite = 0x02, // Repeated Write
    ThingUnlockOpErrorCodeFirmwareIdUnavailable = 0x03, // No Available Hardware ID
    ThingUnlockOpErrorCodePasswordTypeError = 0x04, // Password Type Error, Non-numeric
    ThingUnlockOpErrorCodePasswordLengthError = 0x05, // Password Length Error
    ThingUnlockOpErrorCodeUnspoortOpType = 0x06, // Unsupported Unlocking Method
    ThingUnlockOpErrorCodeFingerWriting = 0x07, // Fingerprint Enrollment in Progress
    ThingUnlockOpErrorCodeCardWriting = 0x08, // Card Enrollment in Progress
    ThingUnlockOpErrorCodeFaceWriting = 0x09, // Facial Recognition Enrollment in Progress
    ThingUnlockOpErrorCodePasswordIsTooSimple= 0x0A, // Password is Too Simple
    
    ThingUnlockOpErrorCodeFirmwareIdError = 0xFE, // Incorrect Hardware ID
} ThingUnlockOpErrorCode;

typedef enum : NSInteger {
    ThingUnlockOpWriteStart = 0x00, // Enrollment Start
    ThingUnlockOpWriteProcessing = 0xFC, // Enrollment in Progress
    ThingUnlockOpWriteEnd = 0xFF, // Enrollment End
} ThingUnlockOpWriteProcessType;


typedef enum : NSInteger {
    ThingUnlockOpWriteStateStart = 0x00, // Start
    ThingUnlockOpWriteStateProcessing = 0xFC, // Enrollment in Progress
    ThingUnlockOpWriteStateFailure = 0xFD, // Enrollment Failure
    ThingUnlockOpWriteStateCancel = 0xFE, // Enrollment Cancellation (Initiated by App)
    ThingUnlockOpWriteStateFinish = 0xFF, // Enrollment Completion
} ThingUnlockOpWriteStateType;


@interface ThingSmartBLELockOpMessageModel : NSObject

@property (nonatomic, assign) ThingUnlockOpType opType;
@property (nonatomic, assign) ThingUnlockOpWriteStateType stateType;
@property (nonatomic, assign) BOOL isAdmin;
@property (nonatomic, assign) int lockUserId;
@property (nonatomic, assign) int firmwareId;

@property (nonatomic, assign) ThingUnlockOpWriteProcessType processType;
@property (nonatomic, assign) ThingUnlockOpErrorCode errorCode;

@property (nonatomic, assign) BOOL deleteResult;

@property (nonatomic, assign) BOOL modifyResult;

@property (nonatomic, strong) NSString *originDataString;

@end

NS_ASSUME_NONNULL_END
