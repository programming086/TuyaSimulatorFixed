
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingP2PSessionExtInfo : NSObject

@property (nonatomic, copy, readonly, nullable) NSDictionary *infos;

@end

@interface ThingP2PSessionParams : NSObject

+ (instancetype)params;

@property (nonatomic, strong, nullable) ThingP2PSessionExtInfo *extInfo;

@end

typedef NS_ENUM(NSUInteger, ThingSmartP2pConnectMode);

@interface ThingP2PConnectParams : ThingP2PSessionParams

@property (nonatomic, assign) ThingSmartP2pConnectMode connectMode;

@property (nonatomic, assign) NSInteger timeout;

@end


@interface ThingP2PQueryFileParams : ThingP2PSessionParams

/**
albumName given by the device
*/
@property (nonatomic, copy) NSString *albumName;

@end


@interface ThingP2PQueryFileInfo : NSObject

/**
idx given by the device
*/
@property (nonatomic, assign) NSInteger idx;

/**
channel channel number
*/
@property (nonatomic, assign) NSInteger channel;

/**
type file type，0: image，2: mp4, 3: Panoramic stitching file
*/
@property (nonatomic, assign) NSInteger type;

/**
dir 0: file，1: directory
*/
@property (nonatomic, assign) NSInteger dir;

/**
filename file name contains suffix
*/
@property (nonatomic, copy) NSString *fileName;

/**
createTime  file create time
*/
@property (nonatomic, assign) NSInteger createTime;

/**
duration file duration
*/
@property (nonatomic, assign) NSInteger duration;

@end


@interface ThingP2PQueryFileInfos : NSObject

/**
file count
*/
@property (nonatomic, assign) NSInteger count;

/**
file index infos
*/
@property (nonatomic, copy) NSArray<ThingP2PQueryFileInfo *> *fileInfos;

@end


@interface ThingP2PUploadFileParams : ThingP2PSessionParams

/**
albumName given by the device
*/
@property (nonatomic, copy) NSString *albumName;

/**
local file path
*/
@property (nonatomic, copy) NSString *filePath;

/**
ext data
*/
@property (nonatomic, copy, nullable) NSString *extData;

/**
 ext data length
*/
@property (nonatomic, assign) NSInteger extDataLength;

@end

@interface ThingP2PDownloadParams : ThingP2PSessionParams

/**
albumName given by the device
*/
@property (nonatomic, copy) NSString *albumName;

/**
file name jsons，eg: {"files":["filesname1", "filesname2", "filesname3" ]}
*/
@property (nonatomic, copy) NSString *jsonfiles;

@end

@interface ThingP2PDownloadFileParams : ThingP2PDownloadParams

/**
local file path
*/
@property (nonatomic, copy) NSString *filePath;

@end


@interface ThingP2PDownloadStreamParams : ThingP2PDownloadParams

@end

@interface ThingP2PDownloadFileStreamInfo : NSObject

/**
file total count
*/
@property (nonatomic, assign) NSInteger totalFiles;

/**
file name
*/
@property (nonatomic, copy) NSString *fileName;

/**
file index, dirty data
*/
@property (nonatomic, assign) NSInteger fileIndex;

/**
file length
*/
@property (nonatomic, assign) NSInteger fileLength;

/**
packet data
*/
@property (nonatomic, copy) NSString *packetData;

/**
packet data length
*/
@property (nonatomic, assign) NSInteger packetLength;

/**
 file serial number
*/
@property (nonatomic, assign) NSInteger fileSerialNumber;

/**
 packet index
*/
@property (nonatomic, assign) NSInteger packetIndex;

/**
 packet header/packet tail 0b00XY Y:packet header  X:packet tail
*/
@property (nonatomic, assign) NSInteger packetType;

@end

NS_ASSUME_NONNULL_END
