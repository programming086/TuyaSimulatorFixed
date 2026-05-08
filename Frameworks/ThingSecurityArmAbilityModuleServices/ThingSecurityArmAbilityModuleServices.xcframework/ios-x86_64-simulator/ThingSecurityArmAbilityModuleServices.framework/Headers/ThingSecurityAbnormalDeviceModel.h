
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityAbnormalDeviceModel : NSObject

/// abnormal device id
@property (nonatomic, copy) NSString *deviceId;

/// abnormal device description
@property (nonatomic, copy) NSString *stateDescription;


@end

NS_ASSUME_NONNULL_END

