//
//  ThingLockCardManager.h
//  ThingSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLockCardModel;

typedef void (^ThingLockCardSuccessList)(NSArray<ThingLockCardModel *> * _Nullable list, NSInteger totalSize);
typedef void (^ThingLockCardSuccess)(ThingLockCardModel * _Nullable model);

@interface ThingLockCardManager : NSObject

+ (instancetype)shared;

/// Retrieves a list of cards for a specified device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device for which to retrieve the card list.
///   - pageNo: The page number to retrieve.
///   - pageSize: The number of items per page.
///   - success: Success callback
///   - failure: Failure callback
- (void)getCardListWithSiteId:(long long)siteId
                     deviceId:(NSString *)deviceId
                       pageNo:(NSInteger)pageNo
                     pageSize:(NSInteger)pageSize
                      success:(ThingLockCardSuccessList)success
                      failure:(ThingFailureError)failure;

/// Retrieves the details of a specified card for a device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device containing the card.
///   - cardId: The ID of the card to retrieve details for.
///   - success: Success callback
///   - failure: Failure callback
- (void)getCardDetailWithSiteId:(long long)siteId
                       deviceId:(NSString *)deviceId
                         cardId:(NSString *)cardId
                        success:(ThingLockCardSuccess)success
                        failure:(ThingFailureError)failure;

/// Creates a limited-use card for a specified device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device for which to create the card.
///   - cardName: The name of the card to be created.
///   - effectiveTimeInterval: The time interval during which the card will be valid.
///   - invalidTimeInterval: The time interval after which the card will be invalid.
///   - success: Success callback
///   - failure: Failure callback
- (void)createLimitCardWithSiteId:(long long)siteId
                         deviceId:(NSString *)deviceId
                         cardName:(NSString *)cardName
            effectiveTimeInterval:(NSTimeInterval)effectiveTimeInterval
              invalidTimeInterval:(NSTimeInterval)invalidTimeInterval
                          success:(ThingSuccessHandler)success
                          failure:(ThingFailureError)failure;

/// Creates a permanent card for a specified device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device for which to create the card.
///   - cardName: The name of the card to be created.
///   - success: Success callback
///   - failure: Failure callback
- (void)createPermanentCardWithSiteId:(long long)siteId
                             deviceId:(NSString *)deviceId
                             cardName:(NSString *)cardName
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;

/// Updates the name of a specified card for a device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device containing the card.
///   - cardId: The ID of the card to be updated.
///   - cardName: The new name for the card.
///   - success: Success callback
///   - failure: Failure callback
- (void)updateNameWithSiteId:(long long)siteId
                    deviceId:(NSString *)deviceId
                      cardId:(NSString *)cardId
                    cardName:(NSString *)cardName
                     success:(ThingSuccessHandler)success
                     failure:(ThingFailureError)failure;

/// Removes a specified card from a device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device containing the card.
///   - cardId: The ID of the card to be removed.
///   - lockId: The ID of the lock associated with the card.
///   - success: Success callback
///   - failure: Failure callback
- (void)removeCardWithSiteId:(long long)siteId
                    deviceId:(NSString *)deviceId
                      cardId:(NSString *)cardId
                      lockId:(NSString *)lockId
                     success:(ThingSuccessHandler)success
                     failure:(ThingFailureError)failure;

/// Clears all cards from a device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device from which to clear all cards.
///   - success: Success callback
///   - failure: Failure callback
- (void)clearAllCardWithSiteId:(long long)siteId
                       deviceId:(NSString *)deviceId
                        success:(ThingSuccessHandler)success
                        failure:(ThingFailureError)failure;



/// Cancels the card creation.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The device ID on which the card creation is to be canceled.
///   - success: Success callback
///   - failure: Failure callback
- (void)cancelCardCreateWithSiteId:(long long)siteId
                          deviceId:(NSString *)deviceId
                           success:(ThingSuccessHandler)success
                           failure:(ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
