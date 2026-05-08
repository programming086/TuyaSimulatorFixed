
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * ThingCameraVASCategoryCode NS_STRING_ENUM;
FOUNDATION_EXPORT ThingCameraVASCategoryCode const ThingCameraVASCategoryCodeCloud;
FOUNDATION_EXPORT ThingCameraVASCategoryCode const ThingCameraVASCategoryCodeAI;
FOUNDATION_EXPORT ThingCameraVASCategoryCode const ThingCameraVASCategoryCodeInspection;
FOUNDATION_EXPORT ThingCameraVASCategoryCode const ThingCameraVASCategoryCodeTraffic;

typedef NS_ENUM(NSInteger, ThingCameraVASHybridType) {
    ThingCameraVASHybridTypeH5 = 1,
    ThingCameraVASHybridTypeMiniApp,
    ThingCameraVASHybridTypeUnknown = 10
};

@protocol ThingSmartCameraVASResponse;
typedef void (^ThingSmartCameraVASSuccess)(id<ThingSmartCameraVASResponse> _Nullable response);
typedef void (^ThingSmartCameraVASFailure)(NSError * _Nullable error);

NS_ASSUME_NONNULL_END
