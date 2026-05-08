//
//  ThingSmartMbedTLS.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#if TARGET_OS_IOS

#import <Foundation/Foundation.h>

//@import MbedTLS;

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartMbedTLS;
@protocol ThingSmartMbedTLSDelegate <NSObject>
@optional
/// the progross is beginning
/// @param mbedtls mbedtls
- (void)mbedTLSDidBeginning:(ThingSmartMbedTLS *)mbedtls;

/// the progross is ending
/// @param mbedtls mbedtls
- (void)mbedTLSDidEnding:(ThingSmartMbedTLS *)mbedtls;

///  Completion of establishes a TCP connection.
/// @param mbedtls mbedtls
- (void)mbedTLSDidConnected:(ThingSmartMbedTLS *)mbedtls;

/// Encounter an error, TLS be close
/// @param mbedtls mbedtls
/// @param error error
- (void)mbedTLS:(ThingSmartMbedTLS *)mbedtls didCloseWithError:(NSError *)error;

/// Completion of handshaking. Next, can send request by tls
/// @param mbedtls mbedtls
- (void)mbedTLSDidHandshake:(ThingSmartMbedTLS *)mbedtls;

/// Completion of sending data
/// Please don't use「startReceiveData」anymore the「success」block of the method 「sendTLSDataWithType」, if the call is called in「startReceiveData」this callback
/// @param mbedtls mbedtls
- (void)mbedTLSDidWrite:(ThingSmartMbedTLS *)mbedtls;

/// Completion of sending data
/// @param mbedtls mbedtls
- (void)mbedTLS:(ThingSmartMbedTLS *)mbedtls didWriteFailedWithData:(NSData *)data;

/// Receive data by tls
/// @param mbedtls mbedtls
/// @param data the response
- (void)mbedTLS:(ThingSmartMbedTLS *)mbedtls didReceiveData:(NSData *)data;

/// Receive data by tls
/// @param mbedtls mbedtls
/// @param error the cause of the error in receiving data
- (void)mbedTLS:(ThingSmartMbedTLS *)mbedtls didReceiveFailedWithError:(NSError *)error;
@end


@interface ThingSmartMbedTLS : NSObject
@property (nonatomic, strong) NSString *lpv;
@property (nonatomic, weak) id<ThingSmartMbedTLSDelegate> delegate;
// Set whether the certificate is available
@property (nonatomic, assign) BOOL enableCertificates;

// request all supported cipher suites
- (NSArray *)allowCipherSuites;

// Establishes a TCP connection.
- (void)initTcpClientWithHost:(NSString *)host;

- (void)initTcpClientWithHost:(NSString *)host success:(nullable void(^)(void))success failure:(nullable void(^)(NSError * _Nullable error))failure;

- (void)initTcpClientWithHost:(NSString *)host port:(NSString *)port success:(nullable void(^)(void))success failure:(nullable void(^)(NSError * _Nullable error))failure;

- (void)startHandshakeWithPers:(NSString *)pers psk:(NSData *)psk pskIdentity:(NSString *)pskIdentity;


/// Send a message By TLS.
/// @param type the instruction type
/// @param encryptData the message data
- (void)sendTLSDataWithType:(int)type encryptDatas:(NSData *)encryptData;


/// Send a message By TLS.
/// @param type the instruction type
/// @param encryptData the message data
/// @param success the success block, if called「startReceiveData」in the delegate「mbedTLSDidWrite」，Please don't call「startReceiveData」anymore
/// @param failure the failure block
- (void)sendTLSDataWithType:(int)type encryptDatas:(NSData *)encryptData success:(nullable void (^)(void))success failure:(nullable void (^)(NSError *))failure;

- (NSData *)genPSKKeyWithPwd:(NSString *)pwd salt:(NSString *)salt iterations:(int)iterations keyLength:(int)keyLength;


/// Receive a message By TLS
- (void)startReceiveData;


- (bool)hasTcpConnection;


// Closes all connections.
- (void)closeAllTcpClient;

@end

NS_ASSUME_NONNULL_END

#endif
