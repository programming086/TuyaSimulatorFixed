//
//  TYSQHomeDataProtocol.h
//  Pods
//
//  Created by WenMingYan on 2021/1/6.
//

#ifndef TYSQHomeDataProtocol_h
#define TYSQHomeDataProtocol_h

@class TuyaCommunityHouse;
@class TuyaCommunityHouseModel;

@protocol TYSQHomeDataProtocol <NSObject>


/**
 清除当前家庭并清除缓存
 */
- (void)clearCurrentHouse;

/**
 要使用该API获取当前家庭，请务必在更新当前家庭id的时候使用该协议的’updateCurrentHouseId:‘Api。
 获取当前的家庭，当前没有家庭的时候，返回nil。
 
 @return TuyaSmartHome
 */
- (TuyaCommunityHouse *)getCurrentHouse;


/**
 获取当前家庭id
 */
- (long long)getCurrentHouseId;

/**
 获取当前房屋id
 */
- (NSString *)getCurrentRoomId;

/**
 获取当前家庭项目id
 */
- (NSString *)getCurrentHouseProjectId;

/**
 获取当前房屋小区id
 */
- (NSString *)getCurrentHouseCommunityId;

/**
 获取当前家庭model
 */
- (TuyaCommunityHouseModel *)getCurrentHouseModel;

/**
 更新当前的家庭id并写到GroupUserDefault缓存中

 @param houseId 家庭id
 */
- (void)updateCurrentHouseId:(long long)houseId;



@end
#endif /* TYSQHomeDataProtocol_h */
