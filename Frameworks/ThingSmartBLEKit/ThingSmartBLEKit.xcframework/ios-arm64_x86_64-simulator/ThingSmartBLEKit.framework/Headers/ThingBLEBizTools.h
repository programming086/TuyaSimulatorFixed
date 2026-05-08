
#import <Foundation/Foundation.h>
#import <ThingSmartBLECoreKit/ThingBLEDeviceInfoProtocol.h>
#import <ThingSmartBLECoreKit/ThingBLEGeneralHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingBLEBizTools : NSObject

//大数据command
/// 获取大数据摘要信息
/// @param type type
+ (NSData *)bigDataSummary:(unsigned int)type;

/// 获取大数据块摘要信息
/// @param type 类型
/// @param index 序号
+ (NSData *)bigDataBlockSummaryType:(unsigned int)type index:(NSInteger)index;

/// 删除大数据指令
/// @param type type
+ (NSData *)bigDataDel:(unsigned int)type ;

/**
 * 通过 UUID 换取设备 ThingSmartDeviceModel
 */
+ (ThingSmartDeviceModel *)getDeviceModelWithUUID:(NSString *)uuid;

/**
 *  设备是否属于当前账号
 */
+ (BOOL)deviceIsActive:(NSString *)uuid;

/**
*  判断是否是双模多协议设备
*/
+ (BOOL)isDualModeDevice:(NSString *)uuid;

+ (BOOL)isDualModeDeviceWithDevId:(NSString *)devId;

/**
*  判断双模多协议设备是否需要连接控制
*/
+ (BOOL)dualModeDeviceSupportBLEControl:(id <ThingBLEDeviceInfoProtocol>)deviceInfo;

#pragma mark - 设备强制解绑


/**
 *  查询设备是否属于其他账号
 */
- (void)unbindDeviceHandle:(ThingBLEAdvModel *)item success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


/// 清除设备缓存信息
- (void)clearUnbindDeviceCach;


/**
 *  重置设备查询缓存
 */
- (void)removeUnbindDeviceFlag:(NSString *)unbindDeviceId;

+ (void)updateBLEDeviceOnline:(ThingSmartDeviceModel *)device;

/// 通过广播包获取设备连接类型
+ (ThingBLESupportConnect)getConfigConnectType:(id<ThingBLEDeviceInfoProtocol>)dev;

//get connect type from deviceId
+ (ThingBLESupportConnect)getConfigConnectTypeWithUUID:(NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
