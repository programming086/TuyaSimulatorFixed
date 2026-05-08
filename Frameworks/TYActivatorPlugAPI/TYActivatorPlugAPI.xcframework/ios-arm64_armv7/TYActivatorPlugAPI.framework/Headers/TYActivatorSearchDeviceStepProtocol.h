//
//  TYActivatorSearchDeviceStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/10.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TYActivatorScanMode) {
    TYActivatorScanModeAP,///< access point mode
    TYActivatorScanModeQRCode,///< QR Code mode
};

@protocol TYActivatorSearchDeviceStepProtocol <NSObject>
@property (nonatomic, assign) NSTimeInterval timeout;
@property (nonatomic, strong) NSArray *cycleTitles;
@property (nonatomic, assign) TYActivatorScanMode mode;
@end

