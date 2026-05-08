
#import <Foundation/Foundation.h>
#import <ThingSmartP2pChannelKit/ThingSmartP2pChannelKit.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingSmartCameraBase/ThingSmartCameraBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingNVRConnectState) {
    ThingNVRNotSupport = -1,
    ThingNVRDisconnected = 0,
    ThingNVRConnecting,
    ThingNVRConnected,
    ThingNVRSkillUnfound,
};

@class ThingSmartNVR;
@protocol ThingSmartNVRDelegate <NSObject>

@optional
- (void)nvr:(ThingSmartNVR *)nvr sessionStatusDidChanged:(NSInteger)status;

@end

@interface ThingSmartNVR : NSObject

@property (nonatomic, assign) ThingNVRConnectState connectState;

@property (nonatomic, assign) BOOL didSubDevicesBind;

@property (nonatomic, weak) id<ThingSmartNVRDelegate> delegate;

+ (instancetype)nvrWithDeviceId:(NSString *)devId;

- (void)connectWithMode:(ThingSmartP2pConnectMode)connectMode success:(void(^)(void))success failure:(void(^)(NSInteger errCode))failure;

- (void)setupSubDevices:(NSArray<ThingSmartDeviceModel *> *)devices success:(void(^)(void))success failure:(void(^)(NSInteger errCode))failure;

- (id<ThingSmartCameraType>)cameraWithNodeId:(NSString *)nodeId;

- (void)connectSubDeviceWithCamera:(id<ThingSmartCameraType>)camera delegate:(id<ThingSmartCameraDelegate>)delegate  success:(void(^)(id<ThingSmartCameraType> camrea))success failure:(void(^)(NSInteger errCode))failure;

- (void)disconnect;

@end

NS_ASSUME_NONNULL_END
