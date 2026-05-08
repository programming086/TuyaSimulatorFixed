//
//  TSceneCoreError.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/3/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const ThingSmartSceneErrorDomain;

typedef NS_ENUM(NSInteger, ThingSceneErrorCode) {
    /// The illegal homeID.
    ThingSceneErrorCodeIllegalHomeId = 20001,
    /// The illeagal roomID.
    ThingSceneErrorCodeIllegalRoomId,
    /// The response is incorrect.
    ThingSceneErrorResponseTypeIncorrect,
    /// The invalid params.
    ThingSceneErrorCodeInvalidRequestParams = 20099
};

/// Error infomation
///
/// Description: Error infomation.
@interface TSceneCoreError : NSObject
/// The error code.
@property (nonatomic, assign) ThingSceneErrorCode code;
/// Error infomation description.
@property (nonatomic, strong) NSString *message;

@end

NS_ASSUME_NONNULL_END
