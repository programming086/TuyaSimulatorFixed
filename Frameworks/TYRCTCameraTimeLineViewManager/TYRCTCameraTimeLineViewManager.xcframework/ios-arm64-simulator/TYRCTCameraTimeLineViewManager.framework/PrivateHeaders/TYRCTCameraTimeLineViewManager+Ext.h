//
//  TYRCTCameraTimeLineViewManager+Ext.h
//
//  Auto-Created on 2019/11/28.
//  Copyright © 2019年 Tuya. All rights reserved.
//


#import <Foundation/Foundation.h>

/**
 * 由于类文件会被覆盖重写，请在 Ext.h 文件的匿名分类（扩展）中声明所需使用的属性
 * 注意：所有类文件中的修改在插件构建时都将被重置
 */
@interface TYRCTCameraTimeLineViewManager ()

@property (nonatomic, strong) NSArray *periods;

@property (nonatomic, strong) NSString *playbackDay;

@property (nonatomic, strong) NSString * currentTime;

@property (nonatomic, copy) RCTBubblingEventBlock onChange;

// 0：竖屏，1：横屏
@property (nonatomic, assign) int orientation;

@end
