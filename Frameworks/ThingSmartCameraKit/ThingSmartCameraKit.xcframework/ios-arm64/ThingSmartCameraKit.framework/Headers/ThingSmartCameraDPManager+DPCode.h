
#import "ThingSmartCameraDPManager.h"

@interface ThingSmartCameraDPManager (DPCode)

- (BOOL)isSupportDPCode:(ThingSmartCameraDPKey)DPCode;

- (id)valueForDPCode:(ThingSmartCameraDPKey)DPCode;

- (void)valueForDPCode:(ThingSmartCameraDPKey)DPCode success:(ThingSuccessID)success failure:(ThingFailureError)failure;

- (void)setValue:(id)value forDPCode:(ThingSmartCameraDPKey)DPCode success:(ThingSuccessID)success failure:(ThingFailureError)failure;

- (NSString *)dpCodeForDpId:(NSString *)dpId;
- (NSString *)dpIdForDpCode:(NSString *)dpCode;

@end
