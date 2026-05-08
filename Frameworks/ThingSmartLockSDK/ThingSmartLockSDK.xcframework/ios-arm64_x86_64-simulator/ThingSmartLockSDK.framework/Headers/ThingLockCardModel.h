//
//  ThingLockCardModel.h
//  ThingSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import "ThingLiveCycleModel.h"
#import "ThingLockPasswordModel.h"

typedef NS_ENUM(NSUInteger, ThingLockLivecycleType) {
    ThingLockLivecyclePermanentType,
    ThingLockLivecyclePeriodicityType,
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingLockCardModel : NSObject

@property (nonatomic, strong) NSString *operatorName;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *periodType;
@property (nonatomic, strong) NSString *cardId;
@property (nonatomic, strong) NSString *lockId;
@property (nonatomic, assign) ThingLockActionStatus status;
@property (nonatomic, assign) ThingLockLivecycleType livecycleType;
@property (nonatomic, assign) NSTimeInterval effectiveTimeInterval;
@property (nonatomic, assign) NSTimeInterval invalidTimeInterval;


@end

NS_ASSUME_NONNULL_END
