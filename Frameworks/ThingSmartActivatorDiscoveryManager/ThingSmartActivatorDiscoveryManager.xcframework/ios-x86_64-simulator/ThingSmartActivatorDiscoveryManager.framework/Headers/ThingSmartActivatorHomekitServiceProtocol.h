//
//  ThingSmartActivatorHomekitServiceProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/9/6.
//

#ifndef ThingSmartActivatorHomekitServiceProtocol_h
#define ThingSmartActivatorHomekitServiceProtocol_h

@class ThingSmartActivatorHomekitDevice;
/// Homekit 协议方法用来搜索 Homekit 设备
@protocol ThingSmartActivatorHomekitServiceProtocol <NSObject>

@required
/**
 开始扫描homekit设备
 */
- (void)startSearchHomekitDevice:(void (^)(ThingSmartActivatorHomekitDevice *device))callback;

/**
 停止扫描Homekit设备
*/
- (void)stopSearchHomekitDevice;

/**
 开始配网
 
 @param device 设备
 @param homeId 家庭id
 @param success 成功回调
 @param failure 失败回调
 */
- (void)configThingSmartHomeKitDevice:(ThingSmartActivatorHomekitDevice *)device
                             timeout:(NSTimeInterval)timeout
                              homeId:(long long)homeId
                             success:(void (^)(ThingSmartDeviceModel *))success
                             failure:(void (^)(NSError *error))failure;

/**
 移除显示的homekit设备
 */
- (void)clearDisplayHomekitDevices;

@end


#endif /* ThingSmartActivatorHomekitServiceProtocol_h */
