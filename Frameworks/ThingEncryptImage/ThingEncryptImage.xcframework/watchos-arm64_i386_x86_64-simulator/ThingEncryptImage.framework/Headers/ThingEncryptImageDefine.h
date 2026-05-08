
#import "ThingEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>

#ifndef ThingEncryptImageDefine_h
#define ThingEncryptImageDefine_h

/// Indicated where the image came from.
typedef NS_ENUM(NSUInteger, ThingEncryptWebImageFromType) {
    
    /// No value.
    ThingWebImageFromNone = 0,
    
    /// Fetched from memory cache immediately.
    /// If you called "setImageWithURL:..." and the image is already in memory,
    /// then you will get this value at the same call.
    ThingWebImageFromMemoryCacheFast,
    
    /// Fetched from memory cache.
    ThingWebImageFromMemoryCache,
    
    /// Fetched from disk cache.
    ThingWebImageFromDiskCache,
    
    /// Fetched from remote (web or file path).
    ThingWebImageFromRemote,
};

/// Indicated image fetch complete stage.
typedef NS_ENUM(NSInteger, ThingEncryptWebImageStage) {
    
    /// Incomplete, progressive image.
    ThingWebImageStageProgress  = -1,
    
    /// Cancelled.
    ThingWebImageStageCancelled = 0,
    
    /// Finished (succeed or failed).
    ThingWebImageStageFinished  = 1,
};

/**
 Image file type.
 */
typedef NS_ENUM(NSUInteger, ThingEncryptImageType) {
    ThingEncryptImageTypeUnknown = 0, ///< unknown
    ThingEncryptImageTypeJPEG,        ///< jpeg, jpg
    ThingEncryptImageTypeJPEG2000,    ///< jp2
    ThingEncryptImageTypeTIFF,        ///< tiff, tif
    ThingEncryptImageTypeBMP,         ///< bmp
    ThingEncryptImageTypeICO,         ///< ico
    ThingEncryptImageTypeICNS,        ///< icns
    ThingEncryptImageTypeGIF,         ///< gif
    ThingEncryptImageTypePNG,         ///< png
    ThingEncryptImageTypeWebP,        ///< webp
    ThingEncryptImageTypeOther,       ///< other image format
};

/// The options to control image operation.
typedef NS_OPTIONS(NSUInteger, ThingEncryptWebImageOptions) {
    
    /// Load the image from remote and refresh the image cache.
    ThingEncryptWebImageOptionRefreshImageCache = 1 << 0,
    
    /// Do not load image from/to disk cache.
    ThingEncryptWebImageOptionIgnoreDiskCache = 1 << 1,
    
    /// Do not change the view's image before set a new URL to it.
    ThingEncryptWebImageOptionIgnorePlaceHolder = 1 << 2,
    
    /// By default, placeholder images are loaded while the image is loading. This flag will delay the loading
    /// of the placeholder image until after the image has finished loading.
    ThingEncryptWebImageOptionDelayPlaceholder = 1 << 3,
    
    /// Ignore image decoding.
    /// This may used for image downloading without display.
    ThingEncryptWebImageOptionIgnoreImageDecoding = 1 << 4,
    
    /// Do not set the image to the view when image fetch complete.
    /// You may set the image manually.
    ThingEncryptWebImageOptionAvoidSetImage = 1 << 5,
    
    /// Use NSURLCache instead of ThingImageCache.
    ThingEncryptWebImageOptionUseNSURLCache = 1 << 6,
    
    /// Handles cookies stored in NSHTTPCookieStore.
    ThingEncryptWebImageOptionHandleCookies = 1 << 7,
   
};

/**
 The block invoked when image fetch finished or cancelled.
 
 @param image       The image.
 @param url         The image url (remote or local file path).
 @param from        Where the image came from.
 @param stage       Current download stage.
 @param error       Error during image fetching.
 */
typedef void (^ThingEncryptWebImageCompletionBlock)(UIImage * _Nullable image, NSURL * _Nullable url, ThingEncryptWebImageFromType from, ThingEncryptWebImageStage stage, NSError * _Nullable error);

/**
 The block invoked in remote image fetch progress.
 
 @param receivedSize Current received size in bytes.
 @param expectedSize Expected total size in bytes (-1 means unknown).
 */
typedef void(^ThingEncryptWebImageProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);

#endif /* ThingEncryptImageDefine_h */
