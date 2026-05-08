
#import <Foundation/Foundation.h>
@class ThingBLERequest;

@interface ThingBLEWriteService : NSObject

- (void)addRequest:(ThingBLERequest *)request;

- (BOOL)writeData:(ThingBLECharacteristic *)writeCharacteristic data:(NSData *)data ifNeedTimeout:(double)timeout;

@end
