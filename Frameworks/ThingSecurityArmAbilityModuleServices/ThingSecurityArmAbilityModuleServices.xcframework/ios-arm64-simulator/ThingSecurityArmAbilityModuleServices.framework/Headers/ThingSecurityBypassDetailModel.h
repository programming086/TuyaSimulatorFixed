
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityBypassDetailModel : NSObject

/// gateway device id
@property (nonatomic, strong) NSString *gwId;

/// gateway state
@property (nonatomic, assign) NSInteger state;

/// gateway subdevice ids
@property (nonatomic, strong) NSArray<NSString *>*bypassDeviceIds;


@end

NS_ASSUME_NONNULL_END

