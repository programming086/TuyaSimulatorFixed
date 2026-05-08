
#import <ThingSmartDeviceCoreKit/ThingSmartDevice.h>
#import "ThingSmartSweeperDefines.h"
#import "ThingSmartSweeperHistoryModel.h"
#import "ThingSmartSweeperMQTTMessage.h"
#import "ThingSmartFileDownloadModel.h"
#import "ThingSmartFileDownloadRateModel.h"
#import "ThingSmartSweeperRecordDetail.h"
#import "ThingSmartSweeperRecordList.h"

@class ThingSmartSweeperDevice;

NS_ASSUME_NONNULL_BEGIN


typedef NSString * ThingSmartSweeperCurrentPathKey;

FOUNDATION_EXPORT NSString * const THING_SDK_SWEEPER_VERSION;

/**
 * Key for real-time map path
 */
FOUNDATION_EXPORT ThingSmartSweeperCurrentPathKey const ThingSmartSweepCurrentMapPathKey;
/**
 * Key for real-time route path
 */
FOUNDATION_EXPORT ThingSmartSweeperCurrentPathKey const ThingSmartSweepCurrentRoutePathKey;

@protocol ThingSmartSweeperDeviceDelegate <ThingSmartDeviceDelegate>

@optional
/**
 * When received device stream data, the delegate will execute.
 *
 * @param sweeperDevice instance
 * @param data Received Data
 */
- (void)sweeperDevice:(ThingSmartSweeperDevice *)sweeperDevice didReceiveStreamData:(NSData *)data;

/**
 * File information callback of sweeping machine data channel
 *
 * @param sweeperDevice instance
 * @param message MQTT body
 */
- (void)sweeperDevice:(ThingSmartSweeperDevice *)sweeperDevice didReceiveMessage:(ThingSmartSweeperMQTTMessage *)message;

/**
 * File information callback for the data channel of the sweeping machine (when the value of shouldetAutoDownloadData is True, the SDK will download the file content)
 *
 * @param sweeperDevice instance
 * @param message MQTT body
 * @param data Binary data after file download
 * @param error error of downloading
 */
- (void)sweeperDevice:(ThingSmartSweeperDevice *)sweeperDevice didReceiveMessage:(ThingSmartSweeperMQTTMessage *)message downloadData:(nullable NSData *)data downloadError:(nullable NSError *)error;

/**
 * File download status
 *
 * @param sweeperDevice instance
 * @param type file type
 * @param status file status
 */
- (void)sweeperDevice:(ThingSmartSweeperDevice *)sweeperDevice type:(NSString *)type downloadStatus:(ThingSmartSweeperFileDownloadStatus)status;

/**
 * File download progress
 *
 * @param sweeperDevice instance
 * @param type file type
 * @param progress download progress
 */
- (void)sweeperDevice:(ThingSmartSweeperDevice *)sweeperDevice type:(NSString *)type downloadProgress:(int)progress;

@end


@interface ThingSmartSweeperDevice : ThingSmartDevice

@property (weak, nonatomic, nullable) id<ThingSmartSweeperDeviceDelegate> delegate;

/**
 * Download laser sweeper binary data from mapPath URL. Default false.
 */
@property (nonatomic, assign) BOOL shouldAutoDownloadData;


#pragma mark - Transfer Data

/**
 * Subscribe to the streaming data of the device
 */
- (void)subscribeDeviceDataTransfer;

/**
 * Unsubscribe the streaming data of the device
 */
- (void)unsubscribeDeviceDataTransfer;

#pragma mark - P2P

/// Connect to device by P2P
///
/// @param success callback when connect success
/// @param failure callback when connect fail
- (void)connectDeviceByP2P:(void (^)(void))success
                        failure:(void (^)(NSError * _Nullable error))failure
__deprecated_msg("This method is deprecated, Use ThingSmartSweeperP2PManager API instead");

/// Connect to device by P2P
///
/// @param isStopReconnect is Stop the internal reconnection
/// @param success callback when connect success
/// @param failure callback when connect fail
- (void)connectDeviceByP2P:(BOOL)isStopReconnect success:(void (^)(void))success
                        failure:(void (^)(NSError * _Nullable error))failure
__deprecated_msg("This method is deprecated, Use ThingSmartSweeperP2PManager API instead");

/// Start observer data from sweeper device.
///
/// @param downloadType 0:download only once, 1: continuous download when device update.
/// @param receiveP2PData  callback when observer success
/// @param failure callback when connect fail
- (void)startObserverSweeperDataByP2P:(ThingSmartSweeperP2PDownloadType)downloadType
                           receiveP2PData:(void (^)(NSDictionary *data))receiveP2PData
                                  failure:(void (^)(NSError * _Nullable error))failure
__deprecated_msg("This method is deprecated, Use ThingSmartSweeperP2PManager API instead");

