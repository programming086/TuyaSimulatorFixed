//
//  ThingAuthorizationBluetooth.h
//  ThingAuthorizationManager
//
//  Created by kaier on 2021/12/2.
//

/// 蓝牙
///
/// 注意：这里有一个注意点，CBCentralManager 的创建是异步的。如果初始化完成之前没有被当前创建它的类所持有
/// 就会在下一次RunLoop 迭代的时候释放。当然 CBCentralManager 实例如果不是在 ViewController 中创建的，
/// 那么持有 CBCentralManager 的这个类在初始化之后也必须被 ViewController 持有，否则控制台会有如下的错误输出：
/// [CoreBluetooth] XPC connection invalid
/// ECPrivacyCheckBluetooth 也要使用全局属性定义
///
/// 「系统设置内状态」与「代码内能拿到的状态」关系
/// 蓝牙未授权。    sys 拒绝，app 开。落地页显示 1 个（未授权）。
/// sys 开，app 关。sys 拒绝，app 关。
/// sys 关，app 关。sys 拒绝，app 关。
/// sys 开，app 开。sys 开，app 开。落地页显示 1 个（已授权）。
/// sys 关，app 开。sys 关，app 开。落地页显示 2 个。

#import <Foundation/Foundation.h>
#import <ThingAuthorizationServices/ThingAuthorizationServices.h>

@interface ThingAuthorizationBluetooth : NSObject <ThingBluetoothAuthProtocol>

// App 权限状态是稳定的，使用 state
@property (nonatomic, readonly, assign) ThingCBAuthorizationStatus appAuthState;
// 系统权限状态是不稳定的，使用 status
@property (nonatomic, readonly, assign) ThingCBAuthorizationState sysPowerStatus;

@property (nonatomic, assign) BOOL requested;

@end

