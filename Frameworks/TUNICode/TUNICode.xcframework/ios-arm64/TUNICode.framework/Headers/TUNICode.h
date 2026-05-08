

@import Foundation;    

/**
通用插件统一code模块
@version: 1.0.0
@platform: all
*/
    

typedef NS_ENUM(NSInteger, TUNIPluginCode)
{
    
    /// success
    TUNIPluginCode_SUCCESS = 0,

    /// The context is not registered
    TUNIPluginCode_CONTEXT_IS_NOT_REGISTERED = 1,

    /// can‘t find module
    TUNIPluginCode_UNDEFINED_MODULE = 2,

    /// can‘t find methodName
    TUNIPluginCode_UNDEFINED_METHOD = 3,

    /// can't transfer model
    TUNIPluginCode_UNDEFINED_MODEL = 4,

    /// The necessary parameters are missing
    TUNIPluginCode_LACK_OF_PARAM = 5,

    /// The parameter format is incorrect
    TUNIPluginCode_INCORRECT_PARAM = 6,

    /// API Internal processing failed
    TUNIPluginCode_INTERNAL_ERROR = 7,

    /// Method Unauthorized access
    TUNIPluginCode_METHOD_NO_PERMISSION = 8,

    /// Method UnKnown error
    TUNIPluginCode_METHOD_UNKNOWN = 9,

    /// Activity is invalid
    TUNIPluginCode_ACTIVITY_IS_INVALID = 9001,

    /// Context is invalid
    TUNIPluginCode_CONTEXT_IS_INVALID = 9002,

    /// can‘t find scope permission
    TUNIPluginCode_UNDEFINED_SCOPE_PERMISSION_ERROR = 9003,

    /// app no permission
    TUNIPluginCode_APP_NO_PERMISSION_ERROR = 9004,

    /// can‘t find service
    TUNIPluginCode_UNDEFINED_SERVICE_ERROR = 9005,

    /// network request error
    TUNIPluginCode_NETWORK_REQUEST_ERROR = 9006,

    /// file path is illegal
    TUNIPluginCode_FILE_PATH_IS_ILLEGAL = 9007,

    /// -------------- BaseKit 10000 Start ----------------
    TUNIPluginCode_BASEKIT_START_MARKER = 10000,

    /// Sensor initialization fail
    TUNIPluginCode_BASEKIT_SENSORS_INIT_ERROR = 10001,

    /// Image picker error
    TUNIPluginCode_BASEKIT_IMAGE_PICKER_ERROR = 10002,

    /// network request error
    TUNIPluginCode_BASEKIT_NETWORK_REQUEST_ERROR = 10003,

    /// audio play error
    TUNIPluginCode_BASEKIT_AUDIO_PLAY_ERROR = 10004,

    /// audio seek error
    TUNIPluginCode_BASEKIT_AUDIO_SEEK_ERROR = 10005,

    /// audio stop error
    TUNIPluginCode_BASEKIT_AUDIO_STOP_ERROR = 10006,

    /// download file error
    TUNIPluginCode_BASEKIT_DOWNLOAD_FILE_ERROR = 10007,

    /// upload file error
    TUNIPluginCode_BASEKIT_UPLOAD_FILE_ERROR = 10008,

    /// scan code error
    TUNIPluginCode_BASEKIT_SCAN_CODE_ERROR = 10009,

    /// storage json syntax error
    TUNIPluginCode_BASEKIT_STORAGE_ERROR = 10010,

    /// file not exist
    TUNIPluginCode_BASEKIT_FILE_NOT_EXIST = 10011,

    /// read file encoding invalid
    TUNIPluginCode_BASEKIT_READ_FILE_ENCODING_INVALID = 10012,

    /// read file error
    TUNIPluginCode_BASEKIT_READ_FILE_ERROR = 10013,

    /// can not use this route url in the APP
    TUNIPluginCode_BASEKIT_ROUTE_CAN_NOT_USED = 10014,

    /// get file stats error
    TUNIPluginCode_BASEKIT_GET_FILE_STATS_ERROR = 10015,

    /// create dir error
    TUNIPluginCode_BASEKIT_MKDIR_ERROR = 10016,

    /// delete dir error
    TUNIPluginCode_BASEKIT_RMDIR_ERROR = 10017,

    /// remove saved file error
    TUNIPluginCode_BASEKIT_REMOVE_SAVED_FILE_ERROR = 10018,

    /// write file error
    TUNIPluginCode_BASEKIT_WRITE_FILE_ERROR = 10019,

    /// sdcard not mounted error
    TUNIPluginCode_BASEKIT_SDCARD_NO_MOUNTED_ERROR = 10020,

    /// SSID nil error
    TUNIPluginCode_BASEKIT_SSID_NIL_ERROR = 10021,

    /// media info parse error
    TUNIPluginCode_BASEKIT_MEDIA_INFO_PARSE_ERROR = 10022,

    /// nvalid params when parse media info
    TUNIPluginCode_BASEKIT_MEDIA_INFO_PARAMS_INVALID = 10023,

    /// invalid params when save video
    TUNIPluginCode_BASEKIT_SAVE_VIDEO_PARAMS_INVALID = 10024,

    /// save video error
    TUNIPluginCode_BASEKIT_SAVE_VIDEO_ERROR = 10025,

    /// get file info error
    TUNIPluginCode_BASEKIT_GET_FILE_INFO_ERROR = 10026,

    /// mqtt connect error
    TUNIPluginCode_BASEKIT_MQTT_CONNECT_ERROR = 10027,

    /// mqtt subscribe error
    TUNIPluginCode_BASEKIT_MQTT_SUBSCRIBE_ERROR = 10028,

    /// mqtt unsubscribe error
    TUNIPluginCode_BASEKIT_MQTT_UNSUBSCRIBE_ERROR = 10029,

    /// mqtt publish error
    TUNIPluginCode_BASEKIT_MQTT_PUBLISH_ERROR = 10030,

    /// fail when convert video to gif
    TUNIPluginCode_BASEKIT_VIDEO_TO_GIF_CONVERT_ERROR = 10031,

    /// invalid video source
    TUNIPluginCode_BASEKIT_VIDEO_SOURCE_INVALID = 10032,

    /// fail when convert gif to images
    TUNIPluginCode_BASEKIT_GIF_TO_IMAGES_CONVERT_ERROR = 10033,

    /// invalid gif source
    TUNIPluginCode_BASEKIT_GIF_SOURCE_INVALID = 10034,

    /// -------------- DeviceKit 20000 Start ----------------
    TUNIPluginCode_DEVICEKIT_START_MARKER = 20000,

    /// DeviceId is invalid
    TUNIPluginCode_DEVICEKIT_DEVICE_ID_INVALID = 20001,

    /// GroupId is invalid
    TUNIPluginCode_DEVICEKIT_GROUP_ID_INVALID = 20002,

    /// MeshId is invalid
    TUNIPluginCode_DEVICEKIT_MESH_ID_INVALID = 20003,

    /// ProductId is invalid
    TUNIPluginCode_DEVICEKIT_PRODUCT_ID_INVALID = 20004,

    /// DeviceId and GroupId is invalid
    TUNIPluginCode_DEVICEKIT_DEVICE_ID_AND_GROUP_ID_INVALID = 20005,

    /// Device model and Group model is null
    TUNIPluginCode_DEVICEKIT_DEVICE_MODEL_AND_GROUP_MODEL_NULL = 20006,

    /// Device network error
    TUNIPluginCode_DEVICEKIT_DEVICE_NETWORK_ERROR = 20007,

    /// Cannot find either deviceId or uiId
    TUNIPluginCode_DEVICEKIT_MISSING_DEVICEID_AND_UIID = 20008,

    /// The URL is invalid
    TUNIPluginCode_DEVICEKIT_URL_INVALID = 20009,

    /// Cannot find service
    TUNIPluginCode_DEVICEKIT_SERVICE_NULL = 20021,

    /// Device model is null
    TUNIPluginCode_DEVICEKIT_DEVICE_MODEL_NULL = 20022,

    /// Gateway model is null
    TUNIPluginCode_DEVICEKIT_GATEWAY_MODEL_NULL = 20023,

    /// Cache model is null
    TUNIPluginCode_DEVICEKIT_CACHE_MODEL_NULL = 20024,

    /// Device is offline
    TUNIPluginCode_DEVICEKIT_DEVICE_OFFLINE = 20025,

    /// Remove device error
    TUNIPluginCode_DEVICEKIT_REMOVE_DEVICE_ERROR = 20026,

    /// Get subDeviceList from cloud error
    TUNIPluginCode_DEVICEKIT_GET_SUBDEVICELIST_ERROR = 20027,

    /// Publish Dps error
    TUNIPluginCode_DEVICEKIT_PUBLISH_DPS_ERROR = 20028,

    /// Publish Dps with type error
    TUNIPluginCode_DEVICEKIT_PUBLISH_DPS_WITH_TYPE_ERROR = 20029,

    /// Publish Mqtt message error
    TUNIPluginCode_DEVICEKIT_PUBLISH_MQTT_ERROR = 20030,

    /// Publish socket message error
    TUNIPluginCode_DEVICEKIT_PUBLISH_SOCKET_ERROR = 20031,

    /// Get device property error
    TUNIPluginCode_DEVICEKIT_GET_DEVICE_PROPERTY_ERROR = 20032,

    /// Set device property error
    TUNIPluginCode_DEVICEKIT_SET_DEVICE_PROPERTY_ERROR = 20033,

    /// Connect ThingBLE device error
    TUNIPluginCode_DEVICEKIT_CONNECT_ThingBLE_DEVICE_ERROR = 20034,

    /// Disconnect ThingBLE device error
    TUNIPluginCode_DEVICEKIT_DISCONNECT_ThingBLE_DEVICE_ERROR = 20035,

    /// Get ThingBLE online state error
    TUNIPluginCode_DEVICEKIT_GET_ThingBLE_ONLINE_ERROR = 20036,

    /// Publish ThingBLE transparentData error
    TUNIPluginCode_DEVICEKIT_PUBLISH_ThingBLE_DATA_ERROR = 20037,

    /// Post ThingBLE bigData channel with progress error
    TUNIPluginCode_DEVICEKIT_POST_ThingBLE_BIGDATA_CHANNEL_WITH_PROGRESS_ERROR = 20038,

    /// Query dps error
    TUNIPluginCode_DEVICEKIT_QUERY_DPS_ERROR = 20039,

    /// localKey is invalid
    TUNIPluginCode_DEVICEKIT_LOCAL_KEY_INVALID = 20040,

    /// communicationId is invalid
    TUNIPluginCode_DEVICEKIT_COMMUNICATION_ID_INVALID = 20041,

    /// communicationId is the same as deviceId
    TUNIPluginCode_DEVICEKIT_COMMUNICATION_ID_SAME_AS_DEVICE_ID = 20042,

    /// gw is invalid
    TUNIPluginCode_DEVICEKIT_GW_ID_INVALID = 20043,

    /// GwSubDevice activator error
    TUNIPluginCode_DEVICEKIT_GW_SUB_DEVICE_ACTIVATOR_ERROR = 20044,

    /// Open URL failed
    TUNIPluginCode_DEVICEKIT_OPEN_URL_ERROR = 20045,

    /// Open RN panel failed
    TUNIPluginCode_DEVICEKIT_OPEN_RN_PANEL_ERROR = 20046,

    /// Reset factory error
    TUNIPluginCode_DEVICEKIT_RESET_FACTORY_ERROR = 20048,

    /// Get BT info failed
    TUNIPluginCode_DEVICEKIT_GET_BT_INFO_ERROR = 20049,

    /// Get local support app list failed
    TUNIPluginCode_DEVICEKIT_GET_LOCAL_SUPPORT_APP_LIST_ERROR = 20050,

    /// Create BT bond failed
    TUNIPluginCode_DEVICEKIT_CREATE_BT_BOND_ERROR = 20051,

    /// Remove BT bond failed
    TUNIPluginCode_DEVICEKIT_REMOVE_BT_BOND_ERROR = 20052,

    /// Subscribe topic failed
    TUNIPluginCode_DEVICEKIT_SUBSCRIBE_TOPIC_ERROR = 20053,

    /// Unsubscribe topic failed
    TUNIPluginCode_DEVICEKIT_UNSUBSCRIBE_TOPIC_ERROR = 20054,

    /// Get bluetooth capability of BT failed
    TUNIPluginCode_DEVICEKIT_BLUETOOTH_CAPABILITY_BT_ERROR = 20055,

    /// Activate directly connected device failed
    TUNIPluginCode_DEVICEKIT_DIRECTLY_CONNECTED_ACTIVATOR_ERROR = 20056,

    /// Get share device info failed
    TUNIPluginCode_DEVICEKIT_GET_SHARE_DEVICE_INFO_ERROR = 20057,

    /// Remove received shared device failed
    TUNIPluginCode_DEVICEKIT_REMOVE_SHARE_DEVICE_ERROR = 20058,

    /// Get device offline reminder support failed
    TUNIPluginCode_DEVICEKIT_IS_DEVICE_SUPPORT_OFFLINE_REMINDER_ERROR = 20059,

    /// Get device offline reminder state failed
    TUNIPluginCode_DEVICEKIT_GET_DEVICE_OFFLINE_REMINDER_STATE_ERROR = 20060,

    /// Toggle device offline reminder failed
    TUNIPluginCode_DEVICEKIT_TOGGLE_DEVICE_OFFLINE_REMINDER_ERROR = 20061,

    /// Sync device info failed
    TUNIPluginCode_DEVICEKIT_SYNC_DEVICE_INFO_ERROR = 20062,

    /// Check ota upgrade status failed
    TUNIPluginCode_DEVICEKIT_CHECK_OTA_UPGRADE_STATUS_ERROR = 20063,

    /// Group model is null
    TUNIPluginCode_DEVICEKIT_GROUP_MODEL_NULL = 20064,

    /// Get group support dpcode device count failed
    TUNIPluginCode_DEVICEKIT_GET_GROUP_SUPPORT_DPCODE_DEVICE_COUNT_ERROR = 20065,

    /// Publish group dps failed
    TUNIPluginCode_DEVICEKIT_PUBLISH_GROUP_DPS_ERROR = 20066,

    /// Update thing model info failed
    TUNIPluginCode_DEVICEKIT_UPDATE_THING_MODEL_INFO_ERROR = 20067,

    /// Publish thing model message failed
    TUNIPluginCode_DEVICEKIT_PUBLISH_THING_MODEL_MESSAGE_ERROR = 20068,

    /// Publish local area network message failed
    TUNIPluginCode_DEVICEKIT_PUBLISH_LAN_MESSAGE_ERROR = 20069,

    /// nodeId is invalid
    TUNIPluginCode_DEVICEKIT_NODE_ID_INVALID = 20070,

    /// SigMeshBean is null
    TUNIPluginCode_DEVICEKIT_SIGMESH_MODEL_NULL = 20071,

    /// Get supported third party services failed
    TUNIPluginCode_DEVICEKIT_GET_SUPPORTED_THIRD_PARTY_SERVICES_ERROR = 20072,

    /// BLE device scan bind failed
    TUNIPluginCode_DEVICEKIT_BLE_DEVICE_SCAN_BIND_ERROR = 20073,

    /// Get device offline reminder warning text failed
    TUNIPluginCode_DEVICEKIT_GET_DEVICE_OFFLINE_REMINDER_WARNING_TEXT_ERROR = 20074,

    /// Get device BT info failed
    TUNIPluginCode_DEVICEKIT_GET_DEVICE_BT_INFO_ERROR = 20075,

    /// Group Control Error
    TUNIPluginCode_DEVICEKIT_GROUP_CONTROL_ERROR = 20076,

    /// rename device error
    TUNIPluginCode_DEVICEKIT_RENAME_DEVICE_ERROR = 20077,

    /// dp code invalid
    TUNIPluginCode_DEVICEKIT_DP_CODE_INVALID = 20078,

    /// Error obtaining the number of devices in the group
    TUNIPluginCode_DEVICEKIT_GROUP_GET_DEVICE_NUM_ERROR = 20079,

    /// publish sigMesh multiDps error
    TUNIPluginCode_DEVICEKIT_GROUP_PUBLISH_SIGMESH_MULTI_DPS_ERROR = 20080,

    /// devicekit mesh getDpData error
    TUNIPluginCode_DEVICEKIT_MESH_GET_DPDATA_BY_MESH_ERROR = 20081,

    /// get opCode and params by verdor id error
    TUNIPluginCode_DEVICEKIT_MESH_OPCODE_PARAMS_NULL = 20082,

    /// get mesh nodeId format error
    TUNIPluginCode_DEVICEKIT_MESH_NUMBER_FORMAT_ERROR = 20083,

    /// ble transfer file don`t exit
    TUNIPluginCode_DEVICEKIT_BLE_TRANSFER_FILE_DONT_EXIT = 20084,

    /// ble file transfer error
    TUNIPluginCode_DEVICEKIT_BLE_FILE_TRANSFER_ERROR = 20085,

    /// device wifi activator error
    TUNIPluginCode_DEVICEKIT_WIFI_ACTIVATOR_ERROR = 20086,

    /// scene create action error
    TUNIPluginCode_DEVICEKIT_SCENE_CREATE_ACTION_ERROR = 20087,

    /// scene edit action error
    TUNIPluginCode_DEVICEKIT_SCENE_EDIT_ACTION_ERROR = 20088,

    /// scene show dialog error
    TUNIPluginCode_DEVICEKIT_SCENE_SHOW_DIALOG_ERROR = 20089,

    /// scene open pre condition error
    TUNIPluginCode_DEVICEKIT_SCENE_OPEN_PRECONDITION_ERROR = 20090,

    /// scene create condition error
    TUNIPluginCode_DEVICEKIT_SCENE_CREATE_CONDITION_ERROR = 20091,

    /// scene edit condition error
    TUNIPluginCode_DEVICEKIT_SCENE_EDIT_CONDITION_ERROR = 20092,

    /// open recommend scene detail error
    TUNIPluginCode_DEVICEKIT_OPEN_RECOMMEND_SCENE_DETAIL_ERROR = 20093,

    /// connect WiFi error
    TUNIPluginCode_DEVICEKIT_CONNECT_WIFI_ERROR = 207201,

    /// -------------- ThingKit or BIZKit 30000 start ----------------
    TUNIPluginCode_ThingKIT_START_MARKER = 30000,

    /// atop request error
    TUNIPluginCode_ATOP_REQUEST_ERROR = 30001,

    /// Cannot find image file from path
    TUNIPluginCode_ThingKIT_INVALID_IMAGE_PATH_ERROR = 30002,

    /// encryptKey is empty or null
    TUNIPluginCode_ThingKIT_ENCRYPT_KEY_INVALID = 30003,

    /// image url is empty or null
    TUNIPluginCode_ThingKIT_IMAGE_URL_INVALID = 30004,

    /// UIId empty or null
    TUNIPluginCode_ThingKIT_UIID_INVALID = 30005,

    /// Get private key with spaceIzd error
    TUNIPluginCode_ThingKIT_GET_PRIVATE_KEY_WITH_SPACE_ID_ERROR = 30006,

    /// Get private key with deviceId error
    TUNIPluginCode_ThingKIT_GET_PRIVATE_KEY_WITH_DEVICE_ID_ERROR = 30007,

    /// image upload failed
    TUNIPluginCode_ThingKIT_IMAGE_UPLOAD_FAILED = 30008,

    /// share failed
    TUNIPluginCode_ThingKIT_SHARE_FAILED = 30009,

    /// highway request error
    TUNIPluginCode_ThingKIT_HIGHWAY_REQUEST_ERROR = 30010,

    /// iap is not ready
    TUNIPluginCode_ThingKIT_IAP_IS_NOT_READY = 30011,

    /// db crud error
    TUNIPluginCode_BizKIT_AI_ASSISTANT_DB_ERROR = 30012,

    /// AIAssistant error
    TUNIPluginCode_BizKIT_AI_ASSISTANT_ERROR = 30013,

    /// ASR error
    TUNIPluginCode_BizKIT_AI_ASR_ERROR = 30014,

    /// WebSocket error
    TUNIPluginCode_BizKIT_AI_WS_ERROR = 30015,

    /// ng rawkey error
    TUNIPluginCode_BizKIT_NG_RAWKEY_ERROR = 30016,

    /// can't access private data
    TUNIPluginCode_BizKIT_NG_PRIVATE_ERROR = 30017,

    /// share not support thrid login
    TUNIPluginCode_BizKIT__NOT_SUPPORT_THRID_LOGIN = 30018,

    /// share not support input channel
    TUNIPluginCode_BizKIT__NOT_SUPPORT_INPUT_CHANNEL = 30019,

    /// Thrid login already bind
    TUNIPluginCode_BizKIT__THRID_LOGIN_ALREADY_BIND = 30020,

    /// Thrid login not support channel
    TUNIPluginCode_BizKIT_THRID_LOGIN_NOT_SUPPORT_CHANNEL = 30021,

    /// Thrid login not bind
    TUNIPluginCode_BizKIT_THRID_LOGIN_NOT_BIND = 30022,

    /// Thrid login bind canceled
    TUNIPluginCode_BizKIT_THRID_LOGIN_BIND_CANCELED = 30023,

    /// video upload failed
    TUNIPluginCode_BizKIT_VIDEO_UPLOAD_FAILED = 30024,

    /// message center unread count or feedback unread count fetch failed
    TUNIPluginCode_BizKT_UNREAD_COUNT_FETCH_FAILD = 30030,

    /// upload App log failed
    TUNIPluginCode_BizKT_LOG_UPLOAD_FAILED = 30040,

    /// upload App log canceled
    TUNIPluginCode_BizKT_LOG_UPLOAD_CANCELED = 30041,

    /// ------------------- BizKit AI Stream Kit 39000 Start ----------------
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_Start = 39000,

    /// ai stream internal error
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_INTERNAL_ERROR = 39001,

    /// invalid params
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_INVALID_PARAMS = 39002,

    /// http request fail
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_HTTP_REQUEST_FAIL = 39003,

    /// connection not connected
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_NOT_CONNECTED = 39004,

    /// session id invalid
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_SESSION_ID_INVALID = 39005,

    /// event id invalid
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_EVENT_ID_INVALID = 39006,

    /// data channel invalid
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_DATA_CHANNEL_INVALID = 39007,

    /// data packet invalid
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_DATA_PACKET_INVALID = 39008,

    /// file read error
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_FILE_READ_ERROR = 39009,

    /// send data packet error
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_SEND_DATA_PACKET_ERROR = 39010,

    /// session break error
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_SESSION_BREAK_ERROR = 39011,

    /// connection break error
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_CONNECTION_BREAK_ERROR = 39012,

    /// the image format error
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_IMAGE_FORMAT_ERROR = 39013,

    /// the recording initialization failed
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_RECORDING_INIT_FAILED = 39014,

    /// the db initialization failed
    TUNIPluginCode_BizKIT_AI_STREAM_KIT_DB_INIT_FAILED = 39015,

    /// -------------- ThingMiniAppCore 40000 Start
    TUNIPluginCode_MINIAPP_START_MARKER = 40000,

    /// the last page cannot be navigator back
    TUNIPluginCode_MINIAPP_NAVIGATOR_BACK_FAIL = 40001,

    /// the page not be found
    TUNIPluginCode_MINIAPP_NAVIGATOR_PAGE_NOT_FOUND = 40002,

    /// miniapp not exist
    TUNIPluginCode_MINIAPP_ID_ERROR = 40003,

    /// navigatorTo cannot open tab url
    TUNIPluginCode_MINIAPP_NAVIGATOR_TO_CANNOT_OPEN_TAB_URL = 40004,

    /// redirectTo cannot open tab url
    TUNIPluginCode_MINIAPP_REDIRECT_TO_TO_CANNOT_OPEN_TAB_URL = 40005,

    /// A maximum of ten pages can be opened
    TUNIPluginCode_MINIAPP_MAX_PAGE_COUNT = 40006,

    /// cannot find page url from tab config
    TUNIPluginCode_MINIAPP_TAB_CONFIG_NOT_FOUND_URL = 40007,

    /// no tab config
    TUNIPluginCode_MINIAPP_HAVE_NO_TAB_CONFIG = 40008,

    /// miniapp already been open, cannot be open again
    TUNIPluginCode_MINIAPP_AlREADY_OPEN = 40009,

    /// miniapp can not be exit
    TUNIPluginCode_MINIAPP_EXIT_ERROR = 40010,

    /// miniapp can not support on tab
    TUNIPluginCode_MINIAPP_SWITCHTAB_NOT_SUPPORT_ON_TAB = 40011,

    /// request domain invalid
    TUNIPluginCode_MINIAPP_INVALID_DOMAIN = 40012,

    /// domain is not configured, please configure it on the platform
    TUNIPluginCode_MINIAPP_DOMAIN_UNCONFIGURED = 40013,

    /// api is not configured, please configure it on the platform
    TUNIPluginCode_MINIAPP_API_UNCONFIGURED = 40014,

    /// miniapp highway request error
    TUNIPluginCode_MINIAPP_HIGHWAY_REQUEST_ERROR = 40015,

    /// router name is not configured, please configure it in the app.json
    TUNIPluginCode_MINIAPP_ROUTER_NAME_UNCONFIGURED = 40016,

    /// navigate back event already been intercept
    TUNIPluginCode_MINIAPP_CAN_NOT_NAVIGATE_BACK = 40017,

    /// query auth code fail
    TUNIPluginCode_MINIAPP_AUTH_CODE_FAIL = 40018,

    /// ext api not found
    TUNIPluginCode_MINIAPP_EXT_API_NOT_FOUND = 40019,

    /// ext api fail
    TUNIPluginCode_MINIAPP_EXT_API_FAIL = 40020,

    /// this page is not support set orientation
    TUNIPluginCode_MINIAPP_ORIENTATION_NOT_SUPPORT = 40021,

    /// this page can not hide menu button
    TUNIPluginCode_MINIAPP_MENU_BUTTON_CAN_NOT_HIDE = 40022,

    /// illegal permission name
    TUNIPluginCode_MINIAPP_ILLEGAL_PERMISSION = 40023,

    /// permission has been denied by user
    TUNIPluginCode_MINIAPP_PERMISSION_DENIED_BY_USER = 40024,

    /// permission did not apply through authorize api
    TUNIPluginCode_MINIAPP_PERMISSION_DID_NOT_APPLY_THROUGH_AUTHORIZE_API = 40025,

    /// open url fail, not exist app can open it.
    TUNIPluginCode_MINIAPP_OPEN_THIRD_APP_URL_FAIL = 40026,

    /// Not authorized to call this api
    TUNIPluginCode_MINIAPP_API_NO_PERMISSION = 40027,

    /// File path through
    TUNIPluginCode_MINIAPP_FILE_PATH_THROUGH_FAIL = 40028,

    /// Tab common container not allowed relaunch
    TUNIPluginCode_MINIAPP_TAB_COMMON_CONTAINER_DID_NOT_RELAUNCH = 40029,

    /// Tab common container not allowed redirect
    TUNIPluginCode_MINIAPP_TAB_COMMON_CONTAINER_DID_NOT_REDIRECT = 40030,

    /// -------------- Independent service module 50000 Start ----------------
    TUNIPluginCode_FEATURE_START_MARKER = 50000,

    /// No location permission
    TUNIPluginCode_MAPKIT_NO_LOCATION_PERMISSION = 50001,

    /// Failed to get location
    TUNIPluginCode_MAPKIT_FAIL_GET_LOCATION = 50002,

    /// The parameter format is incorrect
    TUNIPluginCode_MAPKIT_INCORRECT_PARAM = 50003,

    /// Has no geofence register
    TUNIPluginCode_MAPKIT_GEOFENCE_HAS_NO_REGISTERS = 50004,

    /// Failed to get geofence count
    TUNIPluginCode_MAPKIT_FAIL_GET_GEOFENCE_COUNT = 50005,

    /// Failed to register geofence
    TUNIPluginCode_MAPKIT_FAIL_REGISTER_GEOFENCE = 50006,

    /// Failed to unregister geofence
    TUNIPluginCode_MAPKIT_FAIL_UNREGISTER_GEOFENCE = 50007,

    /// This error is triggered when the geofencing feature is not enabled. Geofencing is a premium service that requires activation. If not activated, this error will be returned.
    TUNIPluginCode_MAPKIT_GEOFENCE_NO_SUPPORT = 50008,

    /// Triggered when the maximum number of geofences is exceeded. This error occurs if the user tries to create more geofences than allowed.
    TUNIPluginCode_MAPKIT_GEOFENCE_MAX_LIMIT_EXCEEDED = 50009,

    /// Geofence class's businessType parameter received an unsupported type
    TUNIPluginCode_MAPKIT_GEOFENCE_UNKNOW_BUSINESS_TYPE = 50010,

    /// -------------- Home trade Power 60000 start ----------------
    TUNIPluginCode_HOMEKIT_START_MARKER = 60000,

    /// Get device room info failed
    TUNIPluginCode_HOMEKIT_GET_DEVICE_ROOM_INFO_ERROR = 60001,

    /// Switch device room failed
    TUNIPluginCode_HOMEKIT_SWITCH_DEVICE_ROOM_ERROR = 60002,

    /// payment control entry not found
    TUNIPluginCode_HOMEKIT_PAYMENT_CONTROL_ENTRY_NOT_FOUND_ERROR = 60003,

    /// -------------- p2p file transfer capability 70000 Start ----------------
    TUNIPluginCode_P2P_FILE_TRANSFER = 70000,

    /// P2P connection in progress
    TUNIPluginCode_P2P_CONNECTING = 70001,

    /// P2P connection failed
    TUNIPluginCode_P2P_CONNECT_FAIL = 70002,

    /// P2P is not connected
    TUNIPluginCode_P2P_CONNECT_NOT = 70003,

    /// Other files are being uploaded
    TUNIPluginCode_P2P_UPLOADING = 70101,

    /// File upload failed
    TUNIPluginCode_P2P_UPLOAD_FAIL = 70102,

    /// File upload cancellation failed
    TUNIPluginCode_P2P_UPLOAD_CANCEL_FAIL = 70103,

    /// On querying file
    TUNIPluginCode_P2P_FILE_QUERYING = 70110,

    /// File query failed
    TUNIPluginCode_P2P_FILE_QUERY_FAIL = 70111,

    /// Other files are being downloaded
    TUNIPluginCode_P2P_DOWNLOADING = 70112,

    /// File download failed
    TUNIPluginCode_P2P_DOWNLOAD_FAIL = 70113,

    /// File download cancellation failed
    TUNIPluginCode_P2P_DOWNLOAD_CANCEL_FAIL = 70114,

    /// -------------- IPC Power 80000 Start ----------------
    TUNIPluginCode_IPCKIT_PARAMS_INVALID = 80000,

    /// accept doorbell call failed
    TUNIPluginCode_IPCKIT_ACCEPT_DOORBELL_CALL_FAIL = 80001,

    /// hangup doorbell call failed
    TUNIPluginCode_IPCKIT_HANGUP_DOORBELL_CALL_FAIL = 80002,

    /// -------------- DEVELOPER Power 100000 Start ----------------
    TUNIPluginCode_DEVELOPER_START_MARKER = 100000,

};

