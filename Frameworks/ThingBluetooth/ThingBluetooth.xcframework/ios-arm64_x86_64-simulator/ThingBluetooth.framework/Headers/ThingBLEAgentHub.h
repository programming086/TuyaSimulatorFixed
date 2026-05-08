
#import <Foundation/Foundation.h>

CB_EXTERN NSString * _Nonnull const Thing_BLE_AGENT_SIGEL_BLE;
CB_EXTERN NSString * _Nonnull const Thing_BLE_AGENT_BLE_MESH;
CB_EXTERN NSString * _Nonnull const Thing_BLE_AGENT_SIG_MESH;
CB_EXTERN NSString * _Nonnull const Thing_BLE_AGENT_BLE_BEACON;
CB_EXTERN NSString * _Nonnull const Thing_BLE_AGENT_BLE_MATTER;
CB_EXTERN NSString * _Nonnull const Thing_BLE_AGENT_BLE_BEACON_MESH;

NS_ASSUME_NONNULL_BEGIN

@class ThingBLEAgent;
@interface ThingBLEAgentHub : NSObject

@property (nonatomic, strong, readonly) NSMutableArray *connectList;

+ (ThingBLEAgent *)getAgentWithAgentKey:(NSString *)AgentKey;

+ (NSArray *)getServiceUUIDsWithAgentKey:(NSString *)AgentKey;

+ (instancetype)hub;

- (void)appendConnectP:(NSString *)identifie;

- (void)removeConnectP:(NSString *)identifie;

@end

NS_ASSUME_NONNULL_END
