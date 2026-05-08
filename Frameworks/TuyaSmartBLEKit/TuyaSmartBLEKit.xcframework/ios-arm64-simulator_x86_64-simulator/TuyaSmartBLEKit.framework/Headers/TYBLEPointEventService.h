//
//  TYBLEPointEventService.h
//  TuyaSmartBLEKit
//
//  Created by milong on 2022/5/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYBLEEventWayModel : NSObject
@property (nonatomic, strong) NSString *category;
@property (nonatomic, strong) NSString *subCategory;
@property (nonatomic, strong) NSString *thirdCategory;
@property (nonatomic, assign) NSString *device_id;
@property (nonatomic, assign) NSString *pid;
@property (nonatomic, assign) NSString *pv;
@property (nonatomic, assign) NSString *extend;

@end

@interface TYBLEEventConnectWayModel : TYBLEEventWayModel
@property (nonatomic, strong) NSString *connectTypeStrategy;
@property (nonatomic, assign) NSString *result;
@property (nonatomic, strong) NSString *errorCode;

@end


@interface TYBLEPointEventService : NSObject

- (void)reportConnectWayToClouldWithDeviceId:(NSString *)devId result:(NSUInteger)result errorCode:(nullable NSString *)errorCode;


- (void)reportConnectWayToClouldWithModel:(TYBLEEventConnectWayModel *)connectWayModel ;

@end

NS_ASSUME_NONNULL_END
