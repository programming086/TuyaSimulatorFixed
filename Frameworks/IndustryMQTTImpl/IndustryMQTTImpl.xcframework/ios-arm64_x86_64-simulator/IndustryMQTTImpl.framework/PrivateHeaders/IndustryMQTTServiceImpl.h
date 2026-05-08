//
//  IndustryMQTTServiceImpl.h
//  ThingMQTTCoreImpl
//
//  Created by 后主 on 2022/6/15.
//

#import <Foundation/Foundation.h>
@protocol IMQTTListener, IMQTTConfig;


NS_ASSUME_NONNULL_BEGIN

@interface IndustryMQTTServiceImpl : NSObject

@property (nonatomic, copy) id<IMQTTConfig> _Nullable (^configProvider)(void);

@end

NS_ASSUME_NONNULL_END
