
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartNBDeviceBindRequestData, ThingSmartNBDeviceBindResponseData;

@interface ThingSmartNBDeviceActivator : NSObject

/// Bind NB device to the cloud using parameters.
/// - Parameters:
///   - param: request parameter
///   - success: success callback
///   - failure: failure callback
- (void)requestNBDeviceBindWithParam:(ThingSmartNBDeviceBindRequestData *)param success:(void(^)(ThingSmartNBDeviceBindResponseData *result))success failure:(ThingFailureError)failure;

@end

#pragma mark -
@interface ThingSmartNBDeviceBindRequestData : NSObject

@property (nonatomic, copy) NSString *hid; //token
@property (nonatomic, copy) NSString *timeZone;
@property (nonatomic, assign) long long gid;

@end

#pragma mark -
@interface ThingSmartNBDeviceBindResponseData : NSObject

@property (nonatomic, strong) NSString *errorCode;
@property (nonatomic, assign) BOOL relyCloud;
@property (nonatomic, strong) NSString *iconUrl;
@property (nonatomic, strong) NSString *errorMsg;
@property (nonatomic, strong) NSString *devId;
@property (nonatomic, assign) BOOL changeSpace;
@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *icon;

@property (nonatomic, strong, nullable) NSDictionary *raw;

@end

NS_ASSUME_NONNULL_END
