
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSweeperFileManagerModel : NSObject

@end

@interface ThingSmartSweeperP2PConnectionParams : NSObject

/**
 Device ID
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 Connection mode  0:INTERNET  1:LAN
*/
@property (nonatomic, assign) NSInteger mode;

/**
 Duration of timeout, unit: ms, Setting 0 will be set as the default value, Internet：15000ms， Lan：3000ms
*/
@property (nonatomic, assign) NSInteger timeout;

@end

@interface ThingSmartSweeperP2PAlbum : NSObject

/**
 Device ID
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 Agree on fields with the device
*/
@property (nonatomic, copy, nonnull) NSString* albumName;

@end

@interface ThingSmartSweeperP2PAlbumFileIndex : NSObject

/**
 Unique identifier provided by the device
*/
@property (nonatomic, assign) NSInteger idx;

/**
 Channel number
*/
@property (nonatomic, assign) NSInteger channel;

/**
 File type, 0: Image, 2: mp4,  3: Panoramic stitching file
*/
@property (nonatomic, assign) NSInteger type;

/**
 0:  File, 1: Folder. Reserved fields, currently all are 0
*/
@property (nonatomic, assign) NSInteger dir;

/**
 file name with file suffix
*/
@property (nonatomic, copy, nonnull) NSString* filename;

/**
 File creation time
*/
@property (nonatomic, assign) NSInteger createTime;

/**
 Video file duration
*/
@property (nonatomic, assign) NSInteger duration;

@end

@interface ThingSmartSweeperP2PAlbumFileIndexs : NSObject

/**
 Number of files
*/
@property (nonatomic, assign) NSInteger count;

/**
 File index
*/
@property (nonatomic, copy, nonnull) NSArray<ThingSmartSweeperP2PAlbumFileIndex*> * items;

@end

@interface ThingSmartSweeperP2PDownloadFile : NSObject

/**
 Device ID
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 Agree on fields with the device
*/
@property (nonatomic, copy, nonnull) NSString* albumName;

/**
 Download file local storage path
*/
@property (nonatomic, copy, nonnull) NSString* filePath;

/**
 Download file name，eg: {"files":["filesname1", "filesname2", "filesname3" ]}
*/
@property (nonatomic, copy, nonnull) NSString* jsonfiles;

@end

@interface ThingSmartSweeperP2PSessionStatus : NSObject

/**
 Device ID

*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 Status value, less than 0 indicates disconnection
*/
@property (nonatomic, assign) NSInteger status;

@end

@interface ThingSmartSweeperFileManagerProgress : NSObject

/**
 Device ID

*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 Local file path
*/
@property (nonatomic, copy, nonnull) NSString* filePath;

/**
 Upload/Download Progress
*/
@property (nonatomic, assign) float progress;

@end

@interface ThingSmartSweeperFileDownloadProgress : NSObject

/**
 device ID

*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 The name of the file being downloaded
*/
@property (nonatomic, copy, nonnull) NSString* fileName;

/**
 Upload/Download Progress
*/
@property (nonatomic, assign) float progress;

@end

@interface ThingSmartSweeperFileDownloadTotalProgress : NSObject

/**
 Device ID
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 Upload/Download Progress
*/
@property (nonatomic, assign) float progress;

@end

@interface ThingSmartSweeperFileDownloadCompletion : NSObject

/**
 Device ID
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 file name
*/
@property (nonatomic, copy, nonnull) NSString* fileName;

/**
 index
*/
@property (nonatomic, assign) NSInteger index;

@end

@interface ThingSmartSweeperFileManagerPacketReceived : NSObject

/**
 Device ID
*/
@property (nonatomic, copy, nonnull) NSString* deviceId;

/**
 Number of files
*/
@property (nonatomic, assign) NSInteger totalFiles;

/**
 File name
*/
@property (nonatomic, copy, nonnull) NSString* fileName;

/**
 Index, currently incorrect data
*/
@property (nonatomic, assign) NSInteger fileIndex;

/**
 File size
*/
@property (nonatomic, assign) NSInteger fileLength;

/**
 Packet data
*/
@property (nonatomic, copy, nonnull) NSString* packetData;

/**
 Packet size
*/
@property (nonatomic, assign) NSInteger packetLength;

/**
 File serial number
*/
@property (nonatomic, assign) NSInteger fileSerialNumber;

/**
 Package Index
*/
@property (nonatomic, assign) NSInteger packetIndex;

/**
 Header/Tail 0b00XY  Y:header  X:Tail
*/
@property (nonatomic, assign) NSInteger packetType;

@end

NS_ASSUME_NONNULL_END
