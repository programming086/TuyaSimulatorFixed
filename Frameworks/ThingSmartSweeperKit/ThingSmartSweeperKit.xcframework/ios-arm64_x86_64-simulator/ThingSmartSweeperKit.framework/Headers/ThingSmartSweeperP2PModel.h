
#import <Foundation/Foundation.h>
#import <ThingP2PSessionKit/ThingP2PSessionProtocol.h>
#import "ThingSmartSweeperFileManagerModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingSuccessID)(id result);
typedef void (^ThingFailureError)(NSError * _Nullable error);

@class ThingSmartSweeperFileModel,ThingSmartSweeperAlbumFileIndexModel;

@interface ThingSmartSweeperP2PModel : NSObject

@property (nonatomic, strong, nullable) id <ThingP2PSession> session;
@property (nonatomic, strong, nullable) ThingSmartSweeperFileModel *fileModel;
@property (nonatomic, strong, nullable) ThingSmartSweeperAlbumFileIndexModel *fileIndexModel;

@end

@interface ThingSmartSweeperFileModel : NSObject

@property (nonatomic, copy) NSString *filePath;
@property (nonatomic, copy) ThingSuccessID success;
@property (nonatomic, copy) ThingFailureError failure;

@end

@interface ThingSmartSweeperAlbumFileIndexModel : NSObject

@property (nonatomic, copy) void (^success)(ThingSmartSweeperP2PAlbumFileIndexs *model);
@property (nonatomic, copy) ThingFailureError failure;

@end


NS_ASSUME_NONNULL_END
