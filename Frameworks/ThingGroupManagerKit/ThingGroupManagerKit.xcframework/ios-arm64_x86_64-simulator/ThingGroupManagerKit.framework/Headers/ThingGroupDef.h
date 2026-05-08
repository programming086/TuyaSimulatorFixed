
#ifndef ThingGroupDef_h
#define ThingGroupDef_h

@class ThingSmartGroupDevListModel;

typedef void (^ThingGroupDevListResult)(NSArray<ThingSmartGroupDevListModel *> *list);
typedef void (^ThingGroupSuccess)(NSString *groupId);
typedef void (^ThingGroupFailure)(NSError *error);
typedef void (^ThingGroupResultFailure)(NSDictionary <NSString *, id> * errorInfo);
typedef void (^ThingGroupProcess)(NSDictionary<NSString *,NSNumber *> *process);

typedef NS_ENUM(NSInteger, ThingRemoteControlFilterType) {
    /// PCC
    ThingRemoteControlFilterTypePCC = 0,
    /// Category
    ThingRemoteControlFilterTypeCategory = 1,
};

typedef NS_ENUM(NSInteger, ThingGroupErrorType) {
    /// Over the Scenario Limit
    ThingGroupErrorTypeLimit = 1,
    /// Sub-device Timeout
    ThingGroupErrorTypeSubDeviceTimeout = 2,
    /// Setting Value Out of Range
    ThingGroupErrorTypeValueOutOfRange = 3,
    /// Write File Error
    ThingGroupErrorTypeWriteFileError = 4,
    /// Other Errors
    ThingGroupErrorTypeOther = 5,
    /// Receive callback timeout
    ThingGroupErrorTypeRequestTimeout = 6,
    /// Send command failed
    ThingGroupErrorTypeSendCommandFailure = 7,
    ///CBManagerStatePoweredOff
    ThingGroupErrorTypeBLEPoweredOff = 8,
};

typedef NS_ENUM(NSInteger, ThingBleMeshHandleGroupInnerError) {
    /// Timeout
    ThingBleMeshHandleGroupInnerTimeout = 1,
    /// Empty
    ThingBleMeshHandleGroupInnerEmpty = 2,
    /// Full
    ThingBleMeshHandleGroupInnerFull = 3,
    /// Other
    ThingBleMeshHandleGroupInnerException = 4,
};

typedef NS_ENUM(NSInteger, ThingGroupBizType) {
    /// WiFi
    ThingGroupBizTypeWiFi = 0,
    /// StandardWiFi
    ThingGroupBizTypeStandardWiFi = 1,
    /// Zigbee
    ThingGroupBizTypeZigbee = 2,
    /// Thing Mesh
    ThingGroupBizTypeBLEMesh = 3,
    /// SIG Mesh
    ThingGroupBizTypeSIGMesh = 4,
    /// Standard SIG Mesh
    ThingGroupBizTypeStandardSIGMesh = 5,
    /// Beacon
    ThingGroupBizTypeBeacon = 6,
    /// Zigbee RemoteControl
    ThingGroupBizTypeZigbeeRemoteControl = 7,
    /// Thing Mesh RemoteControl
    ThingGroupBizTypeBLEMeshRemoteControl = 8,
    /// SIG Mesh RemoteControl
    ThingGroupBizTypeSIGMeshRemoteControl = 9,
    /// Zigbee Standard
    ThingGroupBizTypeStandardZigbee = 10,
    /// Thread 
    ThingGroupBizTypeThread = 11,
    /// BLEMeshV2
    ThingGroupBizTypeBLEMeshV2 = 12,
};


#endif /* ThingGroupDef_h */
