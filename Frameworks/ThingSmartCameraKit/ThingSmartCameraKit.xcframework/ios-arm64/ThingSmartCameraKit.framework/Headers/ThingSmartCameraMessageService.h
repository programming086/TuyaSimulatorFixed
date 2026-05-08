
#import <UIKit/UIKit.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartCameraMessageService : ThingSmartRequest

/// get video fragments
/// - Parameters:
///   - devId: device id
///   - prefixTime: prefix time
///   - success: success callback
///   - failure: failure callback
- (void)getVideoMessageFragments:(NSString *)devId
                      prefixTime:(NSTimeInterval)prefixTime
                         success:(ThingSuccessID)success
                         failure:(ThingFailureError)failure;

/// get video message secret
/// - Parameters:
///   - devId: device id
///   - success: success callback
///   - failure: failure callback
- (void)requestVideoMessageSecretWithDeviceId:(NSString *)devId
                                      success:(ThingSuccessString)success
                                      failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
