
#import <Foundation/Foundation.h>
#import "ThingMachRegisterDefine.h"

NS_ASSUME_NONNULL_BEGIN
@interface ThingMachRegisterItem : NSObject
@property (nonatomic, assign) NSUInteger priority;
@property (nonatomic, strong) NSString * type;
@property (nonatomic, strong) NSString * Key;

- (nullable Class)registerClass; // Returns the associated class
- (nullable id)generate:(nullable id)defaultValue; // Returns the instance
@end

@interface ThingMachRegisterType : NSObject
/// Registered instances of max priority
@property (nonatomic, strong) NSMutableDictionary<NSString *, ThingMachRegisterItem *> * itemMap;
/// Registered instances of all priorities
@property (nonatomic, strong) NSMutableArray<ThingMachRegisterItem *> * itemList;


/// Get all registered nodes
/// - Parameter Key: node key
- (NSArray<ThingMachRegisterItem *> *)registerItemListWithKey:(NSString *)Key;
@end


/// Thread safety
@interface ThingMachRegisterManager : NSObject
+ (ThingMachRegisterManager *)shareInstance;

// Get the registered class with the highest priority
- (nullable Class)classWithType:(NSString *)type
                            key:(NSString *)key;

// Run the registration subject to obtain the instance value with the highest priority
- (nullable id)generateWithType:(NSString *)type
                            key:(NSString *)key;

// Determine whether registration exists
- (BOOL)exsitWithType:(NSString *)type
                  key:(NSString *)key;

// Get the information registered under the specified type
- (nullable ThingMachRegisterType *)registerModelWithType:(NSString *)type;

//Used to count how many codes use this collection method
- (void)trackerRegisterResultWithType:(NSString *)type count:(NSInteger)count deprecated:(BOOL)deprecated;
- (void)fetchDeprecatedRegisterResultWithComplete:(void (^)(NSDictionary<NSString *, NSNumber *> * map))block;
@end

NS_ASSUME_NONNULL_END
