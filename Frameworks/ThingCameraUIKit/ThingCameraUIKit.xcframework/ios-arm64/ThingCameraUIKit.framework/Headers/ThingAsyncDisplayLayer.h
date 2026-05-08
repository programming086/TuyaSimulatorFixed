
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@class ThingAsyncDisplayLayer;
@protocol ThingAsyncDisplayLayerDelegate <NSObject>
@optional
- (void)asyncDisplayLayerWillDisplay:(ThingAsyncDisplayLayer *)layer;

- (void)asyncDisplayLayer:(ThingAsyncDisplayLayer *)layer
                 drawRect:(CGRect)rect
                inContext:(CGContextRef)ctx
              isCancelled:(BOOL(^)(void))isCancelled;

- (void)asyncDisplayLayer:(ThingAsyncDisplayLayer *)layer didDisplay:(BOOL)complete;

@end

@interface ThingAsyncDisplayLayer : CALayer

@property (nonatomic, assign) BOOL displaysAsynchronously;

@property (nonatomic, assign) BOOL autoCancel;

@property (nonatomic, strong) dispatch_queue_t displaysQueue;

@property (nonatomic, weak) id<ThingAsyncDisplayLayerDelegate> displayDelegate;

- (void)cancel;

@end
