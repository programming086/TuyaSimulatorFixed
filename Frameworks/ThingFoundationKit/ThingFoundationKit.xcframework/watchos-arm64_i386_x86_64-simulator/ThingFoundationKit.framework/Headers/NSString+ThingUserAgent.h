//
//  NSString+ThingUserAgent.h
//  ThingFoundationKit
//
//  Created by 尼奥 on 2025/3/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingUserAgent)

/**
 * Retrieves the custom User-Agent string for Thing WebView.
 *
 * This User-Agent includes application identifiers, version information, and device system version.
 * It is essential for Thing WebView to use this custom User-Agent when initializing WKWebView to ensure proper functionality and service compatibility.
 *
 * @return NSString The custom User-Agent string.
 */
+ (NSString *)thing_h5UserAgent;

@end

NS_ASSUME_NONNULL_END
