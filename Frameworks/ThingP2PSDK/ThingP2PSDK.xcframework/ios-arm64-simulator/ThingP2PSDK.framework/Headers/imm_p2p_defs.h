#ifndef __IMM_P2P_DEFS_H__
#define __IMM_P2P_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define IMM_P2P_ID_LEN_MAX 80
#define IMM_P2P_CHANNEL_NUMBER_MAX 330
#define IMM_P2P_SESSION_NUMBER_MAX 1024
#define IMM_P2P_VIDEO_BITRATE_MIN (600)
#define IMM_P2P_VIDEO_BITRATE_MAX (4000)

#define IMM_P2P_ERROR_SUCCESSFUL                               0
#define IMM_P2P_ERROR_NOT_INITIALIZED                          -1
#define IMM_P2P_ERROR_ALREADY_INITIALIZED                      -2
#define IMM_P2P_ERROR_TIME_OUT                                 -3
#define IMM_P2P_ERROR_INVALID_ID                               -4
#define IMM_P2P_ERROR_INVALID_PARAMETER                        -5
#define IMM_P2P_ERROR_DEVICE_NOT_ONLINE                        -6
#define IMM_P2P_ERROR_FAIL_TO_RESOLVE_NAME                     -7
#define IMM_P2P_ERROR_INVALID_PREFIX                           -8
#define IMM_P2P_ERROR_ID_OUT_OF_DATE                           -9
#define IMM_P2P_ERROR_NO_RELAY_SERVER_AVAILABLE                -10
#define IMM_P2P_ERROR_INVALID_SESSION_HANDLE                   -11
#define IMM_P2P_ERROR_SESSION_CLOSED_REMOTE                    -12
#define IMM_P2P_ERROR_SESSION_CLOSED_TIMEOUT                   -13
#define IMM_P2P_ERROR_SESSION_CLOSED_CALLED                    -14
#define IMM_P2P_ERROR_REMOTE_SITE_BUFFER_FULL                  -15
#define IMM_P2P_ERROR_USER_LISTEN_BREAK                        -16
#define IMM_P2P_ERROR_MAX_SESSION                              -17
#define IMM_P2P_ERROR_UDP_PORT_BIND_FAILED                     -18
#define IMM_P2P_ERROR_USER_CONNECT_BREAK                       -19
#define IMM_P2P_ERROR_SESSION_CLOSED_INSUFFICIENT_MEMORY       -20
#define IMM_P2P_ERROR_INVALID_APILICENSE                       -21
#define IMM_P2P_ERROR_FAIL_TO_CREATE_THREAD                    -22
#define IMM_P2P_ERROR_OUT_OF_SESSION                           -23
#define IMM_P2P_ERROR_INVALID_PRE_SESSION                      -24
#define IMM_P2P_ERROR_PRE_SESSION_NOT_CONNECTED                -25
#define IMM_P2P_ERROR_PRE_SESSION_ALREADY_ACTIVE               -26
#define IMM_P2P_ERROR_PRE_SESSION_NOT_ACTIVE                   -27
#define IMM_P2P_ERROR_PRE_SESSION_SUSPENDED                    -28
#define IMM_P2P_ERROR_OUT_OF_MEMORY                            -29
#define IMM_P2P_ERROR_HTTP_FAILED                              -30
#define IMM_P2P_ERROR_PRECONNECT_UNSUPPORTED                   -31
#define IMM_P2P_ERROR_DTLS_HANDSHAKE_FAILED_FINGERPRINT        -32
#define IMM_P2P_ERROR_GET_TOKEN_TIMEOUT                        -33
#define IMM_P2P_ERROR_AUTH_FAILED                              -34
#define IMM_P2P_ERROR_INIT_MBEDTLS_MD_AND_AES_FAILED           -35
#define IMM_P2P_ERROR_HEARTBEAT_TIMEOUT                        -36
#define IMM_P2P_ERROR_DTLS_HANDSHAKE_FAILED                    -37
#define IMM_P2P_ERROR_DTLS_HANDSHAKE_TIMEOUT                   -38
#define IMM_P2P_ERROR_REMOTE_NO_RESPONSE                       -39
#define IMM_P2P_ERROR_PRE_SESSION_RESERVE_TIMEOUT              -40
#define IMM_P2P_ERROR_RESET                                    -41
#define IMM_P2P_ERROR_UV_TIMER_INIT_FAILED                     -42
#define IMM_P2P_ERROR_SDP_INIT_FAILED                          -43
#define IMM_P2P_ERROR_SDP_ADD_MEDIA_FAILED                     -44
#define IMM_P2P_ERROR_SDP_ADD_CODEC_FAILED                     -45
#define IMM_P2P_ERROR_CHANNEL_INIT_FAILED                      -46
#define IMM_P2P_ERROR_INVALID_AES_KEY                          -47
#define IMM_P2P_ERROR_SDP_SET_AES_KEY_FAILED                   -48
#define IMM_P2P_ERROR_INVALID_TOKEN                            -49
#define IMM_P2P_ERROR_TIME_OUT_NO_ANSWER                       -50
#define IMM_P2P_ERROR_TIME_OUT_LOCAL_NO_HOST_CAND              -51
#define IMM_P2P_ERROR_TIME_OUT_LOCAL_NAT                       -52
#define IMM_P2P_ERROR_TIME_OUT_REMOTE_NAT                      -53
#define IMM_P2P_ERROR_TIME_COWBOY_NO_RESPONSE                  -54
#define IMM_P2P_ERROR_TOKEN_EXPIRED                            -55
#define IMM_P2P_ERROR_TOKEN_DEVICE_NOTMATCH                    -56
#define IMM_P2P_ERROR_TOKEN_AUTH_FAILED                        -57
#define IMM_P2P_ERROR_MQTT_SEND_FAILED                         -58
// Publish | Subscribe | Unsubscribe failed, due to the MQTT channel not yet connected.
// private static final String MQTT_ERROR_CODE_NOT_CONNECT = "6000";
#define IMM_P2P_ERROR_MQTT_NOT_CONNECT                         -60
// MQTT broker acknowledged that the subscription to the topic failed.
// private static final String MQTT_ERROR_CODE_ACK_FAIL = "6001";
#define IMM_P2P_ERROR_MQTT_ACK_FAIL                            -61
// Encode message data failed.
// private static final String MQTT_ERROR_CODE_ENCODE_FAIL = "6002";
#define IMM_P2P_ERROR_MQTT_ENCODE_FAIL                         -62
// Publish message failed due to a timeout for MQTT Broker Ack.
// private static final String MQTT_ERROR_CODE_PUB_ACK_TIMEOUT = "6003";
#define IMM_P2P_ERROR_MQTT_PUB_ACK_TIMEOUT                     -63
// Publish message failed because the topic is not yet subscribed.
// private static final String MQTT_ERROR_CODE_PUB_FAIL_NOT_SUB = "6004";
#define IMM_P2P_ERROR_MQTT_PUB_FAIL_NOT_SUB                    -64
// Publish message failed for a general reason. (see the `error.userInfo[NSUnderlyingErrorKey]`)
// private static final String MQTT_ERROR_CODE_PUB_FAIL_GENERAL = "6005";
#define IMM_P2P_ERROR_MQTT_PUB_FAIL_GENERAL                    -65
// Subscribe failed for a general reason.
// private static final String MQTT_ERROR_CODE_SUB_FAIL_GENERAL = "6006";
#define IMM_P2P_ERROR_MQTT_SUB_FAIL_GENERAL                    -66

