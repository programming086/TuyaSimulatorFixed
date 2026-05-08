
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Multilingual delegate before and after hooks are implemented based on the onion model.
///
/// ```
/// delegate before → /return/
///    ↓
/// system
///    ↓
/// delegate after
///    ↓
/// /return/
/// ```
@protocol ThingLanguageLoaderDelegate <NSObject>

@optional

/// Callback method before retrieving the localized string. If this callback returns a non-nil value, 
/// the localizedString method will return this value. You can use this method to modify the project's localization 
/// at runtime; if the before hook is executed, the after hook will not be executed.
/// @param languageKey The key for the localized string.
- (nullable NSString *)beforeLocalizedWithKey:(NSString *)languageKey;

/// Callback method after retrieving the localized string. If this callback returns a non-nil value, 
/// the localizedString method will return this value. You can use this to modify project localization at runtime, 
/// for example, to replace unsatisfactory translations.
/// @param languageKey The key for the localized string.
/// @param isFound Indicates whether the localized string was found.
/// @param isCurrent When isFound is true, this field is valid. Indicates whether the localization was taken from 
///                  the main bundle (not the default language bundle).
/// @param localizedString The content of the localization; if isFound is NO, then localizedString == languageKey.
- (nullable NSString *)afterLocalizedWithKey:(NSString *)languageKey
                                     isFound:(BOOL)isFound
                                   isCurrent:(BOOL)isCurrent
                             localizedString:(NSString *)localizedString;
@end


@interface ThingLanguageLoader : NSObject

@property (nonatomic, weak) id<ThingLanguageLoaderDelegate> delegate;

/// The bundle and fallback language currently in use for localization. 
/// To modify, use the registerLocalizedBundle:defaultLanguage: method.
@property (nonatomic, strong, readonly) NSBundle *localizedBundle;
@property (nonatomic, copy, readonly) NSString *defaultLanguage;

+ (instancetype)sharedInstance;

// Reverts to the previous rootBundle if under a specific language bundle.
+ (NSBundle *)languageRootBundle:(NSBundle *)bundle;


/// Registers a bundle and fallback language, taking multilingual resources from the registered bundle. 
/// Defaults to [NSBundle mainBundle] and @"en".
/// @param bundle The custom bundle from which to take localization.
/// @param defaultLanguage The default language. If other languages are unavailable, 
///                        it will fill with the default language, e.g., @"en".
///                        If this parameter is nil, defaults to @"en".
- (void)registerLocalizedBundle:(NSBundle *)bundle defaultLanguage:(NSString *)defaultLanguage;


/// Checks if the multilingual resource corresponding to the keys can be found in the registered bundle.
/// @param languageKey The key for the localized string.
- (BOOL)isExistLocalized:(NSString *)languageKey;


/// Retrieves the localized string corresponding to the key.
/// @param languageKey The key for the localized string.
- (NSString *)localizedString:(NSString *)languageKey;
@end

NS_ASSUME_NONNULL_END
