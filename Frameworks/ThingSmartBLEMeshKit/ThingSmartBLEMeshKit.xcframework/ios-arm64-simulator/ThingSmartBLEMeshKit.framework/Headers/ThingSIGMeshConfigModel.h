
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ThingSIGMeshOnlineProfile) {
    //After the mesh is successfully connected, all devices are online.
    ThingSIGMeshOnlineProfileMeshNetworkLogin,
    //The device is considered to be online only after receiving an online message.
    ThingSIGMeshOnlineProfileMeshQuery,
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshConfigModel : NSObject

@property (nonatomic, assign) ThingSIGMeshOnlineProfile onlineProfile;

@end

NS_ASSUME_NONNULL_END
