//
//  TSceneFeatureResult.h
//  ThingSceneFeatureAPI
//
//  Created by mile on 2024/1/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Interface call result
typedef NS_ENUM(NSInteger, TSceneFeatureResultCode) {
    // An error occurred
    TSceneFeatureResultVerificationErrorOccurred = 0,
    // No verification required
    TSceneFeatureResultVerificationNoRequired,
    // Verification completed
    TSceneFeatureResultVerificationComplete,
    // Device offline
    TSceneFeatureResultVerificationDeviceOffline
};

/// Local scene execution result
typedef NS_ENUM(NSInteger, TSceneFeatureVerifiedStatus) {
    /// Verification succeeded
    TSceneFeatureVerifiedStatusCreateSucceeded = 0,
    /// Exceeded the number limitation for writing data
    TSceneFeatureVerifiedStatusOverLimit,
    /// Response timeout when writing
    TSceneFeatureVerifiedStatusResponseTimeout,
    /// Set value exceeds minimum and maximum limits
    TSceneFeatureVerifiedStatusValueOutRange,
    /// Failed to write file
    TSceneFeatureVerifiedStatusWriteFileFailed,
    /// Other errors
    TSceneFeatureVerifiedStatusOther,
    /// Gateway timeout
    TSceneFeatureVerifiedStatusGatewayTimeout
};

/// Single action verification model
@interface TSceneFeatureVerifiedModel : NSObject
/// Device ID
@property (nonatomic, copy) NSString *devId;
/// Gateway ID
@property (nonatomic, copy) NSString *gwId;
/// Action execution DP data
@property (nonatomic, copy) NSDictionary *dps;
/// Device communication ID
@property (nonatomic, copy) NSString *nodeId;
/// Action content display
@property (nonatomic, copy) NSDictionary *actionDisplayNew;
/// Action execution result code
@property (nonatomic, assign) TSceneFeatureVerifiedStatus code;
/// Verification information
@property (nonatomic, copy) NSString *sid;
/// Verification information
@property (nonatomic, copy) NSString *gid;

@end

/// Interface call return result model
@interface TSceneFeatureResultModel : NSObject
/// Interface call result code
@property (nonatomic, assign) TSceneFeatureResultCode code;
/// Array of verification results, containing information related to each verification action
@property (nonatomic, strong) NSArray<TSceneFeatureVerifiedModel *> *verifiedModels;

@end

NS_ASSUME_NONNULL_END
