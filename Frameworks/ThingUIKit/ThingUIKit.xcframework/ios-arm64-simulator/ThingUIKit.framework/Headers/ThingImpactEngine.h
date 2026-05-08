
#import <Foundation/Foundation.h>

typedef enum : NSInteger {
    ThingImpactStyleLight = UIImpactFeedbackStyleLight,
    ThingImpactStyleMedium = UIImpactFeedbackStyleMedium,
    ThingImpactStyleHeavy = UIImpactFeedbackStyleHeavy,
    
    ThingImpactStyleSelection,
    
    ThingImpactStyleNotificationSucc,
    ThingImpactStyleNotificationFail,
    ThingImpactStyleNotificationError,
} ThingImpactStyle;

@interface ThingImpactEngine : NSObject

+ (void)impactWithStyle:(ThingImpactStyle)style NS_AVAILABLE_IOS(10_0);

@end

