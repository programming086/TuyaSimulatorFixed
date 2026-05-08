//
//  TYBleTimerProtocol.h
//  TYTimerModule
//
//  Created by jesse on 2021/7/14.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@class TYTimerModel;

/// 蓝牙定时入参
@interface TYBleTimerParameter: NSObject

@property (nonatomic, copy) NSString *gwId;
@property (nonatomic, copy) NSString *devId;
@property (nonatomic, copy) NSString *category;
@property (nonatomic, copy) NSString *repeat;
@property (nonatomic, copy) NSArray  *config;
@property (nonatomic, copy) NSDictionary *timerConfig;
@property (nonatomic, assign) BOOL enableFilter;

/// 群组 1，非群组 0
@property (nonatomic, assign) NSInteger bizType;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end

/// 蓝牙定时协议
@protocol TYTimerBleTimerProtocol

@required
@property (nonatomic, readonly) TYBleTimerParameter *param;

- (instancetype)initWithParam:(TYBleTimerParameter *)param;

@optional

- (void)configParam:(TYBleTimerParameter *)param;
/// 获取定时列表
/// @param success success 定时模型
/// @param failure failure
- (void)getTimerListSuccess:(void(^)(NSArray<TYTimerModel *> *list))success
                    failure:(TYFailureError)failure;

/// 添加定时
/// @param model 定时模型
/// @param success success (timerId)
/// @param failure failure
- (void)addTimerWithModel:(TYTimerModel *)model
                  success:(TYSuccessInt)success
                  failure:(TYFailureError)failure;


/// 更新定时
/// @param model 定时 model
/// @param success success
/// @param failure failure
- (void)updateTimerWithModel:(TYTimerModel *)model
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;


/// 更新定时开关
/// @param model 定时 model
/// @param status 开 YES， 关 NO
/// @param success success
/// @param failure failure
- (void)updateTimerStatusWithModel:(TYTimerModel *)model
                            status:(BOOL)status
                           success:(TYSuccessHandler)success
                           failure:(TYFailureError)failure;

/// 移除定时
/// @param model 定时 model
/// @param success success
/// @param failure failure
- (void)removeTimerWithModel:(TYTimerModel *)model
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
