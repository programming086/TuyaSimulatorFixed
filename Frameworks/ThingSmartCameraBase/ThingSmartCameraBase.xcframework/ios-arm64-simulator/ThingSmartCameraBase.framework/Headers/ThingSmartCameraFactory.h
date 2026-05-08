
#import <Foundation/Foundation.h>
#import "ThingSmartCameraType.h"

typedef NS_ENUM(NSUInteger, ThingSmartCameraP2PType) {
    ThingSmartCameraP2PTypeTUTK = 1,
    ThingSmartCameraP2PTypePPCS,
    ThingSmartCameraP2PTypeTHING
};

@interface ThingSmartCameraConfig : NSObject

- (instancetype)initCameraConfig:(NSDictionary *)dictionary;

/**
 [^en]
 device id of the camera
 [$en]
 */
@property (nonatomic, strong) NSString *devId;

/**
 [^en]
 Get the configuration data through the "thing.m.ipc.config.get" api, the value of the "p2pId" field in the data.
 [$en]
 */
@property (nonatomic, strong) NSString *p2pId;

/**
 [^en]
 Get the configuration data through the "thing.m.ipc.config.get" api, the value of the "password" field in the data.
 [$en]

 */
@property (nonatomic, strong) NSString *password;

/**
 [^en]
 Get the configuration data through the "thing.m.ipc.config.get" api, the value of the "p2pConfig" field in the data.if there is no "p2pConfig" field, set nil.
 [$en]

 */
@property (nonatomic, strong) NSDictionary *p2pConfig;

/**
 [^en]
 Get the configuration data through the "thing.m.ipc.config.get" api, the value of the "p2pSpecifiedType" field in the data.
 [$en]

 */
@property (nonatomic, assign) NSInteger p2pSpecifiedType;

@property (nonatomic, assign) NSInteger p2pType;

@property (nonatomic, assign) NSInteger p2pPolicy;

/**
 [^en]
 The "localKey" property in the ThingSmartDeviceModel object corresponding to the camera device.
 [$en]

 
 */
@property (nonatomic, strong) NSString *localKey;

/**
 [^en]
 ThingSmartUser.uid
 [$en]

 */
@property (nonatomic, strong) NSString *uid;

/**
 [^en]
 camera station sub device info
  
  NSDictionary *dic = @{@"did" : stationDid,
  @"subDid" : listDevicDid};
 [$en]
 */
@property (nonatomic, strong) NSDictionary *subDic;

// [^en]private log trace id[$en]
@property (nonatomic, strong) NSString *traceId;

@property (nonatomic, assign) BOOL isLocalChannel;

/// skills of camera device
@property (nonatomic, strong) NSString *skills;


/// ~ skills 【4.0】
@property (nonatomic, strong) NSDictionary *skillV4;

///media skills of device's screen
@property (nonatomic, copy) NSString *screenMediaSkills;

/// 清晰度
@property (nonatomic, strong) NSNumber *vedioClarity;
/// 支持的清晰度
@property (nonatomic, strong) NSArray *vedioClaritys;

@property (nonatomic, copy) NSString *sessionTid;
@property (nonatomic, strong) NSArray *panoramicInfo;

/// 【4.0】
@property (nonatomic, strong) NSString *timeZoneId;
@property (nonatomic, strong) NSArray *videoClarities;
@property (nonatomic, strong) NSNumber *maxZoomInTimes;
@property (nonatomic, strong) NSDictionary *mediaConsumerSkill;
@property (nonatomic, assign) BOOL isLowPower;
@property (nonatomic, strong) NSNumber *defaultVideoClarity;
@property (nonatomic, strong) NSDictionary *audioAttributes;
@property (nonatomic, strong) NSDictionary *mediaProducer;
@property (nonatomic, strong) NSDictionary *mediaConsumer;


@property (nonatomic, strong) NSDictionary *rowData;
@end

@protocol ThingSmartCameraMaker <NSObject>

+ (void)resetSocket;

+ (void)userDidLogOut;

+ (BOOL)handleP2PType:(id)type;

+ (id<ThingSmartCameraType>)createCameraWithConfig:(ThingSmartCameraConfig *)ipcConfig delegate:(id<ThingSmartCameraDelegate>)delegate;

+ (id<ThingSmartCameraType>)createCameraWithDeviceId:(NSString *)devId delegate:(id<ThingSmartCameraDelegate>)delegate;

@end

@interface ThingSmartCameraFactory : NSObject

+ (void)initSDKs __deprecated_msg("SDK will auto init when create camera instance");

+ (void)resetSocket;

+ (void)userDidLogOut;

/**
 [^en]
 get the camera sdk version
 [$en]

 */
+ (NSString *)thingSmartCameraVersion;

/**
 [^en]
 create a camera instance
 [$en]


 @param type [^en]p2p type，pass the value of the "p2pType" field in the "skills" attribute of the "ThingSmartDeviceModel" object corresponding to the camera device.[$en]
 
 @param ipcConfig camera config
 @param delegate delgate
 @return camera instance
 */
+ (id<ThingSmartCameraType>)cameraWithP2PType:(id)type config:(ThingSmartCameraConfig *)ipcConfig delegate:(id<ThingSmartCameraDelegate>)delegate;

/**
[^en]
create a camera instance
[$en]

@param type [^en]p2p type，pass the value of the "p2pType" field in the "skills" attribute of the "ThingSmartDeviceModel" object corresponding to the camera device.[$en]

@param devId device id
@param delegate delgate
@return camera instance
*/
+ (id<ThingSmartCameraType>)cameraWithP2PType:(id)type deviceId:(NSString *)devId delegate:(id<ThingSmartCameraDelegate>)delegate;


/**
 [^en]
 create a camera config instance
 [$en]


 @param uid [^en]User identifier from [ThingSmartUser sharedInstance].uid[$en]
 @param localKey [^en]from ThingSmartDeviceModel.localKey[$en]
 @param data [^en]the respond data of API  "thing.m.ipc.config.get"[$en]
 @return [^en]camera config[$en]
*/
+ (ThingSmartCameraConfig *)ipcConfigWithUid:(NSString *)uid localKey:(NSString *)localKey configData:(NSDictionary *)data;

#pragma mark - private, ignore this

+ (NSMutableArray<Class<ThingSmartCameraMaker>> *)cameraMakers;
+ (void)registerCameraMaker:(Class<ThingSmartCameraMaker>)maker;

@end
