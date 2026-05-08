//
//  ThingEKeyModel.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLiveCycleModel;


@interface ThingEKeyModel : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *unlockId;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *account;
@property (nonatomic, strong) NSString *operatorName;
@property (nonatomic, strong) NSString *eKeyId;
@property (nonatomic, strong) NSString *accountType;
@property (nonatomic, assign) BOOL remoteUnlock;
@property (nonatomic, strong) ThingLiveCycleModel *liveCycle;

@end

NS_ASSUME_NONNULL_END
