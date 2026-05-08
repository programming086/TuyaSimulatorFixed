
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMiniAppExtApiModelProtocol;

typedef void (^ThingMiniExtApiResponseCallback)(id<ThingMiniAppExtApiModelProtocol> model);

typedef NS_ENUM(NSInteger, ThingMiniAppExtApiModelStatus) {
    ThingMiniAppExtApiModelStatusSuccess = 0,
    ThingMiniAppExtApiModelStatusFailure = 1
};

@protocol ThingMiniAppExtApiModelProtocol <NSObject>

@property (nonatomic, assign, readonly) ThingMiniAppExtApiModelStatus status;
@property (nonatomic, copy,   readonly) NSString *errorCode;
@property (nonatomic, copy,   readonly) NSString *errorMsg;
@property (nonatomic, strong, readonly) id data;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)successExtApiModel;
+ (instancetype)successExtApiModelWithData:(nullable id)data;
+ (instancetype)failureExtApiModel:(nullable NSString *)errorCode;
+ (instancetype)failureExtApiModel:(nullable NSString *)errorCode
                          errorMsg:(nullable NSString *)errorMsg;

@end

NS_ASSUME_NONNULL_END
