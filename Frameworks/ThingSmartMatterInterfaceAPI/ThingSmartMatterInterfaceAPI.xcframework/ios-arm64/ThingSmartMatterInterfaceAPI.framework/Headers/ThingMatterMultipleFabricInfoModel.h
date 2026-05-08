
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingMatterMultipleFabricInfoModel : NSObject

@property (nonatomic, strong) NSNumber *vendorId;
@property (nonatomic, assign) long long nodeId;
@property (nonatomic, assign) long long fabricId;
@property (nonatomic, assign) NSInteger fabricIndex;
@property (nonatomic, strong, nullable) NSString *label;
@property (nonatomic, assign) BOOL isCurrent;

@end

NS_ASSUME_NONNULL_END
