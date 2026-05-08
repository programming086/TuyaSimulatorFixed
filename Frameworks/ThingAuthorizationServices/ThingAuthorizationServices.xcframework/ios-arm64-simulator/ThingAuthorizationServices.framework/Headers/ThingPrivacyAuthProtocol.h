
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingPrivacyAuthProtocol <NSObject>

/// Is it necessary to trigger the permission verification landing page?
/// @param type Permission type
/// @param source Permission source
- (BOOL)isShowPrivacy:(ThingPrivacyAuthType)type source:(NSString *)source;

/// permission title
/// @param type Permission type
/// @param source Permission source
- (NSString *)titleWithType:(ThingPrivacyAuthType)type source:(NSString *)source;

/// Permission description
/// @param type Permission type
/// @param source Permission source
- (NSString *)descWithType:(ThingPrivacyAuthType)type source:(NSString *)source;


- (void)markOnceSourceHasShown;

@end

NS_ASSUME_NONNULL_END
