//
//  ThingLightingResourcePoolModel.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingResourcePoolModel : NSObject

@property (nonatomic, strong) NSArray<NSNumber *> *nodeIds;
@property (nonatomic, strong) NSArray<NSString *> *groups;
@property (nonatomic, strong) NSArray<NSString *> *pubAddress;

@end

NS_ASSUME_NONNULL_END
