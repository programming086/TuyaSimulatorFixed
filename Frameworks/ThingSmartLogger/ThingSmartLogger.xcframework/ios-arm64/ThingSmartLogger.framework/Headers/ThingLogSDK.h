//
//  ThingLogSDK.h
//  ThingLogLibrary
//
//  Created by nil on 2022/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLogSDK : NSObject

+ (void)startLog;

+ (NSArray *)logPath;

@end

NS_ASSUME_NONNULL_END
