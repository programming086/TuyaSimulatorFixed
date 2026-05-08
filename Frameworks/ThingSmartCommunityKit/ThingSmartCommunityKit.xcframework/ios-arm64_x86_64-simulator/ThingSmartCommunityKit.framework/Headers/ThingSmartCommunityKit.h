//
//  ThingSmartCommunityKit.h
//
//  Created by Tuya Inc. on 2023/9/22.
//

#import <Foundation/Foundation.h>

#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

#if TARGET_OS_IOS
    #import <ThingSmartActivatorKit/ThingSmartActivatorKit.h>
#endif

#import <ThingSmartBLEKit/ThingSmartBLEKit.h>
#import <ThingSmartBLEMeshKit/ThingSmartBLEMeshKit.h>

#import <ThingSmartSceneKit/ThingSmartSceneKit.h>
#import <ThingSmartTimerKit/ThingSmartTimerKit.h>
#import <ThingSmartFeedbackKit/ThingSmartFeedbackKit.h>
#import <ThingSmartMessageKit/ThingSmartMessageKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartCommunityKit : NSObject

@end

NS_ASSUME_NONNULL_END
