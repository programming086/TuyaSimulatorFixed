
#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, ThingSIGMeshFittingMsgType){
    ThingSIGMeshFittingMsgTypeAuth = 0,
    ThingSIGMeshFittingMsgTypeCheck = 2,
    ThingSIGMeshFittingMsgTypeDelete,
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshFittingMsgModel : NSObject
/// Message type
@property (nonatomic, assign) ThingSIGMeshFittingMsgType msgType;

/// The device ID of the message source
@property (nonatomic, strong) NSString *devId;

/// Fitting's mac
@property (nonatomic, strong) NSString *mac;

/// Fitting's group ID
@property (nonatomic, assign) NSInteger groupId;

/// Fitting's secret key
@property (nonatomic, strong) NSString *authDeviceS1;

/// This parameter is required when the message type is ThingSIGMeshFittingMsgTypeAuth or ThingSIGMeshFittingMsgTypeCheck.
@property (nonatomic, assign) BOOL result;

@end

NS_ASSUME_NONNULL_END
