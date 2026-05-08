
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingMatterAttributeBasicInfo : NSObject

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

NS_ASSUME_NONNULL_END
