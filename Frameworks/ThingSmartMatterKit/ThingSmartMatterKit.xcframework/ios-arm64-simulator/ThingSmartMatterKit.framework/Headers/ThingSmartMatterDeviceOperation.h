
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterAttributeBasicInfo : NSObject
@property (nonatomic, strong, nullable) NSString *vendorName;
@property (nonatomic, strong, nullable) NSNumber *vendorId;
@property (nonatomic, strong, nullable) NSString *productName;
@property (nonatomic, strong, nullable) NSNumber *productId;
@property (nonatomic, strong, nullable) NSString *nodeLabel;
@property (nonatomic, strong, nullable) NSString *location;
@property (nonatomic, strong, nullable) NSNumber *hardwareVersion;
@property (nonatomic, strong, nullable) NSString *hardwareVersionString;
@property (nonatomic, strong, nullable) NSNumber *softwareVersion;
@property (nonatomic, strong, nullable) NSString *softwareVersionString;
@property (nonatomic, strong, nullable) NSString *productUrl;
@property (nonatomic, strong, nullable) NSString *productLabel;
@property (nonatomic, strong, nullable) NSString *serialNumber;
@property (nonatomic, strong, nullable) NSString *uniqueId;
@end


@interface ThingSmartMatterDeviceOperation : NSObject

/// Create a `ThingSmartMatterDeviceOperation` object with a `ThingSmartDeviceModel` object.
/// @param deviceModel The object of `ThingSmartDeviceModel`
- (instancetype)initWithDeviceModel:(ThingSmartDeviceModel *)deviceModel;

/// Check the device query attributes command communicate channels available or not.
- (BOOL)checkQueryPipelineAvailable;

/// Query matter basic infomation.
/// @param success success.
/// @param failure failure.
- (void)queryAttributeBasicInfo:(void(^)(ThingSmartMatterAttributeBasicInfo *info))success
                        failure:(nullable ThingFailureError)failure;

/// Query matter device attributes info.
///
/// **Input & Output Examples**
/// ```
/// // Input Example:
/// [{"endpointId": 0, "clusterId": 8, "attributeId": 2, "fabricFiltered": true/false},
///  {"endpointId": 0, "clusterId": 8, "attributeId": 3, "fabricFiltered": true/false}, ...]
///
/// // Output Exmaple:
/// // "payload"、"code" maybe empty.
/// [{"endpointId": 0, "clusterId": 8, "attributeId": 2, "payload": xxx},
///  {"endpointId": 0, "clusterId": 8, "attributeId": 3, "code": err_code}, ...]
/// ```
///
/// **Notice: Limit queries to fewer than 5 attributes at once**
///
/// @param attributes Matter attribute infos.
/// @param success success.
/// @param failure failure.
- (void)queryMatterAttributes:(NSArray<NSDictionary *> *)attributes
                      success:(ThingSuccessList)success
                      failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