// Device-specific errors
#define IMM_P2P_ERROR_DEVICE_SECRET_MODE                       -102
#define IMM_P2P_ERROR_DEVICE_CREATE_SEND_THREAD_FAILED         -103
#define IMM_P2P_ERROR_DEVICE_OUT_OF_SESSION                    -104
#define IMM_P2P_ERROR_DEVICE_AUTH_FAILED                       -105
#define IMM_P2P_ERROR_DEVICE_SESSION_CLOSED                    -106
#define IMM_P2P_ERROR_DEVICE_CREATE_WEBRTC_THREAD_FAILED       -107
#define IMM_P2P_ERROR_DEVICE_ZOMBI_SESSION                     -108
#define IMM_P2P_ERROR_DEVICE_USER_CLOSE                        -109
#define IMM_P2P_ERROR_DEVICE_USER_EXIT                         -110
#define IMM_P2P_ERROR_DEVICE_IN_SECRET_MODE                    -111
#define IMM_P2P_ERROR_DEVICE_CALLING                           -113
#define IMM_P2P_ERROR_DEVICE_WEBRTC_EXIT                       -300
#define IMM_P2P_ERROR_REMOTE                                   -100

typedef enum imm_p2p_rtc_log_level {
    IMM_P2P_LOG_TRACE,
    IMM_P2P_LOG_DEBUG,
    IMM_P2P_LOG_INFO,
    IMM_P2P_LOG_WARN,
    IMM_P2P_LOG_ERROR,
    IMM_P2P_LOG_FATAL
}imm_p2p_rtc_log_level_e;

