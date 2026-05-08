//
//  ThingSmartLangsPersistentStore.h
//  ThingSmartLangsPackKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartLangsPersistentStore : NSObject

+ (instancetype)sharedInstance;

/**
 * Multilingual file persistence root directory
 * @return  NSURL
 */
- (NSURL *)rootDirPath;

/**
 * Initialize multilingual storage
 *
 * @param storeCostLimit At present, we mainly set the upper limit of the capacity of persistent storage. When the upper limit is exceeded, the files are cleaned in time according to the elimination mechanism, and the default cache of nil is 200M
 */
- (void)setupWithCostLimit:(NSUInteger)storeCostLimit;

/**
 * Try to clean up storage space
 */
- (void)cleanupIfNeeded;

/**
 * clean up storage space
 */
- (void)clearPersistentStore;


#pragma mark - Product Lang Store

/**
 * Store the latest product language pack
 *
 * @param JSONObj   Language package JSON dictionary
 * @param productID product ID
 * @param i18nTime  Language pack update timestamp
 * @return  Verify success before persistence
 */
- (BOOL)storeProductLangWithJSONObj:(NSDictionary *)JSONObj
                          productID:(NSString *)productID
                         productVer:(NSString *)productVer
                           i18nTime:(long long)i18nTime
                              error:(NSError **)error;



#pragma mark - Get Product Lang

/**
 * Check if the language pack exists
 *
 * @param productID     product ID
 * @param i18nTime      Language pack update timestamp
 * @return  if exist？
 */
- (BOOL)productLangExistWithProductID:(NSString *)productID
                           productVer:(NSString *)productVer
                             i18nTime:(long long)i18nTime;

/**
 * Get the product language pack
 *
 * @param productID product ID
 * @param i18nTime  Language pack update timestamp
 * @param update Whether to update the access time
 * @return  Language pack
*/
- (nullable NSDictionary *)getProductLangWithProductID:(NSString *)productID
                                            productVer:(NSString *)productVer
                                              i18nTime:(long long)i18nTime
                                  updateLastAccessTime:(BOOL)update;

/**
 * Get the product language pack
 *
 * @param productID product ID
 * @param i18nTime   Language pack update timestamp
 * @return  Language pack
 */
- (nullable NSDictionary *)getProductLangWithProductID:(NSString *)productID
                                            productVer:(NSString *)productVer
                                              i18nTime:(long long)i18nTime;


@end

NS_ASSUME_NONNULL_END
