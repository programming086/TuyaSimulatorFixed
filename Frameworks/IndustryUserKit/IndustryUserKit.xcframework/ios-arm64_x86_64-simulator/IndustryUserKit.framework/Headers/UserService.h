//
//  UserService.h
//  IndustryUserKit
//
//  Created by 后主 on 2022/8/19.
//

#import <Foundation/Foundation.h>
#import "IUserService.h"

NS_ASSUME_NONNULL_BEGIN

@interface UserService : NSObject <IUserService>

+ (instancetype)shared;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
