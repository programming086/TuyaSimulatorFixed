
#ifndef ThingActivatorLinkModeDefine_h
#define ThingActivatorLinkModeDefine_h

/*
 Depending on the pairing method, 1000 to 1003 are more detailed types based on ThingLinkModeBT, and 1000 is chosen to avoid duplicating the new types. */
typedef NS_ENUM(NSInteger, ThingLinkMode) {
    ThingLinkModeDefault = 0,
    ThingLinkModeEZ = 1,
    ThingLinkModeAP = 2,
    /// Zigbee
    ThingLinkModeZIGSUB = 3,
    /// WiFi version of QR code mapping (provided by app, contains Wi-Fi information)
    ThingLinkModeWifiQRCode = 4,
    /// NB
    ThingLinkModeNB = 5,
    /// GPRS
    ThingLinkModeGPRS = 6,
    /// Bluetooth
    ThingLinkModeBT = 7,
    /// Wired
    ThingLinkModeWC = 8,
    /// 433 sub-device
    ThingLinkMode433SUB = 9,
    /// Code scanning for network allocation (internally, follow steps to guide code scanning/ hand-entry of uuid, request for token)
    /// Cloud MQTT Direct Connect Device, formerly known as ThingLinkModeCaputreDevice2
    ThingLinkModeMQTTDirectly = 10,
    /// Cellular version of QR code distribution (app provides QR code, does not contain Wi-Fi information)
    ThingLinkModeCellularQRCode = 11,
    /// Assistance to the pairing network
    ThingLinkModeAssistAccessory = 12,
    /// QR code scanning of Bluetooth
    ThingLinkModeBLEQRCode = 13,
    /// Broadband
    ThingLinkModeBroadband = 14,
    /// Applet AP pairing
    ThingLinkModeApH5 = 17,
    /// Applet dual-mode pairing
    ThingLinkModeBleWifiH5 = 18,
    /// 4G gateway
    ThingLinkMode4GGateway = 21,
    /// new combine ble
    ThingLinkModeBleCombine = 22,
    /// Static IP AP
    ThingLinkModeStaticIPAP = 23,
    /// Static IP BLE
    ThingLinkModeStaticIPBLE = 24,
    
    /// QR code scanning (scan, get uuid after scanning, request token; token passed in as input)
    ThingLinkModeScanMQTTDirectly = 1000,
    /// ThingLink device (get uuid after scanning, pass in homeId, bind device)
    ThingLinkModeThingLink = 1001,
    /// Directly connected devices (QR code Scan)
    ThingLinkModeApDirectly = 1002,
    /// Virtual device（QR code Scan）
    ThingLinkModeVirtual = 1003,
    /// OEM pairing（QR code Scan）
    ThingLinkModeOEM = 1004,
    /// Matter (QR code Scan)
    ThingLinkModeMatter = 1005,
    /// Matter (Manual entry of the pairing network)
    ThingLinkModeMatterSetupCode = 1006,
    /// IPC sub device
    ThingLinkModeIPCSub = 1007,
    /// ThirdBuletooth
    ThingLinkModeThirdBuletooth = 1008,
    /// ProductId replace
    ThingLinkModePidReplace = 1009,
    /// NFC BLE
    ThingLinkModeNFCBLE = 1010,

    /// Auto Search
    ThingLinkModeAutoSearch = 1101,
    /// Popup
    ThingLinkModePopup = 1102,
    /// Gateway Panel with Sub-devices
    ThingLinkModeSUBPanel = 1103,
    /// Lightning Router Panel with Sub-Devices
    ThingLinkModePegasusPanel = 1104,
   
    ThingLinkModeEnd
};


FOUNDATION_EXTERN NSString*NSStringFromThingLinkMode(ThingLinkMode value);

#endif /* ThingActivatorLinkModeDefine_h */
