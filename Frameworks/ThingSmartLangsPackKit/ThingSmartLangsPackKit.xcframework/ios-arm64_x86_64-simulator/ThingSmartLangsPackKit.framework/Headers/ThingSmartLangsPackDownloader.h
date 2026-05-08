//
//  ThingSmartLangsPackDownloader.h
//  ThingSmartLangsPackKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ThingSmartLangsPackDownloadCompleteBlock)(NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> * _Nullable langsPack, NSError * _Nullable error);

@interface ThingSmartLangsPackDownloader : NSObject

+ (instancetype)downloader;

#pragma mark - Download Product Langs
/**
 * Download Language Pack with version
 *
 * @param productID     product ID
 * @param productVer    product version
 * @param i18nTime      Language pack update timestamp
 * @param callbackQueue If you specify the GCD queue to execute the block, use a serial queue to avoid timing error. If you pass nil, use the main thread dispatch_get_main_queue()
 * @param completeBlock Complete the callback
 */
- (void)downloadLangsPackWithProductID:(NSString *)productID
                            productVer:(NSString *)productVer
                              i18nTime:(long long)i18nTime
                         callbackQueue:(nullable dispatch_queue_t)callbackQueue
                         completeBlock:(ThingSmartLangsPackDownloadCompleteBlock)completeBlock;
@end

NS_ASSUME_NONNULL_END

