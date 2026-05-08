//
//  TuyaSmartAProductGuideData.h
//  TYActivatorSktAPI
//
//  Created by qisong on 2022/3/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartAProductGuideInfo : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *content;
@property (nonatomic, strong) NSString *url;
@end

@interface TuyaSmartAProductGuideData : NSObject
@property (nonatomic, strong) NSArray <TuyaSmartAProductGuideInfo *>*guideInfo;
@end

NS_ASSUME_NONNULL_END
