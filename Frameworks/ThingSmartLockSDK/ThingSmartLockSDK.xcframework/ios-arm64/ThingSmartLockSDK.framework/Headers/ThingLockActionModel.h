//
//  ThingLockOperateModel.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLockActionModel : NSObject

@property (nonatomic, strong) NSString *type;
@property (nonatomic, assign) NSTimeInterval time;
@property (nonatomic, strong) NSString *user;

@end

NS_ASSUME_NONNULL_END
