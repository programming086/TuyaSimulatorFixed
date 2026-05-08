
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingSmartSweeperHistoryModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString * ThingSweeperCurrentPathKey;

FOUNDATION_EXPORT ThingSweeperCurrentPathKey const ThingSweeperCurrentMapPathKey;
FOUNDATION_EXPORT ThingSweeperCurrentPathKey const ThingSweeperCurrentRoutePathKey;

@class ThingSmartSweeper;
__deprecated_msg("No longer supported; please adopt ThingSmartSweeperDeviceDelegate (see ThingSmartSweeperDevice.h)") @protocol ThingSmartSweeperDelegate <NSObject>
@optional
/**
 * File data information callback
 *
 * @param sweeper instance
 * @param devId device ID
 * @param mapType  0:map，1:path
 * @param mapPath filepath
 */
- (void)sweeper:(ThingSmartSweeper *)sweeper didReciveDataWithDevId:(NSString *)devId mapType:(NSInteger)mapType mapPath:(NSString *)mapPath __deprecated_msg("This method is deprecated, Use -[ThingSmartSweeperDelegate sweeper:didReciveDataWithDevId:message:] instead");

/**
 * File data information callback
 *
 * @param sweeper instance
 * @param devId device ID
 * @param message MQTT message
 */
- (void)sweeper:(ThingSmartSweeper *)sweeper didReciveDataWithDevId:(NSString *)devId message:(NSDictionary *)message;

/**
 * Map data information callback
 *
 * Need to set 'should AutoDownloadData'=YES in advance, which will automatically request data download based on the returned map URL
 *
 * @param sweeper instance
 * @param devId device ID
 * @param mapType  0:map，1:path
 * @param mapData  map data
 * @param error OSS error code: https://help.aliyun.com/document_detail/32005.html?spm=a2c4g.11186623.6.1328.609b28126VcNPW
 */
- (void)sweeper:(ThingSmartSweeper *)sweeper didReciveDataWithDevId:(NSString *)devId mapType:(NSInteger)mapType mapData:(NSData *)mapData error:(NSError *)error;


@end


__deprecated_msg("No longer supported; please adopt ThingSmartSweeperDevice (see ThingSmartSweeperDevice.h)") @interface ThingSmartSweeper : NSObject


/**
 * Whether to automatically download map file data
 */
@property (nonatomic, assign) BOOL shouldAutoDownloadData;

@property (nonatomic, weak) id<ThingSmartSweeperDelegate> delegate;

/**
 * Initialize cloud configuration
 *
 * @param devId device ID
 * @param complete  Successfully returned bucket information for file storage (used to obtain the storage URL of the file)
 */
- (void)initCloudConfigWithDevId:(NSString *)devId
                        complete:(void(^)(NSString *bucket, NSError * _Nullable error))complete;

/**
 * Update cloud configuration
 *
 * @param devId device ID
 * @param complete Successfully returned bucket information for file storage
 */
- (void)updateCloudConfigWithDevId:(NSString *)devId
                          complete:(void(^)(NSString *bucket, NSError * _Nullable error))complete;


/**
 * Get data file address
 *
 * @param bucket Bucket for file storage
 * @param path File Path
 */
- (nullable NSString *)getCloudFileUrlWithBucket:(NSString *)bucket
                                            path:(NSString *)path;

/**
 * OSS error code: https://help.aliyun.com/document_detail/32005.html?spm=a2c4g.11186623.6.1328.609b28126VcNPW
 *
 * @param bucket Bucket for file storage
 * @param path File Path
 * @param complete callback
 */
- (void)getSweeperDataWithBucket:(NSString *)bucket
                            path:(NSString *)path
                        complete:(void(^)(NSData *data, NSError * _Nullable error))complete;

/**
 * Obtain real-time map storage paths and path storage paths
 *
 * @param devId device ID
 * @param complete callback
 */
- (void)getSweeperCurrentPathWithDevId:(NSString *)devId complete:(void(^)(NSString *mapPath, NSString *routePath, NSError * _Nullable error))complete __deprecated_msg("This method is deprecated, Use -[ThingSmartSweeper getSweeperCurrentPathWithDevId:success:failure:] instead");

