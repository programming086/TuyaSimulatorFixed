
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSInteger {
    ThingSmartThemeStyleLight,
    ThingSmartThemeStyleBlack,
} ThingSmartThemeStyle __attribute__((deprecated("Use ThingThemeManagerProtocol instead")));


/**
 A constant string type used as a key for identifying languages in the application.

 This type ensures consistent use of predefined language keys for localization purposes.
 */
typedef NSString *const ThingSmartBizLanguageKey;


@protocol ThingSmartBizLanguageInterceptorProtocol <NSObject>

/**
 Replaces the localized string based on the provided language key and language code.

 This method attempts to replace the given `originalString` with a localized version
 corresponding to the specified `languageKey` and `languageCode`. If no replacement is necessary
 or possible, the method returns the `originalString` as is.

 @param languageKey A `ThingSmartBizLanguageKey` representing the key for the desired language.
 This key is used to identify the language context for localization.

 @param languageCode A string representing the code for the desired language. This code is used
 to determine the appropriate localized string to replace the original string.

 @param originalString The original localized string that may be replaced. If no suitable
 replacement is found or needed, this string will be returned unchanged.

 @return A new string that is the localized replacement of the `originalString` if a suitable
 replacement is found. If no replacement is made, returns the `originalString`. Returns `nil`
 if the operation cannot be completed due to invalid input or other errors.
 */
- (nullable NSString *)stringByReplacingLocalizedStringForLanguageKey:(ThingSmartBizLanguageKey)languageKey
                                                         languageCode:(NSString *)languageCode
                                                           withString:(NSString *)originalString;
                            
@end

@interface ThingSmartBizCore : NSObject

+ (_Nonnull instancetype)sharedInstance;

/**
 * Get the instance which implement the special service protocol
 * eg:
 *  id<TYMallProtocol> impl = [[TuyaSmartBizCore sharedInstance] serviceOfProtocol:@protocol(TYMallProtocol)];
 *  [impl xxx]; // your staff...
 *
 * @param serviceProtocol service protocol
 * @return instance
 */
- (id)serviceOfProtocol:(Protocol *)serviceProtocol;

/**
 * Register a instance for service which can not be served by BizBundle itself
 * Each service can only register one instance or class at a time, whichever is the last
 *
 * @param service   service protocol
 * @param instance  instance which conform to the service protocol, strong reference
 *                  unregister if nil
 */
- (void)registerService:(Protocol *)service withInstance:(id)instance;

/**
 * Register a class for service which can not be served by BizBundle itself
 * Each service can only register one instance or class at a time, whichever is the last
 *
 *
 * @param service   service protocol
 * @param cls       class which conform to the service protocol, [cls new] to get instance
 *                  unregister if nil
 */
- (void)registerService:(Protocol *)service withClass:(Class)cls __attribute__((deprecated("Use -registerService:withInstance: instead.")));

/**
 * Register route handler for route which can not be handled by BizBundle itself
 * @param handler   block to handle route
 *                  @param url  the route url
 *                  @param raw  the route raw data
 *                  @return true if route can be handled, otherwise return false
 */
- (void)registerRouteWithHandler:(BOOL(^)(NSString *url, NSDictionary *raw))handler;

/**
* Update config of biz resource
*
*/
- (void)updateConfig;

#pragma mark language

// Language keys with original language identifiers as comments
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyGerman; // de
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyTraditionalChinese; // zh-Hant
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyRussian; // ru
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyPortuguese; // pt
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyKorean; // ko
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyEnglish; // en
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyItalian; // it
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyBrazilianPortuguese; // pt-BR
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyFrench; // fr
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeySimplifiedChinese; // zh-Hans
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeySpanish; // es
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyArabic; // ar
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyLatinAmericanSpanish; // es-419
extern ThingSmartBizLanguageKey ThingSmartBizLanguageKeyJapanese; // ja

/// Switch the app language, if the 'language' is passed as nil, then use the system language.
/// @param language Use the key in the returned information from the `supportedLanguages` method.
- (void)languageSwitchTo:(ThingSmartBizLanguageKey _Nullable)language;

/**
 Returns a dictionary of supported languages with complete translations.

 This method provides a list of languages that have full translation support. Each entry in the dictionary
 maps a language code to its corresponding language name.

 @return A dictionary where keys are language codes (e.g., "en", "fr") and values are the full names of the languages.
    key:language IDs for all the localizations contained in the bundle. e.g. 'en'
    value:language name
 */
- (NSDictionary<ThingSmartBizLanguageKey, NSString *> *_Nonnull)recommendedLanguages;

/**
 Returns a dictionary of languages with incomplete translations.

 This method provides a list of languages that have partial translation support. These languages are not
 recommended for direct use due to incomplete translations. This method is maintained for compatibility
 with older versions and is marked as deprecated.

 @return A dictionary where keys are language codes and values are the names of the languages with incomplete translations.

 @deprecated This method is deprecated and should not be used in new code. Consider using `supportedLanguages` instead.
 */
- (NSDictionary<ThingSmartBizLanguageKey, NSString *> *_Nonnull)supportedLanguages __attribute__((deprecated("This method is deprecated. Use `recommendedLanguages` instead.")));

/**
 Returns the current language key being used by the application.

 This method provides the language key that represents the current language setting of the application.
 It reflects the language that the app is currently using for its interface and content. This can be
 useful for determining the current localization and for displaying language-specific content.
 
 @return The `ThingSmartBizLanguageKey` representing the current language setting of the app.
 */
- (ThingSmartBizLanguageKey)currentLanguageKey;

/**
 Exception name for errors in ThingSmartBiz core operations.

 This exception is thrown when:
 - A nil language interceptor is set.
 - There's a conflict with the `ThingLanguageLoader` delegate.

 Handle this exception to ensure proper error management.
 */
extern NSString *const ThingSmartBizCoreExceptionName;

/**
 Sets a language interceptor to customize language string replacements.

 This method allows you to set a language interceptor that conforms to the `ThingSmartBizLanguageInterceptorProtocol`.
 The interceptor is used to handle custom language string replacements within the application.

 @param interceptor An object conforming to `ThingSmartBizLanguageInterceptorProtocol` to handle language string replacements.
 
 @throws NSException Throws a ThingSmartBizCoreExceptionName if the interceptor is nil or if the [ThingLanguageLoader sharedInstance].delegate is already set.
 */
- (void)setLanuageInterceptor:(id<ThingSmartBizLanguageInterceptorProtocol>)interceptor;


#pragma mark theme

/// Change dark mode or light mode
- (void)changeThemeStyle:(ThingSmartThemeStyle)themeStyle API_AVAILABLE(ios(13.0)) __attribute__((deprecated("Use ThingThemeManagerProtocol instead")));


#pragma mark Deprecated

/// Change dark mode or light mode
- (void)changeThemeStype:(ThingSmartThemeStyle)themeStyle API_AVAILABLE(ios(13.0)) __attribute__((deprecated("Use ThingThemeManagerProtocol instead")));

/// Enables compatibility with UISceneDelegate when using it.
- (void)enableSceneDelegateCompatibility API_AVAILABLE(ios(13.0)) __attribute__((deprecated("This feature will enable automatically within the application.")));

@end

NS_ASSUME_NONNULL_END
