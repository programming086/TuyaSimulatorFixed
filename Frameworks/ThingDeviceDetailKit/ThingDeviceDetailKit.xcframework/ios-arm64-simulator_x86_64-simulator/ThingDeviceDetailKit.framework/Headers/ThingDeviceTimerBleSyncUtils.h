
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// ===========
/// Bluetooth Protocol Implementation
/// ===========
///
/// Bluetooth channel business identifier [Bluetooth Timing Business]
/// Bluetooth timing subcmd, 2 bytes
#define ThingDeviceTimerBleSyncSubCmdLength 2
#define ThingDeviceTimerBleSyncSubCmd 0x0000

/// Maximum of 30 timing tasks
#define ThingDeviceTimerBleSyncMaxTaskSize 30

/// Timer type
typedef NS_ENUM(uint8_t, ThingDeviceTimerBleSyncTimerType) {
    /// Normal timer
    ThingDeviceTimerBleSyncTimerType_Normal = 0x01,
};

/// Operation code
typedef NS_ENUM(uint8_t, ThingDeviceTimerBleSyncOpCode) {
    /// Set timer
    ThingDeviceTimerBleSyncOPCode_Set = 0x01,
    /// Delete timer
    ThingDeviceTimerBleSyncOPCode_Remove = 0x02,
    /// Read timer
    ThingDeviceTimerBleSyncOPCode_Read = 0x03,
};

/// Operation result
typedef NS_ENUM(uint8_t, ThingDeviceTimerBleSyncResultCode) {
    /// Operation successful
    ThingDeviceTimerBleSyncResultCodeSuccess = 0x00,
    /// Operation failed
    ThingDeviceTimerBleSyncResultCodeFail_Unknow = 0x01
};


/// ============
/// Read Timer Tasks
/// ============

/**
 Header size for reading timer tasks  (3 bytes)
 ret_code | count | length
 */
#define ThingDeviceTimerBleSyncReadingDataHeaderSize 3
/**
 Size of a single timer task data read (8 bytes)
 timer_id | crc32
 */
#define ThingDeviceTimerBleSyncReadingDataBodyLength 8

/// Header for reading timer tasks
typedef struct ThingDeviceTimerBleSyncReadingHeader {
    ThingDeviceTimerBleSyncResultCode ret_code;           // Operation result
    uint8_t count;                                        // Number of return values
    uint8_t length;                                       // Data length (length+id1+crc+id2+crc+...) including itself
} ThingDeviceTimerBleSyncReadingHeader;

/// Body for reading timer tasks
@interface ThingDeviceTimerBleSyncReadingBody: NSObject
@property (nonatomic, assign) uint32_t timer_id; // Timer ID
@property (nonatomic, assign) uint32_t crc32;
@end

/// Reading Timer Tasks
@interface ThingDeviceTimerBleSyncReadingTask : NSObject
@property (nonatomic, assign) ThingDeviceTimerBleSyncReadingHeader header;
@property (nullable, nonatomic, copy) NSArray<ThingDeviceTimerBleSyncReadingBody *> *taskList;

/// Initialize with data returned from Bluetooth
/// @param data Data returned from Bluetooth
/// @return Returns nil if the format has issues
- (nullable instancetype)initWithBleData:(NSData *)data;
@end


/// ============
/// Setting Timer Tasks
/// ============

/**
 Data header size for setting timer (bytes)
 ThingDeviceTimerBleSyncOpCode - ThingDeviceTimerBleSyncTimerType - Data length (2 bytes)
 */
#define ThingDeviceTimerBleSyncSettingDataHeaderLength 4

/// DP Type
typedef NS_ENUM(uint8_t, ThingDeviceTimerBleDPType) {
    ThingDeviceTimerBleDPType_RAW = 0,
    ThingDeviceTimerBleDPType_BOOL = 1,
    ThingDeviceTimerBleDPType_VALUE = 2,
    ThingDeviceTimerBleDPType_STRING = 3,
    ThingDeviceTimerBleDPType_ENUM = 4,
    ThingDeviceTimerBleDPType_BITMAP = 5,
};

/// Header for setting timer tasks (10 bytes)
typedef struct ThingDeviceTimerBleSyncSettingHeader {
    uint8_t year;       // (last two digits)
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t loops;
    uint32_t timer_id;
} ThingDeviceTimerBleSyncSettingHeader;

@interface ThingDeviceTimerBleSyncSettingTask : NSObject

@property (nonatomic, assign) ThingDeviceTimerBleSyncSettingHeader header;

/// If YES, calculate crc32 for the range header{hour, minute, loops, timer_id}, dpData
/// Otherwise, header{year, month, day, hour, minute, loops, timer_id}, dpData
///
/// Default is NO
@property (nonatomic) BOOL crc32IgnoreDate;

/// Big-endian sequence
///
/// Generated after `makeData`
@property (nonatomic, assign) uint32_t crc32;

/// Initialize setting timer task
/// @param header Header
/// @param dps Timer DP
/// @param schemaDict DP schema
- (instancetype)initWithHeader:(ThingDeviceTimerBleSyncSettingHeader)header dps:(NSDictionary *)dps schemaDict:(NSDictionary *)schemaDict;

// Convenience method
- (instancetype)initWithTimerId:(uint32_t)timerId loops:(NSString *)loops dps:(NSDictionary *)dps dateComponents:(NSDateComponents *)dateComponents schemaDict:(NSDictionary *)schemaDict;

/// Returns the Data to be sent to the Bluetooth device
///
/// @note Only calling this method will calculate `crc32`
- (NSData *)makeData;

@end

@interface ThingDeviceTimerBleSyncUtils : NSObject

/// Convert binary string to uint32_t
+ (uint32_t)convertBinaryStringToUint32:(NSString *)binaryString;

@end

NS_ASSUME_NONNULL_END
