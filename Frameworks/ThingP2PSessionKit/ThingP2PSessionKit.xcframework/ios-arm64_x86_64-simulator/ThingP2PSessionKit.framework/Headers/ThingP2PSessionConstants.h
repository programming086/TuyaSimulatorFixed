
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingP2PQueryFileInfos;
typedef void(^ThingP2PQueryFileInfosSuccess)(ThingP2PQueryFileInfos *fileInfos);
typedef void(^ThingP2PSessionFailure)(NSError *error);
typedef void(^ThingP2PSessionVoidSuccess)(void);
typedef void(^ThingP2PSessionIdSuccess)(id result);

NS_ASSUME_NONNULL_END
