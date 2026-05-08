//
//  tuya_p2p_file_trans_defines.h
//  TuyaP2PFileTransSDK
//
//  Created by Foster on 2022/2/15.
//

#ifndef tuya_p2p_file_trans_defines_h
#define tuya_p2p_file_trans_defines_h

#define TuyaP2pFileTransSDK_version "1.0.1-rc.1"

#define UNINITIALIZED -1

typedef enum{
    kTuyaEvent_Download_Start = 0,                                        // 下载业务开始
    kTuyaEvent_Download_Cancel = 1,                                       // 下载业务取消
    kTuyaEvent_Upload_Start = 2,                                          // 上传业务开始
    kTuyaEvent_Upload_Cancel = 3,                                        // 上传业务取消
}TuyaEventCode;

typedef enum{
    kTuyaErrCode_NoErr                  =  0,       // 错误码 无错
    kTuyaErrCode_FragmentEnd            =  1,       // 错误码 片段播放结束通知
    kTuyaErrCode_Err                    =  -1,      // 错误码 通用错误
    kTuyaErrCode_ModuleNotInitialized   = -10000,   // 错误码 未初始化
    kTuyaErrCode_NotConnected           = -10001,   // 错误码 设备未连接
    kTuyaErrCode_SessionInvalid         = -10002,   // 错误码 无效的session
    kTuyaErrCode_TimeOut                = -10003,   // 错误码 超时
    kTuyaErrCode_ConnectionCancelled    = -10004,   // 错误码 连接被取消

    kTuyaErrCode_DeviceNotOnline        = -10006,   // 错误码 设备不在线
    kTuyaErrCode_CancelByUser           = -10007,   // 错误码 用户取消操作
    kTuyaErrCode_DeviceError            = -10008,   // 错误码 设备通用错误
    kTuyaErrCode_InvalidCommand         = -20001,   // 错误码 无效的命令
    kTuyaErrCode_ParamsInvalid          = -20002,   // 错误码 无效的参数
    kTuyaErrCode_DataInvalid            = -20003,   // 错误码 无效的数据
    kTuyaErrCode_Interrupted            = -20004,   // 错误码 操作被中断
    kTuyaErrCode_OperationNotAllowed    = -20005,   // 错误码 操作不允许
    kTuyaErrCode_VersionNotSupported    = -20006,   // 错误码 当前app版本不支持该协议[需要升级app]
    kTuyaErrCode_DownloadFailed         = -30001,   // 错误码 下载文件失败
    kTuyaErrCode_ResponseReturnErr      = -30060,   // 错误码 设备端Response 返回错误
    kTuyaErrCode_ErrOccurDataTransport  = -30061,   // 错误码 数据传输过程中出现错误
    kTuyaErrCode_FileNotExists          = -30062,   // 错误码 文件不存在
    kTuyaErrCode_CreateFileFailed       = -30063,   // 错误码 创建本地文件失败，请检查路径是否存在。
    kTuyaErrCode_TooManyFilesDownload   = -30064,   // 错误码 下载的文件太多或者为0
    kTuyaErrCode_DeleteFilesFailed      = -30065,   // 错误码 删除文件失败
    
    kTuyaErrCode_FileNameTooLong        = -30100,   // 错误码 文件名过长
}TuyaErrCode;

typedef enum{
    kTuyaSessionStatus_Connected        =  0,       // 链接成功
    kTuyaSessionStatus_ConnectTimeout   = -3,       // 链接超时
    kTuyaSessionStatus_ClosedRemote     = -12,      // 链接断开
    kTuyaSessionStatus_ClosedTimeOut    = -13,      // 链接超时
    kTuyaSessionStatus_ClosedCalled     = -14,      // 链接关闭
}TuyaSessionStatus;

#endif /* tuya_p2p_file_trans_defines_h */
