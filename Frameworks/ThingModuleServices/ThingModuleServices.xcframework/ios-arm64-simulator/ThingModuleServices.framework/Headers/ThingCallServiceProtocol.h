//
//  ThingCallServiceProtocol.h
//  Pods
//
//  Created by 后主 on 2023/3/16.
//

#ifndef ThingCallServiceProtocol_h
#define ThingCallServiceProtocol_h

NS_ASSUME_NONNULL_BEGIN

@protocol ThingCallServiceProtocol <NSObject>

/// 是否正在通话中
- (BOOL)isCalling;

/// 是否可以发起呼叫
- (BOOL)canLaunchCall;


/// start call
- (void)startCallWithTargetId:(NSString *)targetId timeout:(NSInteger)timeout extra:(NSDictionary *)extra success:(nullable void(^)(void))success failure:(nullable void(^)(NSError *))failure;


/// handle push message
- (void)handlePushMessageHandle:(NSDictionary *)message;

@end

NS_ASSUME_NONNULL_END


#endif /* ThingCallServiceProtocol_h */
