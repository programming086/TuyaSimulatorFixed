//
//  ThingLightingFeedBackModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

@class ThingLightingTicketResourceModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingFeedBackModel : NSObject

/// The content of feedback
@property (nonatomic, copy) NSString *feedbackContent;

/// The resource of feedback (image/video)
@property (nonatomic, strong) NSArray *feedbackResource;

@end

NS_ASSUME_NONNULL_END
