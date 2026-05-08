//
//  TYTimerBleTimer+RN.h
//  TYTimerModule
//
//  Created by jesse on 2021/8/9.
//

#import "TYTimerBleTimer.h"

NS_ASSUME_NONNULL_BEGIN

/**
 提供给 RNAPI 使用，自动切换通道
 
 errorDomain: TYTimerBleTimerErrorDomain
 */
@interface TYTimerBleTimer (RN)

- (void)rn_syncTimerListSuccess:(void(^)(NSArray<TYTimerModel *> *list))success
                        failure:(TYFailureError)failure;

- (void)rn_addTimerWithModel:(TYTimerModel *)model
                     success:(TYSuccessInt)success
                     failure:(TYFailureError)failure;

- (void)rn_updateTimerWithModel:(TYTimerModel *)model
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

- (void)rn_updateTimerStatusWithModel:(TYTimerModel *)model
                               status:(BOOL)status
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;
    
- (void)rn_removeTimerWithModel:(TYTimerModel *)model
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
