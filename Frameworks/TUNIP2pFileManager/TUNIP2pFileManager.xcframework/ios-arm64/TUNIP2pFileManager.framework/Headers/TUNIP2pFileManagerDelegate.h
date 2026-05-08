

#import <Foundation/Foundation.h>
#import <TUNIAPIManagerKit/TUNIAPIManagerKit.h>
#import "TUNIP2pFileManagerModelDefined.h"


/**
The APIs about P2P file transfer
@version: 1.0.0
@platform: all
*/
@protocol TUNIP2pFileManagerDelegate  <NSObject>

@optional



/**
P2P status changed event

@available 1.0.0
@param body ThingP2PSessionStatus
*/
- (void)sessionStatusChangeWithModel:(TUNIP2pFileManagerThingP2PSessionStatus *)body;


/**
upload file progress event

@available 1.0.0
@param body ProgressEvent
*/
- (void)uploadProgressUpdateWithModel:(TUNIP2pFileManagerProgressEvent *)body;


/**
single file download progress event

@available 1.0.0
@param body DownloadProgressEvent
*/
- (void)downloadProgressUpdateWithModel:(TUNIP2pFileManagerDownloadProgressEvent *)body;


/**
total download progress event

@available 1.0.0
@param body DownloadTotalProgressEvent
*/
- (void)downloadTotalProgressUpdateWithModel:(TUNIP2pFileManagerDownloadTotalProgressEvent *)body;


/**
single file download completed event

@available 1.0.0
@param body FileDownloadCompletionEvent
*/
- (void)fileDownloadCompleteWithModel:(TUNIP2pFileManagerFileDownloadCompletionEvent *)body;


/**
download packet received event

@available 1.0.0
@param body StreamDownloadPacketReceivedEvent
*/
- (void)streamPacketReceiveWithModel:(TUNIP2pFileManagerStreamDownloadPacketReceivedEvent *)body;

@end

