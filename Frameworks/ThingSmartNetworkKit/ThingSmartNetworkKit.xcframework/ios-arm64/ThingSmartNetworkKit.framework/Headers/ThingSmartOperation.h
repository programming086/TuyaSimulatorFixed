
#import <Foundation/Foundation.h>
#import "ThingSmartResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartOperation : NSOperation

- (void)execute;
- (void)finish;

@end

@interface ThingSmartRequestOperation <__covariant ResponseDataType, __covariant ProcessedObjType> : ThingSmartOperation

@property (nonatomic, strong) NSString *apiName;
@property (nonatomic, strong) NSString *apiVersion;
@property (nonatomic, strong) NSDictionary *params;
@property (nonatomic, copy) ThingSmartResult<ResponseDataType, NSError *> *originResponseData;
@property (nonatomic, strong, readonly) ProcessedObjType data;

+ (instancetype)operationWithApiName:(NSString *)apiName
                          apiVersion:(NSString *)apiVersion
                              params:(nullable NSDictionary *)params
                     responseHandler:(nullable ProcessedObjType (^)(ThingSmartResult<ResponseDataType, NSError *> *result))responseHandler
                          completion:(nullable void(^)(void))completion;

@end

NS_ASSUME_NONNULL_END
