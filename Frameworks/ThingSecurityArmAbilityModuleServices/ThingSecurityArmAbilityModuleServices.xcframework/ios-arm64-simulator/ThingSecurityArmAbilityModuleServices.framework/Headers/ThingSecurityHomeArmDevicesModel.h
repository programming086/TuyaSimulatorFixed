
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityHomeArmDevicesModel : NSObject

@property (nonatomic, assign) NSInteger leavingDeviceNum;
@property (nonatomic, assign) NSInteger crashDeviceNum;
@property (nonatomic, assign) NSInteger stayingDeviceNum;
@property (nonatomic, assign) BOOL hasStayingDevice;
@property (nonatomic, assign) BOOL hasLeavingDevice;
@property (nonatomic, assign) BOOL hasCrashDevice;


@end

NS_ASSUME_NONNULL_END
