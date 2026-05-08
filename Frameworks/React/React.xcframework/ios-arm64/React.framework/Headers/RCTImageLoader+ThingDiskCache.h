//
// Created by luobei on 2020/2/18.
//

#import <Foundation/Foundation.h>
#import "RCTImageLoader.h"

@interface RCTImageLoader (ThingDiskCache)

- (void)thing_setImageDataToDiskCache:(NSData *)imageData withURL:(NSURL *)imageURL;

- (NSData *)thing_diskCachedImageDataWithURL:(NSURL *)imageURL;

+ (void)thing_clearAllNetworkImageCached;

@end
