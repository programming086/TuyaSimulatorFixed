
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSweeperHistoryModel : NSObject

/**
 * History file id
 */
@property (copy, nonatomic) NSString *fileId;

/**
 * Timestamp
 */
@property (assign, nonatomic) long time;

/**
 * File splitting and reading rules (json string)
 */
@property (copy, nonatomic) NSString *extend;

/**
 * History file's bucket in the oss/s3
 */
@property (copy, nonatomic) NSString *bucket;

/**
 * History file path
 */
@property (copy, nonatomic) NSString *file;

/**
 * History file name
 */
@property (copy, nonatomic) NSString *fileName;
@end

NS_ASSUME_NONNULL_END
