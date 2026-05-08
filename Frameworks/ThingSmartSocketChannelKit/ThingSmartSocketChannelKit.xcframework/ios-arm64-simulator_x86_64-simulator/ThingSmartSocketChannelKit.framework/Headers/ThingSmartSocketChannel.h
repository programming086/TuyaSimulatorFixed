
#import <Foundation/Foundation.h>
#import <ThingSmartSocketChannelKit/ThingSmartSocketReadModel.h>
#import <ThingSmartSocketChannelKit/ThingSmartSocketWriteModel.h>

// The protocol.
#define SOCKET_TYPE_BROADCAST             0x00
#define SOCKET_TYPE_BROADCAST_V4          0x13
#define SOCKET_TYPE_BROADCAST_V34         0x23
#define SOCKET_TYPE_AP_ERROR              0x15
#define SOCKET_TYPE_AP_CONFIG             0x01
#define SOCKET_TYPE_AP_ACTIVATE           0x02
#define SOCKET_TYPE_DP_PUBLISH            0x07
#define SOCKET_TYPE_DP_REPORT             0x08
#define SOCKET_TYPE_HEARTBEAT             0x09
#define SOCKET_TYPE_QUERY_DEV_INFO        0x0a
#define SOCKET_TYPE_QUERY_SSID_LIST       0x0b
#define SOCKET_TYPE_DP_CAD_PUBLISH        0x0d
#define SOCKET_TYPE_LOCL_SCENE_EXE        0x11
#define SOCKET_TYPE_ENABLE_LOG            0x20
#define SOCKET_TYPE_BIND_TOKEN            0x0c
#define SOCKET_TYPE_ACTIVE_SUBDEV         0x0e
#define SOCKET_TYPE_QUERY_CAD_DEV_INFO    0x10
#define SOCKET_TYPE_INITIATIVE_QUERY_DPS  0x12
#define SOCKET_TYPE_AP_CONFIG             0x01
#define SOCKET_TYPE_AP_CONFIG_NEW         0x14
#define SOCKET_TYPE_AP_CONFIG_BROADCAST   0x11
#define SOCKET_TYPE_AP_CONFIG_TLS_BROADCAST   0x31

#define SOCKET_TYPE_HANDSHAKE_RAND_A      0x03
#define SOCKET_TYPE_HANDSHAKE_RAND_B      0x04
#define SOCKET_TYPE_HANDSHAKE_RAND_ACK_B  0x05

#define SOCKET_TYPE_IPC_AP_SET_PWD        0x21
#define SOCKET_TYPE_AP_SEND_PSK_V30       0x24
#define SOCKET_TYPE_BROADCAST_APP_SEND    0x25

#define SOCKET_TYPE_EXTENSION             0x40

#define SOCKET_TYPE_FOR_ACTIVE_EXTENSION  0x42

#pragma mark - ap direct
#define SOCKET_TYPE_AP_QUERY_DEV_INFO     0x16
#define SOCKET_TYPE_AP_CONFIG_SCHEMA      0x17
#define SOCKET_TYPE_AP_CONFIG_TIME        0x18

#define SOCKET_TYPE_AP_OTA_START          0x1a
#define SOCKET_TYPE_AP_OTA_DATA           0x1b
#define SOCKET_TYPE_AP_OTA_END            0x1c
#define SOCKET_TYPE_AP_DEVICE_RESET       0x1d

@class ThingSmartSocketChannel;

@protocol ThingSmartSocketChannelDelegate <NSObject>

@optional

#pragma mark - TCP Delegate

// The TCP connection is successful.
- (void)socketDidTcpConnected:(ThingSmartSocketChannel *)socket devId:(NSString *)devId;

// Receives a TCP message.
- (void)socket:(ThingSmartSocketChannel *)socket didReceiveTcpData:(ThingSmartSocketReadModel *)tcpData tag:(long)tag devId:(NSString *)devId;

// Closes the TCP connection.
- (void)socketDidTcpDisconnect:(ThingSmartSocketChannel *)socket devId:(NSString *)devId error:(NSError *)error;


#pragma mark - UDP Delegate

// Receives a UDP message.
- (void)socket:(ThingSmartSocketChannel *)socket didReceiveUdpData:(ThingSmartSocketReadModel *)udpData;

// Closes a UDP connection.
- (void)socketDidUdpClose:(ThingSmartSocketChannel *)socket error:(NSError *)error;

// Closes a UDP connection.
- (void)socketDidUdpClose:(ThingSmartSocketChannel *)socket port:(NSInteger)port error:(NSError *)error;

@end

@interface ThingSmartSocketChannel : NSObject

+ (instancetype)sharedInstance;

/**
 *  A list of inactive devices.
 */
@property (nonatomic, strong) ThingSDKSafeMutableDictionary   *inactiveDevices;

@property (nonatomic, strong) ThingSDKSafeMutableDictionary    *HKDFDic;

#pragma mark - config keys

// config keys 
- (void)configKeys:(NSData *)zigbeeKey broadcastKey:(NSData *)broadcastKey sendKey:(NSData *)sendKey;

#pragma mark - TCP

// Establishes a TCP connection.
- (void)initTcpClientWithHost:(NSString *)host devInfo:(NSDictionary *)devInfo;

// Sends a TCP message.
- (void)sendTcpRequest:(ThingSmartSocketWriteModel *)request
               success:(ThingSuccessDict)success
               failure:(ThingFailureHandler)failure __deprecated_msg("This method is deprecated, Use sendTcpWithRequest:success:failure: instead");

// Sends a TCP message.
- (void)sendTcpWithRequest:(ThingSmartSocketWriteModel *)request
                   success:(ThingSuccessDict)success
                   failure:(ThingFailureError)failure;

- (void)removeInactiveDevice:(NSString *)gwId;

- (void)removeAllInactiveDevice;

// Indicates whether the TCP connection is established.
- (BOOL)hasTcpClientWithDevId:(NSString *)devId;

// Closes a TCP connection.
- (void)closeTcpClientWithDevId:(NSString *)devId;

// Closes all TCP connections.
- (void)closeAllTcpClient;

#pragma mark - UDP

// Initializes a UDP server.
- (void)initUdpServerWithPort:(NSInteger)port;

// Sends a UDP message.
- (void)sendUdpRequestWithHost:(NSString *)host port:(NSInteger)port type:(int)type body:(NSDictionary *)body success:(ThingSuccessHandler)success failure:(ThingFailureHandler)failure;

- (void)sendUdpRequestWithHost:(NSString *)host port:(NSInteger)port type:(int)type body:(NSDictionary *)body lpv:(NSString *)lpv success:(ThingSuccessHandler)success failure:(ThingFailureHandler)failure;

// Closes a UDP server.
- (void)closeUdpServerWithPort:(uint16_t)port;

#pragma mark - Delegate

// Adds a socket channel delegate.
- (void)addDelegate:(id<ThingSmartSocketChannelDelegate>)delegate;

// Removes a socket channel delegate.
- (void)removeDelegate:(id<ThingSmartSocketChannelDelegate>)delegate;

@end

