//
//  ThingSmartSceneExprModel.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)
//

#import <Foundation/Foundation.h>

/// @brief Scene expression model, it can be defined as any type.
@interface ThingSmartSceneExprModel : NSObject

/// Used to store expression data, it can be used as any type.
@property (nonatomic, strong) NSArray *expr;

/// Initialization generates an expr object.
/// @param expr The expression data, the data in the array can be of any type.
///
/// @return A expr model object.
- (instancetype)initWithExpr:(NSArray *)expr;

+ (instancetype)exprModelWithExpr:(NSArray *)expr;

@end

