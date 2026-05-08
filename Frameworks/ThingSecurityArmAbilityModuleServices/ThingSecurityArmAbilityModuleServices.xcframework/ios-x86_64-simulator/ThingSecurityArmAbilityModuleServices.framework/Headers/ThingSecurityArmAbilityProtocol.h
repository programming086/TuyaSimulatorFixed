
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityArmDelayTimeModel.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecuritSaveModeDeviceRuleModel.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityArmAbilityDelegate.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityHomeArmDevicesModel.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityArmAbilityEnum.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityHomeBaseStateModel.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityAbnormalDeviceModel.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityAlarmMessageModel.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityModeSettingDeviceModel.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityAlarmDetailModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSecurityArmMode);
typedef NS_ENUM(NSInteger, ThingSecurityHomeInitType);

typedef void(^ThingSecurityGetArmModeHandler)(ThingSecurityArmMode mode,NSError * _Nullable error);

@protocol ThingSecurityArmAbilityProtocol <NSObject>

#pragma mark - init

- (void)securityHomeInitialize:(ThingSecurityHomeInitType)securityType;


- (void)registerSecurityModeDelegate:(id<ThingSecurityArmAbilityDelegate>)delegate;

- (void)unregisterDelegate:(id<ThingSecurityArmAbilityDelegate>)delegate;

- (void)updateSecurityWhiteGatewayList;


- (void)hasArmAbilityWith:(ThingSecurityArmMode)mode
                  success:(void(^)(NSArray<NSString *> *result))success
                  failure:(void(^)(NSError *error))failure;


- (void)getLocationCurrentMode:(ThingSecurityGetArmModeHandler)handler;

- (void)getHomeArmMode;

- (ThingSecurityArmMode)getCurretnModeFromCache;


- (void)getHomeStateSuccess:(void(^)(ThingSecurityHomeBaseStateModel *result))success
                    failure:(void(^)(NSError *error))failure;


- (void)updateArmedStateWithMode:(ThingSecurityArmMode)mode;


- (void)getIrregularDevice:(ThingSecurityArmMode)mode
                   success:(void(^)(NSArray<NSString *> *devices))success
                   failure:(void(^)(NSError *error))failure;


- (void)getAbnormalDevicesWithSuccess:(void(^)(NSArray<ThingSecurityAbnormalDeviceModel *>*result))success
                              failure:(void(^)(NSError *error))failure;

- (void)updateSecurityProductDpDescription;


- (void)getHomeArmDeviceSuccess:(void(^)(ThingSecurityHomeArmDevicesModel *result))success
                          failure:(void(^)(NSError *error))failure;


- (void)getDevicesInRuleByMode:(ThingSecurityArmMode)mode
                       success:(void (^)(ThingSecurityModeSettingDeviceModel *model))success
                       failure:(void (^)(NSError *error))failure;


- (void)saveDeviceListWithMode:(ThingSecurityArmMode)mode
                         datas:(NSArray<ThingSecuritSaveModeDeviceRuleModel *> *)datas
                       success:(void(^)(BOOL result))success
                       failure:(void(^)(NSError *error))failure;


- (void)getModeDelayInfo:(void(^)(NSArray<ThingSecurityArmDelayTimeModel *> *result))success
                 failure:(void(^)(NSError *error))failure;


- (void)saveArmedDelayTime:(ThingSecurityArmMode)mode
                 delayTime:(NSInteger)delayTime
                   success:(void(^)(BOOL result))success
                   failure:(void(^)(NSError *error))failure;


- (void)saveAlarmDelayTime:(ThingSecurityArmMode)mode
                 delayTime:(NSInteger)delayTime
                   success:(void(^)(BOOL result))success
                   failure:(void(^)(NSError *error))failure;

- (BOOL)locationOffline;

- (void)didSwitchSecurityLocation;


- (void)triggerAlarmAlarmType:(ThingHSGatewaySOSType)alarmType
                       success:(void(^)(BOOL result))success
                       failure:(void(^)(NSError *error))failure;


- (void)getAlarmInfoWithSuccess:(void(^)(ThingSecurityAlarmDetailModel *result))success
                        failure:(void(^)(NSError *error))failure;


- (void)updateAlarmActionWithAction:(ThingHSGatewayStateUpdateType)action
                            success:(void(^)(BOOL result))success
                            failure:(void(^)(NSError *error))failure;


- (void)sendAlarmToPlatformWithAlarmIds:(NSArray<NSString *> *)alarmIds
                                success:(void(^)(BOOL result))success
                                failure:(void(^)(NSError *error))failure;

- (void)enableAlarmVoice;

- (void)disableAlarmVoice;

@end

NS_ASSUME_NONNULL_END
