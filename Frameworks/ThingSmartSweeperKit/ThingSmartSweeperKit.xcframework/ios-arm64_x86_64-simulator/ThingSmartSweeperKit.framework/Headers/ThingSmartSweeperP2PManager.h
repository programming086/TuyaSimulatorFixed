
#import <Foundation/Foundation.h>
#import "ThingSmartSweeperFileManagerModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartSweeperP2PManagerProtocol <NSObject>

/**
 * P2P SDK init
 *
 * @param userId   user ID
 * @param success callback
 * @param failure callback
 */
- (void)initP2PSDKWithUserId:(nullable NSString *)userId
                     success:(void (^)(void))success
                     failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Connect P2P
 *
 * @param params   params
 * @param success callback
 * @param failure callback
 */
- (void)connectDevice:(ThingSmartSweeperP2PConnectionParams*)params
              success:(void (^)(void))success
              failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Disconnect P2P
 *
 * @param devId Device ID
 * @param success callback
 * @param failure callback
 */
- (void)disconnectDevice:(NSString*)devId
                 success:(void (^)(void))success
                 failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Check P2P connectiojn
 *
 * @param devId     device ID
 * @param success callback
 * @param failure callback
 */
- (void)isP2PActive:(NSString*)devId
            success:(void (^)(void))success
            failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Query file index list
 *
 * @param params   params
 * @param success callback
 * @param failure callback
 */
- (void)queryAlbumFileIndexs:(ThingSmartSweeperP2PAlbum*)params
                     success:(void (^)(ThingSmartSweeperP2PAlbumFileIndexs *data))success
                     failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Download file
 *
 * @param params   params
 * @param success callback
 * @param failure callback
 */
- (void)downloadFile:(ThingSmartSweeperP2PDownloadFile*)params
             success:(void (^)(void))success
             failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Cancel downloading files
 *
 * @param devId      device ID
 * @param success callback
 * @param failure callback
 */
- (void)cancelDownloadTask:(NSString*)devId
                   success:(void (^)(void))success
                   failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Deinitialization
 *
 * @param success callback
 * @param failure callback
 */
- (void)deInitSDK:(void (^)(void))success
          failure:(void (^)(NSError * _Nullable error))failure;

@end

@protocol ThingSmartSweeperP2PManagerDelegate  <NSObject>

@optional

/**
 * Connection status change callback
 *
 * @param model State Model
 */
- (void)sessionStatusChangeWithModel:(ThingSmartSweeperP2PSessionStatus *)model;

/**
 * Upload progress callback
 *
 * @param progress schedule model
 */
- (void)uploadProgressUpdateWithModel:(ThingSmartSweeperFileManagerProgress *)progress;

/**
 * Single file download progress callback
 *
 * @param progress schedule model
 */
- (void)downloadProgressUpdateWithModel:(ThingSmartSweeperFileDownloadProgress *)progress;

/**
 * Download overall progress callback
 *
 * @param progress schedule model
 */
- (void)downloadTotalProgressUpdateWithModel:(ThingSmartSweeperFileDownloadTotalProgress *)progress;

/**
 * Single file download completion event
 *
 * @param model Download completed data model
 */
- (void)fileDownloadCompleteWithModel:(ThingSmartSweeperFileDownloadCompletion *)model;

/**
 * Received packet event
 *
 * @param model Data packet model
 */
- (void)streamPacketReceiveWithModel:(ThingSmartSweeperFileManagerPacketReceived *)model;

@end

@interface ThingSmartSweeperP2PManager : NSObject<ThingSmartSweeperP2PManagerProtocol>

@property (nonatomic, weak) id <ThingSmartSweeperP2PManagerDelegate> p2pFileManagerDelegate;

@end

NS_ASSUME_NONNULL_END
