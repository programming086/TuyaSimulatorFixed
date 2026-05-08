
#ifndef ThingSmartStreamDefines_h
#define ThingSmartStreamDefines_h

#import <Foundation/Foundation.h>
#import "NSError+ThingSmartStream.h"

typedef NS_ENUM(NSUInteger, ThingSmartStreamClientType) {
    ThingSmartStreamClientTypeDevice = 1,
    ThingSmartStreamClientTypeApp = 2,
    ThingSmartStreamClientTypeDeveloper = 3
};

#import "ThingStreamConnectInfo.h"
#import "ThingStreamSessionInfo.h"
#import "ThingStreamPacketModels.h"

typedef void(^ThingSmartStreamCompletion)(BOOL result, NSError *error);

#endif /* ThingSmartStreamDefines_h */
