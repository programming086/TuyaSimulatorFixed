
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ThingActivatorFactoryProtocol;
@class ThingSmartDeviceCategoryModel, ThingActivatorFactoryConfig;

@interface ThingActivatorLinkModeInfo : NSObject
@property (nonatomic, copy) NSString *linkModeKey; /// The key of linkMode

@property (nonatomic, assign) NSInteger linkModeValue; /// linkMode value https://wiki.thing-inc.com:7799/page/1537370846127988811

@property (nonatomic, strong) Class factoryClass;   /**< Classe for the factory implementations */
@end


@interface ThingActivatorProcessBuilder : NSObject
@property (nonatomic, copy) NSString *linkModeKey; /// The key of linkMode

@property (nonatomic, assign) NSInteger linkModeValue; /// LinkMode value

@property (nonatomic, strong, nullable) ThingSmartDeviceCategoryModel *categoryModel; /// Tertiary category details

@property (nonatomic, strong, nullable) ThingActivatorFactoryConfig *config; /// Pairing network parameters

@property (nonatomic, strong, nullable) NSDictionary *userInfo; /// Custom Parameters

@property (nonatomic, strong, nullable) UIViewController *rootVc; /// Starting VC before entering the pairing process

@end

NS_ASSUME_NONNULL_END
