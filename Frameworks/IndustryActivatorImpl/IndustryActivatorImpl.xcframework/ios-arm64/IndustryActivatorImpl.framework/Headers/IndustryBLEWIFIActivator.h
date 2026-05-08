//
//  IndustryBLEWIFIActivator.h
//  IndustryActivatorImpl
//
//  Created by 后主 on 2022/8/11.
//

#import <Foundation/Foundation.h>

@import IndustryActivatorKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryBLEWIFIActivator : NSObject <IActivator>

@property (nonatomic, weak) id<IActivatorListener> listener;

@end

NS_ASSUME_NONNULL_END
