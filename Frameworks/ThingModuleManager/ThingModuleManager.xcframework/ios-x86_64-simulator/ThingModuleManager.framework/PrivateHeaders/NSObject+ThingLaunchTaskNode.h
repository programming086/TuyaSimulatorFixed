//
//  NSObject+ThingLaunchTaskNode.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/10/23.
//

#import <Foundation/Foundation.h>

#import "ThingLaunchTaskProtocol.h"

@interface NSObject (ThingLaunchTaskNode)

@property (nonatomic, strong, readonly) NSMutableArray<id<ThingLaunchTaskProtocol>> *parentArr;
@property (nonatomic, strong, readonly) NSMutableArray<id<ThingLaunchTaskProtocol>> *childArr;

@end
