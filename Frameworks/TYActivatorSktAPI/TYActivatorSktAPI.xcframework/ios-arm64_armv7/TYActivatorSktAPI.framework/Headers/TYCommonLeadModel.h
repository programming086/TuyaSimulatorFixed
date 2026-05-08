//
//  TYCommonLeadModel.h
//  TYActivatorModule
//
//  Created by 龙卷 on 2019/12/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TYActivatorLeadModel;
@interface TYCommonLeadModel : NSObject

@property (nonatomic, strong) NSArray<TYActivatorLeadModel *> *activatorLeadList;

@end

@interface TYActivatorLeadModel : NSObject

@property (nonatomic, copy) NSString *desText;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *iconUrl;

@end

NS_ASSUME_NONNULL_END
