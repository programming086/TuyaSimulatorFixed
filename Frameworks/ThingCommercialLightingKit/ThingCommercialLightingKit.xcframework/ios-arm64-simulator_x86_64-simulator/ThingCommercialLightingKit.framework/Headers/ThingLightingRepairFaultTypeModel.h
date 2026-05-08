//
//  ThingLightingRepairFaultTypeModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingRepairFaultTypeModel : NSObject

/// The code of repair order fault type
@property (nonatomic, strong) NSString *code;

/// The value of repair order fault type
@property (nonatomic, strong) NSString *value;

@end

NS_ASSUME_NONNULL_END
