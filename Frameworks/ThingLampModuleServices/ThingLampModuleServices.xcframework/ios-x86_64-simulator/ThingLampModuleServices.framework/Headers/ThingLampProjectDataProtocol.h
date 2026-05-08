//
//  ThingLampProjectDataProtocol.h
//  Pods
//
//  Created by SanTong on 2021/3/29.
//

#import <Foundation/Foundation.h>

@class ThingLightingProject;
@class ThingLightingAreaModel;

@protocol ThingLampProjectDataProtocol <NSObject>

/**
 清除当前项目并清除缓存
 */
- (void)clearCurrentProject;

/**
 要使用该API获取当前项目，请务必在更新当前id的时候使用该协议的’updateCurrentProjectId:‘Api。
 获取当前的项目，当前没有项目的时候，返回nil。
 
 @return ThingSmartProject
 */
- (ThingLightingProject *)getCurrentProject;


/**
 更新当前的项目id并写到GroupUserDefault缓存中

 @param projectId 项目id
 */
- (void)updateCurrentProjectId:(NSInteger)projectId;

/// 获取当前项目 ID
- (NSInteger)currentProjectId;

#pragma mark - 2.0 版本新增接口

/// 返回当前空间 Id
- (NSInteger)currentAreaId;

/// 切换空间后，调用该接口以更新当前空间 Id。
- (void)setCurrentAreaId:(NSInteger)areaId;

/// 切换至根空间。（根空间对应于未分区，其空间的 gId 与项目的 projectId 相同。）
- (void)resetCurrentAreaId;

/// 返回当前空间 Model
- (ThingLightingAreaModel *)currentArea;

/// 返回当前空间 gId
- (NSInteger)currentGId;

@end
