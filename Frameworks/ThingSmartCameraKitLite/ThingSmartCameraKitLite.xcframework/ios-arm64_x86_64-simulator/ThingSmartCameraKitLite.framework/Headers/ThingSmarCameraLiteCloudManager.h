//
//  ThingSmarCameraLiteCloudManager.h
//  ThingSmartCameraKitLite
//
//  Created by MokZF on 2025/1/15.
//

#import <Foundation/Foundation.h>
#import "ThingSmartCameraCloudDelegate.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ThingSmartCameraCloudDataHandler)(id datas);
typedef void(^ThingSmartCameraCloudDataFailHandler)(NSError *error);

@interface ThingSmarCameraLiteCloudParamas : NSObject

//start time
@property (nonatomic, assign) NSTimeInterval startTime;

//end time
@property (nonatomic, assign) NSTimeInterval endTime;

// page index 【begin from 1】
@property (nonatomic, assign) NSInteger pageIndex;

//page size
@property (nonatomic, assign) NSInteger pageSize;


/// 片段信息
@property (nonatomic, strong)  id metaData;

@end

@interface ThingSmarCameraLiteCloudManager : NSObject

@property (nonatomic, weak) id<ThingSmartCameraCloudDelegate> delegate;

- (instancetype)initWithDeviceId:(NSString *)devId productId:(NSString *)productId token:(NSString *)token;

/// load cloud datas
/// - Parameters:
///   - params: params
///   - success: success callback
///   - fail: fail callback
- (void)loadCloudData:(ThingSmarCameraLiteCloudParamas *)params success:(ThingSmartCameraCloudDataHandler)success fail:(ThingSmartCameraCloudDataFailHandler)fail;

/// play cloud video
/// - Parameters:
///   - startTime: startTime
///   - endTime: endTime
///   - pageIndex: page index
///   - pageSize: page size
- (void)playCloudDatas:(ThingSmarCameraLiteCloudParamas *)params
       responseHandler:(void (^)(const char* msg,int errCode))responseHander
     playFinishHandler:(void (^)(const char* msg,int errCode))finishaHandler;

/// Update mute status
/// - Parameter mute: mute
- (void)updateMute:(BOOL)mute;

/**
 [^en]
 pause play cloud video.
 [$en]
 
 @return [^en]error Code, 0 is success.[$en]
 */
- (int)pausePlayCloudVideo;

/**
 [^en]
 resume play cloud video.
 [$en]

 @return [^en]error Code, 0 is success.[$en]
 */
- (int)resumePlayCloudVideo;

/**
 [^en]
 stop play cloud video.
 [$en]

 @return [^en]error Code, 0 is success.[$en]
 */
- (int)stopPlayCloudVideo;


@end

NS_ASSUME_NONNULL_END
