
#import <Foundation/Foundation.h>
#include "ThingCameraDefines.h"
@protocol ThingCameraEngineDelegate;
@interface ThingCameraEngine : NSObject
@property (nonatomic,   weak) id<ThingCameraEngineDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
/**
    sharedInstance.
 */
+ (instancetype)sharedInstance ;

/**
    init the engine.
 */
-(int)initlize ;

/**
    de init the engine.
 */
-(int)deInitialize ;
/*
    get the sdk version.
 */
-(NSString*) getVersion ;

-(int)setLogPath:(NSString*)path ;

-(int)setSoftDecodeStatus:(bool)enable ;


-(bool)getSoftDecodeStatus ;


-(bool)getCurVideoSoftDecodeStatus ;


-(int)setNetworkType:(ThingSmartNetType)type ;


-(void)setLogPathWithPath:(NSString*)path ;
/**
    init the p2p module for PPCS only.
 */
- (int)initP2PModuleWithServerString:(NSString*)serverString ;

/**
    deinit the p2p module. shangyun only.
 */
- (int)deInitP2PModule ;


/**
    set loud speaker status
 */
- (int)setLoudspeakerStatus:(bool) enable ;
/**
    get loud speaker status
 */
- (bool)getLoudspeakerStatus ;

/**
    add network query handler
 */
- (void)addNetworkQueryHandler:(ThingSmartNetType(^)(void))networkQueryHandler;

@end

@protocol ThingCameraEngineDelegate<NSObject>
@required

@end
