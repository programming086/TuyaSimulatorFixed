//
//  ThingSmartMultiControlParentRuleModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMultiControlParentRuleDpModel : NSObject

@property (copy, nonatomic) NSString *dpId;///< The DP ID.
@property (copy, nonatomic) NSString *dpName;///< The DP name.

@end

@interface ThingSmartMultiControlParentRuleModel : NSObject

@property (copy, nonatomic) NSString *ruleId;///< The automation ID.
@property (copy, nonatomic) NSString *name;///< The automation name.

@property (strong, nonatomic) NSArray<ThingSmartMultiControlParentRuleDpModel *> *dpList;

@end

NS_ASSUME_NONNULL_END
