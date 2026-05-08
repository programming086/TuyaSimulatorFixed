//
//  ThingSmartCameraDevice.h
//  ThingSmartCameraKitLite
//
//  Created by MokZF on 2025/1/6.
//

#import <Foundation/Foundation.h>
#import "ThingSmartCameraTypeProtocol.h"
#import "ThingSmartCameraDeviceDataSource.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ThingCameraConfigInfoHandler)(NSString  * _Nullable config,NSError  * _Nullable error);

@interface ThingSmartCameraDevice : NSObject<ThingSmartCameraTypeProtocol>

/// init camera device
/// - Parameters:
///   - productKey: your product key
///   - deviceSecret: your device secret
///   - deviceName: your deviceName name【your hardwoare id】
- (id<ThingSmartCameraTypeProtocol>)createCameraWithProductKey:(NSString *)productKey
                                                  deviceSecret:(NSString *)deviceSecret
                                                    deviceName:(NSString *)deviceName    token:(NSString *)token;


@property (nonatomic, weak) id<ThingSmartCameraDeviceDataSource> dataSource;
@property (nonatomic, weak) id<ThingSmartCameraVirsualDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
