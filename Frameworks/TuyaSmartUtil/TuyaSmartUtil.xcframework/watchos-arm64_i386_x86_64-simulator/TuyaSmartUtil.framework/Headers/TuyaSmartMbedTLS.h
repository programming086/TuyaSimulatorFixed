//
//  TuyaSmartMbedTLS.h
//  Pods
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#if TARGET_OS_IOS

#import <Foundation/Foundation.h>

//@import MbedTLS;

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartMbedTLS;

@protocol TuyaSmartMbedTLSDelegate <NSObject>

/// the progross is beginning
/// @param mbedtls mbedtls
- (void)mbedTLSDidBeginning:(TuyaSmartMbedTLS *)mbedtls;

/// the progross is ending
/// @param mbedtls mbedtls
- (void)mbedTLSDidEnding:(TuyaSmartMbedTLS *)mbedtls;

///  Completion of establishes a TCP connection.
/// @param mbedtls mbedtls
- (void)mbedTLSDidConnected:(TuyaSmartMbedTLS *)mbedtls;

/// Encounter an error, TLS be close
/// @param mbedtls mbedtls
/// @param error error
- (void)mbedTLS:(TuyaSmartMbedTLS *)mbedtls didCloseWithError:(NSError *)error;

/// Completion of handshaking. Next, can send request by tls
/// @param mbedtls mbedtls
- (void)mbedTLSDidHandshake:(TuyaSmartMbedTLS *)mbedtls;

/// Completion of sending data
/// Please don't use「startReceiveData」anymore the「success」block of the method 「sendTLSDataWithType」, if the call is called in「startReceiveData」this callback
/// @param mbedtls mbedtls
- (void)mbedTLSDidWrite:(TuyaSmartMbedTLS *)mbedtls;

/// Completion of sending data
/// @param mbedtls mbedtls
- (void)mbedTLS:(TuyaSmartMbedTLS *)mbedtls didWriteFailedWithData:(NSData *)data;

/// Receive data by tls
/// @param mbedtls mbedtls
/// @param data the response
- (void)mbedTLS:(TuyaSmartMbedTLS *)mbedtls didReceiveData:(NSData *)data;

@end

@interface TuyaSmartMbedTLS : NSObject

@property (nonatomic, strong) NSString *lpv;

@property (nonatomic, weak) id<TuyaSmartMbedTLSDelegate> delegate;

// Set whether the certificate is available
@property (nonatomic, assign) BOOL enableCertificates;

// request all supported cipher suites
- (NSArray *)allowCipherSuites;

// Establishes a TCP connection.
- (void)initTcpClientWithHost:(NSString *)host;

- (void)startHandshakeWithPers:(NSString *)pers
                           psk:(NSString *)psk
                   pskIdentity:(NSString *)pskIdentity;

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

/// Receive a message By TLS
- (void)startReceiveData;

// Closes all connections.
- (void)closeAllTcpClient;

@end

NS_ASSUME_NONNULL_END

#endif
