
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingMeshBeaconAdvType){
    ThingMeshBeaconAdvTypeUnknow                   = 0,
    ThingMeshBeaconAdvTypePairing                  = 1,     //配网广播
    ThingMeshBeaconAdvTypeDevice                   = 2,     //配网完毕的设备信息广播
    ThingMeshBeaconAdvTypeOther                    = 3,     //统一其他头
    ThingMeshBeaconAdvTypeRecovery                 = 4,     //自恢复
};

@interface ThingMeshBeaconAdverstingQuickFrame : NSObject

@property (nonatomic, strong) NSData *header;
@property (nonatomic, strong) NSString *mac;
@property (nonatomic, strong) NSString *pid;
@property (nonatomic, strong) NSString *device_rand;
@property (nonatomic, strong) NSString *auth;
@property (nonatomic, strong) NSData *advertiseingData;
@property (nonatomic, strong) NSData *category_bit;
@property (nonatomic, strong) NSData *rfu;

@property (nonatomic, assign) ThingMeshBeaconAdvType type;

//设备已配网广播字段
@property (nonatomic, strong) NSData *mesh_categroy;

@property (nonatomic, strong) NSData *mesh_category_ext;

@property (nonatomic, strong) NSData *version;

@property (nonatomic, strong) NSData *unicast_addr;

@property (nonatomic, strong) NSData *net_auth;

@property (nonatomic, strong) NSString *mcuVersion;

@property (nonatomic, assign) BOOL needPublishAddr;

@property (nonatomic, assign) BOOL recoverySuccess;

//校验广播包是否是mesh beacon2.0广播
+ (BOOL)validateQuickBeaconformatData:(NSDictionary *)data;

+ (instancetype)frameWithAdverstingData:(NSArray *)services;

+ (instancetype)frameWithBeaconData:(NSData *)advertisingData;

- (void)updateFrameWithUncrptyData:(NSData *)data;

- (BOOL)supportRecovery;

@end

NS_ASSUME_NONNULL_END
