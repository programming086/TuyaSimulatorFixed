//
//  ThingSmartMerchantModel.h
//  ThingSaaSLoginPlugAPI
//
//  Created by yin eason on 2023/2/9.
//

#import <Foundation/Foundation.h>

/// User register type.
typedef NS_ENUM(NSInteger, ThingMerchantCodeType) {
    /// Register from email.
    ThingMerchantCodeLogin,
    /// Register from mobile phone.
    ThingMerchantCodeReg,
    /// Register from other.
    ThingMerchantCodeModifyOrFindPasswordOrQuery,
    /// Login be reg
    ThingMerchantCodeLoginBeReg
};


NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMerchantModel : NSObject

/// Merchant Code.
@property (nonatomic,strong) NSString *merchantCode;

/// Merchant Name.
@property (nonatomic,strong) NSString *merchantName;

/// Whether password of current account match this merchant.
@property (nonatomic,assign) BOOL match;

@end

NS_ASSUME_NONNULL_END
