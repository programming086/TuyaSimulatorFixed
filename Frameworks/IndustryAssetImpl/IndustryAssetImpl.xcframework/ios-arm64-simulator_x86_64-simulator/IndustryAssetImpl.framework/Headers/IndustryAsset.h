//
//  IndustryAsset.h
//  IndustryAssetImpl
//
//  Created by 后主 on 2022/7/25.
//

#import <Foundation/Foundation.h>
@import IndustryAssetKit;


NS_ASSUME_NONNULL_BEGIN

@interface IndustryAsset : NSObject <IAsset>

@property (nonatomic, copy) NSString *assetId;
@property (nonatomic, copy) NSString *assetName;
@property (nonatomic, copy, nullable) NSString *parentAssetId;
@property (nonatomic, copy) NSString *permission;
@property (nonatomic, assign) NSInteger currentSubAssetNum;
@property (nonatomic, assign) NSInteger currentAssetDeviceNum;

@property (nonatomic, copy) NSString *userDefinedPath;

@end

NS_ASSUME_NONNULL_END
