
#import <UIKit/UIKit.h>
#import "ThingEncryptWebImageCompat.h"

NS_ASSUME_NONNULL_BEGIN

/**
 ThingEncryptKVStorageItem is used by `ThingEncryptImageKVStorage` to store key-value pair and meta data.
 Thingpically, you should not use this class directly.
 */
@interface ThingEncryptKVStorageItem : NSObject
@property (nonatomic, strong) NSString *key;                ///< key
@property (nonatomic, strong) NSData *value;                ///< value
@property (nullable, nonatomic, strong) NSString *filename; ///< filename (nil if inline)
@property (nonatomic) int size;                             ///< value's size in bytes
@property (nonatomic) int modTime;                          ///< modification unix timestamp
@property (nonatomic) int accessTime;                       ///< last access unix timestamp
@property (nullable, nonatomic, strong) NSData *extendedData; ///< extended data (nil if no extended data)
@end


/**
 ThingKVStorage is a key-value storage based on sqlite and file system.
 Thingpically, you should not use this class directly.
 
 @discussion The designated initializer for ThingKVStorage is `initWithPath:`.
 After initialized, a directory is created based on the `path` to hold key-value data.
 Once initialized you should not read or write this directory without the instance.

 
 @warning The instance of this class is *NOT* thread safe, you need to make sure
 that there's only one thread to access the instance at the same time. If you really
 need to process large amounts of data in multi-thread, you should split the data
 to multiple KVStorage instance (sharding).
 */
@interface ThingEncryptImageKVStorage : NSObject

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================

@property (nonatomic, readonly) NSString *path;        ///< The path of this storage.
@property (nonatomic, readonly) NSString *dataDirectory;        ///< The data path of this storage.
@property (nonatomic) BOOL errorLogsEnabled;           ///< Set `YES` to enable error logs for debug.

#pragma mark - Initializer
///=============================================================================
/// @name Initializer
///=============================================================================
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 The designated initializer.
 
 @param path  Full path of a directory in which the storage will write data. If
    the directory is not exists, it will try to create one, otherwise it will
    read the data in this directory.
 @return  A new storage object, or nil if an error occurs.
 @warning Multiple instances with the same path will make the storage unstable.
 */
- (nullable instancetype)initWithPath:(NSString *)path NS_DESIGNATED_INITIALIZER;


#pragma mark - Save Items
///=============================================================================
/// @name Save Items
///=============================================================================

/**
 Save an item or update the item with 'key' if it already exists.
 
 @discussion This method will save the item.key, item.value, item.filename and
 item.extendedData to disk or sqlite, other properties will be ignored. item.key
 and item.value should not be empty (nil or zero length).
 the item.filename should not be empty.
 
 @param item  An item.
 @return Whether succeed.
 */
- (BOOL)saveItem:(ThingEncryptKVStorageItem *)item;

/**
 Save an item or update the item with 'key' if it already exists.
 
 @param key   The key, should not be empty (nil or zero length).
 @param value The key, should not be empty (nil or zero length).
 @return Whether succeed.
 */
- (BOOL)saveItemWithKey:(NSString *)key value:(NSData *)value;

/**
 Save an item or update the item with 'key' if it already exists.
 the `filename` should not be empty.
 
 @param key           The key, should not be empty (nil or zero length).
 @param value         The key, should not be empty (nil or zero length).
 @param filename      The filename.
 @param extendedData  The extended data for this item (pass nil to ignore it).
 
 @return Whether succeed.
 */
- (BOOL)saveItemWithKey:(NSString *)key
                  value:(NSData *)value
               filename:(nullable NSString *)filename
           extendedData:(nullable NSData *)extendedData;

#pragma mark - Remove Items
///=============================================================================
/// @name Remove Items
///=============================================================================

/**
 Remove an item with 'key'.
 
 @param key The item's key.
 @return Whether succeed.
 */
- (BOOL)removeItemForKey:(NSString *)key;

/**
 Remove items with an array of keys.
 
 @param keys An array of specified keys.
 
 @return Whether succeed.
 */
- (BOOL)removeItemForKeys:(NSArray<NSString *> *)keys;

/**
 Remove all items which last access time is earlier than a specified timestamp.
 
 @param time  The specified unix timestamp.
 @return Whether succeed.
 */
- (BOOL)removeItemsEarlierThanTime:(int)time;

/**
 Remove items to make the total size not larger than a specified size.
 The least recently used (LRU) items will be removed first.
 
 @param maxSize The specified size in bytes.
 @return Whether succeed.
 */
- (BOOL)removeItemsToFitSize:(int)maxSize;

/**
 Remove all items in background queue.
 
 @discussion This method will remove the files and sqlite database to a trash
 folder, and then clear the folder in background queue.
 
 @return Whether succeed.
 */
- (BOOL)removeAllItems;

/**
 Remove all items under the given path in background queue.
 
 @return Whether succeed.
 */
- (BOOL)removeItemsAtPath:(NSString *)path;


#pragma mark - Get Items
///=============================================================================
/// @name Get Items
///=============================================================================

/**
 Get item with a specified key.
 
 @param key A specified key.
 @return Item for the key, or nil if not exists / error occurs.
 */
- (nullable ThingEncryptKVStorageItem *)getItemForKey:(NSString *)key;

/**
 Get item value with a specified key.
 
 @param key  A specified key.
 @return Item's value, or nil if not exists / error occurs.
 */
- (nullable NSData *)getItemValueForKey:(NSString *)key;

/**
 Get items value with an array of keys.
 
 @param keys  An array of specified keys.
 @return A dictionary which key is 'key' and value is 'value', or nil if not
    exists / error occurs.
 */
- (nullable NSDictionary<NSString *, NSData *> *)getItemValueForKeys:(NSArray<NSString *> *)keys;

/**
 The cache path for key

 @param key A string identifying the value
 @return The cache path for key. Or nil if the key can not associate to a path
 */
- (nullable NSString *)cachePathForKey:(nonnull NSString *)key;

#pragma mark - Get Storage Status
///=============================================================================
/// @name Get Storage Status
///=============================================================================

/**
 Whether an item exists for a specified key.
 
 @param key  A specified key.
 
 @return `YES` if there's an item exists for the key, `NO` if not exists or an error occurs.
 */
- (BOOL)itemExistsForKey:(NSString *)key;

/**
 Get total item count.
 @return Total item count, -1 when an error occurs.
 */
- (int)getItemsCount;

/**
 Get item value's total size in bytes.
 @return Total size in bytes, -1 when an error occurs.
 */
- (int)getItemsSize;

@end

NS_ASSUME_NONNULL_END
