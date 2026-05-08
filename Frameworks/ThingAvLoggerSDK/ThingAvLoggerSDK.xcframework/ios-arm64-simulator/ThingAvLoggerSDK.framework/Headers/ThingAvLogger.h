
#import <Foundation/Foundation.h>

@protocol ThingAvLoggerDelegate;

@interface ThingAvLogger : NSObject

@property (nonatomic,weak) id<ThingAvLoggerDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)sharedInstance;

/**
 initialize the avlogger
 The delegate property must be set before this method can be called!!
 */
- (void)initAvLoggerWithDelegate;

/**
 deinitialize the sdk
 */
-(void) deinitAvLogger;

/**
 enalbe the log report to platform
 */
-(int) enableLogReport:(bool)enable;

/**
 set the debug folder for log file and dump file saved.
 */
-(int) setFileDumpFolder:(NSString *) folder ;

/**
    set the cache folder.
 */
-(int) setCacheFolder:(NSString*)folder ;

/**
 enable the debug or not
 open the consolle output or not
    enable :
        true    : open the consolle output
        false   : close  the consolle output
*/

-(int) enableDebug:(bool)enable;
/**
 
 */
-(int) enableFileDump:(bool)enable ;
/**
    enable local log file record.
 */
-(int) enableLocalLogFileRecord:(bool)enable;
/**
 
 */
-(BOOL)getDumpStatus;

/**
 get the sdk version
 */
-(NSString*) getVersion;


/**
 set log print interVal
 */
-(int) setLogInterval:(int)interVal;

@end


@protocol ThingAvLoggerDelegate <NSObject>

@optional


-(void)avLogger:(ThingAvLogger*)Logger onSendApmLogWithEventName:(NSString*)eventName apmLog:(NSString*)apmLog;

-(void)avLogger:(ThingAvLogger*)Logger onSengNativeLogWithMessage:(NSString*)msg;

-(void)avLogger:(ThingAvLogger*)Logger onSendFullLinkLogWithType:(NSString*)type jsonAttribute:(NSString*)jsonAttribute
      jsonInfos:(NSString*)jsonInfos trackType:(NSString*)trackType traceId:(NSString*)traceId ;

@end
