//
//  ThingLightingUploadFileModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingUploadFileModel : NSObject

/// The biz ulr.
@property (nonatomic, strong) NSString *bizUrl;

/// The public url.
@property (nonatomic, strong) NSString *publicUrl;

/// The file ID.
@property (nonatomic, strong) NSString *fileId;


@end

NS_ASSUME_NONNULL_END
