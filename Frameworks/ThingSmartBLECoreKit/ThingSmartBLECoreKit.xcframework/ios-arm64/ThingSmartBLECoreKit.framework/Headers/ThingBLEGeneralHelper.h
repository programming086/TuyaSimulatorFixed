
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ThingBLESupportConnect) {
    ThingBLESupportConnect_DEFAULT   = 1,   /// 默认连接(未配置)
    ThingBLESupportConnect_REQUEST   = 2,   /// 按需连接
    ThingBLESupportConnect_KEEP      = 3,   /// 保持连接
    ThingBLESupportConnect_NONEED    = 4,   /// 不连接
};

typedef NS_ENUM(NSUInteger, ThingBLESupportDisconnect) {
    ThingBLESupportDisconnect_INTIME               = 1,    /// 及时断连
    ThingBLESupportDisconnect_REQUEST              = 2,    /// 按需断连
    ThingBLESupportDisconnect_DEFAULT              = 3,    /// 不断连(未配置)
    ThingBLESupportDisconnect_INTIME_REQUEST       = 4,    /// 退出面板/ app 退到后台 30s 断连
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingBLEGeneralHelper : NSObject

+ (ThingBLESupportConnect)configConnect:(NSDictionary *)configMetas;

+ (ThingBLESupportDisconnect)configDisconnect:(NSDictionary *)configMetas;

+ (NSString *)string2JSONString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
