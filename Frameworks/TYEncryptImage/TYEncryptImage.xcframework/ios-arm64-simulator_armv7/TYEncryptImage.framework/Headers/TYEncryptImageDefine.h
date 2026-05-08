//
//  TYEncryptImageDefine.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2020/5/26.
//

#import "TYEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>

#ifndef TYEncryptImageDefine_h
#define TYEncryptImageDefine_h

/// Indicated where the image came from.
typedef NS_ENUM(NSUInteger, TYEncryptWebImageFromType) {
    
    /// No value.
    TYWebImageFromNone = 0,
    
    /// Fetched from memory cache immediately.
    /// If you called "setImageWithURL:..." and the image is already in memory,
    /// then you will get this value at the same call.
    TYWebImageFromMemoryCacheFast,
    
    /// Fetched from memory cache.
    TYWebImageFromMemoryCache,
    
    /// Fetched from disk cache.
    TYWebImageFromDiskCache,
    
    /// Fetched from remote (web or file path).
    TYWebImageFromRemote,
};

/// Indicated image fetch complete stage.
typedef NS_ENUM(NSInteger, TYEncryptWebImageStage) {
    
    /// Incomplete, progressive image.
    TYWebImageStageProgress  = -1,
    
    /// Cancelled.
    TYWebImageStageCancelled = 0,
    
    /// Finished (succeed or failed).
    TYWebImageStageFinished  = 1,
};

/**
 Image file type.
 */
typedef NS_ENUM(NSUInteger, TYEncryptImageType) {
    TYEncryptImageTypeUnknown = 0, ///< unknown
    TYEncryptImageTypeJPEG,        ///< jpeg, jpg
    TYEncryptImageTypeJPEG2000,    ///< jp2
    TYEncryptImageTypeTIFF,        ///< tiff, tif
    TYEncryptImageTypeBMP,         ///< bmp
    TYEncryptImageTypeICO,         ///< ico
    TYEncryptImageTypeICNS,        ///< icns
    TYEncryptImageTypeGIF,         ///< gif
    TYEncryptImageTypePNG,         ///< png
    TYEncryptImageTypeWebP,        ///< webp
    TYEncryptImageTypeOther,       ///< other image format
};

/// The options to control image operation.
typedef NS_OPTIONS(NSUInteger, TYEncryptWebImageOptions) {
    
    /// Load the image from remote and refresh the image cache.
    TYEncryptWebImageOptionRefreshImageCache = 1 << 0,
    
    /// Do not load image from/to disk cache.
    TYEncryptWebImageOptionIgnoreDiskCache = 1 << 1,
    
    /// Do not change the view's image before set a new URL to it.
    TYEncryptWebImageOptionIgnorePlaceHolder = 1 << 2,
    
    /// By default, placeholder images are loaded while the image is loading. This flag will delay the loading
    /// of the placeholder image until after the image has finished loading.
    TYEncryptWebImageOptionDelayPlaceholder = 1 << 3,
    
    /// Ignore image decoding.
    /// This may used for image downloading without display.
    TYEncryptWebImageOptionIgnoreImageDecoding = 1 << 4,
    
    /// Do not set the image to the view when image fetch complete.
    /// You may set the image manually.
    TYEncryptWebImageOptionAvoidSetImage = 1 << 5,
    
    /// Use NSURLCache instead of TYImageCache.
    TYEncryptWebImageOptionUseNSURLCache = 1 << 6,
    
    /// Handles cookies stored in NSHTTPCookieStore.
    TYEncryptWebImageOptionHandleCookies = 1 << 7,
   
};

/**
 The block invoked when image fetch finished or cancelled.
 
 @param image       The image.
 @param url         The image url (remote or local file path).
 @param from        Where the image came from.
 @param stage       Current download stage.
 @param error       Error during image fetching.
 */
typedef void (^TYEncryptWebImageCompletionBlock)(UIImage * _Nullable image, NSURL * _Nullable url, TYEncryptWebImageFromType from, TYEncryptWebImageStage stage, NSError * _Nullable error);

/**
 The block invoked in remote image fetch progress.
 
 @param receivedSize Current received size in bytes.
 @param expectedSize Expected total size in bytes (-1 means unknown).
 */
typedef void(^TYEncryptWebImageProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);

#endif /* TYEncryptImageDefine_h */
