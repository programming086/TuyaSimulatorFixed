
#import <Foundation/Foundation.h>
#include "imm_p2p_defs.h"

typedef void (^ThingMQTTSender)(BOOL LANmode, NSString *remoteId, NSString *signal);
typedef void (^ThingApmLogSender)(NSString *eventName, NSString *value);
typedef void (^ThingNativeLogSender)(NSInteger level, NSString *module, const char *file, const char *function, NSUInteger line, NSString *message);
typedef void (^ThingFullLinkLogSender)(NSString *type, NSDictionary *attribute, NSDictionary *infos, NSString *trackType, NSString *identifier);
typedef void (^ThingHttpsRequest)(NSString *api, NSString *devId, NSDictionary *postData);

@interface ThingP2PSdk : NSObject
+(int)initLoggerWithApmLogSender:(ThingApmLogSender)apmLogSender
                    nativeLogSender:(ThingNativeLogSender)nativeLogSender
                  fullLinkLogSender:(ThingFullLinkLogSender)fullLinkLogSender;

+(void)deinitLogModule;

/**
    Description get the p2p version.
 */
+(int)getVersion;

/**
    Description init the p2p module.

    @param localId : The local Id
    @param mqttSender :
 */
+(int)initWithLocalId:(NSString*)localId mqttSendBlock:(ThingMQTTSender)mqttSender httpsRequest:(ThingHttpsRequest)httpsRequest;


+(int)initWithLocalId:(NSString*)localId appName:(NSString *)appName appVersion:(NSString*)appVersion mqttSendBlock:(ThingMQTTSender)mqttSender httpsRequest:(ThingHttpsRequest)httpsRequest;
/**
 
 */
+(int)initWithLocalId:(NSString*)localId mqttSendBlock:(ThingMQTTSender)tyMqttSender httpsRequest:(ThingHttpsRequest)tyHttpsRequest sessionStateCB:(imm_p2p_rtc_session_state_cb_t)sessionStateCB ;


+(int)initWithLocalId:(NSString*)localId appName:(NSString *)appName appVersion:(NSString*)appVersion mqttSendBlock:(ThingMQTTSender)tyMqttSender httpsRequest:(ThingHttpsRequest)tyHttpsRequest sessionStateCB:(imm_p2p_rtc_session_state_cb_t)sessionStateCB ;

/**
    Description deinit the p2p module.
 */
+(int)deInit;

/**
    Description : connect to the device such as camera.
    @param remoteId : the did
    @param token : token for p2p connect
    @param traceId : traceId for p2p connect
    @param lanMode :    0  -- not lan mode
                        1  -- lan mode
    @param timeout : time out for connect operation.
 
    @return retcode >= 0: handle, retcode < 0: error code
 */
+(int)connectWithRemoteId:(NSString*)remoteId token:(NSString*)token traceId:(NSString*)traceId lanMode:(int)lanMode timeout:(int)timeout;

/**
    connect v3
        preConnectEnable  preconnect enable or not
 */

+(int)connectWithRemoteId:(NSString *)remoteId devId:(NSString *)devId skill:(NSString *)skill token:(NSString*)token traceId:(NSString*)traceId lanMode:(int)lanMode timeout:(int)timeout preConnectEnable:(int)preConnectEnable ;

/**
    Description : break connect while connecting .
    @param traceId : traceId for p2p connect
    
 */
+(int)connectBreakWithTraceId:(NSString*)traceId ;

/**
    Description : disconnect with the device
    @param handle  : handle .The return value of connect operation.
 */
+(int)disConnectWithHandle:(int)handle ;


+(int)disConnectForcedWithHandle:(int)handle ;

/**
    closs all sessions for app
 */
+(int)closeAllSessions ;


/**
    Description     : read data from p2p channel.
    @param handle   : handle .The return value of connect operation.
    @param channel  : the p2p channel
    @param buffer   : buffer pointer
    @param bufferLen : len of buffer
    @param timeOut  : timeout in ms
    @return
            < 0 error
            >= 0 send data length
 */
+(int)recvWithHandle:(int)handle channel:(int)channel buffer:(unsigned char*)buffer bufferLen:(int)bufferLen timeOut:(int)timeOut ;

/**
    Description     : send data from p2p channel.
    @param handle   : handle .The return value of connect operation.
    @param channel  : the p2p channel
    @param buffer   : buffer pointer
    @param bufferLen : len of buffer
    @param timeOut  : timeout in ms
    @return
            < 0 error
            >= 0 send data length
*/
+(int)sendWithHandle:(int)handle channel:(int)channel buffer:(unsigned char*)buffer bufferLen:(int)bufferLen timeOut:(int)timeOut ;
/**
 Description     : send data from p2p channel.
 @param handle   : handle .The return value of connect operation.
 @param channel  : the p2p channel
 @param requestid   :requestid
 @param username :  username
 @param password  : password
 @param timeOut  : timeout in ms
 @return
            < 0 error
            >= 0 send data length
 */
+(int)sendAuthorizationInfoWithHandle:(int)handle channel:(int)channel requestId:(int)requestid username:(NSString *)username password:(NSString*)password timeOut:(int)timeOut ;

/**
    Description     : set the p2p signaling msg
    @param  msg     : p2p signaling msg
    @param  msgLen  : msg length
*/
+(int)setSignalingWithMsg:(const char*)msg msgLen:(int)msgLen ;

/**
    Description     : set the p2p signaling msg
    @param  remoteId : remoteId
    @param  msg     : p2p signaling msg
    @param  msgLen  : msg length
*/
+(int)setSignalingSendResultWithRemoteId:(const char*)remoteId msg:(const char*)msg msgLen:(int)msgLen code:(int)code;
/**
    Description     : ?
    @param remoteId   : the did .
 */
+(int)setRemoteOnlineWithHandle:(const char*)remoteId ;

/**
    Description     : check the p2p active or not
    @param handle   : handle .The return value of connect operation.
 */
+(int)activeCheckWithHandle:(int)handle ;

/**
 Description     : check the p2p active or not
 @param api :
 @param code :
 @param content :
 */
+(int)setHttpsResponseWithApi:(const char *)api code:(int)code content:(const char *)content;


+(char*)getSessionList ;

+(void)freeSessionListWithSessionList:(char*)session_list ;

+(int)startPreConnectWithRemoteId:(char*)remote_id dev_id:(char*)dev_id ;

+(int)closePreConnectWithRemoteId:(char*)remote_id reason:(int)reason ;

/**
 Description: upload the log through p2p interface online.
 */
+(int)uploadLogWithLevel:(imm_p2p_rtc_log_level_e)level log:(NSString*)log ;

@end

