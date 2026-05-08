
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingActivatorPairingDeviceEditInfo, ThingSmartActivatorDeviceModel, ThingActivatorSearchResultStepAction;

typedef void(^ThingActivatorSearchResultEditDeviceCompletion)(ThingActivatorPairingDeviceEditInfo *currentInfo);

typedef void(^ThingActivatorSearchResultCustomEditDeviceBlock)(ThingActivatorPairingDeviceEditInfo *editInfo, ThingActivatorSearchResultEditDeviceCompletion completion);

typedef NSTimeInterval(^ThingActivatorSearchResultCustomPairTimeoutBlock)(NSArray <ThingSmartActivatorDeviceModel *>*pairDevices);

@protocol ThingActivatorSearchResultStepConfigProtocol <NSObject>

@property (nonatomic, copy, nullable) ThingActivatorSearchResultCustomEditDeviceBlock customEditDeviceBlock; //Custom device editing

@property (nonatomic, copy, nullable) ThingActivatorSearchResultCustomPairTimeoutBlock customPairTimeoutBlock; //Customised pairing timeout

@property (nonatomic, strong, nullable) ThingActivatorSearchResultStepAction *action; //Result page custom action

@property (nonatomic, assign) BOOL disableEditName; //Disable device name change

@property (nonatomic, assign) BOOL disableEditRoom; //Disable device room change
@end

NS_ASSUME_NONNULL_END
