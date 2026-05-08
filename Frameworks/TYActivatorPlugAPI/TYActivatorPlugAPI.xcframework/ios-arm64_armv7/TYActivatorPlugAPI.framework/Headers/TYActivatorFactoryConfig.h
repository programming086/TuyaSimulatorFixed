//
//  TYActivatorFactoryConfig.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYActivatorFactoryConfig : NSObject
@property (nonatomic, copy) NSString *ssid; ///< ssid
@property (nonatomic, copy) NSString *password; ///< password
@property (nonatomic, copy) NSString *gwId; ///< 用于子设备
@property (nonatomic, copy) NSString *token; ///< token
@property (nonatomic, strong) NSError *error;
@property (nonatomic, assign, getter=isSupport5G) bool support5G;
@end

NS_ASSUME_NONNULL_END
