//
//  ThingLightingUploadFileManager.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingCommercialLightingKit/ThingLightingUploadFileModel.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingUploadFileManager : NSObject

/// Upload pictures (ompressed into jpeg format).
/// @param image The image object.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)uploadImage:(UIImage *)image
            success:(void(^)(ThingLightingUploadFileModel *))success
            failure:(ThingFailureError)failure;

/// Upload video file (video only supports MP4 format).
/// @param filePath The file path.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)uploadVideoFile:(NSString *)filePath
                success:(void(^)(ThingLightingUploadFileModel *))success
                failure:(ThingFailureError)failure;




@end

NS_ASSUME_NONNULL_END
