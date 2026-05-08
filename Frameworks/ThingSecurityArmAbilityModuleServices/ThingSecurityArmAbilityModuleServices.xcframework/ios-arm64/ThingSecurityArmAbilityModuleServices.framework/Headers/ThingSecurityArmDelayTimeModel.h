
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSecurityArmMode);

@interface ThingSecurityArmDelayTimeModel : NSObject
/// security mode
@property (nonatomic, assign) ThingSecurityArmMode mode;

/// armed delay time
@property (nonatomic, assign) NSInteger enableDelayTime;

/// alarm delay time
@property (nonatomic, assign) NSInteger alarmDelayTime;


@end

NS_ASSUME_NONNULL_END
