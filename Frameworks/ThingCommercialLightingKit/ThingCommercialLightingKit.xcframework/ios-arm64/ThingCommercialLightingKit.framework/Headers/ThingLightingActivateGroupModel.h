//
//  ThingLightingActivateGroupModel.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingActivateGroupModel : NSObject

@property (nonatomic, assign) long long gid;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *localId;
@property (nonatomic, strong) NSMutableArray<NSNumber *> *nodeIds;

@end

NS_ASSUME_NONNULL_END
