//
//  IndustryBLEDiscovery.h
//  IndustryActivatorKit
//
//  Created by 后主 on 2022/8/16.
//

#import <Foundation/Foundation.h>

@import IndustryActivatorKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryBLEDiscovery : NSObject <IDiscovery>

@property (nonatomic, weak) id<IDiscoveryListener> listener;

@end

NS_ASSUME_NONNULL_END
