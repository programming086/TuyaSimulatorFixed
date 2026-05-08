//
//  NSString+ThingURL.h
//  ThingFoundationKit
//
//  Created by 
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingURL)

/// Appends a URL component to the receiver.
/// - Parameter appendUrl: The URL component to append to the receiver. If there is no `/` between the receiver 
///   and appendUrl, it will be added. It also handles cases where there are two `/` between them.
- (NSString *)thing_URLAppend:(NSString *)appendUrl;


/// Appends URL parameters to the receiver.
/// - Parameter params: The parameters to append, where the value will be URL-encoded.
- (NSString *)thing_URLAppendParams:(NSDictionary<NSString *, id> *)params;

/// Appends URL parameters and returns a NSURL.
/// - Parameter params: The parameters to append.
- (NSURL *)thing_URLByAppendingParams:(NSDictionary<NSString *, id> *)params;

/// Converts the string to an NSURL.
- (NSURL *)thing_URL;

@end

NS_ASSUME_NONNULL_END
