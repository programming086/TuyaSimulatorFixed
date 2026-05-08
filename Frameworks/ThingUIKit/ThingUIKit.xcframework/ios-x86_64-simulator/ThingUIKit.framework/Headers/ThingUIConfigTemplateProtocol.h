
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingUIConfigTemplate) {
    ThingUIConfigTemplateUnknown = 0,
    ThingUIConfigTemplateOne = 1,
    ThingUIConfigTemplateTwo = 2,
    ThingUIConfigTemplateThree = 3,
    ThingUIConfigTemplateFour = 4,
    ThingUIConfigTemplateFive = 5,//Reserved, actually no
    ThingUIConfigTemplateSix = 6,
};

@protocol ThingUIConfigTemplateProtocol <NSObject>
// The currently effective configuration of the multi-template
- (ThingUIConfigTemplate)currentTemplateForModuleId:(NSString *)moduleId;
@end

NS_ASSUME_NONNULL_END