typedef enum imm_p2p_rtc_security_level {
    IMM_P2P_SECURITY_LEVEL_0,
    IMM_P2P_SECURITY_LEVEL_1,
    IMM_P2P_SECURITY_LEVEL_2,
    IMM_P2P_SECURITY_LEVEL_3,
    IMM_P2P_SECURITY_LEVEL_4,
    IMM_P2P_SECURITY_LEVEL_5,
    /*************************/
    IMM_P2P_SECURITY_LEVEL_MAX
}imm_p2p_rtc_security_level_e;

typedef enum {
    imm_p2p_rtc_frame_type_audio,
    imm_p2p_rtc_frame_type_video_p,
    imm_p2p_rtc_frame_type_video_i
}imm_p2p_rtc_frame_type_e;

typedef enum imm_p2p_rtc_connection_type {
    imm_p2p_rtc_connection_type_p2p,
    imm_p2p_rtc_connection_type_webrtc
}imm_p2p_rtc_connection_type_e;

typedef enum {
    imm_p2p_rtc_upnp_port_protocol_udp,
    imm_p2p_rtc_upnp_port_protocol_tcp
}imm_p2p_rtc_upnp_port_protocol;

typedef struct imm_p2p_rtc_audio_codec {
    char name[64];
    int sample_rate;
    int channel_number;
}imm_p2p_rtc_audio_codec_t;

typedef struct imm_p2p_rtc_video_codec {
    char name[64];
    int clock_rate;
}imm_p2p_rtc_video_codec_t;

typedef struct {
    char *buf;
    uint32_t size;
    uint32_t len;
    uint64_t pts;
    uint64_t timestamp;
    imm_p2p_rtc_frame_type_e frame_type;
}imm_p2p_rtc_frame_t;

typedef enum rtc_state {
    RTC_STATE_GET_TOKEN,
    RTC_STATE_P2P_CONNECT,
    RTC_STATE_DTLS_SRTP_KEY_NEGO,
    RTC_STATE_STREAM,
    RTC_STATE_FAILED,
    RTC_STATE_NUMBER,
}rtc_state_e;

typedef enum {
    RTC_PRE_NOT_ACTIVE = 0,
    RTC_PRE_ACTIVATING,
    RTC_PRE_ACTIVE,
    RTC_PRE_SUSPENDING
}rtc_active_state_e;

typedef enum {
    RTC_CONNECTION_MODE_UNKNOWN = 0,
    RTC_CONNECTION_MODE_P2P,
    RTC_CONNECTION_MODE_RELAY
}rtc_connection_mode_e;

typedef struct {
    int32_t handle;
    int32_t is_pre;
    rtc_state_e state;
    rtc_active_state_e active_state;
    imm_p2p_rtc_connection_type_e connection_type;
    imm_p2p_rtc_audio_codec_t audio_codec;
    imm_p2p_rtc_video_codec_t video_codec;
    char trace_id[128];
    char session_id[64];
    char sub_dev_id[64];
    int32_t stream_type; // Stream type: 0 -- Main stream, 1 -- Sub stream
    int32_t is_replay;
    char start_time[32];
    char end_time[32];
}imm_p2p_rtc_session_info_t;

// imm p2p sdk relies on several external services, implemented via callbacks or interfaces:
//  1. Signaling Sending
//      When imm p2p sdk needs to send signaling, it calls the user-implemented imm_p2p_rtc_signaling_cb_t to send
//  2. Signaling Reception
//      When the application receives signaling, it should use the imm_p2p_rtc_set_signaling interface to set it in the imm p2p sdk
//  3. HTTP Service
//      When imm p2p sdk needs to send logs, it calls the user-implemented imm_p2p_rtc_log_cb_t to send

// Signaling callback, used for sending signaling
// remote_id: indicates signaling is sent to remote_id
// signaling: starting address of signaling content
// len: length of signaling content
typedef void (*imm_p2p_rtc_signaling_cb_t)(char *remote_id, char *signaling, uint32_t len);

// Log callback, used for sending logs
// log: starting address of log content
// len: length of log content
// flags: 0- do not upload to cloud, 1- upload to cloud
typedef void (*imm_p2p_rtc_log_cb_t)(char *log, uint32_t len, uint32_t flags);

// Authentication callback, used to validate if the offer is legal
// Use hmac-sha256 to compute hash for the content of buf, then compute base64 encoding for the hash result,
// Computation method: base64(hmac-sha256(key=password, content=buf, length=len))
// Compare the result with md, return 0 if same, otherwise return -1
typedef int32_t (*imm_p2p_rtc_auth_cb_t)(char *buf, uint32_t len, char *md, uint32_t md_len);

// HTTP callback, used for sending HTTP requests
// api: name of HTTP interface
// devId: device ID
// content: request content
// content_len: length of content
typedef int32_t (*imm_p2p_rtc_http_cb_t)(char *api, char *devId, char *content, uint32_t content_len);

