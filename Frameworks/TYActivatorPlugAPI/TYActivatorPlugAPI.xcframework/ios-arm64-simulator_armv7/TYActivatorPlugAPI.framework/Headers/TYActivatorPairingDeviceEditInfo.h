//
//  TYActivatorPairingDeviceEditInfo.h
//  TYActivatorModule
//
//  Created by qisong on 2022/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYActivatorPairingDeviceRoomInfo : NSObject
@property (nonatomic, copy) NSString *name; ///< 房间名
@property (nonatomic, assign) long long roomId; // room Id
@end

@interface TYActivatorPairingDeviceEditInfo : NSObject
@property (nonatomic, strong) NSMutableArray <TYActivatorPairingDeviceRoomInfo *>*roomList;

@property (nonatomic, assign) NSInteger selectedIndex;

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *uniqueID;

@property (nonatomic, copy) NSString *devId;

@property (nonatomic, assign) BOOL canEditName;
@end

NS_ASSUME_NONNULL_END
