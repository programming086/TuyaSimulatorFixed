
#import <Foundation/Foundation.h>
#import "ThingSmartBLEAPMMessageModel.h"
#import "ThingSmartBLEAPMEnum.h"

// The reconnection event tracking.
#define Thing_LOG_EVENT_BLE_RECONNECTION                   @"af66d2469918c8d55dc6346598fd7d4f"  // The reconnection event tracking ID.

#define Thing_RECONNECT_LOG_TYPE_BLE_SUCCESS               @"ble_log_connect_success"  // The initial connection is successful.
#define Thing_RECONNECT_LOG_TYPE_BLE_RETRY_SUCCESS         @"ble_log_reconnect_success"  // The reconnection is successful.
#define Thing_RECONNECT_LOG_TYPE_BLE_FAILURE               @"ble_log_reconnect_failure"  // The reconnection failed.

@interface ThingSmartBLEAPMService : NSObject

+ (instancetype)sharedInstance;

- (void)putBLEAPMInDevId:(NSString *)devId type:(ThingSmartBLEAPMType)type des:(NSString *)des dps:(NSDictionary *)dps extInfo:(NSDictionary *)extInfo;
 
- (void)putBLEAPMWithMessageModel:(ThingSmartBLEAPMMessageModel *)messageModel;

- (void)logReconnectEvent:(NSString *)type reconnectCount:(NSInteger)reconnectCount errorCode:(NSInteger)errorCode;

@end
