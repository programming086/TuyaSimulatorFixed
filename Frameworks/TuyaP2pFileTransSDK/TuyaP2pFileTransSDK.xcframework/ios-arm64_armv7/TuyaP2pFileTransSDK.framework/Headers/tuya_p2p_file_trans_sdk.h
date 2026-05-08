//
//  tuya_p2p_file_trans_sdk.h
//  TuyaP2PFileTransSDK
//
//  Created by Foster on 2022/2/15.
//

#ifndef tuya_p2p_file_trans_sdk_h
#define tuya_p2p_file_trans_sdk_h


#import <Foundation/Foundation.h>
#include "tuya_p2p_file_trans_callback.h"

typedef void (^TYMQTTSender)(BOOL LANmode, NSString *remoteId, NSString *signal);
typedef void (^TYHttpsRequest)(NSString *api, NSString *devId, NSDictionary *postData);

@interface TYPhotoFrameSDK : NSObject

// get SDK Version
+(NSString*) getSDKVersion ;
@end





#endif /* tuya_p2p_file_trans_sdk_h */
