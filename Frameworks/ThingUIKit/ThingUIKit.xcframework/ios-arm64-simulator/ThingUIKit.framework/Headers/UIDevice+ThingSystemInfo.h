//
//  UIDevice+ThingSystemInfo.h
//  ThingUIKit
//
//  Created by ThingInc on 2018/12/20.
//

#import <UIKit/UIKit.h>


UIKIT_EXTERN NSString *const kThingSystemName_iOS;

/**
 @return [[[UIDevice currentDevice] systemVersion] floatValue]
 */
UIKIT_EXTERN CGFloat Thing_SystemVersion(void);
/**
 @return [[UIDevice currentDevice] systemName]
 */
UIKIT_EXTERN NSString * Thing_SystemName(void);

/**
 @return [Thing_SystemName isEqualToString:@"iOS"] && Thing_SystemVersion >= version
 */
UIKIT_EXTERN BOOL Thing_IsIOS(CGFloat version);


/**
 can iPad supported
 */
UIKIT_EXTERN BOOL Thing_IsPad(void);

