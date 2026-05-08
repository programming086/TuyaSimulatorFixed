//
//  ThingLightingTicketResourceModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingTicketResourceModel : NSObject

/// The resource URL
@property (nonatomic, copy) NSString *resourceUrl;

/// The type of resource 1.Image 2.Video
@property (nonatomic, assign) NSInteger resourceType;

@end

NS_ASSUME_NONNULL_END
