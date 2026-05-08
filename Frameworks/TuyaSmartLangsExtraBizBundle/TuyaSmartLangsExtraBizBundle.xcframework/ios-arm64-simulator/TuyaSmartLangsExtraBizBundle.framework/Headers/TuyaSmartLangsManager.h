//
//  TuyaSmartLangsManager.h
//  TuyaSmartLangsManager
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartLangsManager : NSObject

+ (instancetype)sharedInstance;

/**
 * Update the product language pack
 *
 * @param productId  product ID
 * @param i18nTime  Language pack update timestamp
 */
- (void)updateProductLangWithProductId:(NSString *)productId
                              i18nTime:(long long)i18nTime
                         completeBlock:(void (^)(NSError *error))completeBlock;

/**
 * Get the product language pack
 *
 * @param productId product ID
 * @param i18nTime  Language pack update timestamp
 */
- (void)getProductLangWithProductId:(NSString *)productId
                           i18nTime:(long long)i18nTime
                       successBlock:(void (^)(NSDictionary *langsDic))successBlock
                          failBlock:(void (^)(NSError *error))failBlock;

@end

NS_ASSUME_NONNULL_END
