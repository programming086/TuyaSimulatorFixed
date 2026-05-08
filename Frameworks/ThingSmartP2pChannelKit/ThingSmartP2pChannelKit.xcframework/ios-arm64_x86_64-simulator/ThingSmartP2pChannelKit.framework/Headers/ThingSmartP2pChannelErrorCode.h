
#import <Foundation/Foundation.h>

//error code <-1000 ~ -1299>
typedef enum {
    ThingSmartP2pChannelErrorCodeRequestInvalidParams = -1000,
    ThingSmartP2pChannelErrorCodeRequestFailed = -1001,
    ThingSmartP2pChannelErrorCodeRequestInvalidResponse = -1002,
    ThingSmartP2pChannelErrorCodeInvalidParams = -1010,
    ThingSmartP2pChannelErrorCodeInvalidResponse = -1011,
    ThingSmartP2pChannelErrorCodeNonexistentDevice = -1020,
    ThingSmartP2pChannelErrorCodeUnsupportP2PType = -1021,
    ThingSmartP2pChannelErrorCodeUnconnected = -1030,
    ThingSmartP2pChannelErrorCodeOnConnecting = -1031,
    ThingSmartP2pChannelErrorCodeOnQuerying = -1040,
    ThingSmartP2pChannelErrorCodeQueryFailed = -1041,
    ThingSmartP2pChannelErrorCodeOnUploading = -1050,
    ThingSmartP2pChannelErrorCodeUploadFailed = -1051,
    ThingSmartP2pChannelErrorCodeDownloadFailed = -1060,
    ThingSmartP2pChannelErrorCodeAppendDownloadFailed = -1061,
    ThingSmartP2pChannelErrorCodeInitFirstly = -1150
} ThingSmartP2pChannelErrorCode;
