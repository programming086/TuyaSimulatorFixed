
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingSuccessHandler)(void);
typedef void (^ThingFailureError)(NSError *error);

@protocol ThingSmartCameraDebugAbilityDelegate <NSObject>

- (void)cameraDidUploadLogWithResult:(BOOL)result extInfo:(nullable NSDictionary *)extInfo;

@end

@protocol ThingSmartCameraUploadLogConfig <NSObject>

@property (nonatomic, assign) NSTimeInterval uploadTimeout;

@end

@protocol ThingSmartCameraExtraAbility <NSObject>

#pragma mark - debug ability

@property (nonatomic, assign, readonly) BOOL hasRespondToUploadLogCmdAbility;

@property (nonatomic, weak) id <ThingSmartCameraDebugAbilityDelegate> debugAbilityDelegate;

- (void)deliverUploadLogCmdWithConfig:(id<ThingSmartCameraUploadLogConfig>)config success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
