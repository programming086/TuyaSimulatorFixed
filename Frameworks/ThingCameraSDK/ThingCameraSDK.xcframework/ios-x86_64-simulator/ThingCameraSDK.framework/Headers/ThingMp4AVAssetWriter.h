
#ifndef ThingMp4Writer_h
#define ThingMp4Writer_h

#import <Foundation/Foundation.h>

@interface ThingMp4Writer : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCxxMp4Recorder:(long)cxxMp4Handler NS_DESIGNATED_INITIALIZER;

- (int)startRecordWithPath:(NSString *)videoPath fileName:(NSString *)fileName mute:(BOOL)mute audioOnly:(BOOL)audioOnly;

- (int)processAudioPacket:(std::shared_ptr<CameraAudioFrameInfo>)audioFrame;

- (int)processVideoPacket:(std::shared_ptr<ThingVideoPacketInfo>)videoPacket;

- (int)stopRecord;

- (int)recordCompensativelyBeforeStop;

@end


#endif /* ThingMp4Writer_h */
