
#import "ThingGroupDef.h"

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const ThingGroupBaseErrorDomain;

@interface ThingGroupBaseError : NSObject

/*
 Example of a failure callback
 {
     "groupId": "xxxx",
     "failureList": [{
         "devId": "xxx",
         "errorCode": 1
     }, {
         "devId": "xxx",
         "errorCode": 1
     }],
     "error": {
         "errorCode": 1,
         "errorMsg": "xxx"
     }
 }
 */

/// Generate failure information based on the error
/// @param error The error object
+ (NSDictionary *)makeFailureInfoWithError:(NSError *)error;

/// Generate failure information based on groupId and failureList
/// @param groupId The group ID
/// @param failureList The list of failures
+ (NSDictionary *)makeFailureInfoWithGroupId:(NSString *)groupId
                                 failureList:(NSArray <NSDictionary *> *)failureList;

/// Convert mesh device error codes to standard error codes
/// @param code The mesh error code
+ (ThingGroupErrorType)standardErrorCodeWithMeshCode:(NSInteger)code;

@end

NS_ASSUME_NONNULL_END