/// Stop observer data from sweeper device.
/// @param success callback when stop success
/// @param failure callback when stop fail
- (void)stopObserverSweeperDataByP2P:(void (^)(void))success
                                    failure:(void (^)(NSError * _Nullable error))failure
__deprecated_msg("This method is deprecated, Use ThingSmartSweeperP2PManager API instead");

/// Destroy P2P SDK and cancel all task.
- (void)onDestroyP2P
__deprecated_msg("This method is deprecated, Use ThingSmartSweeperP2PManager API instead");

/// Check p2p session is active
- (BOOL)P2PActiveCheck
__deprecated_msg("This method is deprecated, Use ThingSmartSweeperP2PManager API instead");

#pragma mark - Laser Sweeper

/**
 * Initialize cloud configuration
 *
 * @param success Successfully returned bucket information for file storage
 * @param failure Failure block
 */
- (void)initCloudConfigWithSuccess:(void (^)(NSString *bucket))success
                           failure:(void (^)(NSError * _Nullable error))failure;

/**
 * update cloud configuration
 *
 * @param success Successfully returned bucket information for file storage
 * @param failure Failure block
 */
- (void)updateCloudConfigWithSuccess:(void (^)(NSString *bucket))success
                             failure:(void (^)(NSError * _Nullable error))failure;


/**
 * Get data file address
 *
 * @param bucket Bucket for file storage
 * @param path file path
 */
- (nullable NSString *)getCloudFileDownloadURLWithBucket:(NSString *)bucket path:(NSString *)path;

/**
 * OSS error code: https://help.aliyun.com/document_detail/32005.html?spm=a2c4g.11186623.6.1328.609b28126VcNPW
 *
 * @param bucket Bucket for file storage
 * @param path file path
 * @param success callback
 * @param failure callback
 */
- (void)getSweeperDataWithBucket:(NSString *)bucket
                            path:(NSString *)path
                         success:(void (^)(NSData *data))success
                         failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Obtain real-time map file information
 *
 * @param success Success block
 * @param failure Failure block
 */
- (void)getSweeperCurrentPathWithSuccess:(void (^)(NSString *bucket, NSDictionary<ThingSmartSweeperCurrentPathKey, NSString *> *paths))success
                                 failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Retrieve the history of the sweeping machine
 *
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param success Success block
 * @param failure Failure block
 */
- (void)getSweeperHistoryDataWithLimit:(NSUInteger)limit
                                offset:(NSUInteger)offset
                               success:(void (^)(NSArray<ThingSmartSweeperHistoryModel *> *datas, NSUInteger totalCount))success
                               failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Retrieve the history of the sweeping machine
 *
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param startTime Start timestamp
 * @param endTime End timestamp
 * @param success Success block
 * @param failure Failure block
 */
- (void)getSweeperHistoryDataWithLimit:(NSUInteger)limit
                                offset:(NSUInteger)offset
                             startTime:(long)startTime
                               endTime:(long)endTime
                               success:(void (^)(NSArray<ThingSmartSweeperHistoryModel *> *datas, NSUInteger totalCount))success
                               failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Delete sweeping machine history
 *
 * @param fileIds File ID Array
 * @param success Success block
 * @param failure Failure block
 */
- (void)removeSweeperHistoryDataWithFileIds:(NSArray<NSString *> *)fileIds
                                    success:(void (^)(void))success
                                    failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Delete all historical records of the current sweeping machine
 *
 * @param success Success block
 * @param failure Failure block
 */
- (void)removeAllHistoryDataWithSuccess:(void (^)(void))success
                                failure:(void (^)(NSError * _Nullable error))failure __deprecated_msg("This method is deprecated on 3.0.0")
;


#pragma mark - Multiple map versions

/**
 * Retrieve (multi map) sweeping machine history records
 *
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param success callback
 * @param failure callback
 */
- (void)getSweeperMultiHistoryDataWithLimit:(NSUInteger)limit
                                     offset:(NSUInteger)offset
                                    success:(void (^)(NSArray<ThingSmartSweeperHistoryModel *> *datas, NSUInteger totalCount))success
                                    failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Retrieve (multi map) sweeping machine history records
 *
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param startTime Start timestamp
 * @param endTime End timestamp
 * @param success callback
 * @param failure callback
 */
- (void)getSweeperMultiHistoryDataWithLimit:(NSUInteger)limit
                                     offset:(NSUInteger)offset
                                  startTime:(long)startTime
                                    endTime:(long)endTime
                                    success:(void (^)(NSArray<ThingSmartSweeperHistoryModel *> *datas, NSUInteger totalCount))success
                                    failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Delete all historical records of the current (multi map) sweeping machine
 *
 * @param success callback
 * @param failure callback
 */
- (void)removeAllMultiHistoryDataWithSuccess:(void (^)(void))success
                                     failure:(void (^)(NSError * _Nullable error))failure __deprecated_msg("This method is deprecated on 3.0.0");


#pragma mark - Gyroscope and Vision Sweeper

