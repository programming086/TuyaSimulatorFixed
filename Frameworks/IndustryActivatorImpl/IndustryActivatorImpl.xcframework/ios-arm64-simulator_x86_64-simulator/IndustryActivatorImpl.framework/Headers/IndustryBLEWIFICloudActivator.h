//
//  IndustryBLEWIFICloudActivator.h
//  IndustryActivatorImpl
//
//  Created by ChenKun on 2024/8/21.
//

#import <Foundation/Foundation.h>

@import IndustryActivatorKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryBLEWIFICloudActivator : NSObject <IActivator>

@property (nonatomic, weak) id<IActivatorListener> listener;

@end

NS_ASSUME_NONNULL_END
