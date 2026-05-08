//
//  UIButton+ThingAESImage.h
//  ThingEncryptImage
//
//  Created by ThingInc on 2021/1/5.
//

#import "ThingEncryptWebImageCompat.h"

#if Thing_EI_UIKIT
 
#import "ThingEncryptImageDefine.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Web image methods for UIButton.
 */
@interface UIButton (ThingAESImage)

#pragma mark - image

/**
 Current image URL for the specified state.
 @return The image URL, or nil.
 */
- (nullable NSURL *)thing_imageURLForState:(UIControlState)state;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 */
- (void)thing_setImageWithURL:(nullable NSURL *)imageURL
                  forState:(UIControlState)state
               placeholder:(nullable UIImage *)placeholder;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL The image url (remote or local file path).
 @param state    The state that uses the specified image.
 */
- (void)thing_setImageWithURL:(nullable NSURL *)imageURL
                  forState:(UIControlState)state;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setImageWithURL:(nullable NSURL *)imageURL
                  forState:(UIControlState)state
               placeholder:(nullable UIImage *)placeholder
                completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setImageWithURL:(nullable NSURL *)imageURL
                  forState:(UIControlState)state
               placeholder:(nullable UIImage *)placeholder
                  progress:(nullable ThingEncryptWebImageProgressBlock)progress
                completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setImageWithURL:(nullable NSURL *)imageURL
                     forState:(UIControlState)state
                  placeholder:(nullable UIImage *)placeholder
                  scaledWidth:(NSInteger)scaledWidth
                     progress:(nullable ThingEncryptWebImageProgressBlock)progress
                   completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Cancel the current image request for a specified state.
 @param state The state that uses the specified image.
 */
- (void)thing_cancelImageRequestForState:(UIControlState)state;

#pragma mark - encrypt image

/**
 Set the button's image with a specified URL and encrypt key for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param encryptKey  The encrypt key of the specified encrypted image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setAESImageWithURL:(nullable NSURL *)imageURL
                     forState:(UIControlState)state
                   encryptKey:(nullable NSString *)encryptKey
                  placeholder:(nullable UIImage *)placeholder
                     progress:(nullable ThingEncryptWebImageProgressBlock)progress
                   completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Set the button's image with a specified URL and encrypt key for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param encryptKey  The encrypt key of the specified encrypted image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setAESImageWithURL:(nullable NSURL *)imageURL
                        forState:(UIControlState)state
                      encryptKey:(nullable NSString *)encryptKey
                     placeholder:(nullable UIImage *)placeholder
                     scaledWidth:(NSInteger)scaledWidth
                        progress:(nullable ThingEncryptWebImageProgressBlock)progress
                      completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

#pragma mark - background image

/**
 Current backgroundImage URL for the specified state.
 @return The image URL, or nil.
 */
- (nullable NSURL *)thing_backgroundImageURLForState:(UIControlState)state;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 */
- (void)thing_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                            forState:(UIControlState)state
                         placeholder:(nullable UIImage *)placeholder;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL The image url (remote or local file path).
 @param state    The state that uses the specified image.
 */
- (void)thing_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                            forState:(UIControlState)state;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                            forState:(UIControlState)state
                         placeholder:(nullable UIImage *)placeholder
                          completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                            forState:(UIControlState)state
                         placeholder:(nullable UIImage *)placeholder
                            progress:(nullable ThingEncryptWebImageProgressBlock)progress
                          completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                               forState:(UIControlState)state
                            placeholder:(nullable UIImage *)placeholder
                            scaledWidth:(NSInteger)scaledWidth
                               progress:(nullable ThingEncryptWebImageProgressBlock)progress
                             completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Cancel the current backgroundImage request for a specified state.
 @param state The state that uses the specified image.
 */
- (void)thing_cancelBackgroundImageRequestForState:(UIControlState)state;

#pragma mark - encrypt background image

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param encryptKey  The encrypt key of the specified encrypted image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setAESBackgroundImageWithURL:(nullable NSURL *)imageURL
                               forState:(UIControlState)state
                             encryptKey:(nullable NSString *)encryptKey
                            placeholder:(nullable UIImage *)placeholder
                               progress:(nullable ThingEncryptWebImageProgressBlock)progress
                             completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param encryptKey  The encrypt key of the specified encrypted image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)thing_setAESBackgroundImageWithURL:(nullable NSURL *)imageURL
                                  forState:(UIControlState)state
                                encryptKey:(nullable NSString *)encryptKey
                               placeholder:(nullable UIImage *)placeholder
                               scaledWidth:(NSInteger)scaledWidth
                                  progress:(nullable ThingEncryptWebImageProgressBlock)progress
                                completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END

#endif
