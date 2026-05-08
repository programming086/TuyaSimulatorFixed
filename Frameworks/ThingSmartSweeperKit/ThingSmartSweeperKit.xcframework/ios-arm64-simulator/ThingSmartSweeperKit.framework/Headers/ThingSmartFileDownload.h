
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

@class ThingSmartFileDownloadModel;
@class ThingSmartFileDownloadRateModel;
@class ThingSmartFileDownload;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSmartFileDownloadStatus) {
    ThingSmartFileDownloadStatusUpgrading = 1,   // Downloading
    ThingSmartFileDownloadStatusFinish,          // Download finsh
    ThingSmartFileDownloadStatusFailure,         // Download failure
};

__deprecated_msg("No longer supported; please adopt ThingSmartSweeperDeviceDelegate (see ThingSmartSweeperDevice.h)") @protocol ThingSmartFileDownloadDelegate <NSObject>

/**
 File download status

 @param fileDownload instance
 @param type file type
 @param status file status
 */
- (void)fileDownloadUpgrade:(ThingSmartFileDownload *)fileDownload type:(NSString *)type status:(ThingSmartFileDownloadStatus)status;

/**
 File download progress

 @param fileDownload instance
 @param type file type
 @param progress download progress
 */
- (void)fileDownloadUpgrade:(ThingSmartFileDownload *)fileDownload type:(NSString *)type progress:(int)progress;

@end

__deprecated_msg("No longer supported; please adopt ThingSmartSweeperDevice (see ThingSmartSweeperDevice.h)") @interface ThingSmartFileDownload : NSObject

@property (weak, nonatomic) id <ThingSmartFileDownloadDelegate> delegate;

+ (instancetype)fileDownloadWithDeviceId:(NSString *)devId;
- (instancetype)initWithDeviceId:(NSString *)devId NS_DESIGNATED_INITIALIZER;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 Retrieve file information
 
 @param success callback
 @param failure callback
 */
- (void)getFileDownloadInfoWithSuccess:(nullable void (^)(NSArray<ThingSmartFileDownloadModel *> *upgradeFileList))success
                               failure:(nullable ThingFailureError)failure;

/**
 Issue the command to download files, and the device will start downloading files. Successful or failed upgrades will be returned through ThingSmartFileDownloadDelegate
 
 @param fileId  fileId of `ThingSmartFileDownloadModel`
 @param success callback (status 0：not downloaded  1：downloadeding)
 @param failure callback
 */
- (void)downloadFileWithFileId:(NSString *)fileId
                       success:(nullable ThingSuccessID)success
                       failure:(nullable ThingFailureError)failure;

/**
 Get file download progress
 
 @param success callback
 @param failure callback
 */
- (void)getFileDownloadRateWithSuccess:(nullable void (^)(ThingSmartFileDownloadRateModel *rateModel))success
                               failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
