//
//  IndustryAssetAssociatedModel.h
//  IndustryAssetImpl
//
//  Created by 后主 on 2022/7/26.
//

#import <Foundation/Foundation.h>
@import IndustryAssetKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryAssetAssociatedModel : NSObject <IAssociatedModel>
@property (nonatomic, copy) NSString *deviceGroupId;
@property (nonatomic, copy) NSString *homeId;
@property (nonatomic, copy) NSString *assetId;
@end

NS_ASSUME_NONNULL_END
