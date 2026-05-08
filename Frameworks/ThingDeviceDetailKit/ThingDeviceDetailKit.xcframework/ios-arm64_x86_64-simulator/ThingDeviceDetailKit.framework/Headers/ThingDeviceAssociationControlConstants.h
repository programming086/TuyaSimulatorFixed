
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Represents information about a multi-control data point.
@interface ThingMultiControlDpInfo : NSObject
/// Data point code
@property (copy, nonatomic) NSString *dpCode;
/// Data point name
@property (copy, nonatomic) NSString *dpName;
/// Data point ID
@property (assign, nonatomic) long long dpId;
@end

// Represents a data point within a multi-control group device.
@interface ThingMultiControlGroupDeviceDp : NSObject
@property (assign, nonatomic) long long dpId;
@property (copy, nonatomic) NSString *code;
@property (copy, nonatomic) NSString *name;
@end

// Represents a device in a multi-control group.
@interface ThingMultiControlGroupDevice : NSObject
/// Multi-control group ID
@property (assign, nonatomic) long long multiControlId;
/// Device data points
@property (strong, nonatomic) NSArray<ThingMultiControlGroupDeviceDp *> *datapoints;
/// Device ID
@property (copy, nonatomic) NSString *devId;
/// Device name
@property (copy, nonatomic) NSString *devName;
/// Data point ID
@property (assign, nonatomic) long long dpId;
/// Data point name
@property (copy, nonatomic) NSString *dpName;
@property (assign, nonatomic) NSInteger status;
/// Whether it is effective
@property (assign, nonatomic) BOOL enabled;
@end

// Represents a multi-control group.
@interface ThingMultiControlGroup : NSObject
/// Multi-control group ID
@property (assign, nonatomic) long long multiControlGroupId;
/// Multi-control ID
@property (assign, nonatomic) long long multiControlId;
/// Multi-control group name
@property (copy, nonatomic) NSString *groupName;
/// Whether it is enabled
@property (assign, nonatomic) BOOL enabled;
/// Multi-control group device information
@property (strong, nonatomic) NSArray<ThingMultiControlGroupDevice *> *groupDetail;
/// Multi-control group type: 0 for panel entry multi-control, 1 for device entry multi-control;
@property (assign, nonatomic) NSInteger groupType;
@end

// Represents a parent rule's data point info for multi-control groups.
@interface ThingMultiControlGroupParentRuleDpInfo : NSObject
@property (assign, nonatomic) long long dpId;
@property (copy, nonatomic) NSString *dpName;
@end

// Represents a parent rule for multi-control groups.
@interface ThingMultiControlGroupParentRule : NSObject
@property (copy, nonatomic) NSString *ruleId;
@property (copy, nonatomic) NSString *name;
@property (strong, nonatomic) NSArray<ThingMultiControlGroupParentRuleDpInfo *> *dpList;
@end

// Represents overall information about a multi-control group.
@interface ThingMultiControlGroupInfo : NSObject
@property (nonatomic, assign) NSInteger bindMaxValue;
@property (nonatomic, strong) ThingMultiControlGroup *multiGroup;
@property (nonatomic, strong) NSArray<ThingMultiControlGroupParentRule *> *parentRules;
@end

// Represents a multi-control device and its properties.
@interface ThingMultiControlDevice : NSObject
@property (strong, nonatomic) NSArray<ThingMultiControlGroupDeviceDp *> *datapoints;
@property (copy, nonatomic) NSString *devId;
@property (copy, nonatomic) NSString *iconUrl;
@property (assign, nonatomic) BOOL inRule;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *multiControlIds;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *productId;
@property (copy, nonatomic) NSString *roomName;
@end

// Represents data point information for a multi-control device.
@interface ThingMultiControlDeviceDpsInfo : NSObject
@property (nonatomic, assign) NSInteger bindMaxValue;
@property (strong, nonatomic) NSArray<ThingMultiControlGroupDeviceDp *> *datapoints;
@property (strong, nonatomic) NSArray<ThingMultiControlGroup *> *mcGroups;
@property (strong, nonatomic) NSArray<ThingMultiControlGroupParentRule *> *parentRules;
@end

// Represents a double control group consisting of main and slave devices.
@interface ThingDoubleControlGroup : NSObject
/// Main device ID
@property (copy, nonatomic) NSString *mainDeviceId;
/// List of slave device IDs
@property (strong, nonatomic) NSArray<NSString *> *slaveDeviceIds;
@end

// Represents a double control device and its association status.
@interface ThingDoubleControlDevice : NSObject
/// Device ID
@property (copy, nonatomic) NSString *devId;
/// Whether it is already related
@property (assign, nonatomic) BOOL isRelate;
/// Parent device ID
@property (copy, nonatomic) NSString *parentId;
@end

// Represents relationships between main and slave devices' data points in double control.
@interface ThingDoubleControlDPRelation : NSObject
/// List of main device data point IDs
@property (strong, nonatomic) NSArray<NSString *> *dpIds;
/// List of slave device data point IDs
@property (strong, nonatomic) NSArray<NSString *> *subDpIds;
/// Map of relationships between slave and main device data point IDs
/// Key: Slave device data point ID, Value: Main device data point ID
@property (strong, nonatomic) NSDictionary<NSString *, NSString *> *dpIdMap;
@end



@interface ThingDoubleControlDPInfo : NSObject
/// dp code
@property (copy, nonatomic) NSString *code;
/// dp id
@property (assign, nonatomic) long long dpId;
/// dp name
@property (copy, nonatomic) NSString *name;
/// schema id
@property (copy, nonatomic) NSString *schemaId;
@end

NS_ASSUME_NONNULL_END
