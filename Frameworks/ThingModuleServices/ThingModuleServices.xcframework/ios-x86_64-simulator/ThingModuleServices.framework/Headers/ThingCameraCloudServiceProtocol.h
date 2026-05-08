//
//  ThingCameraCloudServiceProtocol.h
//  Pods-ThingCameraCloudServiceModule_Example
//
//  Created by 傅浪 on 2020/6/6.
//

#import <Foundation/Foundation.h>
@class ThingSmartDeviceModel;
@protocol ThingCameraCloudServiceProtocol <NSObject>

- (void)requestCloudServicePageWithDevice:(ThingSmartDeviceModel *)deviceModel completionBlock:(void(^)(__kindof UIViewController *page, NSError *error))callback;

@end

