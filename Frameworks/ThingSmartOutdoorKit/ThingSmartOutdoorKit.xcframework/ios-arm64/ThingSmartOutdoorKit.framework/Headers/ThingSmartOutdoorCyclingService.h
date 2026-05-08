
#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <ThingSmartNetworkKit/ThingSmartRequest.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(CycleRecordModel)
@interface ThingSmartOutdoorCycleRecordModel: NSObject
/// default: km
@property (nonatomic, copy) NSString *mileageUnitType;
/// aveage speed, not divide by scale
@property (nonatomic, assign) double speed;
/// total mileage, not divide by scale
@property (nonatomic, assign) double mileage;
/// cost battery value
@property (nonatomic, assign) double battery;
/// if device not report, realBattery is nil
@property (nonatomic, strong, nullable) NSNumber* realBattery;
@property (nonatomic, assign) double duration;
@property (nonatomic, assign) double startTime;
@property (nonatomic, assign) double endTime;
@property (nonatomic, assign) NSInteger bufferFlag;
/// carbon data, Negative numbers indicate invalid.
@property (nonatomic, assign) double savingCarbonData;

@end

NS_SWIFT_NAME(LocationUploadModel)
@interface ThingSmartOutdoorLocationUploadModel: NSObject
/// current location
@property (nonatomic, assign) CLLocationCoordinate2D coord;
/// current speed
@property (nonatomic, assign) double speed;
/// current mileage
@property (nonatomic, assign) double mileage;
/// set false will end record
@property (nonatomic, assign) BOOL started;
/// current battery value
@property (nonatomic, assign) double batteryValue;
@end

NS_SWIFT_NAME(CyclingService)
@interface ThingSmartOutdoorCyclingService : NSObject
/// request track record list
- (void)requestTripTrackWithDeviceId:(NSString *)devId
                        size:(NSInteger)size
                        completion:(void (^)(NSArray<ThingSmartOutdoorCycleRecordModel *> *records, NSError *error))completion;

/// request track statistic between startTime and endTime
- (void)requestTripTrackStatisticWithDeviceId:(NSString *)devId
                                    startTime:(double)startTime
                                      endTime:(double)endTime
                                   completion:(void (^)(ThingSmartOutdoorCycleRecordModel *record, NSError *error))completion;

/// update cycling info for track record
- (void)uploadLocatonWithDeviceId:(NSString *)devId
                        productId:(NSString *)pid
                    uploadModel:(ThingSmartOutdoorLocationUploadModel *)uploadModel
                     completion:(void (^)(BOOL success, NSError *error))completion;

/// query the latest track segment of the device
- (void)requestTripTrackLatestSegmentWithDeviceId:(NSString *)devId
                                          success:(ThingSuccessID)success failure:(ThingFailureError)failure;

@end
NS_ASSUME_NONNULL_END
