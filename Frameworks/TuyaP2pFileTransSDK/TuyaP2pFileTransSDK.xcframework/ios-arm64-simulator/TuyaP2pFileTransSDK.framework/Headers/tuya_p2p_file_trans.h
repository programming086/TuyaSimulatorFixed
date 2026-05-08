//
//  tuya_p2p_file_trans.h
//  TuyaP2PFileTransSDK
//
//  Created by Foster on 2022/2/15.
//

#ifndef tuya_p2p_file_trans_h
#define tuya_p2p_file_trans_h

#import <Foundation/Foundation.h>
@protocol TYP2PFileTransDelegate;

@interface TYP2PFileTrans : NSObject

@property (nonatomic, strong) NSString        *device_id_;  //device id
@property (nonatomic, assign) BOOL            is_connected; //connect status

@property (nonatomic,   weak) id<TYP2PFileTransDelegate> delegate_;

- (instancetype)init NS_UNAVAILABLE;

/// init TYPhotoFrame with device id
/// @param deviceId  device id
- (instancetype)initWithDeviceId:(NSString*)deviceId;

/// Description connect to deveice
/// @param username session_id

/// @return retcode >= 0: session id, retcode < 0: error code
/// call while p2p session has connected;
- (int)SetSessionId:(int)session_id;

- (int)getSessionId;

/// Description P2P 3.0 connect
/// @param username username
/// @param pwd  password
/// @param token  (json) p2p config field  obtained from cloud
/// @param skills  (json) device capability set, skill field obtained from the cloud
/// @param traceId  id of a full link log, the value can be empty
/// @return retcode >= 0: session id, retcode < 0: error code
- (int)connectWithUserName:(NSString *)username password:(NSString *)pwd token:(NSString *)token skills:(NSString *)skills traceId:(NSString *)traceId;

/// disconnect p2p link
- (void)disconnect;

/// download file
/// @param albumname  album name
/// @param folder The destination folder
/// @param jsonfiles  The name of the files need to download, eg. {"files":["filesname1", "filesname2", "filesname3" ]}

-(int)startDownloadFileWithAlbumName:(NSString*)albumname folder:(NSString*)folder jsonfiles:(NSString*)jsonfiles;

/// cancel file download or upload task
-(int)cancelUpDownloadFileWithChannel;

/// upload file
/// @param albumName album name
/// @param folder   The source folder
/// @param filename file to be uploaded
/// @param extData additional file information
/// @param extDataLen additional file information length
-(int)startUploadFileWithAlbumName:(NSString*)albumName folder:(NSString*)folder filename:(NSString*)filename extData:(const char*)extData extDataLen:(int)extDataLen ;

-(int)queryAlbumFileIndexWithAlbumName:(NSString*)albumName;

-(int)deleteAlbumFileWithAlbumName:(NSString*)albumName jsonfiles:(NSString*)jsonfiles;

@end

@protocol TYP2PFileTransDelegate<NSObject>
@optional

/// session status callback immediately when it changes
/// @param device  which device
/// @param status  session status, status < 0 means lose connection
- (void)p2pfiletrans:(TYP2PFileTrans *)device didSessionStatusChangedWithStatus:(NSInteger)status;


/// FIle download or upload callback immediately when it finished
/// @param device device id
/// @param event  event name, kTuyaEvent_Download_Start indicates download task, kTuyaEvent_Upload_Start indicates upload task
/// @param filename  filename
/// @param index file index, ranging from 0 to file total count, -1 means all file download or upload finished
/// @param errCode error code
- (void)p2pfiletrans:(TYP2PFileTrans *)device didFileFinishedWithEvent:(NSInteger)event filename:(NSString *)filename index:(int)index errCode: (int)errCode;

/// download or upload total progress
/// @param device  device id
/// @param event   event name, kTuyaEvent_Download_Start indicates download task, kTuyaEvent_Upload_Start indicates upload task
/// @param progress total  progress of download or upload files
- (void)p2pfiletrans:(TYP2PFileTrans *)device didProgressWithEvent:(NSInteger)event progress:(NSInteger)progress;

/// download or upload single file progress
/// @param device  device id
/// @param event event name, kTuyaEvent_Download_Start indicates download task, kTuyaEvent_Upload_Start indicates upload task
/// @param progress progress of download or upload file
/// @param filename  filename
- (void)p2pfiletrans:(TYP2PFileTrans *)device didFileProgressWithEvent:(NSInteger)event progress:(NSInteger)progress filename:(NSString *)filename;

///  p2p response callback
/// @param device  device id
/// @param event   event name, kTuyaEvent_Download_Start indicates download task, kTuyaEvent_Upload_Start indicates upload task
/// @param errCode  error code
/// @param data  response data, it is temporarily empty
- (void)p2pfiletrans:(TYP2PFileTrans *)device didP2pResponse:(NSInteger)event errCode: (int)errCode data:(const char *)data;

//p2p query file callback
- (void)p2pfiletrans:(TYP2PFileTrans *)device didQueryFileResponse:(NSInteger)event errCode:(int)errCode data:(const char *)data;
@end



#endif /* tuya_p2p_file_trans_h */
