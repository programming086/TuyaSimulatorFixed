
#import <Foundation/Foundation.h>
#import "ThingSmartVideoExtInfoType.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSNumber * thing_ipc_split_video_index;

@interface thing_ipc_split_video_frame_info : NSObject
@property (nonatomic, assign, readonly) CGFloat x;
@property (nonatomic, assign, readonly) CGFloat y;
@property (nonatomic, assign, readonly) CGFloat w;
@property (nonatomic, assign, readonly) CGFloat h;
@property (nonatomic, assign, readonly) CGFloat sizeRate;
@property (nonatomic, assign, readonly) CGSize size;
@end

@interface thing_ipc_split_video_align_info : NSObject

@property (nonatomic, assign) NSInteger align_type;
@property (nonatomic, copy) NSArray<NSArray<thing_ipc_split_video_index> *> *align_group;
@property (nonatomic, copy) NSArray<thing_ipc_split_video_index> *localizer_group;
@property (nonatomic, copy) NSArray<thing_ipc_split_video_index> *linked_group;

@end

@interface thing_ipc_split_video_info : NSObject

@property (nonatomic, assign) ThingSmartVideoIndex index;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, copy) NSArray<NSArray<thing_ipc_split_video_index> *> *res_pos;
@property (nonatomic, copy, readonly) NSArray<thing_ipc_split_video_frame_info *> *frame_infos;
@property (nonatomic, assign) NSInteger lens_type;
@property (nonatomic, assign) BOOL zoom_enable;
@property (nonatomic, strong) NSArray<NSNumber *> *support_directions;

@end

@interface thing_ipc_split_video_sum_info : NSObject

@property (nonatomic, assign) NSInteger total_split_num;
@property (nonatomic, copy) NSArray <thing_ipc_split_video_info *> *split_info;
@property (nonatomic, strong) thing_ipc_split_video_align_info *align_info;

@property (nonatomic, assign) NSInteger p_v;

@end

NS_ASSUME_NONNULL_END
