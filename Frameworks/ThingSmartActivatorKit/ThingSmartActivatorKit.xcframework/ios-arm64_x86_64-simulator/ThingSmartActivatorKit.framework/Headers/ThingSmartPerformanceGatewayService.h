
#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import "ThingSmartActivatorDefinition.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartPerformanceGatewayProperty;
@class ThingSmartPerformanceGatewaySubMaximum;

@interface ThingSmartPerformanceGatewayProperty : NSObject
@property (nonatomic, copy)   NSString *gwId;
@property (nonatomic, assign) BOOL gwAutoRelation;
@property (nonatomic, strong) ThingSmartPerformanceGatewaySubMaximum *subMaximum;
@end

@interface ThingSmartPerformanceGatewaySubMaximum : NSObject
@property (nonatomic, assign) NSInteger blu;
@property (nonatomic, assign) NSInteger zig;
@end


@interface ThingSmartPerformanceGatewayService : ThingSmartRequest


typedef void (^ThingSmartPerformanceGatewayPropertySuccess)(NSArray <ThingSmartPerformanceGatewayProperty *> *elements);
typedef NS_ENUM(NSInteger, ThingSmartPerformanceGatewayPropertyErrorCode) {
    ThingSmartPerformanceGatewayPropertyErrorCodeDeviceIDEmpty = -10000,
    ThingSmartPerformanceGatewayPropertyErrorCodeParseError,
};

- (void)gatewayPropertyGatewayIDList:(NSArray<NSString *> *)gatewayIDList success:(ThingSmartPerformanceGatewayPropertySuccess __nullable)success failure:(ThingFailureError __nullable)failure;




typedef NS_ENUM(NSInteger, ThingSmartPerformanceGatewayMiniAppURLErrorCode) {
    ThingSmartPerformanceGatewayMiniAppURLErrorCodeParserError = -10000,
};

- (void)fetchMiniAppURLWithSuccess:(ThingSuccessString __nullable)success failure:(ThingFailureError __nullable)failure;



typedef NS_ENUM(NSInteger, ThingSmartPerformanceGatewayAutoBindingErrorCode) {
    ThingSmartPerformanceGatewayAutoBindingErrorCodeGatewayEmpty = -10000,
    ThingSmartPerformanceGatewayAutoBindingErrorCodeSubDeviceIDEmpty,
    ThingSmartPerformanceGatewayAutoBindingErrorCodeSubDeviceOver,
    ThingSmartPerformanceGatewayAutoBindingErrorCodeParserError,
};

- (void)autoBindingGateway:(ThingSmartPerformanceGatewayProperty *)gatewayProperty subDeviceIDList:(NSArray<NSString *> *)subDeviceIDList success:(ThingSuccessBOOL __nullable)success failure:(ThingFailureError __nullable)failure;

@end

NS_ASSUME_NONNULL_END
