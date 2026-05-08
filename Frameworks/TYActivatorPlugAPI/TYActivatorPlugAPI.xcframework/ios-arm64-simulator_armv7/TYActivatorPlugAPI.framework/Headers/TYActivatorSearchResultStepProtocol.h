//
//  TYActivatorSearchResultStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class TYActivatorPairingDeviceEditInfo;

typedef void(^TYActivatorSearchResultEditDeviceCompletion)(TYActivatorPairingDeviceEditInfo *currentInfo);

@protocol TYActivatorSearchResultStepProtocol <NSObject>
@property (nonatomic, copy, nullable) void(^customEditDeviceBlock)(TYActivatorPairingDeviceEditInfo *editInfo, TYActivatorSearchResultEditDeviceCompletion completion); //自定义设备编辑

@property (nonatomic, assign) BOOL disableEditName; //禁止修改设备名称

@property (nonatomic, assign) BOOL disableEditRoom; //禁止修改设备房间
@end

NS_ASSUME_NONNULL_END
