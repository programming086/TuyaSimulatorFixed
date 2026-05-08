//
//  TYActivatorResultModel.h
//  TYModuleServices
//
//  Created by huangjj on 2021/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYActivatorResultModel : NSObject

@property (nonatomic, copy) NSString *iconUrl; ///< 设备图标 url
@property (nonatomic, copy) NSString *name; ///< 设备名
@property (nonatomic, strong) NSString     *devId; ///<  device Id
@property (nonatomic, strong) NSString     *uuid;
@property (nonatomic, strong) NSString     *parentId; ///<  parent Id

@property (nonatomic, copy) NSError *error; ///< 错误信息
@property (nonatomic, strong) id otherParam; ///< 用于存储原始的设备模型


@end


NS_ASSUME_NONNULL_END
