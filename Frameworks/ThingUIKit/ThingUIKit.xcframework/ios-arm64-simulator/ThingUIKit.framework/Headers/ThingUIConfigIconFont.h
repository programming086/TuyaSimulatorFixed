
#import <Foundation/Foundation.h>

@interface ThingUIConfigIconFont : NSObject
/**
    @param key iconfont image name
    @param iconfontStyle iconfont.ttf file name, the ttf file name needs to be consistent with the corresponding json name
 */
+ (NSString *)getStringWithKey:(NSString *)key withStyle:(NSString *)iconfontStyle;

/**
 Get the iconfont file name + iconfont picture name of default_iconfont configured in info.plist
    @param key iconfont Picture name
 */
+ (NSString *)getDefaultStringWithKey:(NSString *)key;
@end

