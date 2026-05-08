//
//  ThingFingerPrintModel.h
//  ThingSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import "ThingLockCardModel.h"
#import "ThingLockPasswordModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingLockFingerprintModel : NSObject

@property (nonatomic, strong) NSString *operatorName;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *periodType;
@property (nonatomic, strong) NSString *fingerprintId;
@property (nonatomic, strong) NSString *lockId;
@property (nonatomic, assign) ThingLockActionStatus status;
@property (nonatomic, assign) ThingLockLivecycleType livecycleType;
@property (nonatomic, assign) NSTimeInterval effectiveTimeInterval;
@property (nonatomic, assign) NSTimeInterval invalidTimeInterval;

@end

NS_ASSUME_NONNULL_END
