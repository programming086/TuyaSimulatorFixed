//
//  ThingLampDeviceMonitorProtocol.h
//  ThingLampModuleServices
//
//  Created by SanTong on 2020/12/28.
//

#ifndef ThingLampDeviceMonitorProtocol_h
#define ThingLampDeviceMonitorProtocol_h
#import <CoreLocation/CoreLocation.h>

@protocol ThingLampDeviceMonitorProtocol


- (void)pushToDeviceLocationWithDevid:(NSString *)devId
                              address:(NSString *)adderss
                           coordinate:(CLLocationCoordinate2D)coordinate
                             callBack:(void(^)(NSString *adderss, CLLocationCoordinate2D coordinate))callBack;



@end

#endif /* ThingLampDeviceMonitorProtocol_h */
