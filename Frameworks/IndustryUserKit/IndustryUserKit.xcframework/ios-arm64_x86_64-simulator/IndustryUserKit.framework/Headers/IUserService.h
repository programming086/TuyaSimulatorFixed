//
//  IUserService.h
//  IndustryUserKit
//
//  Created by 后主 on 2022/8/19.
//

#import <Foundation/Foundation.h>
#import "IUser.h"

@import IndustryAuthKit;

NS_ASSUME_NONNULL_BEGIN

@protocol IUserService <NSObject>

/// Get user instance.
- (nullable id<IUser>)user;

/// Enables login with an params.
/// @param params The params.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithParams:(NSDictionary *)params
                success:(void(^)(void))success
                failure:(void(^)(NSError *))failure;

/// Logout.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)logoutSuccess:(void(^)(void))success
              failure:(void(^)(NSError *))failure;

/// Get user information.
/// @param params The params.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getUserDetailWithParams:(NSDictionary *_Nullable)params
                        success:(void(^)(NSDictionary *))success
                        failure:(void(^)(NSError *))failure;

@end

NS_ASSUME_NONNULL_END
