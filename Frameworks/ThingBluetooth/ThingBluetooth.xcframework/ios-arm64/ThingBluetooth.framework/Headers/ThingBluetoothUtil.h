
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingBluetoothUtil : NSObject

+ (void)storeAdvertisingData:(NSDictionary *)advertisingData pIdentifier:(NSString *)pIdentifier;

+ (NSDictionary *)getAdvertisingDataWithIdentifier:(NSString *)pIdentifier;

+ (void)storeSNWithUUID:(NSString *)uuid sn:(NSInteger)sn;

+ (int)getSNWithUUID:(NSString *)uuid;

+ (void)removeAdvertisingDataWithIdentifier:(NSString *)pIdentifier uuid:(NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
