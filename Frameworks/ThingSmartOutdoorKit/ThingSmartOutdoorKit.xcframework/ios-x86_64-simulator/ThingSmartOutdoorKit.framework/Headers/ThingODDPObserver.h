
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingODDPObserver, ThingSmartSchemaModel;

typedef void(^ThingODDPObserverSchemaMBlock)(ThingSmartSchemaModel *schemaM) NS_SWIFT_NAME(DPObserverSchemaMBlock);

NS_SWIFT_NAME(DPObserverDelegate)
@protocol ThingODDPObserverDelegate <NSObject>

- (void)observer:(ThingODDPObserver *)observer deviceID:(NSString *)deviceID schemaM:(ThingSmartSchemaModel *)schemaM;

@end

NS_SWIFT_NAME(DPObserver)
@interface ThingODDPObserver : NSObject

+ (void)addObserverDelegate:(id<ThingODDPObserverDelegate>)delegate deviceID:(NSString *)deviceID;
+ (void)removeObserverDelegate:(id<ThingODDPObserverDelegate>)delegate deviceID:(NSString *)deviceID;

+ (void)addObserverDelegate:(id<ThingODDPObserverDelegate>)delegate deviceID:(NSString *)deviceID codes:(NSArray<NSString *> *)codes;
+ (void)removeObserverDelegate:(id<ThingODDPObserverDelegate>)delegate deviceID:(NSString *)deviceID codes:(NSArray<NSString *> *)codes;

/// Listening device DPs callback, Block will only trigger once.
/// @param deviceID device ID
/// @param code schema code
/// @param schemaMBlock block callback
+ (void)monitorDPWithDeviceID:(NSString *)deviceID code:(NSString *)code schemaMBlock:(ThingODDPObserverSchemaMBlock)schemaMBlock;
@end

NS_ASSUME_NONNULL_END
