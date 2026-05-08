//
//  NSError+BLEError.h
//  ThingSmartBLEKit
//
//  Created by 吴戈 on 2019/8/15.
//

#import <Foundation/Foundation.h>

#define ThingBLEErrorDomain @"com.ble.www"

//蓝牙业务错误码（新版）
typedef NS_ENUM(NSInteger, ThingBLEError) {
    ThingBLEErrorConnectFail   = 101001,//蓝牙连接外设失败
    ThingBLEErrorConnectPerailTimeOut = 101002,//蓝牙连接连接外设阶段超时
    ThingBLEErrorDiscoverServiceFail = 101003,//发现蓝牙服务错误（服务为空或失败）
    ThingBLEErrorDiscoverCharacterFail = 101004,//发现蓝牙特征值错误（未找到匹配的读写特征值或失败）
    ThingBLEErrorNotifyCharacterFail = 101005,//设置蓝牙特征值错误
    ThingBLEErrorQueryDevInfoFail = 101006,//蓝牙查询设备信息失败
    ThingBLEErrorQueryDevInfoTimeOut = 101007,//蓝牙查询设备信息超时
    ThingBLEErrorPairFail = 101008,//蓝牙配对指令失败
    ThingBLEErrorPairTimeOut = 101009,//蓝牙配对指令超时
    ThingBLEErrorConnectTimeOut = 101010,//蓝牙连接总超时
    
    ThingBLEErrorDeviceNotExist = 101011,//设备不存在
    ThingBLEErrorDeviceInfoNotExist = 101012,//没有蓝牙对象
    ThingBLEErrorNotPowerOn = 101013,//蓝牙未打开
    ThingBLEErrorCapabilityDisabled = 101014,//设备不具备蓝牙能力
    ThingBLEErrorScanTimeOut = 101015,//蓝牙扫描超时未扫到目标设备
    ThingBLEErrorDeviceIsNotActive = 101016,//蓝牙连接设备未配网
    ThingBLEErrorUnableConnectDuringOTA = 101017,//蓝牙设备OTA中蓝牙连接行为不合法
    ThingBLEErrorParamInvalid = 101018,//入参不合法
};
/**
 *
 * APP错误码枚举定义
 */
