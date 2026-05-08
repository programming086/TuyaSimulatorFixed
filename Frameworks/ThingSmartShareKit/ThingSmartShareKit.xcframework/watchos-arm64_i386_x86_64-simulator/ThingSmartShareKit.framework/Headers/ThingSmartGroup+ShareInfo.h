
#import <ThingSmartDeviceCoreKit/ThingSmartGroup.h>

@interface ThingSmartGroup (ShareInfo)

/// Get sharing information of the group.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareGroupFromInfoWithSuccess:(ThingSuccessID)success
                                 failure:(ThingFailureError)failure;


/// Remove sharing groups.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeShareGroupWithSuccess:(ThingSuccessID)success
                            failure:(ThingFailureError)failure;

@end

