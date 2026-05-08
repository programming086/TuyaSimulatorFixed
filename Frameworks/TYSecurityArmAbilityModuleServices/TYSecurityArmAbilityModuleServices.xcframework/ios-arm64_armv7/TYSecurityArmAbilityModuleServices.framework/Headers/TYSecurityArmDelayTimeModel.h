//
//  TYSecurityArmDelayTimeModel.h
//  AFNetworking
//
//  Created by Tuya.Inc on 2021/4/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TYSecurityArmMode);

@interface TYSecurityArmDelayTimeModel : NSObject
/// security mode
@property (nonatomic, assign) TYSecurityArmMode mode;

/// armed delay time
@property (nonatomic, assign) NSInteger enableDelayTime;

/// alarm delay time
@property (nonatomic, assign) NSInteger alarmDelayTime;


@end

NS_ASSUME_NONNULL_END
