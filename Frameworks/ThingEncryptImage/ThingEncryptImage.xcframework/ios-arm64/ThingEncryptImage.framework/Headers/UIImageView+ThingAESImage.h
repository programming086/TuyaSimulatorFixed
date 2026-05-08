//
//  UIImageView+ThingAESImage.h
//  ThingEncryptImage
//
//  Created by ThingInc on 2019/5/31.
//

#import "ThingEncryptWebImageCompat.h"
#import "ThingEncryptImageDefine.h"
#import "ThingEncryptWebImageManager.h"

@interface UIImageView (ThingAESImage)

#pragma mark - image

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
                  scaledWidth:(NSInteger)scaledWidth;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param tintColor image's tintColor and the image's rendingMode will automatically be set to UIImageRenderingModeAlwaysTemplate
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
                 tintColor:(nullable UIColor *)tintColor;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
             placeholderImage:(nullable UIImage *)placeholderImage
                  scaledWidth:(NSInteger)scaledWidth;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param cacheKeyFilter   custom image's cache key
- (void)thing_setImageWithURL:(nullable NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
            cacheKeyFilter:(nullable NSString *_Nonnull(^)(NSURL * _Nonnull url))cacheKeyFilter;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param options          options to use when request the image.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                   options:(ThingEncryptWebImageOptions)options;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param tintColor image's tintColor and the image's rendingMode will automatically be set to UIImageRenderingModeAlwaysTemplate
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                 tintColor:(nullable UIColor *)tintColor;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                 completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param options          options to use when request the image.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                   options:(ThingEncryptWebImageOptions)options
                 completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
                 completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param progress The block invoked (on main thread) during image request.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                  progress:(nullable ThingEncryptWebImageProgressBlock)progress
                 completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param options          options to use when request the image.
/// @param progress The block invoked (on main thread) during image request.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                   options:(ThingEncryptWebImageOptions)options
                  progress:(nullable ThingEncryptWebImageProgressBlock)progress
                 completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param cacheKeyFilter   custom image's cache key
/// @param options          options to use when request the image.
/// @param progress The block invoked (on main thread) during image request.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
            cacheKeyFilter:(nullable NSString *_Nonnull(^)(NSURL * _Nonnull url))cacheKeyFilter
                   options:(ThingEncryptWebImageOptions)options
                  progress:(nullable ThingEncryptWebImageProgressBlock)progress
                 completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
/// @param cacheKeyFilter   custom image's cache key
/// @param options          options to use when request the image.
/// @param progress The block invoked (on main thread) during image request.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setImageWithURL:(nonnull NSURL *)imageUrl
             placeholderImage:(nullable UIImage *)placeholderImage
                  scaledWidth:(NSInteger)scaledWidth
               cacheKeyFilter:(nullable NSString *_Nonnull(^)(NSURL * _Nonnull url))cacheKeyFilter
                      options:(ThingEncryptWebImageOptions)options
                     progress:(nullable ThingEncryptWebImageProgressBlock)progress
                    completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

#pragma mark - encrypt image

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
/// @param placeholderImage placeholder image before network request response
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
              placeholderImage:(nullable UIImage *)placeholderImage;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
                     completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
///
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
/// @param placeholderImage placeholder image before network request response
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
              placeholderImage:(nullable UIImage *)placeholderImage
                     completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
///
/// @param imagePath          The image's URL
/// @param encryptKey         The image's encrypt key string
/// @param placeholderImage   The placeholder image before network request response
/// @param progress           The block invoked (on main thread) during image request.
/// @param completedBlock     A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
              placeholderImage:(nullable UIImage *)placeholderImage
                      progress:(nullable ThingEncryptWebImageProgressBlock)progress
                     completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
///
/// @param imagePath          The image's URL
/// @param encryptKey         The image's encrypt key string
/// @param placeholderImage   The placeholder image before network request response
/// @param options            The options to use when request the image.
/// @param progress           The block invoked (on main thread) during image request.
/// @param completedBlock     A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
              placeholderImage:(nullable UIImage *)placeholderImage
                       options:(ThingEncryptWebImageOptions)options
                      progress:(nullable ThingEncryptWebImageProgressBlock)progress
                     completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
///
/// @param imagePath          The image's URL
/// @param encryptKey         The image's encrypt key string
/// @param cacheKeyFilter     The image's cache key for custom
/// @param placeholderImage   The placeholder image before network request response
/// @param options            The options to use when request the image.
/// @param progress           The block invoked (on main thread) during image request.
/// @param completedBlock     A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
                cacheKeyFilter:(nullable NSString *_Nonnull(^)(NSURL * _Nonnull url))cacheKeyFilter
              placeholderImage:(nullable UIImage *)placeholderImage
                       options:(ThingEncryptWebImageOptions)options
                      progress:(nullable ThingEncryptWebImageProgressBlock)progress
                     completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
///
/// @param imagePath          The image's URL
/// @param encryptKey         The image's encrypt key string
/// @param cacheKeyFilter     The image's cache key for custom
/// @param imageManager       The custom ThingEncryptWebImageManager
/// @param placeholderImage   The placeholder image before network request response
/// @param options            The options to use when request the image.
/// @param progress           The block invoked (on main thread) during image request.
/// @param completedBlock     A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
                cacheKeyFilter:(nullable NSString *_Nonnull(^)(NSURL * _Nonnull url))cacheKeyFilter
                       manager:(nullable ThingEncryptWebImageManager *)imageManager
              placeholderImage:(nullable UIImage *)placeholderImage
                       options:(ThingEncryptWebImageOptions)options
                      progress:(nullable ThingEncryptWebImageProgressBlock)progress
                     completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
///
/// @param imagePath          The image's URL
/// @param encryptKey         The image's encrypt key string
/// @param cacheKeyFilter     The image's cache key for custom
/// @param imageManager       The custom ThingEncryptWebImageManager
/// @param placeholderImage   The placeholder image before network request response
/// @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
/// @param options            The options to use when request the image.
/// @param progress           The block invoked (on main thread) during image request.
/// @param completedBlock     A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)thing_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
                cacheKeyFilter:(nullable NSString *_Nonnull(^)(NSURL * _Nonnull url))cacheKeyFilter
                       manager:(nullable ThingEncryptWebImageManager *)imageManager
              placeholderImage:(nullable UIImage *)placeholderImage
                    scaledWidth:(NSInteger)scaledWidth
                       options:(ThingEncryptWebImageOptions)options
                      progress:(nullable ThingEncryptWebImageProgressBlock)progress
                     completed:(nullable ThingEncryptWebImageCompletionBlock)completedBlock;

@end

