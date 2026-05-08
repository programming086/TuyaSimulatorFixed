
#import <Foundation/Foundation.h>
#import "ThingSmartCallChannelConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartCallEventMessageExt <NSObject>

@property (nonatomic, assign) ThingSmartCallMode channelType;

@property (nonatomic, copy) NSString *category;

@property (nonatomic, copy) ThingSmartCallExtBizType bizType;

@property (nonatomic, assign) int theme;
@property (nonatomic, assign) BOOL keepConnect;

@property (nonatomic, assign, readonly) BOOL isIPCBiz;

@end

NS_ASSUME_NONNULL_END
