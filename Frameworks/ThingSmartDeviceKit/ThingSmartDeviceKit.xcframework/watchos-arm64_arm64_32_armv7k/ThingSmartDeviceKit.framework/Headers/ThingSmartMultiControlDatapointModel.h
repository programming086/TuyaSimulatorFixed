//
//  ThingSmartMultiControlDatapointModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMultiControlDatapointModel : NSObject

@property (copy, nonatomic) NSString *dpId;///< The DP ID.
@property (copy, nonatomic) NSString *name;///< The name.
@property (copy, nonatomic) NSString *code;///< The DP standard name (dpCode).
@property (copy, nonatomic) NSString *schemaId;///< The schema ID to which the key belongs.

@end

NS_ASSUME_NONNULL_END
