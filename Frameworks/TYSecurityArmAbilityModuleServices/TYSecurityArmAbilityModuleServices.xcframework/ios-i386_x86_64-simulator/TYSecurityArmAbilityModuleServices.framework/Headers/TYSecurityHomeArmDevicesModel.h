//
//  TYSecurityHomeArmDevicesModel.h
//  TYSecurityArmAbilityBizKit
//
//  Created by 冰山 on 2021/7/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYSecurityHomeArmDevicesModel : NSObject

@property (nonatomic, assign) NSInteger leavingDeviceNum;   //离家防区勾选设备数量
@property (nonatomic, assign) NSInteger crashDeviceNum;     //紧急防区勾选设备数量
@property (nonatomic, assign) NSInteger stayingDeviceNum;   //在家防区勾选设备数量
@property (nonatomic, assign) BOOL hasStayingDevice;        // 在家防区是否有勾选设备
@property (nonatomic, assign) BOOL hasLeavingDevice;        //离家防区是否有勾选设备
@property (nonatomic, assign) BOOL hasCrashDevice;          // 紧急防区是否有勾选设备


@end

NS_ASSUME_NONNULL_END
