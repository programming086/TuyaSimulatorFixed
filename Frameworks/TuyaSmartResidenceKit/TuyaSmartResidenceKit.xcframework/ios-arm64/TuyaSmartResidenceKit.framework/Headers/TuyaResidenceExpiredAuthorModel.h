//
//  TuyaResidenceExpiredAuthorModel.h
//  TuyaSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaResidenceExpiredAuthorModel : NSObject

/// Authorisation start time
@property (nonatomic, assign) NSTimeInterval authStartTime;

/// Authorisation end time
@property (nonatomic, assign) NSTimeInterval authEndTime;

/// The ID of project
@property (nonatomic, copy) NSString *projectId;

@property (nonatomic, copy) NSString *spaceFullName;

/// The name of project
@property (nonatomic, copy) NSString *projectName;

@property (nonatomic, copy) NSString *spaceName;

@property (nonatomic, copy) NSString *spaceId;

@end

NS_ASSUME_NONNULL_END
