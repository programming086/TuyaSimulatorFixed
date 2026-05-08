
#import <Foundation/Foundation.h>
#import <TUNIAPIManagerKit/TUNIAPIManagerKit.h>
NS_ASSUME_NONNULL_BEGIN

@class TUNIP2pFileModel, TUNIP2pAlbumFileIndexModel, TUNIP2pFileManagerThingP2PAlbumFileIndexs;
@protocol ThingP2PSession;
@interface TUNIP2pModel : NSObject

@property (nonatomic, strong, nullable) id <ThingP2PSession> session;

@property (nonatomic, strong, nullable) TUNIP2pFileModel *fileModel;

@property (nonatomic, strong, nullable) TUNIP2pAlbumFileIndexModel *fileIndexModel;

@end

@interface TUNIP2pFileModel : NSObject

@property (nonatomic, copy) NSString *filePath;

@property (nonatomic, copy) TUNIAPIPluginResponseCallback success;

@property (nonatomic, copy) TUNIAPIPluginResponseCallback fail;

@end

@interface TUNIP2pAlbumFileIndexModel : NSObject

@property (nonatomic, copy) void (^success)(TUNIAPIResponseModel<TUNIP2pFileManagerThingP2PAlbumFileIndexs*> *model);

@property (nonatomic, copy) TUNIAPIPluginResponseCallback fail;

@end

NS_ASSUME_NONNULL_END
