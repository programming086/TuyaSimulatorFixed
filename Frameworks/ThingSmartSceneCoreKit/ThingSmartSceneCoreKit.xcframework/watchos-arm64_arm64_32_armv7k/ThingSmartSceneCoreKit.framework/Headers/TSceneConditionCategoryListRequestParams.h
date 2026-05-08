//
//  TSceneConditionCategoryListRequestParams.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TSceneConditionCategoryListRequestParams : NSObject

/// Whether to display Fahrenheit.
@property (nonatomic, assign) BOOL showFahrenheit;

/// The conditional ability property, according to the binary number, starting from the lowest standard, the lowest fixed 0, from the right test, respectively, indicating the door lock conditions, face recognition conditions, security conditions. Now fix the parameter 00001110, which is 14, and later add the need to change the value of this field.
@property (nonatomic, assign) NSInteger condAbility;

/// Wind speed unit, default is nil.
@property (nonatomic, copy, nullable) NSString *windSpeedUnit;

@end

NS_ASSUME_NONNULL_END
