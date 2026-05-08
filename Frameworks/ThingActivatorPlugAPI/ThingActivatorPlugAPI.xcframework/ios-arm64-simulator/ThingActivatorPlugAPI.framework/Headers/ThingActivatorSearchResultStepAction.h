
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingSmartActivatorDeviceModel, ThingActivatorSearchResultStepAction, ThingActivatorSearchResultStepActionContext;


typedef void(^ThingActivatorSearchResultStepActionComplete)(void);

typedef void (^ThingActivatorSearchResultStepActionFunc)( ThingActivatorSearchResultStepActionContext * _Nullable context, _Nullable ThingActivatorSearchResultStepActionComplete complete);

typedef ThingActivatorSearchResultStepAction* _Nonnull  (^ThingActivatorSearchResultStepActionBuilder)(_Nonnull __strong ThingActivatorSearchResultStepActionFunc actionFunc);


@interface ThingActivatorSearchResultStepAction : NSObject
@property (nonatomic, readonly) ThingActivatorSearchResultStepActionBuilder willStartPairBuilder; // start pairing


- (void)willStartPairDevice:(ThingActivatorSearchResultStepActionContext *)context complete:(_Nullable ThingActivatorSearchResultStepActionComplete)complete;
@end


@interface ThingActivatorSearchResultStepActionContext : NSObject
@property (nonatomic, strong) NSArray <ThingSmartActivatorDeviceModel *>* pairingDevices;
@end

NS_ASSUME_NONNULL_END