/**
 * Obtain real-time map file information
 *
 * @param devId device ID
 * @param success callback
 * @param failure callback
 */
- (void)getSweeperCurrentPathWithDevId:(NSString *)devId
                               success:(void(^)(NSDictionary<ThingSweeperCurrentPathKey, NSString *> *paths))success
                               failure:(void(^)(NSError * _Nullable error))failure;


#pragma mark - Cleaning record

/**
 * Retrieve the history of the sweeping machine
 *
 * @param devId deviceID
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param complete callback
 */
- (void)getSweeperHistoryDataWithDevId:(NSString *)devId
                                 limit:(NSUInteger)limit
                                offset:(NSUInteger)offset
                              complete:(void(^)(NSArray<ThingSmartSweeperHistoryModel *> *datas, NSUInteger totalCount, NSError * _Nullable error))complete;

/**
 * Retrieve the history of the sweeping machine
 *
 * @param devId device ID
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param startTime Start timestamp
 * @param endTime End timestamp
 * @param complete callback
 */
- (void)getSweeperHistoryDataWithDevId:(NSString *)devId
                                 limit:(NSUInteger)limit
                                offset:(NSUInteger)offset
                             startTime:(long)startTime
                               endTime:(long)endTime
                              complete:(void(^)(NSArray<ThingSmartSweeperHistoryModel *> *datas, NSUInteger totalCount, NSError * _Nullable error))complete;

/**
 * Delete sweeping machine history
 *
 * @param devId device ID
 * @param fileIds File ID array
 * @param complete callback
 */
- (void)removeSweeperHistoryDataWithDevId:(NSString *)devId
                                  fileIds:(NSArray<NSString *> *)fileIds
                                 complete:(void (^)(NSError * _Nullable error))complete;

/**
 * Delete all historical records of the current sweeping machine
 *
 * @param devId device ID
 * @param complete callback
 */
- (void)removeAllHistoryDataWithDevId:(NSString *)devId
                             complete:(void (^)(NSError * _Nullable error))complete;


#pragma mark - Multiple map versions

/**
 * Retrieve (multi map) sweeping machine history records
 *
 * @param devId device ID
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param success callback
 * @param failure callback
 */
- (void)getSweeperMultiHistoryDataWithDevId:(NSString *)devId
                                      limit:(NSUInteger)limit
                                     offset:(NSUInteger)offset
                                    success:(void(^)(NSArray<ThingSmartSweeperHistoryModel *> *datas, NSUInteger totalCount))success
                                    failure:(void(^)(NSError * _Nullable error))failure;

/**
 * Retrieve (multi map) sweeping machine history records
 *
 * @param devId device ID
 * @param limit The quantity of data obtained at once (it is recommended not to exceed 100)
 * @param offset Get the offset of data (for pagination)
 * @param startTime Start timestamp
 * @param endTime End timestamp
 * @param success callback
 * @param failure callback
 */
- (void)getSweeperMultiHistoryDataWithDevId:(NSString *)devId
                                      limit:(NSUInteger)limit
                                     offset:(NSUInteger)offset
                                  startTime:(long)startTime
                                    endTime:(long)endTime
                                    success:(void(^)(NSArray<ThingSmartSweeperHistoryModel *> *datas, NSUInteger totalCount))success
                                    failure:(void(^)(NSError * _Nullable error))failure;

/**
 * Delete all historical records of the current (multi map) sweeping machine
 *
 * @param devId DeviceID
 * @param complete callback
 */
- (void)removeAllMultiHistoryDataWithDevId:(NSString *)devId
                                  complete:(void (^)(NSError * _Nullable error))complete;

/// Update sweeper file name
/// @param devId device id
/// @param fileId map id
/// @param fileName file name
/// @param complete if success return res else return error.
- (void)sweeperFileNameUpdateWithDevId:(NSString *)devId
                                fileId:(NSNumber *)fileId
                              fileName:(NSString *)fileName
                              complete:(void (^)(id res, NSError * _Nullable error))complete;
@end

NS_ASSUME_NONNULL_END