/**
 * V1.0 Check the latest cleaning record
 *
 * @param devId Device ID
 * @param start Starting position. The first pass is empty, and when taking the next page, fill in the startRow value from the return value of the previous page
 * @param size Query the size of the data with a fixed parameter of 500
 */
- (void)queryLatestCleanRecord:(NSString *)devId start:(NSString *)start size:(NSInteger)size complete:(void(^)(ThingSmartSweeperRecordDetail *model, NSError *error))complete;

/**
 * V2.0  Check the latest cleaning record
 *
 * @param devId Device ID
 * @param start Starting position. The first pass is empty, and when taking the next page, fill in the startRow value from the return value of the previous page
 * @param size Query the size of the data with a fixed parameter of 500
 */
- (void)queryLatestCleanRecordV2:(NSString *)devId start:(NSString *)start size:(NSInteger)size complete:(void(^)(ThingSmartSweeperRecordDetail *model, NSError *error))complete;

/**
 * List of historical cleaning records
 *
 * @param devId device ID
 * @param offset Get the offset of data (for pagination)
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param startTime Start timestamp
 * @param endTime End timestamp
 */
- (void)getHistoryCleanRecordList:(NSString *)devId offset:(NSInteger )offset limit:(NSInteger)limit startTime:(long long)startTime endTime:(long long)endTime complete:(void(^)(NSArray <ThingSmartSweeperRecordList *> *list, NSError *error))complete;

/**
 * V1.0  Cleaning Record Details
 *
 * @param devId device ID
 * @param subRecordId Sweep the record ID and use different parsing rules based on the data length by parsing the value data in the historical record list. The rules are shown in the table below
 * @param start Starting position. The first pass is empty, and when taking the next page, fill in the startRow value from the return value of the previous page
 * @param size  Query the size of the data with a fixed parameter of 500
 */
- (void)getCleanRecordDetail:(NSString *)devId subRecordId:(NSInteger)subRecordId start:(NSString *)start size:(NSInteger)size complete:(void(^)(ThingSmartSweeperRecordDetail *model, NSError *error))complete;

/**
 * V2.0  Cleaning Record Details
 *
 * @param devId device ID
 * @param subRecordId Sweep the record ID and use different parsing rules based on the data length by parsing the value data in the historical record list. The rules are shown in the table below
 * @param mapId map ID
 * @param datatype map type
 * @param start  Starting position. The first pass is empty, and when taking the next page, fill in the startRow value from the return value of the previous page
 * @param size  Query the size of the data with a fixed parameter of 500
 */
- (void)getCleanRecordDetailV2:(NSString *)devId subRecordId:(NSInteger)subRecordId mapId:(NSInteger)mapId datatype:(NSInteger)datatype start:(NSString *)start size:(NSInteger)size complete:(void(^)(ThingSmartSweeperRecordDetail *model, NSError *error))complete;

/**
 * Delete historical cleaning records
 *
 * @param devId Device ID
 * @param recordId  Cleaning record ID
 */
- (void)deleteHistoryCleanRecord:(NSString *)devId recordId:(NSString *)recordId complete:(void(^)(BOOL success, NSError *error))complete;


#pragma mark - File Manager

/**
 * Retrieve file information
 *
 * @param success callback
 * @param failure callback
 */
- (void)getFileDownloadInfoWithSuccess:(void (^)(NSArray<ThingSmartFileDownloadModel *> *upgradeFileList))success
                               failure:(void (^)(NSError * _Nullable error))failure;
/**
 * Retrieve file information (pagination query)
 *
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param success 成功回调
 * @param failure 失败回调
*/
- (void)getFileDownloadInfoWithLimit:(NSUInteger)limit
                              offset:(NSUInteger)offset
                             success:(void (^)(NSArray<ThingSmartFileDownloadModel *> *upgradeFileList, NSUInteger totalCount))success
                             failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Issue the command to download files, and the device will start downloading files. Successful or failed upgrades will be returned through ThingSmartFileDownloadDelegate
 *
 * @param fileId  fileId of `ThingSmartFileDownloadModel`
 * @param success callback (status 0：not download  1：downloading)
 * @param failure callback
 */
- (void)downloadFileWithFileId:(NSString *)fileId
                       success:(void (^)(id result))success
                       failure:(void (^)(NSError * _Nullable error))failure;

/**
 * Get file download progress
 *
 * @param success callback
 * @param failure callback
 */
- (void)getFileDownloadRateWithSuccess:(void (^)(ThingSmartFileDownloadRateModel *rateModel))success
                               failure:(void (^)(NSError * _Nullable error))failure;

/// Update sweeper file name
/// @param fileId map id
/// @param fileName file name
/// @param success success call back
/// @param failure failure call back
- (void)sweeperFileNameUpdateWithFileId:(NSNumber *)fileId
                              fileName:(NSString *)fileName
                               success:(void (^)(id result))success
                               failure:(void (^)(NSError * _Nullable error))failure;
@end

NS_ASSUME_NONNULL_END
