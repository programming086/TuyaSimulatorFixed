//
//  IToysStory.h
//  Pods
//
//  Copyright (c) 2014-2025 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IToysStory : NSObject

/**
 * 获取家庭下的成员列表
 * @param homeId 家庭ID
 * @param success 成功回调，返回成员列表 (ThingSmartHomeMemberModel 数组)
 * @param failure 失败回调，返回错误信息
 */
- (void)getMembersWithHomeId:(long long)homeId
                     success:(void (^)(NSArray<ThingSmartHomeMemberModel *> *memberList))success
                     failure:(ThingFailureError)failure;

/**
 * 更新成员的名称
 * @param memberId 成员ID 
 * @param newName 新的名称
 * @param success 成功回调
 * @param failure 失败回调，返回错误信息
 */
- (void)updateMemberNameWithMemberId:(long long)memberId
                             newName:(NSString *)newName
                             success:(ThingSuccessDict)success
                             failure:(ThingFailureError)failure;

/**
 * 更新头像
 * @param image 头像图片
 * @param success 成功回调
 * @param failure 失败回调，返回错误信息
 */
+ (void)updateAvatarWithImage:(UIImage *)image
                      success:(nullable ThingSuccessHandler)success
                      failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
