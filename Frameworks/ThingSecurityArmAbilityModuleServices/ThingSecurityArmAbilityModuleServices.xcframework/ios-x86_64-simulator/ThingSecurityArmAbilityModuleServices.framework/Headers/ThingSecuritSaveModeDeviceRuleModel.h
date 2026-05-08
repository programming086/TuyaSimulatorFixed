
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecuritSaveModeDeviceRuleModel : NSObject

@property (nonatomic, copy) NSString *gatewayId;

@property (nonatomic, strong) NSArray<NSString *>*deviceIds;

@property (nonatomic, assign) NSInteger type;
@end

NS_ASSUME_NONNULL_END
