//
//  ThingSmartCameraDeviceDataSource.h
//  ThingSmartCameraKitLite
//
//  Created by MokZF on 2025/1/6.
//

#import <Foundation/Foundation.h>

@protocol ThingSmartCameraDeviceDataSource <NSObject>

/// user mqtt to send message
/// - Parameter message: message
- (void)shouldSendMqttMessage:(NSDictionary *)message;

@end

