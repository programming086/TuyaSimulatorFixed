
#import "ThingSmartSDK.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSDK (Language)

/**
 * Gets the current application language setting
 *
 * @return The language identifier string in ISO format (e.g., "en", "zh-Hans")
 */
- (NSString *)currentAppLanguage;

/**
 * Updates the application's language setting
 *
 * @param localeIdentifier Language locale identifier, supported formats:
 *        - ISO 639-1 language codes (e.g., "en", "zh", "ja")
 *        - Language-region combinations (e.g., "zh-Hans", "zh-Hant", "en-US")
 *        - If nil or empty string is provided, system default language will be used
 * @param success Callback when update succeeds
 * @param failure Callback when update fails, returns error information
 */
- (void)switchLanguageTo:(NSString *)localeIdentifier
                 success:(nullable ThingSuccessHandler)success
                 failure:(nullable ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
