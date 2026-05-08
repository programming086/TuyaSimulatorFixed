
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingThirdPartyVoiceServiceStatusModel : NSObject

/// Authorization time
@property (nonatomic, assign) NSInteger time;

/// Icon URL
@property (nonatomic, copy) NSString *icon;

/// Platform identifier
@property (nonatomic, copy) NSString *clientType;

/// Authorization status. 1 - Authorized, 0 - Not authorized
@property (nonatomic, assign) NSInteger status;

/// Platform name
@property (nonatomic, copy) NSString *platformName;

@property (nonatomic, copy) NSString *widgetUrl;

@end

NS_ASSUME_NONNULL_END
