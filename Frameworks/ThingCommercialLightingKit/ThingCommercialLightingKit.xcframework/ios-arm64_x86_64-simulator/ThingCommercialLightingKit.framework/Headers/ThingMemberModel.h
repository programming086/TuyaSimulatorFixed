//
//  ThingMemberModel.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingMemberModel : NSObject

@property (nonatomic, strong) NSString *nickName;
@property (nonatomic, strong) NSString *uid;
@property (nonatomic, strong) NSString *roleImageUrl;
@property (nonatomic, strong) NSString *loginName;
@property (nonatomic, strong) NSString *roleName;
@property (nonatomic, strong) NSString *countryCode;
@property (nonatomic, strong) NSString *roleCode;
@property (nonatomic, assign) BOOL hasEditPerm;



@end

NS_ASSUME_NONNULL_END
