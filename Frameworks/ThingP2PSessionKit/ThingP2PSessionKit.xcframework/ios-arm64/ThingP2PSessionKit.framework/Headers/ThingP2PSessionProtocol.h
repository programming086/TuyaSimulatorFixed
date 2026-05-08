
#import <Foundation/Foundation.h>

#import "ThingP2PSessionConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingP2PSession;
@class ThingP2PConnectParams;
@class ThingP2PQueryFileParams;
@class ThingP2PQueryFileInfos;
@class ThingP2PUploadFileParams;
@class ThingP2PDownloadParams;
@class ThingP2PDownloadFileParams;
@class ThingP2PDownloadStreamParams;
@class ThingP2PDownloadFileStreamInfo;
@class ThingP2PSessionExtInfo;

@protocol ThingP2PSessionDelegate <NSObject>

- (void)P2PSession:(id<ThingP2PSession>)P2PSession didStatusChange:(NSInteger)status extInfo:(nullable ThingP2PSessionExtInfo *)extInfo;

- (void)P2PSession:(id<ThingP2PSession>)P2PSession didFileQueryCompleteWithFileInfos:(nullable ThingP2PQueryFileInfos *)fileInfos error:(nullable NSError *)error extInfo:(nullable ThingP2PSessionExtInfo *)extInfo;

- (void)P2PSession:(id<ThingP2PSession>)P2PSession didFileUploadProgressChange:(NSInteger)progress fileName:(NSString *)fileName extInfo:(nullable ThingP2PSessionExtInfo *)extInfo;
- (void)P2PSession:(id<ThingP2PSession>)P2PSession didFileUploadCompleteWithFileName:(NSString *)fileName idx:(NSInteger)idx error:(nullable NSError *)error extInfo:(nullable ThingP2PSessionExtInfo *)extInfo;

- (void)P2PSession:(id<ThingP2PSession>)P2PSession didFileDownloadProgressChange:(NSInteger)progress fileName:(NSString *)fileName extInfo:(nullable ThingP2PSessionExtInfo *)extInfo;
- (void)P2PSession:(id<ThingP2PSession>)P2PSession didFilesDownloadTotalProgressChange:(NSInteger)progress extInfo:(nullable ThingP2PSessionExtInfo *)extInfo;
- (void)P2PSession:(id<ThingP2PSession>)P2PSession didFileDownloadCompleteWithFileName:(NSString *)fileName idx:(NSInteger)idx error:(nullable NSError *)error extInfo:(nullable ThingP2PSessionExtInfo *)extInfo;

- (void)P2PSession:(id<ThingP2PSession>)P2PSession didFileStreamReceiveWithStreamInfo:(ThingP2PDownloadFileStreamInfo *)streamInfo extInfo:(nullable ThingP2PSessionExtInfo *)extInfo;

@end


@protocol ThingP2PSession <NSObject>

@property (nonatomic, copy, readonly) NSString *devId;
@property (nonatomic, copy, readonly) NSString *handleId;
@property (nonatomic, copy, readonly) NSString *traceId;

@property (nonatomic, weak) id <ThingP2PSessionDelegate> delegate;

///connect
- (void)connectWithParams:(ThingP2PConnectParams *)params success:(nullable ThingP2PSessionVoidSuccess)success failure:(nullable ThingP2PSessionFailure)failure;

///disconnect
- (int)disconnect;

///query
- (int)queryFileInfosWithParams:(ThingP2PQueryFileParams *)params error:(NSError * _Nullable *)error;

///upload
- (int)uploadFileWithParams:(ThingP2PUploadFileParams *)params error:(NSError * _Nullable *)error;

///download
- (int)downloadFileWithParams:(ThingP2PDownloadFileParams *)params error:(NSError * _Nullable *)error;
- (int)downloadStreamWithParams:(ThingP2PDownloadStreamParams *)params error:(NSError * _Nullable *)error;
- (int)appendDownloadWithParams:(ThingP2PDownloadParams *)params error:(NSError * _Nullable *)error;

///cancel
- (int)cancelTransferTasks;

@end

NS_ASSUME_NONNULL_END
