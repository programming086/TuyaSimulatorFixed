//
//  tuya_p2p_file_trans_callback.h
//  TuyaP2PFileTransSDK
//
//  Created by Foster on 2022/2/15.
//

#ifndef tuya_p2p_file_trans_callback_h
#define tuya_p2p_file_trans_callback_h
#include <stdint.h>
#include "tuya_p2p_file_trans_defines.h"

#ifdef __cplusplus
extern "C"{
#endif
    typedef void (*fnSessionStatusChanged)(void *obj, int nSessionId, int nSessionStatus);

    typedef void (*fnMqttSend)(bool LANmode, char *remote_id, char *signaling, uint32_t len);

    typedef int (*fnHttpsRequest)(char *api, char *devId, char *content, uint32_t content_len);

    typedef void (*fnGetiOSSystemVersion)(char *szVersion, int maxVersionLength);

    typedef void (*fnAudioPlayBackParameterChanged)(void *obj,char *did, int nSessionId,long dIdentityCode,int sampleRate,int nchannel);

    typedef void (*fnDownloadPosCallback)(int sessionId, int requestId, int nErrCode, int nTaskId, int nPos, void *obj, void *data);

    typedef void (*fnFileDownloadProgressCallback)(int sessionId, int requestId, int nErrCode, int nTaskId, int nPos, char *fileName, void *obj, void *data);

    typedef void (*fnFileDownloadFinshedOperationCallBack)(int nSessionId, int nRequestId,char *filename,int index, int nErrCode, void *obj, void *data);

#ifdef __cplusplus
}
#endif

#endif /* tuya_p2p_file_trans_callback_h */
