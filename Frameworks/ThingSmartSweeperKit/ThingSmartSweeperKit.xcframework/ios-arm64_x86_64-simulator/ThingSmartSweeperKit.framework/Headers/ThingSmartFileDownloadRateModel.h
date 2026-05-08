
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartFileDownloadRateModel : NSObject

/**
 * File Id
 */
@property (copy, nonatomic) NSString *fileId;
/**
 * Device Id
 */
@property (copy, nonatomic) NSString *deviceId;
/**
 * Download status. 0: Did not download; 1: Downloading
 */
@property (assign, nonatomic) NSInteger status;
/**
 * Download progress
 */
@property (assign, nonatomic) int rate;

@end

NS_ASSUME_NONNULL_END
