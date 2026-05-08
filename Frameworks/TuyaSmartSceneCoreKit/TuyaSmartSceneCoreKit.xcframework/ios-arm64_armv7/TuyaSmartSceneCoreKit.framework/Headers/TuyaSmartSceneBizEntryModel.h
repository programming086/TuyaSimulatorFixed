//
//  TuyaSmartSceneBizEntryModel.h
//  TuyaSmartSceneCoreKit
//
//  Created by liwan.chen on 2022/2/28.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    TuyaSmartSceneBizEntryTypeNone = 0,
    TuyaSmartSceneBizEntryTypeLight = 1,
} TuyaSmartSceneBizEntryType;

@interface TuyaSmartSceneBizEntryModel : NSObject

@property (nonatomic, assign) TuyaSmartSceneBizEntryType bizEntryType;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *jumpUrl;
@property (nonatomic, strong) NSDictionary *extraInfo;

@end

