//
//  ThingCloudStorageDebugger.h
//  ThingCloudStorageDebugger
//
//  Created by 傅浪 on 2020/11/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ThingCloudStorageDebugger : NSObject

@property (nonatomic, assign) long long deviceSpaceId;

@property (nonatomic, strong) UINavigationController *navi;

+ (instancetype)sharedInstance;

- (void)startWithDeviceSpaceId:(long long)deviceSpaceId navigationController:(UINavigationController *)navi;

@end
