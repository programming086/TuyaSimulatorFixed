//
//  ThingSDKFile.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSDKFile : NSObject

+ (instancetype)sharedInstance;

- (NSString *)thingsdk_getAtDocumentPath:(NSString *)fileName;

- (BOOL)thingsdk_mkdirAtPath:(NSString *)dir;

- (BOOL)thingsdk_fileExistsAtPath:(NSString *)filePath;

- (BOOL)thingsdk_delFileAtPath:(NSString *)filepath;

- (BOOL)thingsdk_createFileAtPath:(NSString *)filePath;


@end

NS_ASSUME_NONNULL_END
