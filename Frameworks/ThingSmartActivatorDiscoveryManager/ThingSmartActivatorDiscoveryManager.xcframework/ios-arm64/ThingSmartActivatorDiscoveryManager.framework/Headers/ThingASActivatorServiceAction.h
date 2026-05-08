//
//  ThingASActivatorServiceAction.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by 尼奥 on 2022/3/10.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorActionContextProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingASActivatorServiceAction;

typedef void (^ThingASActivatorServiceActionComplete)(void);
typedef void (^ThingASActivatorServiceActionFunc)(_Nullable id<ThingSmartActivatorActionContextProtocol>context, _Nullable ThingASActivatorServiceActionComplete complete);
typedef ThingASActivatorServiceAction* _Nonnull  (^ThingASActivatorServiceActionFuncsBuilder)(_Nonnull __strong ThingASActivatorServiceActionFunc actionFunc);

/// 配网步骤中插入的扩展行为
@interface ThingASActivatorServiceAction : NSObject

/*
Builder 执行链式调用
  action.willStartSearch(xxx)
        .didStartSearch(xxx)
        .willStartConfig(xxx)
 */

@property (nonatomic, readonly) ThingASActivatorServiceActionFuncsBuilder willStartSearch;
@property (nonatomic, readonly) ThingASActivatorServiceActionFuncsBuilder didStartSearch;
@property (nonatomic, readonly) ThingASActivatorServiceActionFuncsBuilder willStartConfig;
@property (nonatomic, readonly) ThingASActivatorServiceActionFuncsBuilder didStartConfig;
@property (nonatomic, readonly) ThingASActivatorServiceActionFuncsBuilder willStopConfig;
@property (nonatomic, readonly) ThingASActivatorServiceActionFuncsBuilder didStopConfig;
@property (nonatomic, readonly) ThingASActivatorServiceActionFuncsBuilder willStopScan;
@property (nonatomic, readonly) ThingASActivatorServiceActionFuncsBuilder didStopScan;

#pragma mark - API


- (void)willStartSearch:(_Nullable ThingASActivatorServiceActionComplete)complete context:(id<ThingSmartActivatorActionContextProtocol>)context;
- (void)didStartSearch:(_Nullable ThingASActivatorServiceActionComplete)complete context:(id<ThingSmartActivatorActionContextProtocol>)context;

- (void)willStopScan:(_Nullable ThingASActivatorServiceActionComplete)complete context:(id<ThingSmartActivatorActionContextProtocol>)context;
- (void)didStopScan:(_Nullable ThingASActivatorServiceActionComplete)complete context:(id<ThingSmartActivatorActionContextProtocol>)context;


- (void)willStartConfig:(_Nullable ThingASActivatorServiceActionComplete)complete context:(id<ThingSmartActivatorActionContextProtocol>)context;
- (void)didStartConfig:(_Nullable ThingASActivatorServiceActionComplete)complete context:(id<ThingSmartActivatorActionContextProtocol>)context;


- (void)willStopConfig:(_Nullable ThingASActivatorServiceActionComplete)complete context:(id<ThingSmartActivatorActionContextProtocol>)context;
- (void)didStopConfig:(_Nullable ThingASActivatorServiceActionComplete)complete context:(id<ThingSmartActivatorActionContextProtocol>)context;

@end

NS_ASSUME_NONNULL_END
