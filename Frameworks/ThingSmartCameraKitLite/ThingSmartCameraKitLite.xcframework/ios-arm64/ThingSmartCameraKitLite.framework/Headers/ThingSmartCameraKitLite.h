//
//  ThingSmartCameraKitLite.h
//  ThingSmartCameraKitLite
//
//  Created by MokZF on 2025/1/6.
//

#ifndef ThingSmartCameraKitLite_h
#define ThingSmartCameraKitLite_h

typedef struct {
    int type;
    int codecid;
    int nWidth;
    int nHeight;
    
    int nFrameRate;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
    int nFragmentId;
    int sei_rotation;
} ThingSmartVideoFrameInfo;


//#import "ThingSmartCameraDevice.h"

#endif /* ThingSmartCameraKitLite_h */
