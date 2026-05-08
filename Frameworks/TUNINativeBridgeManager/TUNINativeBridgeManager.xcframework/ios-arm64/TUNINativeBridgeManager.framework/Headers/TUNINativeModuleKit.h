
#import <Foundation/Foundation.h>
#import "TUNINativeBridgeContext.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TUNINativeModuleKitProtocol <NSObject>


@optional
/**
 插件开始释放，手工调用，若不调用，跟随ModuleKit生命周期
 */
- (void)destroy;

/**
 * 当容器暂停时调用此方法。
 * 实现容器状态转换为暂停时应执行的逻辑。
 */
- (void)onContainerPause;

/**
 * 当容器恢复时调用此方法。
 * 实现容器状态转换为恢复时应执行的逻辑。
 */
- (void)onContainerResume;

@required

+ (NSArray <NSString *>*)supportNativeModules;

@end

@interface TUNINativeModuleKit : NSObject<TUNINativeModuleKitProtocol>

/**
 执行环境
 */
@property (nonatomic, strong, readonly) TUNINativeBridgeContext *context;
/**
 执行队列
 */
@property (nonatomic, strong, readonly) dispatch_queue_t invokeQueue;

- (instancetype)init;
- (instancetype)initWithContext:(TUNINativeBridgeContext *)nativeBridgeContext;


@end

NS_ASSUME_NONNULL_END
