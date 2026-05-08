
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartFileDownloadModel : NSObject

/**
 * File Id
 */
@property (copy, nonatomic) NSString *fileId;
/**
 * Product Id
 */
@property (copy, nonatomic) NSString *productId;
/**
 * Voice file name
 */
@property (copy, nonatomic) NSString *name;
/**
 * Voice file description
 */
@property (copy, nonatomic) NSString *desc;
/**
 * Voice audition file download URL
 */
@property (copy, nonatomic) NSString *auditionUrl;
/**
 * Voice official file download URL
 */
@property (copy, nonatomic) NSString *officialUrl;
/**
 * Voice icon URL
 */
@property (copy, nonatomic) NSString *imgUrl;
/**
 * Area Code
 */
@property (strong, nonatomic) NSArray<NSString *> *region;
/**
 * example：
 {
    "extendId" : "",
    "version" : "",
 }
 */
@property (strong, nonatomic) NSDictionary *extendField;

@end

NS_ASSUME_NONNULL_END
