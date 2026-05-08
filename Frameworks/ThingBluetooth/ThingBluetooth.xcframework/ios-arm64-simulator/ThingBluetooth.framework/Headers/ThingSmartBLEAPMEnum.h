
#ifndef ThingSmartBLEAPMEnum_h
#define ThingSmartBLEAPMEnum_h

typedef enum : NSUInteger {
    ThingSmartBLEAPMType_Activate = 1,// Activates the Bluetooth device.
    ThingSmartBLEAPMType_Online = 2,// Connects the device to the LAN.
    ThingSmartBLEAPMType_Offline = 3,// Disconnects the device from the LAN.
    ThingSmartBLEAPMType_Delete = 4,// Removes the device.
    ThingSmartBLEAPMType_Publish = 5,// Sends commands to the device.
    ThingSmartBLEAPMType_Report = 6,// Reports data from the device.
} ThingSmartBLEAPMType;

#endif /* ThingSmartBLEAPMEnum_h */