typedef enum {
    
    //用户主动取消配网
    THING_BLE_CONFIG_CANCEL = 100,
    
    //蓝牙连错误败
    THING_BLE_CONNECT_FAILURE = 101,
    
    //发现蓝牙服务错误
    THING_BLE_FIND_SERVICE_FAILURE = 102,
    
    //打开蓝牙通讯通道失败
    THING_BLE_CHARACTER_FAILURE = 103,
    
    //获取设备信息失败
    THING_BLE_QRY_DEV_INFO_FAILURE = 104,
    
    //配对失败
    THING_BLE_PAIR_FAILURE = 105,
    
    //配网超时
    THING_BLE_TIMEOUT = 106,
    
    //发送配网信息失败
    THING_BLE_CONFIG_INFO_FAILURE = 107,
    
    //Token 失效
    THING_BLE_TOKEN_INVALID = 108,
    
    //获取蓝牙加密密钥失败
    THING_BLE_GET_KEY_FAILURE = 109,
    
    //设备不存在
    THING_BLE_DEVICE_NOT_EXIST = 110,
    
    //设备云端注册失败
    THING_BLE_REGISTER_FAILURE = 111,
    
    //设备云端激活失败
    THING_BLE_ACTIVE_FAILTURE = 112,
    
    //设备强绑定
    THING_BLE_ALREADY_BIND = 113,
    
    //蓝牙状态变化
    THING_BLE_CHECK_FAILURE = 114,
    
    //同步设备信息失败
    THING_BLE_SYNC_DEVICE_FAILURE = 115,
    
    //多协议设备已通过其他途径配网
    THING_BLE_ALREADY_CONFIG_FAILURE = 116,
    
    //OTA升级失败
    THING_BLE_OTA_FAILURE = 117,
    
    //OTA升级超时
    THING_BLE_OTA_TIMEOUT = 118,
    
    //WIFI配网传参校验失败
    THING_BLE_WIFI_CONFIG_CHECK_FAILURE = 119,
    
    //发送密钥失败
    THING_BLE_PWD_FAILURE = 120,
    
    //发现蓝牙连接对象失败
    THING_BLE_FIND_PERP_FAILURE = 121,
    
    //没有蓝牙对象
    THING_BLE_DEVICEINFO_NOT_EXIST = 122,
    
    //游客不支持强绑定
    THING_BLE_GUEST_NOT_SUPPORT_STRONG_BIND = 123,
    
    THING_BLE_COMMON_FAILURE = 124,
    
    // Notify 打开失败
    THING_BLE_NOTIFY_OPEN_FAILURE = 125,
    
    //硬件加密设备端错误
    THING_BLE_CHIP_DEVICE_FAILURE = 126,
    
    //硬件加密云端错误
    THING_BLE_CHIP_CLOUD_FAILURE = 127,
    
    //非 cat.1 设备双模配网失败未输入 password
    THING_BLE_DUAL_ACTIVAT_PSD_FAILURE = 128,
    
    //获取 token 失败
    THING_BLE_GET_TOKEN_FAILURE = 129,
    
    //配网传参错误
    THING_BLE_PP_PARAM_ERROR = 130,
    
    //查询设备 Wi-Fi 信息失败
    THING_BLE_PP_QUERY_WIFI_INFO_FAILURE = 131,
    
    //thing.m.dm.device.active 接口报错
    THING_BLE_PP_ACTIVE_FAIL = 132,
    
    //发送设备激活信息失败
    THING_BLE_PP_SEND_ACTIVE_INFO_FAIL = 133,
    
    //设备云端上线失败导致超时
    THING_BLE_DEVICE_MQ_ONLINE_FAIL = 134,
    
    //
    THING_BLE_QRY_DEV_INFO_TIMEOUT = 135,
    
    //配对指令超时
    THING_BLE_PAIR_TIMEOUT = 136,
    
    THING_BLE_PP_QUERY_WIFI_INFO_TIMEOUT = 137,
    
    //发送设备激活信息超时
    THING_BLE_PP_SEND_ACTIVE_INFO_TIMEOUT = 138,
    
    //激活过程获取云端设备信息失败
    THING_BLE_SERVER_GET_DEVINFO_FAILURE = 139,
    
    //获取绑定状态 无权限
    THING_BLE_SERVER_BIND_STATUS_FAILURE = 140,
    
    // thing.m.device.security.config 拉取失败
    THING_BLE_FETCH_SL_API_FAILURE = 141,

    // subcmd 0x0001 发送失败(psk3.0 双模设备配网)
    THING_BLE_CONFIG_INFO_SL_FAILURE = 142,

    // subcmd 0x0002 发送失败(psk3.0 PnP连云激活)
    THING_BLE_PP_CONFIG_WIFI_SL_FAILURE = 143,
    
    // 查询设备周边wifi列表超时
    THING_BLE_QUERY_WIFILIST_TIMEOUT = 144,
    
    // 蓝牙设备未完成配对（未建立起安全通道）
    THING_BLE_DEVICE_NOT_PAIR = 145,
    
    // 该蓝牙设备不支持该功能
    THING_BLE_NOT_SUPPORT_ABILITY = 146,
    
    // 采集设备端日志超时
    THING_BLE_DEVICE_LOG_TIMEOUT = 147,
    
    // 设备联网阶段超时（连路由器阶段超时）
    THING_BLE_DEVICE_CONNECT_ROUTER_TIMEOUT = 148,
    
    // 设备激活阶段超时（连云阶段超时）
    THING_BLE_DEVICE_ACTIVE_TIMEOUT = 149,
    

    THING_BLE_FITTTING_CLOUDFAIL = 160,
    
    THING_BLE_FITTTING_DEVICENODE_FAIL = 161,
    
    //设备响应OTA异常
    THING_BLE_OTA_DEVICE_STATE_FAIL = 200,
    
    //设备文件校验失败
    THING_BLE_OTA_DEVICE_FILE_CHECK_FAIL,
    
    //设备偏移量异常
    THING_BLE_OTA_OFFSET_INDEX_FAIL,
    
    //设备返回大包ack失败
    THING_BLE_OTA_ACK_FAIL,
    
    //固件发送失败
    THING_BLE_OTA_SEND_FAIL,
    
    //设备最终返回升级失败
    THING_BLE_OTA_RESULT_FAIL,
    
    //ota超时
    BLE_OTA_TIME_OUT,
    
    //pid校验失败
    THING_BLE_OTA_PID_ERROR,
    
    //大数据传输失败
    THING_BLE_BIGDATA_RESULT_FAIL,
    
    THING_BLE_PACKAGE_MTP_ERROR = 300,
    
    THING_BLE_PP_SEND_DEV_ACTIVE_INFO_ERROR = 301,
    
    /// 网关不支持 zigbee 双模配网
    THING_BLE_ZIGBEE_GATEWAY_NOT_SUPPORET = 400,
    
    /// 收到 zigbee 子设备设备信息错误
    THING_BLE_RECEIVE_ZIGBEE_INFO_FAIL = 401,
    
    /// 收到 zigbee 子设备指令信息错误
    THING_BLE_RECEIVE_ZIGBEE_COMMAND_FAIL = 402,
    
    /// 收到 zigbee 网关上报的配网错误
    THING_BLE_RECEIVE_ZIGBEE_GATEWAY_ERROR = 403,
    
    /// 收到 zigbee 网关上报的数据解析错误
    THING_BLE_RECEIVE_ZIGBEE_GATEWAY_INFO_ERROR = 404,
    
    /// zigbee 双模配网，下发网关信息失败
    THING_BLE_SEND_ZIGBEE_GATEWAY_INFO_FAIL = 405,
    
    /// zigbee 双模配网，设备回复网关信息无效
    THING_BLE_SEND_ZIGBEE_GATEWAY_INFO_ERROR = 406,
    
    /// 参数错误
    THING_BLE_PARAM_ERROR = 407,
    
    /// 设备正在 OTA 中
    THING_BLE_INSTRUCTION_STATE_OTA_FAIL = 600,
    
    /// 设备正在 OTA 中
    THING_BLE_INSTRUCTION_OFFLINE_FAIL,
    
    THING_BLE_READ_BROADCAST_FAIL = 700,
    
    THING_BLE_FIND_CHARACTERISTIC_FAIL,
    
    //扫到设备，处理上线逻辑，上线超时
    THING_BLE_ONLINE_TIMEOUT,
    
    THING_BLE_DEVICE_RESET,
    
    //短时间内触发了多次连接
    THING_BLE_CONNECT_BUSY = 704,
} ThingBLEErrorCode;


@interface NSError (BLEError)

+ (instancetype)thingsdk_BLEErrorWithErrorCode:(ThingBLEErrorCode)errorCode errorMsg:(NSString *)errorMsg;

+ (NSError *)thingsdk_BLEErrorWithErrorCode:(ThingBLEErrorCode)errorCode;

+ (NSError *)thingsdk_BLEDefaultErrorWithErrorCode:(ThingBLEErrorCode)errorCode;

+ (NSError *)errorWithErrorCode:(NSInteger)errorCode errorMsg:(NSString *)errorMsg;

//扩充旧error中userInfo 字典内容
+ (NSError *)errorUpdateUserInfo:(NSDictionary *)addUserInfo withError:(NSError *)error;
@end