// Crypt callback function
// mode: "aes", "ecb", ...
// crypt: "encrypt", "decrypt"
typedef int (*imm_p2p_rtc_aes_create_cb_t)(void **handle, char *mode, char *crypt, char *key, int key_bits);
typedef int (*imm_p2p_rtc_aes_destroy_cb_t)(void *handle);
typedef int (*imm_p2p_rtc_aes_encrypt_cb_t)(void *handle, int length, char *iv, char *input, char *output);
typedef int (*imm_p2p_rtc_aes_decrypt_cb_t)(void *handle, int length, char *iv, char *input, char *output);

// UPNP callback functions
typedef int (*imm_p2p_rtc_upnp_alloc_port_cb_t)(imm_p2p_rtc_upnp_port_protocol protocol, int *local_port, char *address, int *port);
typedef int (*imm_p2p_rtc_upnp_release_port_cb_t)(imm_p2p_rtc_upnp_port_protocol protocol, int local_port);
typedef int (*imm_p2p_rtc_upnp_bind_result_cb_t)(imm_p2p_rtc_upnp_port_protocol protocol, int local_port, int error_code);

// Session state callback
typedef int (*imm_p2p_rtc_session_state_cb_t)(char *remote_id, int handle, int is_pre, rtc_state_e state, rtc_active_state_e active_state, int error);

// Localhost callback
// addresses size is 1024
typedef int (*imm_p2p_rtc_session_get_address_cb_t)(char *address);

typedef struct imm_p2p_rtc_cb{
    imm_p2p_rtc_signaling_cb_t on_signaling;       // Signaling callback, application layer sends signaling via MQTT
    imm_p2p_rtc_signaling_cb_t on_moto_signaling;  // Signaling callback, application layer sends signaling via MOTO
    imm_p2p_rtc_signaling_cb_t on_lan_signaling;   // Signaling callback, application layer sends signaling via LAN signaling channel
    imm_p2p_rtc_log_cb_t on_log;                   // Log callback, application layer uploads log content to cloud
    imm_p2p_rtc_auth_cb_t on_auth;                 // Authentication callback, used by device side
    imm_p2p_rtc_http_cb_t on_http;                 // HTTP callback, used by app side, called when imm p2p sdk needs HTTP interface
    struct {
        // External encryption/decryption interface, set to NULL if not needed
        imm_p2p_rtc_aes_create_cb_t on_create;
        imm_p2p_rtc_aes_destroy_cb_t on_destroy;
        imm_p2p_rtc_aes_encrypt_cb_t on_encrypt;
        imm_p2p_rtc_aes_decrypt_cb_t on_decrypt;
    }aes;
    struct {
        imm_p2p_rtc_upnp_alloc_port_cb_t on_alloc;
        imm_p2p_rtc_upnp_release_port_cb_t on_release;
        imm_p2p_rtc_upnp_bind_result_cb_t on_bind;
    }upnp;

    imm_p2p_rtc_session_state_cb_t on_session_state;
    imm_p2p_rtc_session_get_address_cb_t on_get_address;
}imm_p2p_rtc_cb_t;

typedef enum _OSTYPE_{
    IMM_UNKNOWN,
    IMM_IOS,
    IMM_ANDROID,
    IMM_WINDOWS,
}OSTYPE;
// P2P SDK initialization parameters
typedef struct imm_p2p_rtc_options{
    char local_id[IMM_P2P_ID_LEN_MAX];                     // Local ID, device side fills in device ID, client side fills in UID
    imm_p2p_rtc_cb_t cb;                                   // Callback interface
    uint32_t max_channel_number;                            // Maximum number of channels per connection
    uint32_t max_session_number;                            // Maximum number of simultaneous connections allowed
    uint32_t max_pre_session_number;                        // Maximum number of simultaneous pre-connections allowed
    uint32_t send_buf_size[IMM_P2P_CHANNEL_NUMBER_MAX];    // Send buffer size of each channel in bytes
    uint32_t recv_buf_size[IMM_P2P_CHANNEL_NUMBER_MAX];    // Receive buffer size of each channel in bytes
    uint32_t video_bitrate_kbps;                            // Video bitrate for device side, client side does not need to set it
    uint32_t preconnect_enable;                             // Enable pre-connection: 1 - Enable, 0 - Disable
    OSTYPE  os_type ;                                       // Operating system type
    char app_name[IMM_P2P_ID_LEN_MAX] ;                     // App version name, e.g., 5.17.0
    char app_version[IMM_P2P_ID_LEN_MAX] ;                  // App version number, e.g., 5.17.0
}imm_p2p_rtc_options_t;

#ifdef __cplusplus
}
#endif

#endif
