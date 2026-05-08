//
//  TYEncryptDiskCache.h
//  TYEncryptImage
//
//  Created by Jake Hu on 2020/1/31.
//

#import "TYEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYEncryptDiskCache : NSObject

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================

/** The name of the cache. Default is nil. */
@property (nullable, copy) NSString *name;

/** The path of the cache (read-only). */
@property (readonly) NSString *path;

/** The path of the cache data (read-only). */
@property (readonly) NSString *dataDirectory;

/**
 When an object needs to be saved as a file, this block will be invoked to generate
 a file name for a specified key. If the block is nil, the cache use md5(key) as
 default file name.
 
 The default value is nil.
 */
@property (nullable, copy) NSString *(^customFileNameBlock)(NSString *key);



#pragma mark - Limit
///=============================================================================
/// @name Limit
///=============================================================================

/**
 The maximum number of objects the cache should hold.
 
 @discussion The default value is NSUIntegerMax, which means no limit.
 This is not a strict limit — if the cache goes over the limit, some objects in the
 cache could be evicted later in background queue.
 */
@property NSUInteger countLimit;

/**
 The maximum total cost that the cache can hold before it starts evicting objects.
 
 @discussion The default value is NSUIntegerMax, which means no limit.
 This is not a strict limit — if the cache goes over the limit, some objects in the
 cache could be evicted later in background queue.
 */
@property NSUInteger costLimit;

/**
 The maximum expiry time of objects in cache.
 
 @discussion The default value is DBL_MAX, which means no limit.
 This is not a strict limit — if an object goes over the limit, the objects could
 be evicted later in background queue.
 */
@property NSTimeInterval ageLimit;

/**
 The minimum free disk space (in bytes) which the cache should kept.
 
 @discussion The default value is 0, which means no limit.
 If the free disk space is lower than this value, the cache will remove objects
 to free some disk space. This is not a strict limit—if the free disk space goes
 over the limit, the objects could be evicted later in background queue.
 */
@property NSUInteger freeDiskSpaceLimit;

/**
 The auto trim check time interval in seconds. Default is 60 (1 minute).
 
 @discussion The cache holds an internal timer to check whether the cache reaches
 its limits, and if the limit is reached, it begins to evict objects.
 */
@property NSTimeInterval autoTrimInterval;

/**
 Set `YES` to enable error logs for debug.
 */
@property BOOL errorLogsEnabled;

#pragma mark - Initializer
///=============================================================================
/// @name Initializer
///=============================================================================
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 Create a new cache based on the specified path.
 
 @param path Full path of a directory in which the cache will write data.
     Once initialized you should not read and write to this directory.
 
 @return A new cache object, or nil if an error occurs.
 
 @warning If the cache instance for the specified path already exists in memory,
     this method will return it directly, instead of creating a new instance.
 */
- (nullable instancetype)initWithPath:(NSString *)path NS_DESIGNATED_INITIALIZER;


#pragma mark - Access Methods
///=============================================================================
/// @name Access Methods
///=============================================================================

/**
 Returns a boolean value that indicates whether a given key is in cache.
 This method may blocks the calling thread until file read finished.
 
 @param key A string identifying the value. If nil, just return NO.
 @return Whether the key is in cache.
 */
- (BOOL)containsObjectForKey:(NSString *)key;

/**
 Returns a boolean value with the block that indicates whether a given key is in cache.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param key   A string identifying the value. If nil, just return NO.
 @param block A block which will be invoked in background queue when finished.
 */
- (void)containsObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key, BOOL contains))block;

/**
 Returns the value associated with a given key.
 This method may blocks the calling thread until file read finished.
 
 @param key A string identifying the value. If nil, just return nil.
 @return The value associated with key, or nil if no value is associated with key.
 */
- (nullable id<NSCoding>)objectForKey:(NSString *)key;

/**
 Returns the value associated with a given key.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param key A string identifying the value. If nil, just return nil.
 @param block A block which will be invoked in background queue when finished.
 */
- (void)objectForKey:(NSString *)key withBlock:(void(^)(NSString *key, id<NSCoding> _Nullable object))block;

