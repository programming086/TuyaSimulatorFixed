
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 Sample:
     ThingSmartUserLoginJWTModel *JWTModel = [ThingSmartUserLoginJWTModel new];
     JWTModel.uniqueId = @"i";
     JWTModel.encrypted = YES;
     JWTModel.platform = @"p";
     NSDictionary *extraInfo = [JWTModel toDictionary];
 */
@interface ThingSmartUserLoginJWTModel : NSObject

@property (nonatomic, strong) NSString *uniqueId; /// Unique ID for generating cryptographic tokens.
@property (nonatomic, assign) BOOL encrypted; /// Indicates if JWT encryption is used for the accessToken
@property (nonatomic, strong) NSString *platform; /// Identifies the third-party user center.

- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
