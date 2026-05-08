//
//  ThingSmartActivatorSearchEnum.h
//  Pods
//
//  Created by Jesse Zhou on 2021/8/27.
//

#ifndef ThingSmartActivatorType_h
#define ThingSmartActivatorType_h

/// 配网类型
typedef NS_OPTIONS(NSInteger, ThingSmartActivatorType) {
    ThingSmartActivatorTypeDefault =     0,       // 默认，不搜索任何设备
    ThingSmartActivatorTypeWired =       1 << 0,  // 有线
    ThingSmartActivatorTypeBle =         1 << 1,  // 蓝牙
    ThingSmartActivatorTypeBleMesh =     1 << 2,  // BleMesh
    ThingSmartActivatorTypeSigMesh =     1 << 3,  // SigMesh
    ThingSmartActivatorTypeSubDevice =   1 << 4,  // 子设备
    ThingSmartActivatorTypeEZSearch =    1 << 5,  // EZ
    ThingSmartActivatorTypeAuto =        1 << 6,  // 免密配网
    ThingSmartActivatorTypeHomeKit =     1 << 7,  // HomeKit
    ThingSmartActivatorTypeRouter =      1 << 8,  // 路由器配网
    ThingSmartActivatorTypePegasus =     1 << 9,  // 闪电
    ThingSmartActivatorTypeAP =          1 << 10, // AP
    ThingSmartActivatorTypeQRCode =      1 << 11, // 二维码
    ThingSmartActivatorTypeBroadband =   1 << 12, // 宽带配网
    ThingSmartActivatorTypeMatter =      1 << 13, // Matter
    ThingSmartActivatorTypeBeacon =      1 << 14, // Beacon
    ThingSmartActivatorTypeEnd =         1 << 15,
};

// e.g. ThingSmartActivatorTypeDefault -> @"ThingSmartActivatorTypeDefault"
FOUNDATION_EXTERN NSString *NSStringFromThingSmartActivatorType(ThingSmartActivatorType value);
// e.g. @"ThingSmartActivatorTypeDefault" -> ThingSmartActivatorTypeDefault
FOUNDATION_EXTERN ThingSmartActivatorType ThingSmartActivatorTypeFromNSString(NSString *string);

#endif /* ThingSmartActivatorType_h */
