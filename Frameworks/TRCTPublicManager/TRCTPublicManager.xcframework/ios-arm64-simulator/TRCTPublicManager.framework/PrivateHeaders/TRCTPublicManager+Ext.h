//
//  TRCTPublicManager+Ext.h
//
//  Auto-Created on 2019/10/21.
//  Copyright © 2019年 Thing. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <TheAmazingAudioEngine/TheAmazingAudioEngine.h>

/**
 * 由于类文件会被覆盖重写，请在 Ext.h 文件的匿名分类（扩展）中声明所需使用的属性
 * 注意：所有类文件中的修改在插件构建时都将被重置
 */
@interface TRCTPublicManager ()

@property (strong, nonatomic) NSTimer *timer;
@property (strong, nonatomic) AEAudioController *audioController;
@property (assign, nonatomic) BOOL isObserving;

@end
