//
//  ThingSmartSceneBizEntryModel.h
//  ThingSmartSceneCoreKit
//
//  Created by liwan.chen on 2022/2/28.
//

#import <Foundation/Foundation.h>

/**
 The business entry type.
 */
typedef NS_ENUM(NSUInteger, ThingSmartSceneBizEntryType) {
    /**
     The none type.
     */
    ThingSmartSceneBizEntryTypeNone = 0,
    /**
     The light entry type.
     */
    ThingSmartSceneBizEntryTypeLight = 1,
};

/**
 @brief The business entry model.
 */
@interface ThingSmartSceneBizEntryModel : NSObject

/**
 The business entry type.
 */
@property (nonatomic, assign) ThingSmartSceneBizEntryType bizEntryType;
/**
 The entry display name.
 */
@property (nonatomic, copy) NSString *name;
/**
 The entry target jump url.
 */
@property (nonatomic, copy) NSString *jumpUrl;
/**
 The business entry extra information.
 */
@property (nonatomic, strong) NSDictionary *extraInfo;

@end

