
#import <Foundation/Foundation.h>
#import "ThingSmartActivatorDefinition.h"

@class ThingSmartPerformanceGatewayProperty;
@class ThingSmartPerformanceGatewaySubMaximum;

NS_ASSUME_NONNULL_BEGIN


@interface ThingSmartPerformanceGateway : NSObject


- (BOOL)shouldBindForSuccessActivatorDevices:(NSArray <ThingSmartDeviceModel *> *)successActivatorDevices;


typedef NS_ENUM(NSInteger, ThingSmartPerformanceGatewayActionType) {
    ThingSmartPerformanceGatewayActionTypeIdle,
    ThingSmartPerformanceGatewayActionTypeAuto,
    ThingSmartPerformanceGatewayActionTypeManual
};

typedef NS_ENUM(NSInteger, ThingSmartPerformanceGatewayActionTypeErrorCode) {
    ThingSmartPerformanceGatewayActionTypeErrorCodeHomeID = -10000,
    ThingSmartPerformanceGatewayActionTypeErrorCodeNoDevice,
    ThingSmartPerformanceGatewayActionTypeErrorCodeNoGateway,
    ThingSmartPerformanceGatewayActionTypeErrorCodeNoSubDevice,
    ThingSmartPerformanceGatewayActionTypeErrorCodeRequestProerty,
    ThingSmartPerformanceGatewayActionTypeErrorCodeNoPerformanceDevice,
    ThingSmartPerformanceGatewayActionTypeErrorCodePerformanceDeviceOver,
    ThingSmartPerformanceGatewayActionTypeErrorCodeMiniAppURLFailed,
};


extern NSString *const ThingSmartPerformanceGatewayAutoBindErrorKey;

extern NSString *const ThingSmartPerformanceGatewayAutoBindGatewayPropertyKey;

extern NSString *const ThingSmartPerformanceGatewayAutoBindSubDeviceIDListKey;

extern NSString *const ThingSmartPerformanceGatewayAutoBindGatewayMiniAppURLKey;

typedef void(^ThingSmartPerformanceGatewayAutoBindComplete)(ThingSmartPerformanceGatewayActionType actionType, NSDictionary *__nullable userInfo);


- (void)autoBindRoomDevicesWithRoomID:(ThingSmartHomeID)homeID complete:(ThingSmartPerformanceGatewayAutoBindComplete)complete;


- (void)autoBindingGateway:(ThingSmartPerformanceGatewayProperty *)gatewayProperty subDeviceIDList:(NSArray<NSString *> *)subDeviceIDList success:(ThingSuccessBOOL __nullable)success failure:(ThingFailureError __nullable)failure;

@end

NS_ASSUME_NONNULL_END
