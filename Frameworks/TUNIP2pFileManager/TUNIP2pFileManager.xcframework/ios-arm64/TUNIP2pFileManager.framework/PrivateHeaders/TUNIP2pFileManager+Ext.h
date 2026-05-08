

#import <Foundation/Foundation.h>
#import "TUNIP2pModel.h"
#import <ThingP2PSessionKit/ThingP2PSessionProtocol.h>
/**
 * Since class files may be overwritten, please declare the required properties in the anonymous category (extension) of the Ext.h file.
 * Note: All modifications in the class files will be reset during the plugin build.
 */

@interface TUNIP2pFileManager ()<ThingP2PSessionDelegate>

@property (nonatomic, strong) NSMutableDictionary <NSString *,TUNIP2pModel *>*deviceDictionary;

@property (nonatomic, strong) NSLock *deviceDictionaryLock;

@end
