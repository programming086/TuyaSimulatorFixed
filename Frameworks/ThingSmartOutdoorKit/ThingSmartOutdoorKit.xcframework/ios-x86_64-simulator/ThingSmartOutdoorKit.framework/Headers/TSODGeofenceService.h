//
//  TSODGeofenceService.h
//  ThingSmartOutdoorKit
//
//  Created by Hemin Won on 2024/6/21.
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TSODGeofenceNoticeType) {
    TSODGeofenceNoticeType_APP  = 1 << 0, // push and message
    TSODGeofenceNoticeType_Call = 1 << 1,
    TSODGeofenceNoticeType_SMS  = 1 << 2,
} NS_SWIFT_NAME(GeofenceNoticeType);

NS_SWIFT_NAME(GeofenceInfoModel)
@interface TSODGeofenceInfoModel : NSObject

@property (nonatomic, assign) NSInteger radius; // meter

@property (nonatomic, assign) TSODGeofenceNoticeType noticeType;

@property (nonatomic, assign, getter=isOpen) BOOL open;

@property (nonatomic, copy) NSString *dpCode;

@property (nonatomic, strong) id dpValue;

@end

NS_SWIFT_NAME(GeofenceModel)
@interface TSODGeofenceModel : NSObject

@property (nonatomic, copy) NSString *devID;

@property (nonatomic, strong) TSODGeofenceInfoModel *geofenceInfo;

@end

NS_SWIFT_NAME(GeofenceService)
@interface TSODGeofenceService : NSObject

- (void)setGeofenceWithRequestModel:(TSODGeofenceModel *)requestModel
                            success:(nullable ThingSuccessBOOL)success
                            failure:(nullable ThingFailureError)failure NS_SWIFT_NAME(setGeofence(requestModel:success:failure:));

- (void)getGeofenceInfoWithDevID:(NSString *)devID
                         success:(nullable void(^)(TSODGeofenceModel *geofenceModel))success
                         failure:(nullable ThingFailureError)failure NS_SWIFT_NAME(getGeofenceInfo(devID:success:failure:));
@end

NS_ASSUME_NONNULL_END
