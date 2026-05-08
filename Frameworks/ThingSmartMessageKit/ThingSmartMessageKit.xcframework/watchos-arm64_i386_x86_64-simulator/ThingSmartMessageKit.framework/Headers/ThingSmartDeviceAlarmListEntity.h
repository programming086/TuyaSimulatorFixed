
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDeviceAlarmItemEntity : NSObject
/// The device id
@property (nonatomic,strong) NSString *deviceId;
/// The device name
@property (nonatomic,strong) NSString *name;
/// The device icon url
@property (nonatomic,strong) NSString *iconUrl;
/// Number of selected alarm service
@property (nonatomic,assign) NSInteger selectedNum;
/// Total number of alarm service
@property (nonatomic,assign) NSInteger totalNum;
@end

@interface ThingSmartDeviceAlarmListEntity : NSObject
/// Flag indicating whether there are more devices to be loaded
@property (nonatomic, assign) BOOL hasMore;
/// Array of device entities
@property (nonatomic, copy) NSArray <ThingSmartDeviceAlarmItemEntity *>*devices;
@end

NS_ASSUME_NONNULL_END
