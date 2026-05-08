
#import <Foundation/Foundation.h>
#import "ThingSmartCameraVASConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCameraVASParams <NSObject>

///homeId
@property (nonatomic, assign) long long spaceId;

///standard language code.
@property (nonatomic, copy) NSString *languageCode;

///hybrid type, default is miniApp that is suggested.
@property (nonatomic, assign) ThingCameraVASHybridType hybridType;

///device id
@property (nonatomic, copy, nullable) NSString *devId;

/// extra info
@property (nonatomic, copy, nullable) NSDictionary *extInfo;

@end

@protocol ThingSmartCameraVASResponse <NSObject>

/// url
@property (nonatomic, copy, nullable) NSString *url;

///hybrid type
@property (nonatomic, assign) ThingCameraVASHybridType hybridType;

@end

@interface ThingSmartCameraVASParams : NSObject <ThingSmartCameraVASParams>

///service category code
@property (nonatomic, copy) ThingCameraVASCategoryCode categoryCode;

- (instancetype)initWithSpaceId:(long long)spaceId languageCode:(NSString *)languageCode hybridType:(ThingCameraVASHybridType)hybridType categoryCode:(ThingCameraVASCategoryCode)categoryCode devId:(nullable NSString *)devId extInfo:(nullable NSDictionary *)extInfo;

@end

@interface ThingSmartCameraVASInspectionParams : NSObject <ThingSmartCameraVASParams>

///device id
@property (nonatomic, copy) NSString *devId;

///get from 'ThingSmartCameraMessageModel'
@property (nonatomic, assign) NSInteger time;

///get from 'ThingSmartCameraMessageModel.extendParams[@"inspectionReportId"]'
@property (nonatomic, copy) NSString *reportId;

- (instancetype)initWithSpaceId:(long long)spaceId devId:(NSString *)devId languageCode:(NSString *)languageCode hybridType:(ThingCameraVASHybridType)hybridType reportId:(NSString *)reportId time:(NSInteger)time extInfo:(nullable NSDictionary *)extInfo;

@end


NS_ASSUME_NONNULL_END
