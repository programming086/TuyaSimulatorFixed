
#import <Foundation/Foundation.h>
#import <ThingSmartActivatorDiscoveryManager/ThingSmartActivatorDiscoveryManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartActivatorService : NSObject

/// Retrieves primary category data for configuration network device list
/// @param success Callback containing optional `ThingSmartACategoryModel` on success
/// @param failure Callback containing error object on failure
- (void)requestLevelOneListWithSuccess:(void(^)(ThingSmartACategoryModel * _Nullable model))success
                               failure:(void(^)(NSError *error))failure;

/// Retrieves secondary category data for configuration network device list
/// @param levelOneCode Parent category code from primary level
/// @param type Category type identifier from primary level
/// @param success Callback containing array of `ThingSmartACategoryLevel2Model` on success
/// @param failure Callback containing error object on failure
- (void)requestLevelSecondListWithLevelOneCode:(NSString *)levelOneCode
                                          type:(NSString *)type
                                       success:(void(^)(NSArray<ThingSmartACategoryLevel2Model *> * _Nullable modelList))success
                                       failure:(void(^)(NSError *error))failure;

/// Retrieves tertiary category details for specific product configuration
/// @param PID Target product identifier (optional)
/// @param category Device category name (optional)
/// @param success Callback containing `ThingSmartDeviceCategoryModel` on success
/// @param failure Callback containing error object on failure
- (void)requestCategoryDetailWithPID:(NSString * _Nullable)PID
                            category:(NSString * _Nullable)category
                             success:(void(^)(ThingSmartDeviceCategoryModel * _Nullable model))success
                             failure:(void(^)(NSError *error))failure;
@end

NS_ASSUME_NONNULL_END
