
#import <Foundation/Foundation.h>
#import "ThingSmartVideoViewType.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSUInteger ThingSmartVideoIndex;

@protocol ThingSmartVideoExtInfo <NSObject>

@property (nonatomic, assign) ThingSmartVideoIndex videoIndex;

@property (nonatomic, assign) CGSize frameSize;

@end

@protocol ThingSmartVideoViewIndexPair <NSObject>

@property (nonatomic, assign) ThingSmartVideoIndex videoIndex;
@property (nonatomic, strong) UIView<ThingSmartVideoViewType> *videoView;

@end

NS_ASSUME_NONNULL_END
