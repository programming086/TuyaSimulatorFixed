

#import <Foundation/Foundation.h>
#import "TUNIP2pFileManager.h"


/**
The APIs about P2P file transfer
@version: 1.0.0
@platform: all
*/
@interface TUNIP2pFileManager (Impl)


/**
P2P SDK init
@available 1.0.0
@param params ThingP2PInitConfigParams
@param success success
@param fail fail
*/
- (void)impl_P2PSDKInit:(TUNIP2pFileManagerThingP2PInitConfigParams*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
P2P connect
@available 1.0.0
@param params ThingP2PConnectionParams
@param success success
@param fail fail
*/
- (void)impl_connectDevice:(TUNIP2pFileManagerThingP2PConnectionParams*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
check P2P status
@available 1.0.0
@param params ThingP2PConnectionParams
@param success success
@param fail fail
*/
- (void)impl_isP2PActive:(TUNIP2pFileManagerThingP2PConnectionParams*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;

- (TUNIAPIResponseModel *)impl_isP2PActiveSync:(TUNIP2pFileManagerThingP2PConnectionParams*)params;

/**
query device's album file index infos
@available 1.0.0
@param params ThingP2PConnectionParams
@param success success
@param fail fail
*/
- (void)impl_queryAlbumFileIndexs:(TUNIP2pFileManagerThingP2PAlbum*)params success:(void (^)(TUNIAPIResponseModel<TUNIP2pFileManagerThingP2PAlbumFileIndexs*> *model))success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
upload file
@available 1.0.0
@param params ThingP2PUploadFile
@param success success
@param fail fail
*/
- (void)impl_uploadFile:(TUNIP2pFileManagerThingP2PUploadFile*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
download file
@available 1.0.0
@param params ThingP2PDownloadFile
@param success success
@param fail fail
*/
- (void)impl_downloadFile:(TUNIP2pFileManagerThingP2PDownloadFile*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
download file stream
@available 1.0.0
@param params ThingP2PDownloadStream
@param success success
@param fail fail
*/
- (void)impl_downloadStream:(TUNIP2pFileManagerThingP2PDownloadStream*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
append download file stream
@available 1.0.0
@param params ThingP2PDownloadStream
@param success success
@param fail fail
*/
- (void)impl_appendDownloadStream:(TUNIP2pFileManagerThingP2PDownloadStream*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
cancel upload task
@available 1.0.0
@param params ThingP2PUploadTask
@param success success
@param fail fail
*/
- (void)impl_cancelUploadTask:(TUNIP2pFileManagerThingP2PUploadTask*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
cancel download task
@available 1.0.0
@param params ThingP2PDownloadTask
@param success success
@param fail fail
*/
- (void)impl_cancelDownloadTask:(TUNIP2pFileManagerThingP2PDownloadTask*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
P2P disconnect
@available 1.0.0
@param params ThingP2PDevice
@param success success
@param fail fail
*/
- (void)impl_disconnectDevice:(TUNIP2pFileManagerThingP2PDevice*)params success:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


/**
P2P SDK deinit
@available 1.0.0
@param success success
@param fail fail
*/
- (void)impl_deInitSDK:(TUNIAPIPluginResponseCallback)success fail:(TUNIAPIPluginResponseCallback)fail ;


@end
