
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerBleSyncTask : NSObject

@property (nonatomic, copy, readonly) NSString *deviceId;

/// Unique identifier for the task, used only for debugging.
@property (nonatomic, copy, readonly) NSString *identifier;

/// Data of the command.
@property (nonatomic, readonly) NSData *data;

/// Description of the task.
@property (nullable, nonatomic, copy) NSString *desc;

@property (nullable, nonatomic, copy, readonly) void(^completion)(NSData * _Nullable data, NSError *_Nullable error);


+ (instancetype)taskWithDeviceId:(NSString *)deviceId identifier:(NSString *)identifier data:(NSData *)data completion:(void(^)(NSData * _Nullable data, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
