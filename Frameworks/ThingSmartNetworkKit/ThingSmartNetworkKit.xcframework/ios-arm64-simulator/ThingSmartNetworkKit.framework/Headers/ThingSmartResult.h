
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingResultType) {
    ThingResultSuccess,
    ThingResultFailure,
};

@interface ThingSmartResult <__covariant T, __covariant E> : NSObject

@property (nonatomic, strong, readonly, nullable) T data;
@property (nonatomic, strong, readonly, nullable) E error;

@property (readonly) ThingResultType type;

- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

+ (nonnull ThingSmartResult *)success:(nonnull T)data;
+ (nonnull ThingSmartResult *)failure:(nonnull E)error;

- (BOOL)isSuccess;
- (BOOL)isFailure;

@end

NS_ASSUME_NONNULL_END
