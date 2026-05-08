//
//  ThingLightingAccountVO.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingAccountVO : NSObject

/// UID
@property (nonatomic, copy) NSString *uid;

/// The name by login
@property (nonatomic, copy) NSString *loginName;

/// The nick name
@property (nonatomic, copy) NSString *nickName;

/// The code of role
@property (nonatomic, copy) NSString *roleCode;

/// The name of role
@property (nonatomic, copy) NSString *roleName;

/// The remarks of account
@property (nonatomic, copy) NSString *remark;

/// The Creation time of account
@property (nonatomic, copy) NSString *createDate;

/// The Admin ID of account
@property (nonatomic, copy) NSString *adminId;

/// The page index of data source.
@property (nonatomic, assign) NSInteger page;

/// The size per page.
@property (nonatomic, assign) NSInteger pageSize;

@end

NS_ASSUME_NONNULL_END
