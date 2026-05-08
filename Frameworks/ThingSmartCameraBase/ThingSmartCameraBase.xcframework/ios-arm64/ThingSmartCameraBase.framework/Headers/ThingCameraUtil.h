
#import <Foundation/Foundation.h>
#import "ThingSmartCameraType.h"

#define ThingCameraStr(a) [ThingCameraUtil thingDecryptString:a]

@interface ThingCameraUtil : NSObject

+ (void)activeAudioSession;

+ (void)unactiveAudioSession;

+ (NSString *)libCachePath;

+ (NSString *)getAtCachePath:(NSString *)fileName;

+ (NSString *)md5WithString:(NSString *)string;

+ (NSString *)thingDecryptString:(NSString *)string;

+ (UIImage *)rotateImage:(UIImage *)image direction:(ThingSmartVideoRotateDirection)direction;

+ (BOOL)saveImageToPhotoLibrary:(UIImage *)image;

+ (BOOL)saveVideoToPhotoLibrary:(NSString *)videoPath;

+ (NSString *)recordCacheDirectory;

+ (void)removeAllRecordCacheFiles;
+ (BOOL)removeRecordFileAtPath:(NSString *)path;

@end
