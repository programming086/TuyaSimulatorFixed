//
//  ThingSmartActivatorActionContextProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by qisong on 2022/4/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorActionContextProtocol <NSObject>
/// @discussion 子设备配网时的网关Id，用于搜索当前网关下的zigbee子设备；其他配网方式该字段为空
@property (nonatomic, readonly, copy, nullable) NSString *gwDevId;
@end

NS_ASSUME_NONNULL_END
