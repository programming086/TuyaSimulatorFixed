//
//  IndustryUser.h
//  IndustryUserImpl
//
//  Created by ChenKun on 2023/5/5.
//

#import <Foundation/Foundation.h>
@import IndustryUserKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryUser : NSObject<IUser>

/**
 * The user account used for login.
 */
@property (nonatomic, copy, readonly) NSString *userName;

/**
 * The user ID used for login.
 */
@property (nonatomic, copy, readonly) NSString *userId;

/**
 * The space type
 *  1 : space type
 *  2 : asset type
 */
@property (nonatomic, assign, readonly) NSUInteger spaceType;

/**
 *  Clean User info.
 */
- (BOOL)isLogin;

/**
 *  Writes any modifications to storage.
 */
- (void)synchronize;

/**
 *  Clean User info.
 */
- (void)cleanUserInfo;

@end

NS_ASSUME_NONNULL_END
