//
//  IndustryWiredDiscovery.h
//  IndustryActivatorImpl
//
//  Created by ChenKun on 2025/2/10.
//

#import <Foundation/Foundation.h>

@import IndustryActivatorKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryWiredDiscovery : NSObject <IDiscovery>
@property (nonatomic, weak) id<IDiscoveryListener> listener;
@end

NS_ASSUME_NONNULL_END
