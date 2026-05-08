
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartLocalVideoInfoType.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartLocalVideoInfo : NSObject <ThingSmartLocalVideoInfoType>

+ (instancetype)localVideoInfoWithFrameRate:(NSInteger)frameRate width:(CGFloat)width height:(CGFloat)height;

@property (nonatomic, assign) NSInteger codecType;

- (BOOL)validateFrameRate:(NSInteger)frameRate;

@end

NS_ASSUME_NONNULL_END
