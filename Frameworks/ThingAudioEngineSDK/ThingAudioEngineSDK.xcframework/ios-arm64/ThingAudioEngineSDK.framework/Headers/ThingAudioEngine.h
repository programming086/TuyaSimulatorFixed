
#import <Foundation/Foundation.h>

@protocol ThingAudioEngineDelegate ;

@interface ThingAudioEngine : NSObject

@property (nonatomic,   weak) id<ThingAudioEngineDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
/**
    sharedInstance.
 */
+ (instancetype)sharedInstance ;

/**
    initialize the audio engine
 */
- (void)initAudioEngine ;

/*
    get the sdk version.
 */
-(NSString*) getVersion ;

/**
    deinitailize the audio engine.
 */
- (void)deInitAudioEngine;

@end


@protocol ThingAudioEngineDelegate <NSObject>

@optional

- (void)audioEngine:(ThingAudioEngine*)engine onError:(int)err ;

@end
