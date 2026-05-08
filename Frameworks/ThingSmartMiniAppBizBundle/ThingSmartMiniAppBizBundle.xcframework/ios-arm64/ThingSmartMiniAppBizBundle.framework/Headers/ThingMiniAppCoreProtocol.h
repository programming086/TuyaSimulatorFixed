
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMiniAppCoreProtocol <NSObject>

/// open miniapp with appId
/// - Parameter appId: miniapp platform instance id
- (void)openMiniAppByAppId:(nonnull NSString *)appId;

/// open miniapp with appId
/// - Parameters:
///   - appId: miniapp platform instance id
///   - params: extra params
- (void)openMiniAppByAppId:(nonnull NSString *)appId params:(nullable NSDictionary *)params;

/// open miniapp with appId
/// - Parameters:
///   - appId: miniapp platform instance id
///   - appVersion: miniapp version
///   - params: extra params
- (void)openMiniAppByAppId:(nonnull NSString *)appId appVersion:(nullable NSString *)appVersion params:(nullable NSDictionary *)params;

/// open miniapp with url
/// - Parameter url: eg: godzilla://{appid}/{path}
- (void)openMiniAppByUrl:(nonnull NSString *)url;

/// open miniapp with url
/// - Parameters:
///   - url: eg: godzilla://{appid}/{path}
///   - params: extra params
- (void)openMiniAppByUrl:(nonnull NSString *)url params:(nullable NSDictionary *)params;

/// open miniapp with qrcode
/// - Parameter qrcode: qrcode from miniapp platform
- (void)openMiniAppByQrcode:(nonnull NSString *)qrcode;

/// open miniapp with qrcode
/// - Parameters:
///   - qrcode: qrcode from miniapp platform
///   - params: extra params
- (void)openMiniAppByQrcode:(nonnull NSString *)qrcode params:(nullable NSDictionary *)params;

/// predownload miniapp when sometimes
/// - Parameter appId: miniapp platform instance id
- (void)preloadMiniApp:(nonnull NSString *)appId;

/// clean all miniapp cache
- (void)clearCache;

/// open scan page
- (void)openScan;

@end

NS_ASSUME_NONNULL_END
