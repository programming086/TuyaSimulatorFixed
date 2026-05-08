
#import <Foundation/Foundation.h>
#import "ThingModuleApplicationBlueprint.h"
#import "ThingModuleTabRegisterProtocol.h"

typedef NS_ENUM(NSUInteger, ThingModuleLevel) {
    ThingModuleLevelVeryLow,
    ThingModuleLevelLow,
    ThingModuleLevelNormal,
    ThingModuleLevelHigh,
    ThingModuleLevelVeryHigh
};

NS_ASSUME_NONNULL_BEGIN

/// Macro for registering a customizable class in its implementation file. Use class name as the parameter, e.g., ThingModuleCustomizeRegister(ThingModuleCustomizeManager)
#define ThingModuleCustomizeRegister(className) \
char * thingmodule_##className##_data ThingModuleCustomizeDATASection = ""#className"";

#define ThingModuleSectionName "TModuleSection"
#define ThingModuleCustomizeDATASection __attribute((used, section("__DATA, TModuleSection")))



@protocol ThingModuleConfigDataSource <NSObject>

/// Provides the path to the mark information data file used for tracking or analytics.
+ (NSString *)pathForMarkInfoDataFile;

/// Registers the modules to be displayed on the tab bar. Corresponds to the 'tabs' configuration in config_module.json
+ (NSArray<NSString *> *)provideTabBarModules;
+ (NSString *)provideTabBarDefaultSelectModule;

/// Registers all modules as specified in the 'modules' section of config_module.json. Returns an array of module class names.
+ (NSArray<NSString *> *)provideModules;

/// Registers the mix classes. Corresponds to 'mixMap' in config_module.json. Returns a dictionary mapping module identifiers to class names.
+ (NSDictionary<NSString *, NSString *> *)provideMixMaps;

@end

@interface ThingModuleCustomizeManager : NSObject

@property (nonatomic, strong, readonly)NSDictionary<NSString *, NSString*> *mixMap;
@property (nonatomic, strong, readonly)NSString             *applicationModule;
@property (nonatomic, strong, readonly)NSString             *loginConfigClassName;
@property (nonatomic, strong, readonly)NSString             *tabStyleConfigClassName;
@property (nonatomic, strong, readonly)NSArray              *moduleOnTabBar;
@property (nonatomic, strong, readonly)NSString             *tabSelectedModule;
@property (nonatomic, strong, readonly)NSArray              *modules;
@property (nonatomic, strong, readonly)NSMutableSet         *dataProviderSet;

+ (instancetype)shareManager;

- (void)generalCustomerConfig;

@end

NS_ASSUME_NONNULL_END

