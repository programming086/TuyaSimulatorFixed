//
//  ThingLightingSenceTemplateModel.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//@class ThingLightingSenceTemplateItemModel;
//@class ThingLightingSenceTemplateSelectorModel;

@interface ThingLightingSenceTemplateSelectorModel : NSObject

@property (nonatomic, strong) NSString *topCategory;
@property (nonatomic, strong) NSString *devicePurpose;
@property (nonatomic, strong) NSString *spacePurpose;
@property (nonatomic, strong) NSString *spacePurposeName;
@property (nonatomic, strong) NSString *devicePurposeName;

@end


@interface ThingLightingSenceTemplateItemModel : NSObject

@property (nonatomic, strong) ThingLightingSenceTemplateSelectorModel *selector;
@property (nonatomic, assign) NSInteger selectorType;
@property (nonatomic, strong) NSDictionary *strategyExpr;
@property (nonatomic, assign) NSInteger strategyType;

@end


@interface ThingLightingSenceTemplateModel : NSObject

@property (nonatomic, strong) NSString *templateId;
@property (nonatomic, strong) NSString *templateName;
@property (nonatomic, strong) NSArray<ThingLightingSenceTemplateItemModel *> *configs;

@end






NS_ASSUME_NONNULL_END
