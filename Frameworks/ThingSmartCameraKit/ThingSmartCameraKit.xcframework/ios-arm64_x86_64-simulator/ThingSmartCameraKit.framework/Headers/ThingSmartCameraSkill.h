
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartCameraBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCameraSkill <NSObject>

@property (nonatomic, copy, readonly) NSDictionary *skillConfigs;
@property (nonatomic, assign, readonly) NSInteger videoNumber;
@property (nonatomic, assign, readonly) ThingSmartCameraDefinition defaultDefinition;

@property (nonatomic, assign, readonly) BOOL isSpeakerEnabled;
@property (nonatomic, assign, readonly) BOOL isPickupEnabled;
@property (nonatomic, assign, readonly) ThingSmartCameraTalkbackMode defaultTalkbackMode;
@property (nonatomic, assign, readonly) BOOL talkbackModeEditEnabled;

@property (nonatomic, strong, readonly) NSNumber *maxZoomScale;
@property (nonatomic, copy, readonly) NSArray *zoomScales;

@end

typedef void(^ThingCameraSkillSyncCompletion)(id<ThingSmartCameraSkill> skill, BOOL cached);

@interface ThingSmartCameraSkill : NSObject <ThingSmartCameraSkill>

+ (nullable id<ThingSmartCameraSkill>)queryCameraSkilWithDevId:(NSString *)devId completion:(ThingCameraSkillSyncCompletion)completion;

@end

NS_ASSUME_NONNULL_END
