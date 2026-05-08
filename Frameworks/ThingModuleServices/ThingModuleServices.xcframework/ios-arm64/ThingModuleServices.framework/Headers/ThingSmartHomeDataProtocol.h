//
//  ThingSmartHomeDataProtocol.h
//  ThingModuleServices
//
//  Created by Lucca on 2019/2/26.
//

#import <Foundation/Foundation.h>

@class ThingSmartHome;

@protocol ThingSmartHomeDataProtocol <NSObject>

/**
 get current home; return nil if there is no home
 
 @return ThingSmartHome
 */
- (ThingSmartHome *)getCurrentHome DEPRECATED_MSG_ATTRIBUTE("TYSmartHomeDataProtocol is deprecated, use `currentFamilyId` in `TYFamilyProtocol` instead");

@end

