

#import <Foundation/Foundation.h>


/**
The APIs about P2P file transfer
@version: 1.0.0
@platform: all
*/


@class TUNIP2pFileManagerThingP2PInitConfigParams;
@class TUNIP2pFileManagerThingP2PConnectionParams;
@class TUNIP2pFileManagerThingP2PDevice;
@class TUNIP2pFileManagerThingP2PAlbum;
@class TUNIP2pFileManagerThingP2PAlbumFileIndex;
@class TUNIP2pFileManagerThingP2PAlbumFileIndexs;
@class TUNIP2pFileManagerThingP2PUploadFile;
@class TUNIP2pFileManagerThingP2PDownloadFile;
@class TUNIP2pFileManagerThingP2PDownloadStream;
@class TUNIP2pFileManagerThingP2PUploadTask;
@class TUNIP2pFileManagerThingP2PDownloadTask;
@class TUNIP2pFileManagerThingP2PSessionStatus;
@class TUNIP2pFileManagerProgressEvent;
@class TUNIP2pFileManagerDownloadProgressEvent;
@class TUNIP2pFileManagerDownloadTotalProgressEvent;
@class TUNIP2pFileManagerFileDownloadCompletionEvent;
@class TUNIP2pFileManagerStreamDownloadPacketReceivedEvent;

@interface TUNIP2pFileManagerThingP2PInitConfigParams : NSObject

/**
user id
@available undefined
*/
@property (nonatomic, copy, nullable) NSString* userId;

@end

@interface TUNIP2pFileManagerThingP2PConnectionParams : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
connect mode,0:INTERNET  1:LAN
@available undefined
*/
@property (nonatomic, assign) NSInteger mode;

/**
timeout,unit：ms, default as Internet：15000ms,Lan：3000ms
@available undefined
*/
@property (nonatomic, assign) NSInteger timeout;

@end

@interface TUNIP2pFileManagerThingP2PDevice : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

@end

@interface TUNIP2pFileManagerThingP2PAlbum : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
albumName,given by the device
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* albumName;

@end

@interface TUNIP2pFileManagerThingP2PAlbumFileIndex : NSObject

/**
idx,given by the device
@available undefined
*/
@property (nonatomic, assign) NSInteger idx;

/**
channel channel number
@available undefined
*/
@property (nonatomic, assign) NSInteger channel;

/**
type file type,0: image，2: mp4, 3: Panoramic stitching file
@available undefined
*/
@property (nonatomic, assign) NSInteger type;

/**
dir 0: file，1: directory
@available undefined
*/
@property (nonatomic, assign) NSInteger dir;

/**
file name contains suffix
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* filename;

/**
createTime file create time
@available undefined
*/
@property (nonatomic, assign) NSInteger createTime;

/**
duration file duration
@available undefined
*/
@property (nonatomic, assign) NSInteger duration;

@end

@interface TUNIP2pFileManagerThingP2PAlbumFileIndexs : NSObject

/**
file count
@available undefined
*/
@property (nonatomic, assign) NSInteger count;

/**
file index infos
@available undefined
*/
@property (nonatomic, copy, nonnull) NSArray<TUNIP2pFileManagerThingP2PAlbumFileIndex*> * items;

@end

@interface TUNIP2pFileManagerThingP2PUploadFile : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
albumName given by the device
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* albumName;

/**
local file path
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* filePath;

/**
ext data
@available undefined
*/
@property (nonatomic, copy, nullable) NSString* extData;

/**
ext data length
@available undefined
*/
@property (nonatomic, assign) NSInteger extDataLength;

@end

@interface TUNIP2pFileManagerThingP2PDownloadFile : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
albumName given by the device
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* albumName;

/**
local file path
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* filePath;

/**
file name jsons，eg: {"files":["filesname1", "filesname2", "filesname3" ]}
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* jsonfiles;

@end

@interface TUNIP2pFileManagerThingP2PDownloadStream : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
albumName given by the device
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* albumName;

/**
file name jsons，eg: {"files":["filesname1", "filesname2", "filesname3" ]}
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* jsonfiles;

@end

@interface TUNIP2pFileManagerThingP2PUploadTask : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

@end

@interface TUNIP2pFileManagerThingP2PDownloadTask : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

@end

@interface TUNIP2pFileManagerThingP2PSessionStatus : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
status, status < 0 means disconnected
@available undefined
*/
@property (nonatomic, assign) NSInteger status;

@end

@interface TUNIP2pFileManagerProgressEvent : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
local file path
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* filePath;

/**
upload/download progress
@available undefined
*/
@property (nonatomic, assign) float progress;

@end

@interface TUNIP2pFileManagerDownloadProgressEvent : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
file name on downloading
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* fileName;

/**
upload/download progress
@available undefined
*/
@property (nonatomic, assign) float progress;

@end

@interface TUNIP2pFileManagerDownloadTotalProgressEvent : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
upload/download progress
@available undefined
*/
@property (nonatomic, assign) float progress;

@end

@interface TUNIP2pFileManagerFileDownloadCompletionEvent : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
file name
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* fileName;

/**
index
@available undefined
*/
@property (nonatomic, assign) NSInteger index;

@end

@interface TUNIP2pFileManagerStreamDownloadPacketReceivedEvent : NSObject

/**
device id
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
total files count
@available undefined
*/
@property (nonatomic, assign) NSInteger totalFiles;

/**
file name
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* fileName;

/**
file index, dirty data
@available undefined
*/
@property (nonatomic, assign) NSInteger fileIndex;

/**
file length
@available undefined
*/
@property (nonatomic, assign) NSInteger fileLength;

/**
packet data
@available undefined
*/
@property (nonatomic, copy, nonnull) NSString* packetData;

/**
packet data length
@available undefined
*/
@property (nonatomic, assign) NSInteger packetLength;

/**
file serial number
@available undefined
*/
@property (nonatomic, assign) NSInteger fileSerialNumber;

/**
packet index
@available undefined
*/
@property (nonatomic, assign) NSInteger packetIndex;

/**
packet header/packet tail 0b00XY Y:packet header  X:packet tail
@available undefined
*/
@property (nonatomic, assign) NSInteger packetType;

@end

