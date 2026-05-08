//
//  ThingResidenceConst.h
//  Pods
//
//  Created by OYCA168 on 2022/2/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSiteAuthStatus) {
    ThingSiteAuthStatusToEffect    =   0,    //即将生效
    ThingSiteAuthStatusInEffect    =   1,    //有效期内
    ThingSiteAuthStatusOverdue     =   2,    //已过期
    ThingSiteAuthStatusForever     =   3,    //长期生效
};

typedef NS_ENUM(NSInteger, ThingSmartSiteType) {
    ThingSmartSiteType_Home     =   1,    //普通家庭
    ThingSmartSiteType_Access   =   2,    //通行家庭
    ThingSmartSiteType_Bisiness =   3,    //B端授权家庭
};

typedef NS_ENUM(NSInteger, ThingSmartSiteAccesssSource) {
    ThingSmartSiteAccesssSourceOther    =   0,    // 非通行家庭
    ThingSmartSiteAccesssSourceHome     =   1,    // 通行家庭 & 来源为普通家庭
    ThingSmartSiteAccesssSourceBusiness =   2,    // 通信家庭 & 来源为B2C
};

@interface ThingResidenceConst : NSObject

@end

NS_ASSUME_NONNULL_END
