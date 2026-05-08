//
//  IndustryAssetMessageServiceHandler.h
//  IndustryAssetKit
//
//  Created by ChenKun on 2023/5/9.
//

#import <Foundation/Foundation.h>
@import IndustryAssetKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryAssetMessageServiceHandler : NSObject<IAssetMessageService>

@property (nonatomic, copy) NSString *assetId;

- (instancetype)initWithAssetId:(NSString *)assetId;

@end

NS_ASSUME_NONNULL_END
