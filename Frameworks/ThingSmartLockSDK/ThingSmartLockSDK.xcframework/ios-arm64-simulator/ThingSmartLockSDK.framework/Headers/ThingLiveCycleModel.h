//
//  ThingLiveCycleModel.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLiveCycleModel : NSObject

@property (nonatomic, strong) NSString *workingDay;
@property (nonatomic, strong) NSString *startMinute;
@property (nonatomic, strong) NSString *endMinute;
@property (nonatomic, assign) NSTimeInterval effectiveTimeInterval;
@property (nonatomic, assign) NSTimeInterval invalidTimeInterval;


@end

NS_ASSUME_NONNULL_END
