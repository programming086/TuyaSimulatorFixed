#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#include "ThingCameraDefines.h"

@protocol ThingNVRDelegate;

@interface ThingNVR : NSObject

@property (nonatomic, strong) NSString *nvr_device_id_;
@property (nonatomic, assign) int      session_;
@property (nonatomic,   weak) id<ThingNVRDelegate> delegate_;
- (instancetype)init NS_UNAVAILABLE;

/**
Description NVR  initializer.
@param nvrDid nvrdid
@return ThingNVR object.
 */
- (instancetype)initWithNvrId:(NSString*)nvrDid NS_DESIGNATED_INITIALIZER;

/**
Description P2P 3.0 connect(Normal mode, exchange signal through MQTT 302)
 
@param token thing p2p token.
@param skills thing p2p skills for pre connect. supported while  p2p version >= 0xF4030400
@param traceId p2p fulllink log traceId.
@return retcode >= 0: session id, retcode < 0: error code
*/
- (int)connectWithToken:(NSString *)token skills:(NSString *)skills traceId:(NSString *)traceId;

/**
Descriotion  P2P 3.0 disconnect
 */
- (void)disconnect;

/**
Descriotion Nvr device authorization
@param userName userName.
@param password  password
@param callback  result callback
@return error code
*/
- (int)sendAuthorizationWithUsername:(NSString *)userName  pwd:(NSString *)password onResponse:(void (^)(const char* result, int errCode))onResponse;

/**
Description bind subdevices to station
 
@param jsonInfo jsonInfo.
@return error code
*/
- (int)bindSubDevicesInfoWithJsonInfo:(NSString *)jsonInfo onResponse:(void (^)(const char* result, int errCode))onResponse;
@end

@protocol ThingNVRDelegate<NSObject>
@optional
/**
 Description session Session status callback immediately when it changes.
 
 @param device Which camera.
 @param status Current session status.
 */
- (void)device:(ThingNVR *)device didSessionStatusChangedWithStatus:(NSInteger)status;

@end