/**
 Sets the value of the specified key in the cache.
 This method may blocks the calling thread until file write finished.
 
 @param object The object to be stored in the cache. If nil, it calls `removeObjectForKey:`.
 @param key    The key with which to associate the value. If nil, this method has no effect.
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

/**
 Sets the value of the specified key in the cache.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param object The object to be stored in the cache. If nil, it calls `removeObjectForKey:`.
 @param block  A block which will be invoked in background queue when finished.
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(void(^)(void))block;

/**
 Removes the value of the specified key in the cache.
 This method may blocks the calling thread until file delete finished.
 
 @param key The key identifying the value to be removed. If nil, this method has no effect.
 */
- (void)removeObjectForKey:(NSString *)key;

/**
 Removes the value of the specified key in the cache.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param key The key identifying the value to be removed. If nil, this method has no effect.
 @param block  A block which will be invoked in background queue when finished.
 */
- (void)removeObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key))block;

/**
 Empties the cache.
 This method may blocks the calling thread until file delete finished.
 */
- (void)removeAllObjects;

/**
 Empties the cache.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param block  A block which will be invoked in background queue when finished.
 */
- (void)removeAllObjectsWithBlock:(void(^)(void))block;

/**
 Remove all items under the given path in background queue.
 */
- (void)removeObjectsAtPath:(NSString *)path;

/**
 Returns the number of objects in this cache.
 This method may blocks the calling thread until file read finished.
 
 @return The total objects count.
 */
- (NSInteger)totalCount;

/**
 Get the number of objects in this cache.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param block  A block which will be invoked in background queue when finished.
 */
- (void)totalCountWithBlock:(void(^)(NSInteger totalCount))block;

/**
 Returns the total cost (in bytes) of objects in this cache.
 This method may blocks the calling thread until file read finished.
 
 @return The total objects cost in bytes.
 */
- (NSInteger)totalCost;

/**
 Get the total cost (in bytes) of objects in this cache.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param block  A block which will be invoked in background queue when finished.
 */
- (void)totalCostWithBlock:(void(^)(NSInteger totalCost))block;

#pragma mark - Cache file Info

/**
 When an object needs to be saved as a file, this function will be invoked to generate
 a file name use md5(key) as default file name.
 */
- (nullable NSString *)cachedFileNameForKey:(nullable NSString *)key;

#pragma mark - Trim
///=============================================================================
/// @name Trim
///=============================================================================

/**
 Removes objects from the cache use LRU, until the `totalCost` is below the specified value.
 This method may blocks the calling thread until operation finished.
 
 @param cost The total cost allowed to remain after the cache has been trimmed.
 */
- (void)trimToCost:(NSUInteger)cost;

/**
 Removes objects from the cache use LRU, until the `totalCost` is below the specified value.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param cost The total cost allowed to remain after the cache has been trimmed.
 @param block  A block which will be invoked in background queue when finished.
 */
- (void)trimToCost:(NSUInteger)cost withBlock:(void(^)(void))block;

/**
 Removes objects from the cache use LRU, until all expiry objects removed by the specified value.
 This method may blocks the calling thread until operation finished.
 
 @param age  The maximum age of the object.
 */
- (void)trimToAge:(NSTimeInterval)age;

/**
 Removes objects from the cache use LRU, until all expiry objects removed by the specified value.
 This method returns immediately and invoke the passed block in background queue
 when the operation finished.
 
 @param age  The maximum age of the object.
 @param block  A block which will be invoked in background queue when finished.
 */
- (void)trimToAge:(NSTimeInterval)age withBlock:(void(^)(void))block;


#pragma mark - Extended Data
///=============================================================================
/// @name Extended Data
///=============================================================================

/**
 Get extended data from an object.
 
 @discussion See 'setExtendedData:toObject:' for more information.
 
 @param object An object.
 @return The extended data.
 */
+ (nullable NSData *)getExtendedDataFromObject:(id)object;

/**
 Set extended data to an object.
 
 @discussion You can set any extended data to an object before you save the object
 to disk cache. The extended data will also be saved with this object. You can get
 the extended data later with "getExtendedDataFromObject:".
 
 @param extendedData The extended data (pass nil to remove).
 @param object       The object.
 */
+ (void)setExtendedData:(nullable NSData *)extendedData toObject:(id)object;

@end

NS_ASSUME_NONNULL_END
