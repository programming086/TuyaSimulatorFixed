#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>
#include "ThingDefines.h"

@protocol ThingMediaPlayerDelegate;

@interface ThingMediaPlayer : NSObject

/**
    usage：
        ThingMediaPlayer* mediaPlayer_ ;
        mediaPlayer_ = [[ThingMediaPlayer alloc] initWithDelegate:delegate];
        
        // For regular playback
        [mediaPlayer_ setDataSource:url] ;
        int retCode = [mediaPlayer_ asyncPrepare] ;
        if(retCode == 0){
            [mediaPlayer_ play] ;
            [mediaPlayer_ openSound]  ;
            ...
            ...
            [mediaPlayer_ closeSound];
            [mediaPlayer_ close];
        }
 */

@property (nonatomic, weak) id<ThingMediaPlayerDelegate> delegate;
@property (nonatomic, readonly) UIView *view;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDelegate:(id<ThingMediaPlayerDelegate>)delegate NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithView:(CGRect *)view delegate:(id<ThingMediaPlayerDelegate>)delegate NS_DESIGNATED_INITIALIZER;

// Regular playback methods
- (int)setDataSource:(NSString*)url;
- (int)asyncPrepare;
- (int)startCompose;
- (int)play;
- (int)pause;
- (int)resume;
- (int)close;
- (int)openSound;
- (int)closeSound;
- (int)setTransportWithProtocol:(THING_TRANSPORT_PROTOCOL_TYPE)transport_protocol_type;
- (int)setMirror:(bool)force_mirror;
- (int)startRecordWithPath:(NSString*)path : (NSString*)pMp4FileName : (NSString*)pThumbnailFileName : (ThingRotateMode)enRotaMode : (int)nMute;
- (int)stopRecord;
- (int)setSpeedWithSpeedType:(THING_PLAY_SPEED_TYPE)speed forceOnlyIFrame:(bool)forceOnlyIFrame;
- (int)snapshotWithFileName:(NSString*)absoluteFileName;
- (long long)getDuration;
- (int)seekTo:(NSUInteger)timestamp_in_ms;
- (int)seekTo:(NSUInteger)timestamp_in_ms direction:(ThingDirection)direction;

// Common property setting method
- (int)setPropertyWithKey:(NSString *)key value:(NSString *)value; // Also used for filters with key="filter"

@end

@protocol ThingMediaPlayerDelegate<NSObject>
@optional
/**
 * Regular video frame callback
 */
- (void)mediaPlayer:(ThingMediaPlayer *)mediaPlayer videoFrameInfo:(ThingVideoFrame *)videoFrameInfo;

/**
 * Raw data callback
 */
- (void)mediaPlayer:(ThingMediaPlayer *)mediaPlayer timestamp:(int64_t)timestamp handle_name:(const char *)handle_name data:(unsigned char*)data size:(int)size;

/**
 * Runtime info callback
 */
- (void)mediaPlayer:(ThingMediaPlayer *)mediaPlayer runInfo:(ThingMsgRunInfo*)runInfo;
@end
