//
//  ThingResidenceExpiredAuthorModel.h
//  ThingSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceExpiredAuthorModel : NSObject

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
