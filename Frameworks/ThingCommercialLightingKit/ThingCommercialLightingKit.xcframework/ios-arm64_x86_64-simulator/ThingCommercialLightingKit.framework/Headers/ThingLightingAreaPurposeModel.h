//
//  ThingLightingAreaPurposeModel.h
// ThingSmartCommercialLightingSdk
//
// Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingAreaDevicePurposeModel : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong) NSArray<ThingLightingAreaDevicePurposeModel *> *devicePurposes;

@end



@interface ThingLightingAreaSpacePurposeModel : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong) NSArray<ThingLightingAreaSpacePurposeModel *> *spacePurposes;

@end

NS_ASSUME_NONNULL_END
