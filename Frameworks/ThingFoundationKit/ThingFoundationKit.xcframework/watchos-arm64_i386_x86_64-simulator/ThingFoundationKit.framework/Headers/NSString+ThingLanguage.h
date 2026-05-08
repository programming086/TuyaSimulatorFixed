//
//  NSString+ThingLanguage.h
//  ThingFoundationKit
//
//  Created by Hemin Won on 2023/3/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingLanguage)

/// Checks if the string consists entirely of Chinese characters.
- (BOOL)isChinese;

/// Checks if the string contains any Chinese characters.
- (BOOL)includeChinese;

@end

NS_ASSUME_NONNULL_END
