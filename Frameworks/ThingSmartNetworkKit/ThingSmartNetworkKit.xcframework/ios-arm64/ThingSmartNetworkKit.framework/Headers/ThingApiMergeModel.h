
#ifndef ThingApiMergeModel_h
#define ThingApiMergeModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief ThingApiMergeModel is an object of response data from ThingApiMergeService.
@interface ThingApiMergeModel : NSObject

/// Success.
@property (nonatomic, assign) BOOL      success;

/// Api name.
@property (nonatomic, strong) NSString  *apiName;

/// Error.
@property (nonatomic, strong) NSError   *error;

/// Response result.
@property (nonatomic, strong) id        result;

/// Timestamp.
@property (nonatomic, assign) NSTimeInterval time;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingApiMergeModel_h */
