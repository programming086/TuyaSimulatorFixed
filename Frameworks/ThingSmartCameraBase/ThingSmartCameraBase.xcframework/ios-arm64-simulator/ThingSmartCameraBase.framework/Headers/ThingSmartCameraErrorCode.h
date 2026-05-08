
#import <Foundation/Foundation.h>


FOUNDATION_EXTERN const int ThingSmartCameraErrorCodeNoError;


//universal error code
typedef enum {
    ThingSmartCameraErrorCodeDeviceFlowLimit = -115,
    ThingSmartCameraErrorCodeRequestInvalidParams = -1300,
    ThingSmartCameraErrorCodeRequestFailed = -1301,
    ThingSmartCameraErrorCodeRequestInvalidResponse = -1302,
    ThingSmartCameraErrorCodeRequestResponseLostRequriedResult = -1303,
    ThingSmartCameraErrorCodeInvalidParams = -1310,
    ThingSmartCameraErrorCodeInvalidResponse = -1311,
    ThingSmartCameraErrorCodeProtocolNoImpl = -1320,
    ThingSmartCameraErrorCodeMethodHooked = -1321,
    ThingSmartCameraErrorCodeFileInitFailed = -1330,
    ThingSmartCameraErrorCodeWriteFileFailed = -1331,
    ThingSmartCameraErrorCodeImageTransformedFailed = -1332,
    ThingSmartCameraErrorCodeSavePhotoToAlbumFailed = -1340,
    ThingSmartCameraErrorCodeNonexistentDevice = -1350,
    ThingSmartCameraErrorCodeCameraUninitialized = -1360,
    ThingSmartCameraErrorCodeCameraInitFailed = -1361,
    ThingSmartCameraErrorCodeCameraUnconnected = -1362,
    ThingSmartCameraErrorCodeNoTalkParams = -1363,
    ThingSmartCameraErrorCodeCameraViewBindFailed = -1364,
    ThingSmartCameraErrorCodeNVRInitFailed = -1370,
    ThingSmartCameraErrorCodeNVRVendorDevice = -1371,
    ThingSmartCameraErrorCodeNVRUnsupportNewConnection = -1372,
    ThingSmartCameraErrorCodeNVRSubdeviceUnpaired = -1373,
    ThingSmartCameraErrorCodeNVRSubdeviceNodeIdInvalid = -1374,
    ThingSmartCameraErrorCodeNVRSubdeviceUnbound = -1375,
    ThingSmartCameraErrorCodeNVRSubdeviceDisconnectFailed = -1376,
    ThingSmartCameraErrorCodeNVRSkillUnfound = -1377,
    ThingSmartCameraErrorCodeLocalDeviceOffline = -1390,
    ThingSmartCameraErrorCodeLocalDeviceInitFailed = -1391,
    ThingSmartCameraErrorCodeLocalDeviceConnectFailed = -1392,
    ThingSmartCameraErrorCodeUnsupportedDP = -1400,
    ThingSmartCameraErrorCodeDPParamsInvalid = -1401,
    ThingSmartCameraErrorCodeDPQueryFailed = -1402,
    ThingSmartCameraErrorCodeUnsupportedPTZ = -1430,
    ThingSmartCameraErrorCodeEditDisabledInCruiseMode = -1431,
    ThingSmartCameraErrorCodeSwitchCruisesFailed = -1432,
    ThingSmartCameraErrorCodeHadStoppedPreview = -1440,
    ThingSmartCameraErrorCodeUnsupportedAttachType = -1500,
    ThingSmartCameraErrorCodeDownloadImageFailed = -1530,
    ThingSmartCameraErrorCodeUnknownException = -1999,
    ThingSmartCameraErrorCodeDeprecatedAPI = -9999,
    ThingSmartCameraErrorCodeFlowLimit = -60000
}ThingSmartCameraErrorCode;


//cloud storage error code
typedef enum {
    ThingSmartCameraCloudStorageErrorCodeConfigDataTagInvalid = -2000,
    ThingSmartCameraCloudStorageErrorCodeInvalidAuthData = -2001,
    ThingSmartCameraCloudStorageErrorCodeURLParseFailed = -2002,
    ThingSmartCameraCloudStorageErrorCodeNoFrameInfo = -2003,
    ThingSmartCameraCloudStorageUnsupported = -2030
}ThingSmartCameraCloudStorageErrorCode;


//door bell error code
typedef enum {
    ThingDoorBellError_NoError         = 0,
    ThingDoorBellError_CallFailed      = -2300,
    ThingDoorBellError_AnsweredByOther = -2301,
    ThingDoorBellError_DidCanceled     = -2302,
    ThingDoorBellError_TimeOut         = -2303,
    ThingDoorBellError_AnsweredBySelf  = -2304,
    ThingDoorBellError_NotAnswered     = -2305,
    ThingDoorBellError_NotSupport      = -2306
}ThingDoorBellError;

typedef enum {
    ThingVideoMessageError_NoError            = 0,
    ThingVideoMessageError_InvalidParams      = -2050,
    ThingVideoMessageError_RequestError      = -2051,
}ThingVideoMessageError;



@protocol ThingSmartCameraExtErrorCodeInfo <NSObject>

@property (nonatomic, assign, readonly) NSInteger code;

@end
