
#ifndef ThingSIGMeshErrorCode_h
#define ThingSIGMeshErrorCode_h

typedef enum : NSUInteger {
    ThingMeshHandleGroupTimeout = 1, // 超时
    ThingMeshHandleGroupEmpty, // 空
    ThingMeshHandleGroupFull, //
    ThingMeshHandleGroupException,
} ThingBleMeshHandleGroupError;

//The error code of mesh
typedef NS_ENUM (NSInteger, ThingSIGMeshErrorCode){
    ThingSIGMeshErrorCode_ParamIllegal = 204700,//illegal input param
    ThingSIGMeshErrorCode_InvalidResponse = 204701,//the response of device is invalid
    ThingSIGMeshErrorCode_ProxyNodeUnConnect = 204702,//the proxy node is not connect
    ThingSIGMeshErrorCode_TimeOut = 204703,//the response is time out
};

#endif /* ThingSIGMeshErrorCode_h */
