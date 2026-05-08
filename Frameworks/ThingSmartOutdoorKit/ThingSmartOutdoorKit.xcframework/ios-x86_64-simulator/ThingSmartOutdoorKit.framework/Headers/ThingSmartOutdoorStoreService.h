
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// store data model
NS_SWIFT_NAME(StoreModel)
@interface ThingSmartOutdoorStoreModel : NSObject <NSSecureCoding>
/// store id
@property (nonatomic, copy) NSString *identifier;
/// store picture (not support)
@property (nonatomic, copy) NSString *coverUrl;
/// manufacturer
@property (nonatomic, copy) NSString *venderName;
@property (nonatomic, copy) NSString *address;
@property (nonatomic, copy) NSString *phoneNumber;
/// coordinate type
@property (nonatomic, copy) NSString *coordType;
/// distance between current location and store (unit: m)
@property (nonatomic, assign) NSInteger distance;
@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double longitude;
@end

/// store request model
NS_SWIFT_NAME(StoreRequestModel)
@interface ThingSmartOutdoorStoreRequestModel : NSObject
/// search radius(unit: km)
@property (nonatomic, assign) NSInteger radius;
@property (nonatomic, assign) double longitude;
@property (nonatomic, assign) double latitude;
/// coordinate type
/// WGS84-google，GCJ02-gaode，BD09LL-baidu
@property (nonatomic, copy) NSString *coordType;
/// max items
@property (nonatomic, assign) NSInteger max;
@end

/// store page request model
NS_SWIFT_NAME(StorePageRequestModel)
@interface ThingSmartOutdoorStorePageRequestModel : NSObject
@property (nonatomic, assign) double longitude;
@property (nonatomic, assign) double latitude;
@property (nonatomic, copy) NSString *coordType;
@property (nonatomic, copy) NSString *keyword;
@property (nonatomic, assign) NSInteger pageIndex;
@property (nonatomic, assign) NSInteger pageSize;
@end

NS_SWIFT_NAME(StoreService)
@interface ThingSmartOutdoorStoreService : NSObject
/// request store with radius
- (void)requestStoreWithParams:(ThingSmartOutdoorStoreRequestModel *)params
                    completion:(void (^)(NSArray<ThingSmartOutdoorStoreModel*> *storeList, NSError *error))completion;

/// request store with keyword
- (void)requestStorePagesWithParams:(ThingSmartOutdoorStorePageRequestModel *)params
                         completion:(void (^)(NSArray<ThingSmartOutdoorStoreModel*> *storeList, NSError *error))completion;
@end

NS_ASSUME_NONNULL_END
