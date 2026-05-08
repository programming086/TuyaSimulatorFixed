//
//  ThingPersonalServiceProtocol.h
//  ThingModuleServices
//
//  Created by ThingInc on 2019/5/28.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, ThingPersonalServiceType) {
    ThingPersonalServiceTypePushCall,
    ThingPersonalServiceTypePushSMS,
};


@protocol ThingPersonalServiceProtocol <NSObject>

/// 获取增值服务页面
- (void)requestPersonalService:(ThingPersonalServiceType)type completionBlock:(void(^)(__kindof UIViewController *page, NSError *error))callback;
@end

