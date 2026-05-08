//
//  ThingLightingMeshModel.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingMeshModel : NSObject

@property (nonatomic, assign) NSInteger netKeyIndex;
@property (nonatomic, assign) NSInteger ivIndex;
@property (nonatomic, assign) NSInteger appKeyIndex;
@property (nonatomic, strong) NSString *appNetKeySrand;
@property (nonatomic, assign) NSInteger flag;

@end

NS_ASSUME_NONNULL_END
