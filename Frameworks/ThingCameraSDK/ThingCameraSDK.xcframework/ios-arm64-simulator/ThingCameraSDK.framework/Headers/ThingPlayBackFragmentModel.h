
#import <Foundation/Foundation.h>

@interface ThingPlayBackFragmentModel : NSObject

@property (nonatomic, copy) NSString *uuid;           // device uuid
@property (nonatomic, assign) int encrypt;              // need encrypt
@property (nonatomic, copy) NSString *encryptMD5;     // key md5
@property (nonatomic, assign) int videoType;            // 1 -- aov
                                                        // 0 -- normal
@property (nonatomic, assign) int eventType;            // event Type
@property (nonatomic, copy) NSArray *eventTypeArr;      //event types, the max count is 10.
@property (nonatomic, assign) int type;                 //
@property (nonatomic, assign) int startTime;            // fragment starttime
@property (nonatomic, assign) int endTime;              // fragment endtime

@end
