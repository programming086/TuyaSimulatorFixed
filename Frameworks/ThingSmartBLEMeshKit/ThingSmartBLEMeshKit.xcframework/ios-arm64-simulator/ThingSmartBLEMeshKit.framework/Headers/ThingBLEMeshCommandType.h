
#ifndef ThingBLEMeshCommandType_h
#define ThingBLEMeshCommandType_h

/// The type of Bluetooth mesh command.
typedef NS_ENUM(NSUInteger, ThingBLEMeshCommandType) {
    
    /// Modifies the device address.
    ThingBLEMeshSetDeviceAddressCommand = 0xAA,
    
    /// The group operations. For example, a group can be added or deleted, and devices can be added to a group.
    ThingBLEMeshGroupHandlingCommand,
    
    /// Returns the address of the device group.
    ThingBLEMeshFetchGroupAddressCommand,
    
    /// Kicks the device out of the network.
    ThingBLEMeshKickedOutCommand,
    
    /// Returns the IDs of all devices in the group.
    ThingBLEMeshFetchAllDeviceIdFromGroupCommand,
    
    /// Requests the authorization key.
    ThingBLEMeshRequestAuthKeyCommand,
    
    /// Sends the switch command.
    ThingBLEMeshTurnOnAndOffCommand,
    
    /// Returns the status of all devices in a mesh network.
    ThingBLEMeshFetchAllStateCommand,
    
    /// Sets the brightness value.
    ThingBLEMeshSetBrightnessValueCommand,
    
    /// Sets the RGBWCL value.
    ThingBLEMeshSetRGBWCLCommand,
    
    /// Sets the light mode, such as the colored light and cool and warm white light.
    ThingBLEMeshSetLightModelCommand,
    
    /// Controls the sub power strip.
    ThingBLEMeshControlSubSwitchCommand,
    
    /// Sets the countdown.
    ThingBLEMeshSetCountDownCommand,
    
    /// Reads the countdown.
    ThingBLEMeshFetchCountDownCommand,
    
    /// Reads the sensor value.
    ThingBLEMeshFetchSensorValueCommand,
    
    /// Sends the DPs.
    ThingBLEMeshSendDPSCommand,
    
    /// Returns one or two state values.
    ThingBLEMeshFetchStateCommand,
    
    /// Modifies the mode of the current mesh light scene.
    ThingBLEMeshSetLightSceneModelCommand,
    
    /// Returns the mode of the current mesh light scene.
    ThingBLEMeshGetLightSceneModelCommand,
    
    /// Synchronizes time.
    ThingBLEMeshTimeSynchronizationCommand,
    
    /// Sets the timing data.
    ThingBLEMeshSetTimerCommand,
    
    /// Reads the timing data.
    ThingBLEMeshGetTimerCommand,
    
};

#endif /* ThingBLEMeshCommandType_h */
