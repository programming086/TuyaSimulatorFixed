
#ifndef ThingBLEConfig_h
#define ThingBLEConfig_h

// The error domains.
#define kCBErrorDomain @"CoreBLEErrorDomain"

#define kCBErrorCentralDidNotFindService                397
#define kCBErrorCentralDidNotFindCharacteristic         398
#define kCBErrorCentralDidNotFindPeripheral             399
#define kCBErrorCentralConnectionTimeoutCode            400
#define kCBErrorCentralLostConnection                   401
#define kCBErrorCentralDiscoverFailed                   402
#define kCBErrorCentralWriteFailed                      403
#define kCBErrorCentralReadFailed                       404
#define kCBErrorCentralRecvNotifyDataFailed             405
#define kCBErrorPeripheralSendingDataFailed             406
#define kCBErrorPeripheralReadFailed                    407
#define kCBErrorPeripheralWriteFailed                   408
#define kCBErrorPeripheralReadingDataOutofBounds        409
#define kCBErrorCentralDisConnectionTimeoutCode         410
#define kCBErrorCentralConnectionScanTimeout            411

#define kCBErrorPeripheralIsNil                         440
#define kCBErrorCenteralStateNotPoweredOn               450




// The notification maximum transmission unit (MTU) size.
#define kCBNotifyMTU 20

// The background identifier.
#define kCentralRestoreIdentifier @"ThingBLECentralRestoreIdentifier"


#endif /* ThingBLEConfig_h */
