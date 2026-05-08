
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartLocalVideoInfoType <NSObject>

///frame size
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

///frame rate, default is 15.
@property (nonatomic, assign) NSInteger frameRate;

@end

NS_ASSUME_NONNULL_END