typedef NSString *TUNIPluginMsg NS_STRING_ENUM;
/// TUNIPluginCode_SUCCESS = 0, msg = success
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_SUCCESS;
/// TUNIPluginCode_CONTEXT_IS_NOT_REGISTERED = 1, msg = The context is not registered
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_CONTEXT_IS_NOT_REGISTERED;
/// TUNIPluginCode_UNDEFINED_MODULE = 2, msg = can‘t find module
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_UNDEFINED_MODULE;
/// TUNIPluginCode_UNDEFINED_METHOD = 3, msg = can‘t find methodName
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_UNDEFINED_METHOD;
/// TUNIPluginCode_UNDEFINED_MODEL = 4, msg = can't transfer model
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_UNDEFINED_MODEL;
/// TUNIPluginCode_LACK_OF_PARAM = 5, msg = The necessary parameters are missing
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_LACK_OF_PARAM;
/// TUNIPluginCode_INCORRECT_PARAM = 6, msg = The parameter format is incorrect
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_INCORRECT_PARAM;
/// TUNIPluginCode_INTERNAL_ERROR = 7, msg = API Internal processing failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_INTERNAL_ERROR;
/// TUNIPluginCode_METHOD_NO_PERMISSION = 8, msg = Method Unauthorized access
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_METHOD_NO_PERMISSION;
/// TUNIPluginCode_METHOD_UNKNOWN = 9, msg = Method UnKnown error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_METHOD_UNKNOWN;
/// TUNIPluginCode_ACTIVITY_IS_INVALID = 9001, msg = Activity is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ACTIVITY_IS_INVALID;
/// TUNIPluginCode_CONTEXT_IS_INVALID = 9002, msg = Context is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_CONTEXT_IS_INVALID;
/// TUNIPluginCode_UNDEFINED_SCOPE_PERMISSION_ERROR = 9003, msg = can‘t find scope permission
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_UNDEFINED_SCOPE_PERMISSION_ERROR;
/// TUNIPluginCode_APP_NO_PERMISSION_ERROR = 9004, msg = app no permission
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_APP_NO_PERMISSION_ERROR;
/// TUNIPluginCode_UNDEFINED_SERVICE_ERROR = 9005, msg = can‘t find service
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_UNDEFINED_SERVICE_ERROR;
/// TUNIPluginCode_NETWORK_REQUEST_ERROR = 9006, msg = network request error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_NETWORK_REQUEST_ERROR;
/// TUNIPluginCode_FILE_PATH_IS_ILLEGAL = 9007, msg = file path is illegal
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_FILE_PATH_IS_ILLEGAL;
/// TUNIPluginCode_BASEKIT_START_MARKER = 10000, msg = -------------- BaseKit 10000 Start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_START_MARKER;
/// TUNIPluginCode_BASEKIT_SENSORS_INIT_ERROR = 10001, msg = Sensor initialization fail
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_SENSORS_INIT_ERROR;
/// TUNIPluginCode_BASEKIT_IMAGE_PICKER_ERROR = 10002, msg = Image picker error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_IMAGE_PICKER_ERROR;
/// TUNIPluginCode_BASEKIT_NETWORK_REQUEST_ERROR = 10003, msg = network request error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_NETWORK_REQUEST_ERROR;
/// TUNIPluginCode_BASEKIT_AUDIO_PLAY_ERROR = 10004, msg = audio play error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_AUDIO_PLAY_ERROR;
/// TUNIPluginCode_BASEKIT_AUDIO_SEEK_ERROR = 10005, msg = audio seek error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_AUDIO_SEEK_ERROR;
/// TUNIPluginCode_BASEKIT_AUDIO_STOP_ERROR = 10006, msg = audio stop error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_AUDIO_STOP_ERROR;
/// TUNIPluginCode_BASEKIT_DOWNLOAD_FILE_ERROR = 10007, msg = download file error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_DOWNLOAD_FILE_ERROR;
/// TUNIPluginCode_BASEKIT_UPLOAD_FILE_ERROR = 10008, msg = upload file error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_UPLOAD_FILE_ERROR;
/// TUNIPluginCode_BASEKIT_SCAN_CODE_ERROR = 10009, msg = scan code error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_SCAN_CODE_ERROR;
/// TUNIPluginCode_BASEKIT_STORAGE_ERROR = 10010, msg = storage json syntax error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_STORAGE_ERROR;
/// TUNIPluginCode_BASEKIT_FILE_NOT_EXIST = 10011, msg = file not exist
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_FILE_NOT_EXIST;
/// TUNIPluginCode_BASEKIT_READ_FILE_ENCODING_INVALID = 10012, msg = read file encoding invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_READ_FILE_ENCODING_INVALID;
/// TUNIPluginCode_BASEKIT_READ_FILE_ERROR = 10013, msg = read file error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_READ_FILE_ERROR;
/// TUNIPluginCode_BASEKIT_ROUTE_CAN_NOT_USED = 10014, msg = can not use this route url in the APP
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_ROUTE_CAN_NOT_USED;
/// TUNIPluginCode_BASEKIT_GET_FILE_STATS_ERROR = 10015, msg = get file stats error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_GET_FILE_STATS_ERROR;
/// TUNIPluginCode_BASEKIT_MKDIR_ERROR = 10016, msg = create dir error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_MKDIR_ERROR;
/// TUNIPluginCode_BASEKIT_RMDIR_ERROR = 10017, msg = delete dir error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_RMDIR_ERROR;
/// TUNIPluginCode_BASEKIT_REMOVE_SAVED_FILE_ERROR = 10018, msg = remove saved file error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_REMOVE_SAVED_FILE_ERROR;
/// TUNIPluginCode_BASEKIT_WRITE_FILE_ERROR = 10019, msg = write file error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_WRITE_FILE_ERROR;
/// TUNIPluginCode_BASEKIT_SDCARD_NO_MOUNTED_ERROR = 10020, msg = sdcard not mounted error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_SDCARD_NO_MOUNTED_ERROR;
/// TUNIPluginCode_BASEKIT_SSID_NIL_ERROR = 10021, msg = SSID nil error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_SSID_NIL_ERROR;
/// TUNIPluginCode_BASEKIT_MEDIA_INFO_PARSE_ERROR = 10022, msg = media info parse error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_MEDIA_INFO_PARSE_ERROR;
/// TUNIPluginCode_BASEKIT_MEDIA_INFO_PARAMS_INVALID = 10023, msg = nvalid params when parse media info
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_MEDIA_INFO_PARAMS_INVALID;
/// TUNIPluginCode_BASEKIT_SAVE_VIDEO_PARAMS_INVALID = 10024, msg = invalid params when save video
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_SAVE_VIDEO_PARAMS_INVALID;
/// TUNIPluginCode_BASEKIT_SAVE_VIDEO_ERROR = 10025, msg = save video error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_SAVE_VIDEO_ERROR;
/// TUNIPluginCode_BASEKIT_GET_FILE_INFO_ERROR = 10026, msg = get file info error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_GET_FILE_INFO_ERROR;
/// TUNIPluginCode_BASEKIT_MQTT_CONNECT_ERROR = 10027, msg = mqtt connect error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_MQTT_CONNECT_ERROR;
/// TUNIPluginCode_BASEKIT_MQTT_SUBSCRIBE_ERROR = 10028, msg = mqtt subscribe error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_MQTT_SUBSCRIBE_ERROR;
/// TUNIPluginCode_BASEKIT_MQTT_UNSUBSCRIBE_ERROR = 10029, msg = mqtt unsubscribe error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_MQTT_UNSUBSCRIBE_ERROR;
/// TUNIPluginCode_BASEKIT_MQTT_PUBLISH_ERROR = 10030, msg = mqtt publish error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_MQTT_PUBLISH_ERROR;
/// TUNIPluginCode_BASEKIT_VIDEO_TO_GIF_CONVERT_ERROR = 10031, msg = fail when convert video to gif
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_VIDEO_TO_GIF_CONVERT_ERROR;
/// TUNIPluginCode_BASEKIT_VIDEO_SOURCE_INVALID = 10032, msg = invalid video source
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_VIDEO_SOURCE_INVALID;
/// TUNIPluginCode_BASEKIT_GIF_TO_IMAGES_CONVERT_ERROR = 10033, msg = fail when convert gif to images
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_GIF_TO_IMAGES_CONVERT_ERROR;
/// TUNIPluginCode_BASEKIT_GIF_SOURCE_INVALID = 10034, msg = invalid gif source
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BASEKIT_GIF_SOURCE_INVALID;
/// TUNIPluginCode_DEVICEKIT_START_MARKER = 20000, msg = -------------- DeviceKit 20000 Start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_START_MARKER;
/// TUNIPluginCode_DEVICEKIT_DEVICE_ID_INVALID = 20001, msg = DeviceId is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DEVICE_ID_INVALID;
/// TUNIPluginCode_DEVICEKIT_GROUP_ID_INVALID = 20002, msg = GroupId is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GROUP_ID_INVALID;
/// TUNIPluginCode_DEVICEKIT_MESH_ID_INVALID = 20003, msg = MeshId is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_MESH_ID_INVALID;
/// TUNIPluginCode_DEVICEKIT_PRODUCT_ID_INVALID = 20004, msg = ProductId is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PRODUCT_ID_INVALID;
/// TUNIPluginCode_DEVICEKIT_DEVICE_ID_AND_GROUP_ID_INVALID = 20005, msg = DeviceId and GroupId is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DEVICE_ID_AND_GROUP_ID_INVALID;
/// TUNIPluginCode_DEVICEKIT_DEVICE_MODEL_AND_GROUP_MODEL_NULL = 20006, msg = Device model and Group model is null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DEVICE_MODEL_AND_GROUP_MODEL_NULL;
/// TUNIPluginCode_DEVICEKIT_DEVICE_NETWORK_ERROR = 20007, msg = Device network error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DEVICE_NETWORK_ERROR;
/// TUNIPluginCode_DEVICEKIT_MISSING_DEVICEID_AND_UIID = 20008, msg = Cannot find either deviceId or uiId
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_MISSING_DEVICEID_AND_UIID;
/// TUNIPluginCode_DEVICEKIT_URL_INVALID = 20009, msg = The URL is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_URL_INVALID;
/// TUNIPluginCode_DEVICEKIT_SERVICE_NULL = 20021, msg = Cannot find service
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SERVICE_NULL;
/// TUNIPluginCode_DEVICEKIT_DEVICE_MODEL_NULL = 20022, msg = Device model is null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DEVICE_MODEL_NULL;
/// TUNIPluginCode_DEVICEKIT_GATEWAY_MODEL_NULL = 20023, msg = Gateway model is null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GATEWAY_MODEL_NULL;
/// TUNIPluginCode_DEVICEKIT_CACHE_MODEL_NULL = 20024, msg = Cache model is null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_CACHE_MODEL_NULL;
/// TUNIPluginCode_DEVICEKIT_DEVICE_OFFLINE = 20025, msg = Device is offline
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DEVICE_OFFLINE;
/// TUNIPluginCode_DEVICEKIT_REMOVE_DEVICE_ERROR = 20026, msg = Remove device error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_REMOVE_DEVICE_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_SUBDEVICELIST_ERROR = 20027, msg = Get subDeviceList from cloud error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_SUBDEVICELIST_ERROR;
/// TUNIPluginCode_DEVICEKIT_PUBLISH_DPS_ERROR = 20028, msg = Publish Dps error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PUBLISH_DPS_ERROR;
/// TUNIPluginCode_DEVICEKIT_PUBLISH_DPS_WITH_TYPE_ERROR = 20029, msg = Publish Dps with type error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PUBLISH_DPS_WITH_TYPE_ERROR;
/// TUNIPluginCode_DEVICEKIT_PUBLISH_MQTT_ERROR = 20030, msg = Publish Mqtt message error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PUBLISH_MQTT_ERROR;
/// TUNIPluginCode_DEVICEKIT_PUBLISH_SOCKET_ERROR = 20031, msg = Publish socket message error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PUBLISH_SOCKET_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_DEVICE_PROPERTY_ERROR = 20032, msg = Get device property error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_DEVICE_PROPERTY_ERROR;
/// TUNIPluginCode_DEVICEKIT_SET_DEVICE_PROPERTY_ERROR = 20033, msg = Set device property error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SET_DEVICE_PROPERTY_ERROR;
/// TUNIPluginCode_DEVICEKIT_CONNECT_ThingBLE_DEVICE_ERROR = 20034, msg = Connect ThingBLE device error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_CONNECT_ThingBLE_DEVICE_ERROR;
/// TUNIPluginCode_DEVICEKIT_DISCONNECT_ThingBLE_DEVICE_ERROR = 20035, msg = Disconnect ThingBLE device error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DISCONNECT_ThingBLE_DEVICE_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_ThingBLE_ONLINE_ERROR = 20036, msg = Get ThingBLE online state error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_ThingBLE_ONLINE_ERROR;
/// TUNIPluginCode_DEVICEKIT_PUBLISH_ThingBLE_DATA_ERROR = 20037, msg = Publish ThingBLE transparentData error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PUBLISH_ThingBLE_DATA_ERROR;
/// TUNIPluginCode_DEVICEKIT_POST_ThingBLE_BIGDATA_CHANNEL_WITH_PROGRESS_ERROR = 20038, msg = Post ThingBLE bigData channel with progress error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_POST_ThingBLE_BIGDATA_CHANNEL_WITH_PROGRESS_ERROR;
/// TUNIPluginCode_DEVICEKIT_QUERY_DPS_ERROR = 20039, msg = Query dps error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_QUERY_DPS_ERROR;
/// TUNIPluginCode_DEVICEKIT_LOCAL_KEY_INVALID = 20040, msg = localKey is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_LOCAL_KEY_INVALID;
/// TUNIPluginCode_DEVICEKIT_COMMUNICATION_ID_INVALID = 20041, msg = communicationId is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_COMMUNICATION_ID_INVALID;
/// TUNIPluginCode_DEVICEKIT_COMMUNICATION_ID_SAME_AS_DEVICE_ID = 20042, msg = communicationId is the same as deviceId
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_COMMUNICATION_ID_SAME_AS_DEVICE_ID;
/// TUNIPluginCode_DEVICEKIT_GW_ID_INVALID = 20043, msg = gw is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GW_ID_INVALID;
/// TUNIPluginCode_DEVICEKIT_GW_SUB_DEVICE_ACTIVATOR_ERROR = 20044, msg = GwSubDevice activator error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GW_SUB_DEVICE_ACTIVATOR_ERROR;
/// TUNIPluginCode_DEVICEKIT_OPEN_URL_ERROR = 20045, msg = Open URL failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_OPEN_URL_ERROR;
/// TUNIPluginCode_DEVICEKIT_OPEN_RN_PANEL_ERROR = 20046, msg = Open RN panel failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_OPEN_RN_PANEL_ERROR;
/// TUNIPluginCode_DEVICEKIT_RESET_FACTORY_ERROR = 20048, msg = Reset factory error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_RESET_FACTORY_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_BT_INFO_ERROR = 20049, msg = Get BT info failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_BT_INFO_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_LOCAL_SUPPORT_APP_LIST_ERROR = 20050, msg = Get local support app list failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_LOCAL_SUPPORT_APP_LIST_ERROR;
/// TUNIPluginCode_DEVICEKIT_CREATE_BT_BOND_ERROR = 20051, msg = Create BT bond failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_CREATE_BT_BOND_ERROR;
/// TUNIPluginCode_DEVICEKIT_REMOVE_BT_BOND_ERROR = 20052, msg = Remove BT bond failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_REMOVE_BT_BOND_ERROR;
/// TUNIPluginCode_DEVICEKIT_SUBSCRIBE_TOPIC_ERROR = 20053, msg = Subscribe topic failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SUBSCRIBE_TOPIC_ERROR;
/// TUNIPluginCode_DEVICEKIT_UNSUBSCRIBE_TOPIC_ERROR = 20054, msg = Unsubscribe topic failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_UNSUBSCRIBE_TOPIC_ERROR;
/// TUNIPluginCode_DEVICEKIT_BLUETOOTH_CAPABILITY_BT_ERROR = 20055, msg = Get bluetooth capability of BT failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_BLUETOOTH_CAPABILITY_BT_ERROR;
/// TUNIPluginCode_DEVICEKIT_DIRECTLY_CONNECTED_ACTIVATOR_ERROR = 20056, msg = Activate directly connected device failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DIRECTLY_CONNECTED_ACTIVATOR_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_SHARE_DEVICE_INFO_ERROR = 20057, msg = Get share device info failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_SHARE_DEVICE_INFO_ERROR;
/// TUNIPluginCode_DEVICEKIT_REMOVE_SHARE_DEVICE_ERROR = 20058, msg = Remove received shared device failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_REMOVE_SHARE_DEVICE_ERROR;
/// TUNIPluginCode_DEVICEKIT_IS_DEVICE_SUPPORT_OFFLINE_REMINDER_ERROR = 20059, msg = Get device offline reminder support failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_IS_DEVICE_SUPPORT_OFFLINE_REMINDER_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_DEVICE_OFFLINE_REMINDER_STATE_ERROR = 20060, msg = Get device offline reminder state failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_DEVICE_OFFLINE_REMINDER_STATE_ERROR;
/// TUNIPluginCode_DEVICEKIT_TOGGLE_DEVICE_OFFLINE_REMINDER_ERROR = 20061, msg = Toggle device offline reminder failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_TOGGLE_DEVICE_OFFLINE_REMINDER_ERROR;
/// TUNIPluginCode_DEVICEKIT_SYNC_DEVICE_INFO_ERROR = 20062, msg = Sync device info failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SYNC_DEVICE_INFO_ERROR;
/// TUNIPluginCode_DEVICEKIT_CHECK_OTA_UPGRADE_STATUS_ERROR = 20063, msg = Check ota upgrade status failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_CHECK_OTA_UPGRADE_STATUS_ERROR;
/// TUNIPluginCode_DEVICEKIT_GROUP_MODEL_NULL = 20064, msg = Group model is null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GROUP_MODEL_NULL;
/// TUNIPluginCode_DEVICEKIT_GET_GROUP_SUPPORT_DPCODE_DEVICE_COUNT_ERROR = 20065, msg = Get group support dpcode device count failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_GROUP_SUPPORT_DPCODE_DEVICE_COUNT_ERROR;
/// TUNIPluginCode_DEVICEKIT_PUBLISH_GROUP_DPS_ERROR = 20066, msg = Publish group dps failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PUBLISH_GROUP_DPS_ERROR;
/// TUNIPluginCode_DEVICEKIT_UPDATE_THING_MODEL_INFO_ERROR = 20067, msg = Update thing model info failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_UPDATE_THING_MODEL_INFO_ERROR;
/// TUNIPluginCode_DEVICEKIT_PUBLISH_THING_MODEL_MESSAGE_ERROR = 20068, msg = Publish thing model message failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PUBLISH_THING_MODEL_MESSAGE_ERROR;
/// TUNIPluginCode_DEVICEKIT_PUBLISH_LAN_MESSAGE_ERROR = 20069, msg = Publish local area network message failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_PUBLISH_LAN_MESSAGE_ERROR;
/// TUNIPluginCode_DEVICEKIT_NODE_ID_INVALID = 20070, msg = nodeId is invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_NODE_ID_INVALID;
/// TUNIPluginCode_DEVICEKIT_SIGMESH_MODEL_NULL = 20071, msg = SigMeshBean is null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SIGMESH_MODEL_NULL;
/// TUNIPluginCode_DEVICEKIT_GET_SUPPORTED_THIRD_PARTY_SERVICES_ERROR = 20072, msg = Get supported third party services failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_SUPPORTED_THIRD_PARTY_SERVICES_ERROR;
/// TUNIPluginCode_DEVICEKIT_BLE_DEVICE_SCAN_BIND_ERROR = 20073, msg = BLE device scan bind failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_BLE_DEVICE_SCAN_BIND_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_DEVICE_OFFLINE_REMINDER_WARNING_TEXT_ERROR = 20074, msg = Get device offline reminder warning text failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_DEVICE_OFFLINE_REMINDER_WARNING_TEXT_ERROR;
/// TUNIPluginCode_DEVICEKIT_GET_DEVICE_BT_INFO_ERROR = 20075, msg = Get device BT info failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GET_DEVICE_BT_INFO_ERROR;
/// TUNIPluginCode_DEVICEKIT_GROUP_CONTROL_ERROR = 20076, msg = Group Control Error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GROUP_CONTROL_ERROR;
/// TUNIPluginCode_DEVICEKIT_RENAME_DEVICE_ERROR = 20077, msg = rename device error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_RENAME_DEVICE_ERROR;
/// TUNIPluginCode_DEVICEKIT_DP_CODE_INVALID = 20078, msg = dp code invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_DP_CODE_INVALID;
/// TUNIPluginCode_DEVICEKIT_GROUP_GET_DEVICE_NUM_ERROR = 20079, msg = Error obtaining the number of devices in the group
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GROUP_GET_DEVICE_NUM_ERROR;
/// TUNIPluginCode_DEVICEKIT_GROUP_PUBLISH_SIGMESH_MULTI_DPS_ERROR = 20080, msg = publish sigMesh multiDps error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_GROUP_PUBLISH_SIGMESH_MULTI_DPS_ERROR;
/// TUNIPluginCode_DEVICEKIT_MESH_GET_DPDATA_BY_MESH_ERROR = 20081, msg = devicekit mesh getDpData error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_MESH_GET_DPDATA_BY_MESH_ERROR;
/// TUNIPluginCode_DEVICEKIT_MESH_OPCODE_PARAMS_NULL = 20082, msg = get opCode and params by verdor id error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_MESH_OPCODE_PARAMS_NULL;
/// TUNIPluginCode_DEVICEKIT_MESH_NUMBER_FORMAT_ERROR = 20083, msg = get mesh nodeId format error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_MESH_NUMBER_FORMAT_ERROR;
/// TUNIPluginCode_DEVICEKIT_BLE_TRANSFER_FILE_DONT_EXIT = 20084, msg = ble transfer file don`t exit
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_BLE_TRANSFER_FILE_DONT_EXIT;
/// TUNIPluginCode_DEVICEKIT_BLE_FILE_TRANSFER_ERROR = 20085, msg = ble file transfer error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_BLE_FILE_TRANSFER_ERROR;
/// TUNIPluginCode_DEVICEKIT_WIFI_ACTIVATOR_ERROR = 20086, msg = device wifi activator error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_WIFI_ACTIVATOR_ERROR;
/// TUNIPluginCode_DEVICEKIT_SCENE_CREATE_ACTION_ERROR = 20087, msg = scene create action error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SCENE_CREATE_ACTION_ERROR;
/// TUNIPluginCode_DEVICEKIT_SCENE_EDIT_ACTION_ERROR = 20088, msg = scene edit action error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SCENE_EDIT_ACTION_ERROR;
/// TUNIPluginCode_DEVICEKIT_SCENE_SHOW_DIALOG_ERROR = 20089, msg = scene show dialog error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SCENE_SHOW_DIALOG_ERROR;
/// TUNIPluginCode_DEVICEKIT_SCENE_OPEN_PRECONDITION_ERROR = 20090, msg = scene open pre condition error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SCENE_OPEN_PRECONDITION_ERROR;
/// TUNIPluginCode_DEVICEKIT_SCENE_CREATE_CONDITION_ERROR = 20091, msg = scene create condition error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SCENE_CREATE_CONDITION_ERROR;
/// TUNIPluginCode_DEVICEKIT_SCENE_EDIT_CONDITION_ERROR = 20092, msg = scene edit condition error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_SCENE_EDIT_CONDITION_ERROR;
/// TUNIPluginCode_DEVICEKIT_OPEN_RECOMMEND_SCENE_DETAIL_ERROR = 20093, msg = open recommend scene detail error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_OPEN_RECOMMEND_SCENE_DETAIL_ERROR;
/// TUNIPluginCode_DEVICEKIT_CONNECT_WIFI_ERROR = 207201, msg = connect WiFi error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVICEKIT_CONNECT_WIFI_ERROR;
/// TUNIPluginCode_ThingKIT_START_MARKER = 30000, msg = -------------- ThingKit or BIZKit 30000 start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_START_MARKER;
/// TUNIPluginCode_ATOP_REQUEST_ERROR = 30001, msg = atop request error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ATOP_REQUEST_ERROR;
/// TUNIPluginCode_ThingKIT_INVALID_IMAGE_PATH_ERROR = 30002, msg = Cannot find image file from path
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_INVALID_IMAGE_PATH_ERROR;
/// TUNIPluginCode_ThingKIT_ENCRYPT_KEY_INVALID = 30003, msg = encryptKey is empty or null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_ENCRYPT_KEY_INVALID;
/// TUNIPluginCode_ThingKIT_IMAGE_URL_INVALID = 30004, msg = image url is empty or null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_IMAGE_URL_INVALID;
/// TUNIPluginCode_ThingKIT_UIID_INVALID = 30005, msg = UIId empty or null
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_UIID_INVALID;
/// TUNIPluginCode_ThingKIT_GET_PRIVATE_KEY_WITH_SPACE_ID_ERROR = 30006, msg = Get private key with spaceIzd error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_GET_PRIVATE_KEY_WITH_SPACE_ID_ERROR;
/// TUNIPluginCode_ThingKIT_GET_PRIVATE_KEY_WITH_DEVICE_ID_ERROR = 30007, msg = Get private key with deviceId error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_GET_PRIVATE_KEY_WITH_DEVICE_ID_ERROR;
/// TUNIPluginCode_ThingKIT_IMAGE_UPLOAD_FAILED = 30008, msg = image upload failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_IMAGE_UPLOAD_FAILED;
/// TUNIPluginCode_ThingKIT_SHARE_FAILED = 30009, msg = share failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_SHARE_FAILED;
/// TUNIPluginCode_ThingKIT_HIGHWAY_REQUEST_ERROR = 30010, msg = highway request error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_HIGHWAY_REQUEST_ERROR;
/// TUNIPluginCode_ThingKIT_IAP_IS_NOT_READY = 30011, msg = iap is not ready
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_ThingKIT_IAP_IS_NOT_READY;
/// TUNIPluginCode_BizKIT_AI_ASSISTANT_DB_ERROR = 30012, msg = db crud error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_ASSISTANT_DB_ERROR;
/// TUNIPluginCode_BizKIT_AI_ASSISTANT_ERROR = 30013, msg = AIAssistant error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_ASSISTANT_ERROR;
/// TUNIPluginCode_BizKIT_AI_ASR_ERROR = 30014, msg = ASR error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_ASR_ERROR;
/// TUNIPluginCode_BizKIT_AI_WS_ERROR = 30015, msg = WebSocket error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_WS_ERROR;
/// TUNIPluginCode_BizKIT_NG_RAWKEY_ERROR = 30016, msg = ng rawkey error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_NG_RAWKEY_ERROR;
/// TUNIPluginCode_BizKIT_NG_PRIVATE_ERROR = 30017, msg = can't access private data
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_NG_PRIVATE_ERROR;
/// TUNIPluginCode_BizKIT__NOT_SUPPORT_THRID_LOGIN = 30018, msg = share not support thrid login
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT__NOT_SUPPORT_THRID_LOGIN;
/// TUNIPluginCode_BizKIT__NOT_SUPPORT_INPUT_CHANNEL = 30019, msg = share not support input channel
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT__NOT_SUPPORT_INPUT_CHANNEL;
/// TUNIPluginCode_BizKIT__THRID_LOGIN_ALREADY_BIND = 30020, msg = Thrid login already bind
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT__THRID_LOGIN_ALREADY_BIND;
/// TUNIPluginCode_BizKIT_THRID_LOGIN_NOT_SUPPORT_CHANNEL = 30021, msg = Thrid login not support channel
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_THRID_LOGIN_NOT_SUPPORT_CHANNEL;
/// TUNIPluginCode_BizKIT_THRID_LOGIN_NOT_BIND = 30022, msg = Thrid login not bind
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_THRID_LOGIN_NOT_BIND;
/// TUNIPluginCode_BizKIT_THRID_LOGIN_BIND_CANCELED = 30023, msg = Thrid login bind canceled
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_THRID_LOGIN_BIND_CANCELED;
/// TUNIPluginCode_BizKIT_VIDEO_UPLOAD_FAILED = 30024, msg = video upload failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_VIDEO_UPLOAD_FAILED;
/// TUNIPluginCode_BizKT_UNREAD_COUNT_FETCH_FAILD = 30030, msg = message center unread count or feedback unread count fetch failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKT_UNREAD_COUNT_FETCH_FAILD;
/// TUNIPluginCode_BizKT_LOG_UPLOAD_FAILED = 30040, msg = upload App log failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKT_LOG_UPLOAD_FAILED;
/// TUNIPluginCode_BizKT_LOG_UPLOAD_CANCELED = 30041, msg = upload App log canceled
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKT_LOG_UPLOAD_CANCELED;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_Start = 39000, msg = ------------------- BizKit AI Stream Kit 39000 Start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_Start;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_INTERNAL_ERROR = 39001, msg = ai stream internal error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_INTERNAL_ERROR;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_INVALID_PARAMS = 39002, msg = invalid params
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_INVALID_PARAMS;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_HTTP_REQUEST_FAIL = 39003, msg = http request fail
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_HTTP_REQUEST_FAIL;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_NOT_CONNECTED = 39004, msg = connection not connected
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_NOT_CONNECTED;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_SESSION_ID_INVALID = 39005, msg = session id invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_SESSION_ID_INVALID;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_EVENT_ID_INVALID = 39006, msg = event id invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_EVENT_ID_INVALID;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_DATA_CHANNEL_INVALID = 39007, msg = data channel invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_DATA_CHANNEL_INVALID;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_DATA_PACKET_INVALID = 39008, msg = data packet invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_DATA_PACKET_INVALID;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_FILE_READ_ERROR = 39009, msg = file read error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_FILE_READ_ERROR;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_SEND_DATA_PACKET_ERROR = 39010, msg = send data packet error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_SEND_DATA_PACKET_ERROR;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_SESSION_BREAK_ERROR = 39011, msg = session break error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_SESSION_BREAK_ERROR;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_CONNECTION_BREAK_ERROR = 39012, msg = connection break error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_CONNECTION_BREAK_ERROR;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_IMAGE_FORMAT_ERROR = 39013, msg = the image format error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_IMAGE_FORMAT_ERROR;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_RECORDING_INIT_FAILED = 39014, msg = the recording initialization failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_RECORDING_INIT_FAILED;
/// TUNIPluginCode_BizKIT_AI_STREAM_KIT_DB_INIT_FAILED = 39015, msg = the db initialization failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_BizKIT_AI_STREAM_KIT_DB_INIT_FAILED;
/// TUNIPluginCode_MINIAPP_START_MARKER = 40000, msg = -------------- ThingMiniAppCore 40000 Start
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_START_MARKER;
/// TUNIPluginCode_MINIAPP_NAVIGATOR_BACK_FAIL = 40001, msg = the last page cannot be navigator back
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_NAVIGATOR_BACK_FAIL;
/// TUNIPluginCode_MINIAPP_NAVIGATOR_PAGE_NOT_FOUND = 40002, msg = the page not be found
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_NAVIGATOR_PAGE_NOT_FOUND;
/// TUNIPluginCode_MINIAPP_ID_ERROR = 40003, msg = miniapp not exist
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_ID_ERROR;
/// TUNIPluginCode_MINIAPP_NAVIGATOR_TO_CANNOT_OPEN_TAB_URL = 40004, msg = navigatorTo cannot open tab url
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_NAVIGATOR_TO_CANNOT_OPEN_TAB_URL;
/// TUNIPluginCode_MINIAPP_REDIRECT_TO_TO_CANNOT_OPEN_TAB_URL = 40005, msg = redirectTo cannot open tab url
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_REDIRECT_TO_TO_CANNOT_OPEN_TAB_URL;
/// TUNIPluginCode_MINIAPP_MAX_PAGE_COUNT = 40006, msg = A maximum of ten pages can be opened
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_MAX_PAGE_COUNT;
/// TUNIPluginCode_MINIAPP_TAB_CONFIG_NOT_FOUND_URL = 40007, msg = cannot find page url from tab config
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_TAB_CONFIG_NOT_FOUND_URL;
/// TUNIPluginCode_MINIAPP_HAVE_NO_TAB_CONFIG = 40008, msg = no tab config
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_HAVE_NO_TAB_CONFIG;
/// TUNIPluginCode_MINIAPP_AlREADY_OPEN = 40009, msg = miniapp already been open, cannot be open again
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_AlREADY_OPEN;
/// TUNIPluginCode_MINIAPP_EXIT_ERROR = 40010, msg = miniapp can not be exit
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_EXIT_ERROR;
/// TUNIPluginCode_MINIAPP_SWITCHTAB_NOT_SUPPORT_ON_TAB = 40011, msg = miniapp can not support on tab
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_SWITCHTAB_NOT_SUPPORT_ON_TAB;
/// TUNIPluginCode_MINIAPP_INVALID_DOMAIN = 40012, msg = request domain invalid
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_INVALID_DOMAIN;
/// TUNIPluginCode_MINIAPP_DOMAIN_UNCONFIGURED = 40013, msg = domain is not configured, please configure it on the platform
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_DOMAIN_UNCONFIGURED;
/// TUNIPluginCode_MINIAPP_API_UNCONFIGURED = 40014, msg = api is not configured, please configure it on the platform
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_API_UNCONFIGURED;
/// TUNIPluginCode_MINIAPP_HIGHWAY_REQUEST_ERROR = 40015, msg = miniapp highway request error
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_HIGHWAY_REQUEST_ERROR;
/// TUNIPluginCode_MINIAPP_ROUTER_NAME_UNCONFIGURED = 40016, msg = router name is not configured, please configure it in the app.json
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_ROUTER_NAME_UNCONFIGURED;
/// TUNIPluginCode_MINIAPP_CAN_NOT_NAVIGATE_BACK = 40017, msg = navigate back event already been intercept
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_CAN_NOT_NAVIGATE_BACK;
/// TUNIPluginCode_MINIAPP_AUTH_CODE_FAIL = 40018, msg = query auth code fail
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_AUTH_CODE_FAIL;
/// TUNIPluginCode_MINIAPP_EXT_API_NOT_FOUND = 40019, msg = ext api not found
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_EXT_API_NOT_FOUND;
/// TUNIPluginCode_MINIAPP_EXT_API_FAIL = 40020, msg = ext api fail
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_EXT_API_FAIL;
/// TUNIPluginCode_MINIAPP_ORIENTATION_NOT_SUPPORT = 40021, msg = this page is not support set orientation
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_ORIENTATION_NOT_SUPPORT;
/// TUNIPluginCode_MINIAPP_MENU_BUTTON_CAN_NOT_HIDE = 40022, msg = this page can not hide menu button
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_MENU_BUTTON_CAN_NOT_HIDE;
/// TUNIPluginCode_MINIAPP_ILLEGAL_PERMISSION = 40023, msg = illegal permission name
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_ILLEGAL_PERMISSION;
/// TUNIPluginCode_MINIAPP_PERMISSION_DENIED_BY_USER = 40024, msg = permission has been denied by user
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_PERMISSION_DENIED_BY_USER;
/// TUNIPluginCode_MINIAPP_PERMISSION_DID_NOT_APPLY_THROUGH_AUTHORIZE_API = 40025, msg = permission did not apply through authorize api
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_PERMISSION_DID_NOT_APPLY_THROUGH_AUTHORIZE_API;
/// TUNIPluginCode_MINIAPP_OPEN_THIRD_APP_URL_FAIL = 40026, msg = open url fail, not exist app can open it.
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_OPEN_THIRD_APP_URL_FAIL;
/// TUNIPluginCode_MINIAPP_API_NO_PERMISSION = 40027, msg = Not authorized to call this api
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_API_NO_PERMISSION;
/// TUNIPluginCode_MINIAPP_FILE_PATH_THROUGH_FAIL = 40028, msg = File path through
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_FILE_PATH_THROUGH_FAIL;
/// TUNIPluginCode_MINIAPP_TAB_COMMON_CONTAINER_DID_NOT_RELAUNCH = 40029, msg = Tab common container not allowed relaunch
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_TAB_COMMON_CONTAINER_DID_NOT_RELAUNCH;
/// TUNIPluginCode_MINIAPP_TAB_COMMON_CONTAINER_DID_NOT_REDIRECT = 40030, msg = Tab common container not allowed redirect
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MINIAPP_TAB_COMMON_CONTAINER_DID_NOT_REDIRECT;
/// TUNIPluginCode_FEATURE_START_MARKER = 50000, msg = -------------- Independent service module 50000 Start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_FEATURE_START_MARKER;
/// TUNIPluginCode_MAPKIT_NO_LOCATION_PERMISSION = 50001, msg = No location permission
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_NO_LOCATION_PERMISSION;
/// TUNIPluginCode_MAPKIT_FAIL_GET_LOCATION = 50002, msg = Failed to get location
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_FAIL_GET_LOCATION;
/// TUNIPluginCode_MAPKIT_INCORRECT_PARAM = 50003, msg = The parameter format is incorrect
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_INCORRECT_PARAM;
/// TUNIPluginCode_MAPKIT_GEOFENCE_HAS_NO_REGISTERS = 50004, msg = Has no geofence register
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_GEOFENCE_HAS_NO_REGISTERS;
/// TUNIPluginCode_MAPKIT_FAIL_GET_GEOFENCE_COUNT = 50005, msg = Failed to get geofence count
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_FAIL_GET_GEOFENCE_COUNT;
/// TUNIPluginCode_MAPKIT_FAIL_REGISTER_GEOFENCE = 50006, msg = Failed to register geofence
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_FAIL_REGISTER_GEOFENCE;
/// TUNIPluginCode_MAPKIT_FAIL_UNREGISTER_GEOFENCE = 50007, msg = Failed to unregister geofence
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_FAIL_UNREGISTER_GEOFENCE;
/// TUNIPluginCode_MAPKIT_GEOFENCE_NO_SUPPORT = 50008, msg = This error is triggered when the geofencing feature is not enabled. Geofencing is a premium service that requires activation. If not activated, this error will be returned.
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_GEOFENCE_NO_SUPPORT;
/// TUNIPluginCode_MAPKIT_GEOFENCE_MAX_LIMIT_EXCEEDED = 50009, msg = Triggered when the maximum number of geofences is exceeded. This error occurs if the user tries to create more geofences than allowed.
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_GEOFENCE_MAX_LIMIT_EXCEEDED;
/// TUNIPluginCode_MAPKIT_GEOFENCE_UNKNOW_BUSINESS_TYPE = 50010, msg = Geofence class's businessType parameter received an unsupported type
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_MAPKIT_GEOFENCE_UNKNOW_BUSINESS_TYPE;
/// TUNIPluginCode_HOMEKIT_START_MARKER = 60000, msg = -------------- Home trade Power 60000 start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_HOMEKIT_START_MARKER;
/// TUNIPluginCode_HOMEKIT_GET_DEVICE_ROOM_INFO_ERROR = 60001, msg = Get device room info failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_HOMEKIT_GET_DEVICE_ROOM_INFO_ERROR;
/// TUNIPluginCode_HOMEKIT_SWITCH_DEVICE_ROOM_ERROR = 60002, msg = Switch device room failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_HOMEKIT_SWITCH_DEVICE_ROOM_ERROR;
/// TUNIPluginCode_HOMEKIT_PAYMENT_CONTROL_ENTRY_NOT_FOUND_ERROR = 60003, msg = payment control entry not found
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_HOMEKIT_PAYMENT_CONTROL_ENTRY_NOT_FOUND_ERROR;
/// TUNIPluginCode_P2P_FILE_TRANSFER = 70000, msg = -------------- p2p file transfer capability 70000 Start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_FILE_TRANSFER;
/// TUNIPluginCode_P2P_CONNECTING = 70001, msg = P2P connection in progress
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_CONNECTING;
/// TUNIPluginCode_P2P_CONNECT_FAIL = 70002, msg = P2P connection failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_CONNECT_FAIL;
/// TUNIPluginCode_P2P_CONNECT_NOT = 70003, msg = P2P is not connected
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_CONNECT_NOT;
/// TUNIPluginCode_P2P_UPLOADING = 70101, msg = Other files are being uploaded
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_UPLOADING;
/// TUNIPluginCode_P2P_UPLOAD_FAIL = 70102, msg = File upload failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_UPLOAD_FAIL;
/// TUNIPluginCode_P2P_UPLOAD_CANCEL_FAIL = 70103, msg = File upload cancellation failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_UPLOAD_CANCEL_FAIL;
/// TUNIPluginCode_P2P_FILE_QUERYING = 70110, msg = On querying file
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_FILE_QUERYING;
/// TUNIPluginCode_P2P_FILE_QUERY_FAIL = 70111, msg = File query failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_FILE_QUERY_FAIL;
/// TUNIPluginCode_P2P_DOWNLOADING = 70112, msg = Other files are being downloaded
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_DOWNLOADING;
/// TUNIPluginCode_P2P_DOWNLOAD_FAIL = 70113, msg = File download failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_DOWNLOAD_FAIL;
/// TUNIPluginCode_P2P_DOWNLOAD_CANCEL_FAIL = 70114, msg = File download cancellation failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_P2P_DOWNLOAD_CANCEL_FAIL;
/// TUNIPluginCode_IPCKIT_PARAMS_INVALID = 80000, msg = -------------- IPC Power 80000 Start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_IPCKIT_PARAMS_INVALID;
/// TUNIPluginCode_IPCKIT_ACCEPT_DOORBELL_CALL_FAIL = 80001, msg = accept doorbell call failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_IPCKIT_ACCEPT_DOORBELL_CALL_FAIL;
/// TUNIPluginCode_IPCKIT_HANGUP_DOORBELL_CALL_FAIL = 80002, msg = hangup doorbell call failed
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_IPCKIT_HANGUP_DOORBELL_CALL_FAIL;
/// TUNIPluginCode_DEVELOPER_START_MARKER = 100000, msg = -------------- DEVELOPER Power 100000 Start ----------------
FOUNDATION_EXPORT TUNIPluginMsg const _Nonnull TUNIPluginMsg_DEVELOPER_START_MARKER;

@interface TUNICode : NSObject
+ (nullable TUNIPluginMsg)msgWithCode:(TUNIPluginCode)code;
@end

