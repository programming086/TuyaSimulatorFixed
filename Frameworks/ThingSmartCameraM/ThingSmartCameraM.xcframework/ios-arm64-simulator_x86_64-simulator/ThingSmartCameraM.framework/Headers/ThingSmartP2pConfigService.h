
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartCameraType.h>
#import <ThingSmartCameraBase/ThingSmartCameraFactory.h>

@class ThingSmartDeviceModel;
@interface ThingSmartP2pConfigService : NSObject

+ (void)requestConfigWithDeviceModel:(ThingSmartDeviceModel *)deviceModel
                             traceId:(NSString *)traceId
                             success:(void(^)(NSDictionary *config, BOOL fromCache))success
                             failure:(void(^)(NSInteger errCode))failure  DEPRECATED_MSG_ATTRIBUTE(("This method is deprecated,use 'requestConfig:traceId:extraData:success:failure'"));

+ (void)requestConfigWithDeviceModel:(ThingSmartDeviceModel *)deviceModel
                             traceId:(NSString *)traceId
                           extraData:(NSDictionary *)extraData
                             success:(void(^)(NSDictionary *config, BOOL fromCache))success
                             failure:(void(^)(NSInteger errCode))failure DEPRECATED_MSG_ATTRIBUTE(("This method is deprecated,use 'requestConfig:traceId:extraData:success:failure'"));

+ (void)requestConfig:(ThingSmartDeviceModel *)deviceModel
              traceId:(NSString *)traceId
            extraData:(NSDictionary *)extraData
              success:(void(^)(ThingSmartCameraConfig *config, BOOL fromCache))success
              failure:(void(^)(NSInteger errCode))failure;

/// 获取缓存的 p2p config
+ (ThingSmartCameraConfig *)getCachedConfigModelWithDeviceModel:(ThingSmartDeviceModel *)deviceModel;


/// 获取缓存的 p2p config
+ (NSDictionary *)getCachedConfigWithDeviceModel:(ThingSmartDeviceModel *)deviceModel;

/// 将 p2p config 缓存到本地
+ (void)cacheConfig:(NSDictionary *)config forDeviceModel:(ThingSmartDeviceModel *)deviceModel;

+ (void)removeCachedConfigForDeviceModel:(ThingSmartDeviceModel *)deviceModel;

+ (void)queryDeviceSkillsFromLocalChannel:(ThingSmartDeviceModel *)deviceModel;

+ (nullable NSString *)sessionTraceIdWithDeviceModel:(ThingSmartDeviceModel *)deviceModel;

@end

