
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartCameraAdvancedConfigType.h>
#import <ThingSmartCameraBase/ThingSmartVideoExtInfoType.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSNumber * thing_ipc_split_video_index;



@interface thing_ipc_split_video_infos : NSObject

@property (nonatomic, assign) ThingSmartVideoIndex index;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, copy) NSArray<NSArray<thing_ipc_split_video_index> *> *res_pos;
@property (nonatomic, copy, readonly) NSArray<thing_ipc_split_video_frame_info *> *frame_infos;
@property (nonatomic, assign) NSInteger lens_type;
@property (nonatomic, assign) BOOL zoom_enable;

@end


@interface ThingSmartCameraAdvancedConfig : NSObject <ThingSmartCameraAdvancedConfig>

- (instancetype)initWithConfigMetas:(NSDictionary *)configMetas;

@property (nonatomic, strong, readonly) thing_ipc_split_video_sum_info *split_video_sum_info;

@property (nonatomic, assign, readonly) BOOL isVersion2Config;

@property (nonatomic, assign, readonly) NSInteger protocolVersion;

@end

NS_ASSUME_NONNULL_END
