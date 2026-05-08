//
//  IUser.h
//  IndustryUserKit
//
//  Created by 后主 on 2022/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IUser <NSObject>

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
 *  1 : space
 *  2 : asset
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
